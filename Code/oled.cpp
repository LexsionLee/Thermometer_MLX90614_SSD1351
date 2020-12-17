#include "oled.h"
#include <arduino.h>
#include "SPI.h"
#include "oledfont.h"

uu16 BACK_COLOR;

/******************************************************************************
      函数说明：OLED IO口初始化
      入口数据：无
      返回值：  无
******************************************************************************/
void OLED_IOInit(void)
{
  pinMode(OLED_CLK,OUTPUT);
  pinMode(OLED_DIN,OUTPUT);
  pinMode(OLED_RES,OUTPUT);
  pinMode(OLED_DC,OUTPUT);
  pinMode(OLED_CS,OUTPUT);
  OLED_CS_Clr();
}

/******************************************************************************
      函数说明：OLED串行数据写入函数
      入口数据：dat  要写入的串行数据
      返回值：  无
******************************************************************************/
//void OLED_Write_Bus(u8 dat)
//{
//  u8 i;
//  OLED_CS_Clr();
//  for(i=0;i<8;i++)
//  {       
//    OLED_CLK_Clr();
//    if(dat&0x80)
//    {OLED_DIN_Set();}
//    else 
//    {OLED_DIN_Clr();}
//    OLED_CLK_Set();
//    //delayMicroseconds(20);
//    dat<<=1;
//  }     
//  OLED_CS_Set();
//}

void OLED_Write_Bus(u8 dat)
{
  //OLED_CS_Clr();
  
  SPI.transfer(dat);
  
  //OLED_CS_Set();
}

/******************************************************************************
      函数说明：OLED写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void OLED_WR_DATA8(u8 dat)
{
  OLED_DC_Set();//写数据
  OLED_Write_Bus(dat);
}

/******************************************************************************
      函数说明：OLED写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void OLED_WR_DATA(uu16 dat)
{
  OLED_DC_Set();//写数据
  OLED_Write_Bus(dat>>8);
  OLED_Write_Bus(dat);
}

/******************************************************************************
      函数说明：OLED写入命令
      入口数据：dat 写入的命令
      返回值：  无
******************************************************************************/
void OLED_WR_REG(u8 dat)
{
  OLED_DC_Clr();//写命令
  OLED_Write_Bus(dat);
}

/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void OLED_Address_Set(uu16 x1,uu16 y1,uu16 x2,uu16 y2)
{
  OLED_WR_REG(0x15);//列地址设置
  OLED_WR_DATA8(x1);
  OLED_WR_DATA8(x2);
  OLED_WR_REG(0x75);//行地址设置
  OLED_WR_DATA8(y1);
  OLED_WR_DATA8(y2);
  OLED_WR_REG(0x5C);
}

/******************************************************************************
      函数说明：OLED进入睡眠
      入口数据：无
      返回值：  无
******************************************************************************/
void OLED_Sleep(void)
{
  OLED_WR_REG(0xAE);    //Sleep mode On
  OLED_WR_REG(0xAB);    //功能选择
  OLED_WR_DATA8(0x00);  //Disable internal VDD regulator（关闭内部VDD稳压器）
}

/******************************************************************************
      函数说明：OLED退出睡眠
      入口数据：无
      返回值：  无
******************************************************************************/
void OLED_Wakeup(void)
{
  OLED_WR_REG(0xAB);    //功能选择
  OLED_WR_DATA8(0x01);  //Enable internal VDD regulator（打开内部VDD稳压器）
  delay(1);
  OLED_WR_REG(0xAF);    //Sleep mode OFF
}

/******************************************************************************
      函数说明：OLED初始化函数
      入口数据：无
      返回值：  无
******************************************************************************/
void OLED_Init(void)
{
  OLED_RST_Clr();
  delay(500);
  OLED_RST_Set();

//************* Start Initial Sequence **********// 
  OLED_WR_REG(0xFD);    //解锁显示驱动IC命令模式
  OLED_WR_DATA8(0x12);  //Unlock OLED driver IC MCU interface from entering command，0x16 Lock.
  OLED_WR_REG(0xFD);    //解锁显示驱动IC命令模式
  OLED_WR_DATA8(0xB1);  //Command A2,B1,B3,BB,BE accessible if in unlock state,0xB0 Lock.
  OLED_WR_REG(0xAE);    //Sleep mode On
  OLED_WR_REG(0xB3);    //Front Clock Divider(DivSet)/Oscillator Frequency
  OLED_WR_DATA8(0xF1);  //写时钟参数
  OLED_WR_REG(0xCA);    //配置垂直方向像素点数
  OLED_WR_DATA8(0x5F);  //96-1 = 95 = 0x5F   128x128=7F
  OLED_WR_REG(0xA2);    //Set Display Offset（显示偏移）Set vertical scroll by Row from 0-127
  OLED_WR_DATA8(0x00);  //偏移量0
  OLED_WR_REG(0xA1);    //Set Display Start Line
  OLED_WR_DATA8(0x00);  //
/**********************************************************************
 *命令：OLED_WR_REG(0xA0); 
 *功能：Set Re-map / Color Depth(Display RAM to Panel)重映射和颜色深度;
 *详细描述：
 *A[0]=0b, Horizontal address increment [reset]
 *A[0]=1b, Vertical address increment
 *A[1]=0b, Column address 0 is mapped to SEG0 [reset]
 *A[1]=1b, Column address 127 is mapped to SEG0
 *A[2]=0b, Color sequence: A 􀃆 B 􀃆 C [reset]
 *A[2]=1b, Color sequence is swapped: C 􀃆 B 􀃆 A
 *A[3]=0b, Reserved
 *A[3]=1b, Reserved
 *A[4]=0b, Scan from COM0 to COM[N –1] [reset]
 *A[4]=1b, Scan from COM[N-1] to COM0. Where N is the
 *Multiplex ratio.
 *A[5]=0b, Disable COM Split Odd Even [reset]
 *A[5]=1b, Enable COM Split Odd Even
 *A[7:6] Set Color Depth,
 *00b 256 color
 *01b 65K color, [reset]
 *10b 262k color, 8/18-bit,16 bit (1st option) MCU interface
 *11b 262k color, 16 - bit MCU interface (2nd option)
 *Refer to section for 8.3.2 details.
 **********************************************************************/
  OLED_WR_REG(0xA0);    //
  //if(USE_HORIZONTAL)
  OLED_WR_DATA8(0x74);  //
//  else 
//  OLED_WR_DATA8(0x66);//旋转180°

  OLED_WR_REG(0xB5);    //GPIO设置
  OLED_WR_DATA8(0x00);  //输入模式-关闭
  OLED_WR_REG(0xAB);    //功能选择
  OLED_WR_DATA8(0x01);  //Enable internal VDD regulator（打开内部VDD稳压器）
  OLED_WR_REG(0xB4);    //Set Segment Low Voltage(VSL)
  OLED_WR_DATA8(0xA0);  //A[1:0]=00 ：External VSL
  OLED_WR_DATA8(0xB5);  
  OLED_WR_DATA8(0x55);  //
  OLED_WR_REG(0xC1);    //设置颜色ABC的对比电流,用于设置各颜色对比度
  OLED_WR_DATA8(0x34);  //对比值A  R  //0x14
  OLED_WR_DATA8(0x98);  //对比值B  G  //0x90
  OLED_WR_DATA8(0xA0);  //对比值C  B  //0xA0
  OLED_WR_REG(0xC7);    //设置主对比电流
  OLED_WR_DATA8(0x0F);  //不改变；0x00：1/16  0x0E:15/16
  OLED_WR_REG(0xB1);    //Set Reset(Phase 1) /Precharge(Phase 2) period
  OLED_WR_DATA8(0x32);  //低4位放电周期；高4位充电周期
  OLED_WR_REG(0xBB);    //Set pre-charge voltage level
  OLED_WR_DATA8(0x17);  //默认值：0x17
//  OLED_WR_REG(0xB2);    //
//  OLED_WR_DATA8(0xA4);
//  OLED_WR_DATA8(0x00);
//  OLED_WR_DATA8(0x00);
  OLED_WR_REG(0xB6);      //Set Second Pre-charge Period
  OLED_WR_DATA8(0x01);    //0001b 1 DCLKS  ...  1000 8 DCLKS [reset] ...  1111 15 DCLKS
  OLED_WR_REG(0xBE);      //Set VCOMH Voltage
  OLED_WR_DATA8(0x05);    //Set COM deselect voltage level [reset = 05h]  00h:0.72*VCC
  OLED_WR_REG(0xA6);      //RESET to normal display [reset]
  
  OLED_Clear(BLACK );
  OLED_WR_REG(0xAF);      //Sleep mode OFF,Display ON
  
  OLED_WR_REG(0xB8);       //接下来的63个数据字节通过设置DCLK单位的灰度脉冲宽度来定义灰度表(GS）
  OLED_WR_DATA8(0x02);     // Gray Scale Level 1
  OLED_WR_DATA8(0x03);     // Gray Scale Level 2
  OLED_WR_DATA8(0x04);     // Gray Scale Level 3
  OLED_WR_DATA8(0x05);     // Gray Scale Level 4
  OLED_WR_DATA8(0x06);     // Gray Scale Level 5
  OLED_WR_DATA8(0x07);     // Gray Scale Level 6
  OLED_WR_DATA8(0x08);     // Gray Scale Level 7
  OLED_WR_DATA8(0x09);     // Gray Scale Level 8
  OLED_WR_DATA8(0x0A);     // Gray Scale Level 9
  OLED_WR_DATA8(0x0B);     // Gray Scale Level 10
  OLED_WR_DATA8(0x0C);     // Gray Scale Level 11
  OLED_WR_DATA8(0x0D);     // Gray Scale Level 12
  OLED_WR_DATA8(0x0E);     // Gray Scale Level 13
  OLED_WR_DATA8(0x0F);     // Gray Scale Level 14
  OLED_WR_DATA8(0x10);     // Gray Scale Level 15
  OLED_WR_DATA8(0x11);     // Gray Scale Level 16
  OLED_WR_DATA8(0x12);     // Gray Scale Level 17
  OLED_WR_DATA8(0x13);     // Gray Scale Level 18
  OLED_WR_DATA8(0x15);     // Gray Scale Level 19
  OLED_WR_DATA8(0x17);     // Gray Scale Level 20
  OLED_WR_DATA8(0x19);     // Gray Scale Level 21
  OLED_WR_DATA8(0x1B);     // Gray Scale Level 22
  OLED_WR_DATA8(0x1D);     // Gray Scale Level 23
  OLED_WR_DATA8(0x1F);     // Gray Scale Level 24
  OLED_WR_DATA8(0x21);     // Gray Scale Level 25
  OLED_WR_DATA8(0x23);     // Gray Scale Level 26
  OLED_WR_DATA8(0x25);     // Gray Scale Level 27
  OLED_WR_DATA8(0x27);     // Gray Scale Level 28
  OLED_WR_DATA8(0x2A);     // Gray Scale Level 29
  OLED_WR_DATA8(0x2D);     // Gray Scale Level 30
  OLED_WR_DATA8(0x30);     // Gray Scale Level 31
  OLED_WR_DATA8(0x33);     // Gray Scale Level 32
  OLED_WR_DATA8(0x36);     // Gray Scale Level 33
  OLED_WR_DATA8(0x39);     // Gray Scale Level 34
  OLED_WR_DATA8(0x3C);     // Gray Scale Level 35
  OLED_WR_DATA8(0x3F);     // Gray Scale Level 36
  OLED_WR_DATA8(0x42);     // Gray Scale Level 37
  OLED_WR_DATA8(0x45);     // Gray Scale Level 38
  OLED_WR_DATA8(0x48);     // Gray Scale Level 39
  OLED_WR_DATA8(0x4C);     // Gray Scale Level 40
  OLED_WR_DATA8(0x50);     // Gray Scale Level 41
  OLED_WR_DATA8(0x54);     // Gray Scale Level 42
  OLED_WR_DATA8(0x58);     // Gray Scale Level 43
  OLED_WR_DATA8(0x5C);     // Gray Scale Level 44
  OLED_WR_DATA8(0x60);     // Gray Scale Level 45
  OLED_WR_DATA8(0x64);     // Gray Scale Level 46
  OLED_WR_DATA8(0x68);     // Gray Scale Level 47
  OLED_WR_DATA8(0x6C);     // Gray Scale Level 48
  OLED_WR_DATA8(0x70);     // Gray Scale Level 49
  OLED_WR_DATA8(0x74);     // Gray Scale Level 50
  OLED_WR_DATA8(0x78);     // Gray Scale Level 51
  OLED_WR_DATA8(0x7D);     // Gray Scale Level 52
  OLED_WR_DATA8(0x82);     // Gray Scale Level 53
  OLED_WR_DATA8(0x87);     // Gray Scale Level 54
  OLED_WR_DATA8(0x8C);     // Gray Scale Level 55
  OLED_WR_DATA8(0x91);     // Gray Scale Level 56
  OLED_WR_DATA8(0x96);     // Gray Scale Level 57
  OLED_WR_DATA8(0x9B);     // Gray Scale Level 58
  OLED_WR_DATA8(0xA0);     // Gray Scale Level 59
  OLED_WR_DATA8(0xA5);     // Gray Scale Level 60
  OLED_WR_DATA8(0xAA);     // Gray Scale Level 61
  OLED_WR_DATA8(0xAF);     // Gray Scale Level 62
  OLED_WR_DATA8(0xB4);     // Gray Scale Level 63
  
  OLED_WR_REG(0xB1);      //Set Reset(Phase 1) /Precharge(Phase 2) period
  OLED_WR_DATA8(0x32);    //低4位放电周期；高4位充电周期
  OLED_WR_REG(0xBB);      //Set pre-charge voltage level
  OLED_WR_DATA8(0x17);    //默认值：0x17
//  OLED_WR_REG(0xB2);      //
//  OLED_WR_DATA8(0xA4);
//  OLED_WR_DATA8(0x00);
//  OLED_WR_DATA8(0x00);
  OLED_WR_REG(0xB6);      //Set Second Pre-charge Period
  OLED_WR_DATA8(0x01);    //0001b 1 DCLKS  ...  1000 8 DCLKS [reset] ...  1111 15 DCLKS
  OLED_WR_REG(0xBE);      //Set VCOMH Voltage
  OLED_WR_DATA8(0x05);    //Set COM deselect voltage level [reset = 05h]  00h:0.72*VCC

  OLED_WR_REG(0xA6);      //RESET to normal display [reset]
  OLED_WR_REG(0xAF);      //Sleep mode OFF,Display ON
}

/******************************************************************************
      函数说明：OLED清屏函数
      入口数据：无
      返回值：  无
******************************************************************************/
void OLED_Clear(uu16 Color)
{
  uu16 i,j;
  OLED_Address_Set(0,0,OLED_W-1,OLED_H-1);
    for(i=0;i<OLED_W;i++)
   {
    for (j=0;j<OLED_H;j++)
      {
          OLED_WR_DATA(Color);
      }
    }
}

/******************************************************************************
      函数说明：OLED显示汉字
      入口数据：x,y   起始坐标
                index 汉字的序号
                size1  字号
      返回值：  无
******************************************************************************/
void OLED_ShowChinese(uu16 x,uu16 y, u8 index, u8 size1,uu16 color)
{  
  u8 i,j;
  u8 *temp,size2;
  if(size1==16){temp=Hzk16;}//选择字号
  if(size1==32){temp=Hzk32;}
  OLED_Address_Set(x,y,x+size1-1,y+size1-1); //设置一个汉字的区域
  size2=size1*size1/8;//一个汉字所占的字节
  temp+=index*size2;//写入的起始位置
  for(j=0;j<size2;j++)
  {
    for(i=0;i<8;i++)
    {
      if((pgm_read_byte_near(&*temp)&(1<<i))!=0)//从数据的低位开始读
      {
        OLED_WR_DATA(color);//点亮
      }
      else
      {
        OLED_WR_DATA(BACK_COLOR);//不点亮
      }
    }
    temp++;
   }
}

/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
      返回值：  无
******************************************************************************/
void OLED_Fill(uu16 xsta,uu16 ysta,uu16 xend,uu16 yend,uu16 color)
{          
  uu16 i,j;
  OLED_Address_Set(xsta,ysta,xend,yend);      //设置光标位置 
  for(i=ysta;i<=yend;i++)
  {                               
    for(j=xsta;j<=xend;j++)OLED_WR_DATA(color);//设置光标位置      
  }                   
}

/******************************************************************************
      函数说明：OLED画点
      入口数据：x,y   起始坐标
      返回值：  无
******************************************************************************/
void OLED_DrawPoint(uu16 x,uu16 y,uu16 color)
{
  OLED_Address_Set(x,y,x,y);//设置位置 
  OLED_WR_DATA(color);
}

/******************************************************************************
      函数说明：OLED画一个大的点
      入口数据：x,y   起始坐标
      返回值：  无
******************************************************************************/
void OLED_DrawPoint_big(uu16 x,uu16 y,uu16 color)
{
  OLED_Fill(x-1,y-1,x+1,y+1,color);
}

/******************************************************************************
      函数说明：OLED画线
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
      返回值：  无
******************************************************************************/
void OLED_DrawLine(uu16 x1,uu16 y1,uu16 x2,uu16 y2,uu16 color)
{
  int t;
  int xerr=0,yerr=0,delta_x,delta_y,distance;
  int incx,incy,uRow,uCol;
  delta_x=x2-x1; //计算坐标增量 
  delta_y=y2-y1;
  uRow=x1;//画线起点坐标
  uCol=y1;
  if(delta_x>0)incx=1; //设置单步方向 
  else if (delta_x==0)incx=0;//垂直线 
  else {incx=-1;delta_x=-delta_x;}
  if(delta_y>0)incy=1;
  else if (delta_y==0)incy=0;//水平线 
  else {incy=-1;delta_y=-delta_x;}
  if(delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
  else distance=delta_y;
  for(t=0; t<distance+1; t++)
  {
    OLED_DrawPoint(uRow,uCol,color);//画点
    xerr+=delta_x;
    yerr+=delta_y;
    if(xerr>distance)
    {
      xerr-=distance;
      uRow+=incx;
    }
    if(yerr>distance)
    {
      yerr-=distance;
      uCol+=incy;
    }
  }
}

/******************************************************************************
      函数说明：画矩形
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
      返回值：  无
******************************************************************************/
void OLED_DrawRectangle(uu16 x1, uu16 y1, uu16 x2, uu16 y2,uu16 color)
{
  OLED_DrawLine(x1,y1,x2,y1,color);
  OLED_DrawLine(x1,y1,x1,y2,color);
  OLED_DrawLine(x1,y2,x2,y2,color);
  OLED_DrawLine(x2,y1,x2,y2,color);
}

/******************************************************************************
      函数说明：画圆
      入口数据：x0,y0   圆心坐标
                r       半径
      返回值：  无
******************************************************************************/
void OLED_DrawCircle(uu16 x0,uu16 y0,u8 r,uu16 color)
{
  int a,b;
  a=0;b=r;    
  while(a<=b)
  {
    OLED_DrawPoint(x0-b,y0-a,color);             //3           
    OLED_DrawPoint(x0+b,y0-a,color);             //0           
    OLED_DrawPoint(x0-a,y0+b,color);             //1                
    OLED_DrawPoint(x0-a,y0-b,color);             //2             
    OLED_DrawPoint(x0+b,y0+a,color);             //4               
    OLED_DrawPoint(x0+a,y0-b,color);             //5
    OLED_DrawPoint(x0+a,y0+b,color);             //6 
    OLED_DrawPoint(x0-b,y0+a,color);             //7
    a++;
    if((a*a+b*b)>(r*r))//判断要画的点是否过远
    {
      b--;
    }
  }
}

/******************************************************************************
      函数说明：显示字符
      入口数据：x,y    起点坐标
                num    要显示的字符
                mode   1叠加方式  0非叠加方式
      返回值：  无
******************************************************************************/
void OLED_ShowChar(uu16 x,uu16 y,char num,char mode,uu16 color)
{
    u8 temp;
    u8 pos,t;
    uu16 x0=x;   
    if(x>OLED_W-16||y>OLED_H-16)return;     //设置窗口       
  num=num-' ';//得到偏移后的值
  //num=0;
  OLED_Address_Set(x,y,x+7,y+15);      //设置光标位置 
  if(!mode) //非叠加方式
  {
    for(pos=0;pos<16;pos++)
    { 
      temp=pgm_read_byte_near(&asc2_1608[(uu16)num*16+pos]);     //调用1608字体
      for(t=0;t<8;t++)
        {                 
            if(temp&0x01)OLED_WR_DATA(color);
            else OLED_WR_DATA(BACK_COLOR);
        temp>>=1; 
        x++;
        }
      x=x0;
      y++;
    } 
  }else//叠加方式
  {
    for(pos=0;pos<16;pos++)
    {
        temp=pgm_read_byte_near(&asc2_1608[(uu16)num*16+pos]);     //调用1608字体
      for(t=0;t<8;t++)
        {                 
            if(temp&0x01)OLED_DrawPoint(x+t,y+pos,color);//画一个点     
            temp>>=1; 
        }
    }
  }               
}

/******************************************************************************
      函数说明：显示字符串
      入口数据：x,y    起点坐标
                *p     字符串起始地址
      返回值：  无
******************************************************************************/
void OLED_ShowString(uu16 x, uu16 y, const char *p, uu16 color)
{         
    while(*p!='\0')
    {       
        if(x>OLED_W-16){x=0;y+=16;}
        if(y>OLED_H-16){y=x=0;OLED_Clear(RED);}
        OLED_ShowChar(x,y,*p,1,color);
        x+=8;
        p++;
    }  
}

/******************************************************************************
      函数说明：显示数字
      入口数据：m底数，n指数
      返回值：  无
******************************************************************************/
u32 mypow(u8 m,u8 n)
{
  u32 result=1;
  while(n--)result*=m;
  return result;
}

/******************************************************************************
      函数说明：显示数字
      入口数据：x,y    起点坐标
                num    要显示的数字
                len    要显示的数字个数
      返回值：  无
******************************************************************************/
void OLED_ShowNum(uu16 x,uu16 y,uu16 num,u8 len,uu16 color)
{           
  u8 t,temp;
  u8 enshow=0;
  for(t=0;t<len;t++)
  {
    temp=(num/mypow(10,len-t-1))%10;
    if(enshow==0&&t<(len-1))
    {
      if(temp==0)
      {
        OLED_ShowChar(x+8*t,y,' ',0,color);
        continue;
      }else enshow=1; 
       
    }
    OLED_ShowChar(x+8*t,y,temp+48,0,color); 
  }
}

/******************************************************************************
      函数说明：显示小数
      入口数据：x,y    起点坐标
                num    要显示的小数
                len    要显示的数字个数
      返回值：  无
******************************************************************************/
void OLED_ShowNum1(uu16 x,uu16 y,float num,u8 len,uu16 color)
{           
  u8 t,temp;
  //u8 enshow=0;  //这行代码看起来没有用
  uu16 num1;
  num1=num*100;
  for(t=0;t<len;t++)
  {
    temp=(num1/mypow(10,len-t-1))%10;
    if(t==(len-2))
    {
      OLED_ShowChar(x+8*(len-2),y,'.',0,color);
      t++;
      len+=1;
    }
    OLED_ShowChar(x+8*t,y,temp+48,0,color);
  }
}

/******************************************************************************
      函数说明：显示40x40图片
      入口数据：x,y    起点坐标
      返回值：  无
******************************************************************************/
//void OLED_ShowPicture(uu16 x1,uu16 y1,uu16 x2,uu16 y2)
//{
//  int i;
//    OLED_Address_Set(x1,y1,x2,y2);
//    for(i=0;i<1600;i++)
//    {
//      OLED_WR_DATA8(image[i*2+1]);
//      OLED_WR_DATA8(image[i*2]);
//    }     
//}

/******************************************************************************
      函数说明：OLED显示4821数字
      入口数据：x,y   起始坐标
                index 数字的序号
      返回值：  无
******************************************************************************/
void OLED_ShowNumBig(uu16 x,uu16 y,u8 index,uu16 color)
{  
  u8 i,j, k;
  u8 *temp,size2;
  k = 0;
  temp = num_4821;
  OLED_Address_Set(x,y,x+21-1,y+48-1); //设置一个汉字的区域
  size2=144;//一个汉字所占的字节
  temp+=index*size2;//写入的起始位置
  for(j=0;j<size2;j++)
  {
    if(k != 2)
    {
    for(i=0;i<8;i++)
    {
      if((pgm_read_byte_near(&*temp)&(1<<i))!=0)//从数据的低位开始读
      {
        OLED_WR_DATA(color);//点亮
      }
      else
      {
        OLED_WR_DATA(BACK_COLOR);//不点亮
      }
    }
    temp++;
    k++;
    }
    else
    {
    for(i=0;i<5;i++)
    {
      if((pgm_read_byte_near(&*temp)&(1<<i))!=0)//从数据的低位开始读
      {
        OLED_WR_DATA(color);//点亮
      }
      else
      {
        OLED_WR_DATA(BACK_COLOR);//不点亮
      }
    }
      temp++;
      k = 0;
    }
   }
}

/******************************************************************************
      函数说明：OLED显示温度标志
      入口数据：x,y   起始坐标
                index 符号的序号
      返回值：  无
******************************************************************************/
void OLED_ShowCF(uu16 x,uu16 y, u8 index,uu16 color)
{  
  u8 i,j;
  u8 *temp;
  temp = cfsmb_2424;
  OLED_Address_Set(x,y,x+24-1,y+24-1); //设置一个汉字的区域
  temp+=index*72;//写入的起始位置
  for(j=0;j<72;j++)
  {
    for(i=0;i<8;i++)
    {
      if((pgm_read_byte_near(&*temp)&(1<<i))!=0)//从数据的低位开始读
      {
        OLED_WR_DATA(color);//点亮
      }
      else
      {
        OLED_WR_DATA(BACK_COLOR);//不点亮
      }
    }
    temp++;
   }
}

/******************************************************************************
      函数说明：显示测试
      入口数据：无
      返回值：  无
******************************************************************************/
void OLED_Test_FSDSC(void)
{
  OLED_Sleep();
  OLED_Clear(WHITE );
  OLED_Wakeup();
  delay(2500);
  OLED_Sleep();
  OLED_Clear(RED );
  OLED_Wakeup();
  delay(2500);
  OLED_Sleep();
  OLED_Clear(GREEN );
  OLED_Wakeup();
  delay(2500);
  OLED_Sleep();
  OLED_Clear(BLUE );
  OLED_Wakeup();
  delay(2500);
}
