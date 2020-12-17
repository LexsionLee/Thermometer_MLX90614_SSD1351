#include "i2c.h"
#include <Arduino.h>



/************软件模拟方式I2C，IO 初始化***************/
void I2C_sw_IOInit()
{
  pinMode(I2C_SCL,OUTPUT);
  pinMode(I2C_SDA,OUTPUT);
  digitalWrite(I2C_SCL,HIGH);
  digitalWrite(I2C_SDA,HIGH);
}

  
/********开启90614的I2C总线********/
unsigned char I2CStart(void)
{
  I2C_sw_SDA_Set();
  I2C_sw_SCL_Set();
  I2C_sw_Wait();
  if(digitalRead(I2C_SDA) == LOW)
  {
      return false;      //SDA线为低电平则总线忙,退出
  }
  I2C_sw_SDA_Clr();
  I2C_sw_Wait();
  if(digitalRead(I2C_SDA) == HIGH)
  {
      return false;      //SDA线为高电平则总线出错,退出
  }
  I2C_sw_SCL_Clr();
  I2C_sw_Wait();
  
  return true;
}


/********关闭90614的I2C总线*******/
void I2CStop(void)
{
  pinMode(I2C_SDA,OUTPUT);
  pinMode(I2C_SCL,OUTPUT);
  
  I2C_sw_SDA_Clr();
  I2C_sw_SCL_Clr();
  I2C_sw_Wait();
  I2C_sw_SCL_Set();
  I2C_sw_Wait();
  I2C_sw_SDA_Set();
}


/*********发送 ACK*********/
void I2CAck(void)
{
  pinMode(I2C_SDA,OUTPUT);
  pinMode(I2C_SCL,OUTPUT);

  I2C_sw_SDA_Clr();
  I2C_sw_SCL_Clr();
  I2C_sw_Wait();
  I2C_sw_SCL_Set();
  I2C_sw_Wait();
  I2C_sw_SCL_Clr();
}


/*********发送NO ACK*********/
void I2CNoAck(void)
{
  pinMode(I2C_SDA,OUTPUT);
  pinMode(I2C_SCL,OUTPUT);
  
  I2C_sw_SDA_Set();
  I2C_sw_SCL_Clr();
  I2C_sw_Wait();
  I2C_sw_SCL_Set();
  I2C_sw_Wait();
  I2C_sw_SCL_Clr();
}


/*********读取ACK信号*********/
unsigned char I2CWaitAck(void)  //返回为:1=有ACK,0=无ACK
{
  unsigned char errtime = 255;
  
  I2C_sw_SCL_Clr();
  pinMode(I2C_SDA,INPUT);
  I2C_sw_Wait();
  I2C_sw_SCL_Set();
  I2C_sw_Wait();
  while(digitalRead(I2C_SDA) == HIGH)
  {
    errtime--;
    if (!errtime)
    I2C_sw_SCL_Clr();
    return false;
  }
  I2C_sw_SCL_Clr();
  
  return true;
}


/************MCU向90614发送一个字节*************/
void I2CSendByte(unsigned char demand) //数据从高位到低位//
{
  unsigned char i=8;
  
  pinMode(I2C_SDA,OUTPUT);

  while(i--)
  {
    I2C_sw_SCL_Clr();
    asm("NOP");
    if(demand & 0x80)
    {I2C_sw_SDA_Set();}
    else
    {I2C_sw_SDA_Clr();}
    
    demand<<=1;
    I2C_sw_Wait();
    I2C_sw_SCL_Set();
    I2C_sw_Wait();
  }
  I2C_sw_SCL_Clr();
}


/*********MCU从90614接收一字节*********/
unsigned char I2CReceiveByte(void)  //数据从高位到低位//
{
  unsigned char i=8;
  unsigned char ddata=0;
  
  pinMode(I2C_SDA,INPUT);
  while(i--)
  {
    ddata<<=1;          //数据从高位开始读取
    I2C_sw_SCL_Clr();
    I2C_sw_Wait();
    I2C_sw_SCL_Set();
    I2C_sw_Wait();     //从高位开始 ddata|=SDA;ddata<<=1
    if(digitalRead(I2C_SDA) == HIGH)
    {
      ddata |= 0x01;
    }
  }
  I2C_sw_SCL_Clr();
  
  return ddata;
}


//READ DATA FROM RAM/EEPROM
//Name: MEM_READ
//Function: Read the data from MLX90614 with given slave address and command
//Parameters: unsigned char slave_addR (slave address)
//            unsigned char cmdR   (command)
//Return: unsigned long int Data
//--------------------------------------

unsigned char  MEM_READ(unsigned char slave_addR, unsigned char cmdR , unsigned int *temp_data)
{
   unsigned char DataL;                    //
   unsigned char DataH;        //Data packets from MLX90614
         int temp_dat;
   unsigned char Pecreg;         //Calculated PEC byte storage
         unsigned char arr[6];         //Buffer for the sent bytes
   unsigned char ack_nack;
   unsigned char SLA;
         unsigned char error_timer = 0,n,date[3];  //error calculated
                         
   SLA=(slave_addR<<1);
         
         do
         {
           if(error_timer>=5)
           break;
           error_timer ++;
           
        //write command
           I2CStart();
           I2CSendByte(SLA);
           if( I2CWaitAck() == false)
           {
             I2CStop();
             continue;
           }
           I2CSendByte(cmdR);
           if( I2CWaitAck() == false)
           {
             I2CStop();
             continue;
           }

        //read data
           I2CStart();
           I2CSendByte(SLA+1);   
           if( I2CWaitAck() == false)
           {
             I2CStop();
             continue;
           }
           
           for(n=0;n<3;n++)
     {
        date[n]=I2CReceiveByte();
        if (n!=2)         //最后一个数据不应答
        {
     I2CAck();
        }
     }
  I2CNoAck();
  I2CStop();
        
         arr[5]=(SLA);
         arr[4]=cmdR;
         arr[3]=(SLA+1);               
         arr[2]=date[0];
         arr[1]=date[1];
         arr[0]=0;   
        Pecreg = PEC_Calculation(arr);   
           
           
         }while((Pecreg!=date[2]));
         
         if(error_timer<5)
          {
              (*temp_data) = (date[1]<<8)|date[0];    
              return true;
          }
         
         return false;
         

}




//写eeprom
void EEPROM_WRITE(unsigned char slave_addW,unsigned char cmdW,unsigned char DataL,unsigned char DataH)
{

     unsigned char Pecreg;          //Calculated PEC byte storage
     unsigned char SLA;
     unsigned char arr1[6];         //Buffer for the transmitted bytes
     unsigned char error_timer = 0;

     SLA=(slave_addW<<1);
     
     arr1[5] = 0;
     arr1[4] = SLA;
     arr1[3] = cmdW;
     arr1[2] = DataL;
     arr1[1] = DataH;
     arr1[0] = 0;
     
     Pecreg = PEC_Calculation(arr1);
     

    do
     {
         error_timer++;
       if(error_timer>5)
         break;
         I2CStart();
         I2CSendByte(SLA); 
         
        if( I2CWaitAck() == false)
        {
          I2CStop();
        
          continue;
        }
        
         I2CSendByte(cmdW);
        
        if( I2CWaitAck() == false)
        {
          I2CStop();
          continue;
        }
        
         I2CSendByte(DataL);
        
        if( I2CWaitAck() == false)
        {
          I2CStop();
          continue;
        }
        
         I2CSendByte(DataH);
        
        if( I2CWaitAck() == false)
        {
          I2CStop();
          continue;
        }
        
         I2CSendByte(Pecreg);
        
        if( I2CWaitAck() == false)
        {
          I2CStop();
          continue;
        }
     } while(1);
            
     I2CStop();
     delay(100);
}



/*******************************************************************************
* Function Name  : PEC_calculation
* Description    : Calculates the PEC of received bytes
* Input          : pec[]
* Output         : None
* Return         : pec[0]-this byte contains calculated crc value
*******************************************************************************/
unsigned char  PEC_Calculation(unsigned char  pec[])
{
    unsigned char  crc[6];
    unsigned char  BitPosition=47;
    unsigned char  shift;
    unsigned char  i;
    unsigned char  j;
    unsigned char  temp;

    do
    {
        /*Load pattern value 0x000000000107*/
      
        crc[5]=0;
        crc[4]=0;
        crc[3]=0;
        crc[2]=0;
        crc[1]=0x01;
        crc[0]=0x07;

        /*Set maximum bit position at 47 ( six bytes byte5...byte0,MSbit=47)*/
        BitPosition=47;

        /*Set shift position at 0*/
        shift=0;

        /*Find first "1" in the transmited message beginning from the MSByte byte5*/
        i=5;
        j=0;
        while((pec[i]&(0x80>>j))==0 && i>0)
        {
            BitPosition--;
            if(j<7)
            {
                j++;
            }
            else
            {
                j=0x00;
                i--;
            }
        }/*End of while */

        /*Get shift value for pattern value*/
        shift=BitPosition-8;

        /*Shift pattern value */
        while(shift)
        {
            for(i=5; i<0xFF; i--)
            {
                if((crc[i-1]&0x80) && (i>0))
                {
                    temp=1;
                }
                else
                {
                    temp=0;
                }
                crc[i]<<=1;
                crc[i]+=temp;
            }/*End of for*/
            shift--;
        }/*End of while*/

        /*Exclusive OR between pec and crc*/
        for(i=0; i<=5; i++)
        {
            pec[i] ^=crc[i];
        }/*End of for*/
    }
    while(BitPosition>8); /*End of do-while*/

    return pec[0];
}
