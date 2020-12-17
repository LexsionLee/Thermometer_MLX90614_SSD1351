#ifndef _I2C_H
#define _I2C_H

//定义I2C IO口线

#define I2C_SCL   3
#define I2C_SDA   2

/*********I2C延时***********/
#define I2C_sw_Wait();      delayMicroseconds(5);

//定义口线操作
#define I2C_sw_SCL_Set()  digitalWrite(I2C_SCL,HIGH)
#define I2C_sw_SCL_Clr()  digitalWrite(I2C_SCL,LOW)

#define I2C_sw_SDA_Set()  digitalWrite(I2C_SDA,HIGH)
#define I2C_sw_SDA_Clr()  digitalWrite(I2C_SDA,LOW)

void I2C_sw_IOInit();
unsigned char I2CStart(void);
void I2CStop(void);
void I2CAck(void);
void I2CNoAck(void);
unsigned char I2CWaitAck(void);
void I2CSendByte(unsigned char demand);
unsigned char I2CReceiveByte(void);
unsigned char  MEM_READ(unsigned char slave_addR, unsigned char cmdR , unsigned int *temp_data);
void EEPROM_WRITE(unsigned char slave_addW,unsigned char cmdW,unsigned char DataL,unsigned char DataH);
unsigned char  PEC_Calculation(unsigned char  pec[]);

#endif
