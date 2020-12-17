#include"MLX90614.h"
#include<Arduino.h>
#include"i2c.h"

/******************************************************************************
      函数说明：MLX90614 IO口初始化
      入口数据：无
      返回值：  无
******************************************************************************/
void mlx_Init()
{
  I2C_sw_IOInit();
  delay(100);
}

/******************************************************************************
      函数说明：读MLX90614中某个地址的16位数据
      入口数据：unsigned char dat_addr  读取的寄存器地址
      返回值：  unsigned int dat_result  返回数据
******************************************************************************/
unsigned int mlx90614_read(unsigned char dat_addr)
{
  unsigned int dat_result = 0x0000;
  MEM_READ(MLX90614_I2CADDR, dat_addr ,&dat_result);
  return dat_result;
}

/******************************************************************************
      函数说明：写MLX90614中某个地址的16位数据
      入口数据：unsigned char dat_addr 数据写入地址, unsigned int dat 待写的数据
      返回值：  无
******************************************************************************/
void mlx90614_write(unsigned char dat_addr, unsigned int dat)
{
  EEPROM_WRITE(MLX90614_I2CADDR, dat_addr, (dat&0x00FF),(dat>>8));
}

/******************************************************************************
      函数说明：写MLX90614中EMISS并检查写入是否成功
      入口数据：unsigned int dat 待写的数据
      返回值：  0x00成功，0x01失败
******************************************************************************/
unsigned char mlx90614_write_EMISS(unsigned int dat)
{
  //写EMISS需要写0x0000,再写自定义数据
  mlx90614_write(MLX90614_EMISS, 0x0000);
  delay(500);
  mlx90614_write(MLX90614_EMISS, dat);
  delay(500);
  if(dat != mlx90614_read(MLX90614_EMISS))
  {
    return 0x01;
  }else
  {
    return 0x00;
  }
}
