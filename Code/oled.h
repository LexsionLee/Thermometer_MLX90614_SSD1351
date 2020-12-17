#ifndef _OLED_H
#define _OLED_H

//宏定义OLED的IO口线
#define OLED_CLK 15
#define OLED_DIN 16
#define OLED_RES 10
#define OLED_DC 9
#define OLED_CS 8

//宏定义OLED像素尺寸
#define OLED_W  128
#define OLED_H  96

//宏定义基本IO写操作
#define OLED_CLK_Set()  digitalWrite(OLED_CLK,HIGH)
#define OLED_CLK_Clr()  digitalWrite(OLED_CLK,LOW)

#define OLED_DIN_Set()  digitalWrite(OLED_DIN,HIGH)
#define OLED_DIN_Clr()  digitalWrite(OLED_DIN,LOW)

#define OLED_RST_Set()  digitalWrite(OLED_RES,HIGH)
#define OLED_RST_Clr()  digitalWrite(OLED_RES,LOW)

#define OLED_DC_Set()   digitalWrite(OLED_DC,HIGH)
#define OLED_DC_Clr()   digitalWrite(OLED_DC,LOW)

#define OLED_CS_Set()   digitalWrite(OLED_CS,HIGH)
#define OLED_CS_Clr()   digitalWrite(OLED_CS,LOW)

#define OLED_CMD  0 //D\C控制，0写命令
#define OLED_DATA 1

//#define  u8 unsigned char
//#define uu16 unsigned int
//#define u32 unsigned long
typedef unsigned char u8;
typedef unsigned int uu16;
typedef unsigned long u32;

extern uu16 BACK_COLOR, POINT_COLOR;

//#ifdef __cplusplus
//extern "C" {
//#endif

void OLED_IOInit(void);

void OLED_Write_Bus(u8 dat);
void OLED_WR_DATA8(u8 dat);
void OLED_WR_DATA(uu16 dat);
void OLED_WR_REG(u8 dat);
void OLED_Address_Set(uu16 x1,uu16 y1,uu16 x2,uu16 y2);
void OLED_Sleep(void);
void OLED_Wakeup(void);
void OLED_Init(void);
void OLED_Clear(uu16 Color);
void OLED_ShowChinese(uu16 x,uu16 y,u8 index,u8 size1,uu16 color);
void OLED_Fill(uu16 xsta,uu16 ysta,uu16 xend,uu16 yend,uu16 color);
void OLED_DrawPoint(uu16 x,uu16 y,uu16 color);
void OLED_DrawPoint_big(uu16 x,uu16 y,uu16 color);
void OLED_DrawLine(uu16 x1,uu16 y1,uu16 x2,uu16 y2,uu16 color);
void OLED_DrawRectangle(uu16 x1, uu16 y1, uu16 x2, uu16 y2,uu16 color);
void OLED_DrawCircle(uu16 x0,uu16 y0,u8 r,uu16 color);
void OLED_ShowChar(uu16 x,uu16 y,char num,char mode,uu16 color);
void OLED_ShowString(uu16 x,uu16 y,const char *p,uu16 color);
u32 mypow(u8 m,u8 n);
void OLED_ShowNum(uu16 x,uu16 y,uu16 num,u8 len,uu16 color);
void OLED_ShowNum1(uu16 x,uu16 y,float num,u8 len,uu16 color);
//void OLED_ShowPicture(uu16 x1,uu16 y1,uu16 x2,uu16 y2);
void OLED_ShowNumBig(uu16 x,uu16 y,u8 index,uu16 color);
void OLED_ShowCF(uu16 x,uu16 y,u8 index,uu16 color);
void OLED_Test_FSDSC(void);

//#ifdef __cplusplus
//}
//#endif

//颜色
#define WHITE            0xFFFF   //白色
#define BLACK            0x0000     //黑色
#define BLUE             0x001F   //蓝色     0000000000011111
#define BRED             0XF81F   //
#define GRED       0XFFE0   //
#define GBLUE      0X07FF   //
#define RED              0xF800   //红色     1111100000000000
#define MAGENTA          0xF81F   //品红色
#define GREEN            0x07E0   //绿色     0000011111100000
#define CYAN             0x7FFF   //青色
#define YELLOW           0xBFE0   //黄色     1111110010100000
#define ORANGE           0xFCA0   //橙色
#define BROWN        0XBC40   //棕色
#define BRRED        0XFC07   //棕红色
#define GRAY         0X8430   //灰色
//GUI颜色

#define DARKBLUE         0X01CF //深蓝色
#define LIGHTBLUE        0X7D7C //浅蓝色  
#define GRAYBLUE         0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN       0X841F //浅绿色
#define LGRAY            0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

#endif
