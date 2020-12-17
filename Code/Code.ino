/**********************************************
 * MLX90614_with_OLED_SSD1351_Thermometer
 * MLX90614的学习与测试
 * 通过OLED屏幕卖家提供的C51代码适配Arduino
 * 软件模拟IO方式实现I2C、SMBus
 * 
 * Modify：
 * 切换使用硬件SPI
 * -20201119
 * 添加I2C驱动
 * -20201126
 * 参考不知名大佬代码重写I2C.cpp
 * -20201212
 * 
 * Author：
 * Created 14 Dec. 2020
 * by Lexsion Lee
 * https://Lexsion.com
 * 
 * 硬件：
 * 平台：Arduino Pro Micro
 * IO:
 * OLED_CLK 15
 * OLED_DIN 16
 * OLED_RES 10
 * OLED_DC 9
 * OLED_CS 8
 * 
 * I2C_SDA 2
 * I2c_SCL 3
 * 
 * OLED驱动文件：
 * oled.h & oled.cpp
 * -- oledfont.h
 * -- SPI.h & SPI.cpp
 * MLX90614驱动：
 * MLX90614.cpp & MLX90614.h
 * -- i2c.cpp & i2c.h
 *********************************************/

#include "SPI.h"
#include "oled.h"
#include "i2c.h"
#include "MLX90614.h"

float thermo_TOBJ1; //存储温度数据
unsigned char cfb; //摄氏度华氏度指示，0为摄氏，1为华氏 //*!避免出现2，是个警告标识
unsigned int disp_color;  //BLUE:sub35.90 ; GREEN:35.90~37.3 ; ORANGE：37.3~38.00 ; RED:over38.00

//函数声明区域：
void DispWell(uu16 y_posi,uu16 color); //显示欢迎信息
void ThermoDisplay(float dat_disp);  //显示温度
void Write_EMISS(unsigned int dat_e);  //写EMISS数据，并显示是否成功

void setup() {
  // put your setup code here, to run once:

  BACK_COLOR=BLACK ;  //默认背景色
  disp_color = BLUE;  //默认温度显示颜色
  cfb = 0;          //默认摄氏温标
  
  //IO初始化
  OLED_IOInit();
  SPI.begin();
  mlx_Init();

  OLED_Init();  //OLED初始化

  //开始绘制基础界面
  OLED_Fill(0,0,127,23,RED);   
  OLED_ShowString(7,4,"IR Thermometer", BLACK);
  OLED_ShowString(8,80,"by Lexsion.NET",ORANGE);
  OLED_ShowCF(103,52,cfb,disp_color);
  OLED_Fill(46,64,52,70,disp_color);
  OLED_ShowNumBig(0,34,11,disp_color);
  OLED_ShowNumBig(21,34,11,disp_color);
  OLED_ShowNumBig(59,34,11,disp_color);
  OLED_ShowNumBig(80,34,11,disp_color);

  DispWell(28,YELLOW);         //显示欢迎
  /********************完成绘制***********************/
  
  delay(1500);   //延时1.5S等待MLX90614数据稳定
  
  //写EMISS
  //Write_EMISS(0xD99B);
}


void loop() {
  // put your main code here, to run repeatedly:
    thermo_TOBJ1 = mlx90614_read(MLX90614_TOBJ1)*0.02-273.15; //读取温度数据
    ThermoDisplay(thermo_TOBJ1); //将温度显示到屏幕
    
//    以下为测试代码：
//    OLED_ShowNum(31,28,(thermo_TOBJ1),2,RED);
//    OLED_ShowNum1(47,28,(thermo_TOBJ1),2,RED);
//    tempDisplay();
    
    delay(3000);    //延时三秒~，实现大约每3秒刷新一次数据
}

/******************************************************************************
      函数说明：绘制显示区域中心的温度内容
      入口数据：float dat_disp 温度数据
      返回值：  无
******************************************************************************/
void ThermoDisplay(float dat_disp)
{
  unsigned char i,temp;
  unsigned char enshow = 0;
  unsigned int vl; 
  vl = dat_disp * 100;   //将要显示的温度值乘以100

  //根据温度值判断显示颜色
  if(vl <= 3590)
  {
    disp_color = BLUE;
  }else if(vl <= 3730)
  {
    disp_color = GREEN;
  }else if(vl <= 3800)
  {
    disp_color = ORANGE;
  }else if(vl > 3800)
  {
    disp_color = RED;
  }
  
  OLED_Fill(31,28,95,44,BLACK);
  OLED_Fill(46,64,52,70,disp_color);
  OLED_ShowCF(103,52,cfb,disp_color);
  
  for(i=0; i<2; i++)
  {
    temp = (vl/mypow(10,3-i))%10;
    if(enshow==0 && i<1)
    {
      if(temp == 0)
      {
        OLED_Fill(21*i,34,21*(i+1),82,BLACK);
        continue;
      }else enshow = 1;
    }
    OLED_ShowNumBig(21*i,34,temp,disp_color);
  }
  for(i=0; i<2; i++)
  {
    temp = (vl/mypow(10,1-i))%10;
    OLED_ShowNumBig(59+(21*i),34,temp,disp_color);
  }

//根据温度判断是否显示警告标志
  if(vl > 3800)
  {
    OLED_ShowCF(103,28,2,disp_color);             //显示警告标识
  }else
  {
    OLED_ShowCF(103,28,2,BLACK);
  }
}

/******************************************************************************
      函数说明：OLED显示汉字 欢迎使用
      入口数据：  y_posi 起始Y坐标  //28
                color  颜色
      返回值：  无
******************************************************************************/
void DispWell(uu16 y_posi,uu16 color)
{
  OLED_ShowChinese(31,y_posi,0,16,color);
  OLED_ShowChinese(47,y_posi,1,16,color);
  OLED_ShowChinese(63,y_posi,2,16,color);
  OLED_ShowChinese(79,y_posi,3,16,color);
}

/******************************************************************************
      函数说明： 修改EMISS，并显示结果
      入口数据：  dat_e  要修改的EMISS值
                
      返回值：  无
******************************************************************************/
void Write_EMISS(unsigned int dat_e)
{
  if(mlx90614_write_EMISS(dat_e) == 0x00)
  {
    OLED_Fill(0,80,127,95,BLACK);
    OLED_ShowString(8,80,"EMISS Changed!",ORANGE);
    delay(1000);
    OLED_Fill(0,80,127,95,BLACK);
    OLED_ShowString(8,80,"by Lexsion.NET",ORANGE);
  }else
  {
    OLED_Fill(0,80,127,95,BLACK);
    OLED_ShowString(8,80,"EMISS WR FAIL!",ORANGE);
    delay(1000);
    OLED_Fill(0,80,127,95,BLACK);
    OLED_ShowString(8,80,"by Lexsion.NET",ORANGE);
  }
}
