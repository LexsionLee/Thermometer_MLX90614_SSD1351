# Thermometer_MLX90614_SSD1351

## 简介：

本项目当前仅作测试学习，不是一个最终产品。基于Arduino平台，使用的开发板为Pro Micro（ATMEGA32U4）。通过I2C接口与MLX90614通信，通过硬件SPI驱动SSD1351 RGB OLED。有读写MLX90614的代码，但主函数仅实现隔三秒读取温度显示一次。欢迎各位为此项目添砖加瓦！

## 硬件：

MCU：ATMEGA32U4
Board：ProMicro （Arduino Leonardo）

OLED Driver　IC：SSD1351

OLED Power IC：ASM1117 3V3

温度传感器：MLX90614

### 引脚使用：

OLED_CLK:   D15       SCL  
OLED_DIN:    D16       SDIN  
OLED_RES:   D10      RST  
OLED_DC:     D9         D/C  
OLED_CS:     D8         CS  (低电平有效)  

MLX90614_I2C_SDA： D2   
MLX90614_I2C_SCL： D3   

## TODO:

1. 改为按键触发测量，添加灭屏休眠
2. 添加通过按键修改发射率功能
3. 设计一个用于体温测量的补偿算法

...欢迎补充