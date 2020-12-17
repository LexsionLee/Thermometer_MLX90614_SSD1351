#ifndef _OLEDFONT_H
#define _OLEDFONT_H

//常用ASCII表:asc2_1608
//偏移量32
//ASCII字符集
//偏移量32
//大小:12*6

#include <avr/pgmspace.h>
//#define  u8 unsigned char
//#define uu16 unsigned int
//#define u32 unsigned long
typedef unsigned char u8;
typedef unsigned int uu16;
typedef unsigned long u32;
/************************************16*16的点阵************************************/
const u8 Hzk16[] PROGMEM={

// 欢(0) 迎(1) 使(2) 用(3)

0x00,0x03,0x00,0x03,0x7F,0x03,0x60,0x7F,0xE0,0x61,0xB6,0x31,0xFC,0x06,0x78,0x06,
0x18,0x06,0x3C,0x0F,0x6C,0x0F,0xE6,0x19,0x83,0x19,0xC0,0x30,0x60,0x60,0x30,0xC0,/*"欢",0*/
0x00,0x00,0x0C,0x03,0xD8,0x7D,0xD8,0x6C,0xC0,0x6C,0xC0,0x6C,0xDF,0x6C,0xD8,0x6C,
0xD8,0x6C,0xD8,0x7F,0xD8,0x3D,0xD8,0x0C,0x18,0x0C,0x3C,0x0C,0xE6,0xFF,0x00,0x00,/*"迎",1*/
0x18,0x06,0x18,0x06,0xF8,0xFF,0x0C,0x06,0x0C,0x06,0xEE,0x7F,0x6E,0x66,0x6F,0x66,
0xEC,0x7F,0x0C,0x06,0xCC,0x06,0x8C,0x07,0x0C,0x03,0x8C,0x07,0xCC,0x1C,0x7C,0xF0,/*"使",2*/
0x00,0x00,0xFC,0x3F,0x8C,0x31,0x8C,0x31,0x8C,0x31,0xFC,0x3F,0x8C,0x31,0x8C,0x31,
0x8C,0x31,0xFC,0x3F,0x8C,0x31,0x8C,0x31,0x8C,0x31,0x86,0x31,0x86,0x3D,0x03,0x18,/*"用",3*/
};

/****************************************32*32的点阵************************************/
const u8 Hzk32[] PROGMEM={       
 //中(0) 国(1)

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x01,0x00,
0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,
0x10,0x80,0x01,0x04,0xF0,0xFF,0xFF,0x0F,0x30,0x80,0x01,0x04,0x30,0x80,0x01,0x04,
0x30,0x80,0x01,0x04,0x30,0x80,0x01,0x04,0x30,0x80,0x01,0x04,0x30,0x80,0x01,0x04,
0x30,0x80,0x01,0x04,0x30,0x80,0x01,0x04,0xF0,0xFF,0xFF,0x07,0x30,0x80,0x01,0x04,
0x30,0x80,0x01,0x0C,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,
0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,
0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,/*"中",0*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x04,0xF0,0xFF,0xFF,0x1F,
0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,0x30,0x00,0xC0,0x0C,0x30,0xFF,0xFF,0x0D,
0x30,0x80,0x01,0x0C,0x30,0x80,0x01,0x0C,0x30,0x80,0x01,0x0C,0x30,0x80,0x01,0x0C,
0x30,0x80,0x01,0x0C,0x30,0x80,0x21,0x0C,0x30,0xFE,0x7F,0x0C,0x30,0x80,0x01,0x0C,
0x30,0x80,0x05,0x0C,0x30,0x80,0x19,0x0C,0x30,0x80,0x31,0x0C,0x30,0x80,0x71,0x0C,
0x30,0x80,0x21,0x0C,0x30,0x80,0x21,0x0C,0x30,0x80,0xC1,0x0C,0xB0,0xFF,0xFF,0x0D,
0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,0xF0,0xFF,0xFF,0x0F,
0x30,0x00,0x00,0x0C,0x30,0x00,0x00,0x0C,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"国",1*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x03,0x00,0x00,
0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x00,0x80,0x01,0x00,0x08,
0x80,0x41,0xF8,0x1F,0xFC,0xFF,0x08,0x18,0x80,0xC1,0x08,0x18,0x80,0x41,0x08,0x18,
0x80,0x41,0x08,0x18,0x80,0x41,0x08,0x18,0x80,0x41,0x08,0x18,0x80,0x41,0x08,0x18,
0x80,0x41,0x08,0x18,0x80,0x41,0x08,0x18,0x80,0x41,0x08,0x18,0x80,0x40,0x08,0x18,
0x80,0x40,0x08,0x18,0xC0,0x60,0x08,0x18,0xC0,0x60,0x08,0x18,0x40,0x60,0x08,0x18,
0x60,0x60,0x08,0x18,0x20,0x60,0x08,0x18,0xB0,0x30,0xF8,0x1F,0x10,0x3F,0x08,0x18,
0x08,0x1C,0x08,0x18,0x04,0x08,0x08,0x18,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"加",3*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x38,0x00,
0x60,0x00,0x18,0x00,0xC0,0x00,0x18,0x00,0x80,0x01,0x18,0x00,0x80,0x01,0x18,0x00,
0x00,0x18,0x18,0x04,0x00,0xE8,0xFF,0x0F,0x04,0x24,0x18,0x0C,0x08,0x24,0x18,0x0C,
0x38,0x24,0x18,0x0C,0x30,0x22,0x18,0x0C,0x30,0x22,0x18,0x0C,0x20,0x22,0x18,0x0C,
0x00,0x21,0x18,0x0C,0x00,0x21,0x18,0x0C,0x80,0xE1,0xFF,0x0F,0x80,0x20,0x18,0x0C,
0x80,0x20,0x18,0x0C,0xC0,0x20,0x18,0x0C,0x60,0x20,0x18,0x0C,0x78,0x20,0x18,0x0C,
0x60,0x20,0x18,0x0C,0x60,0x20,0x18,0x0C,0x60,0x20,0x18,0x0C,0x60,0xE0,0xFF,0x0F,
0x70,0x20,0x00,0x0C,0x70,0x20,0x00,0x0C,0x60,0x20,0x00,0x04,0x00,0x00,0x00,0x00,/*"油",4*/ 
};

static const u8 asc2_1608[1520] PROGMEM={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x18,0x18,0x00,0x00,
0x00,0x48,0x6C,0x24,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x24,0x24,0x24,0x7F,0x12,0x12,0x12,0x7F,0x12,0x12,0x12,0x00,0x00,
0x00,0x00,0x08,0x1C,0x2A,0x2A,0x0A,0x0C,0x18,0x28,0x28,0x2A,0x2A,0x1C,0x08,0x08,
0x00,0x00,0x00,0x22,0x25,0x15,0x15,0x15,0x2A,0x58,0x54,0x54,0x54,0x22,0x00,0x00,
0x00,0x00,0x00,0x0C,0x12,0x12,0x12,0x0A,0x76,0x25,0x29,0x11,0x91,0x6E,0x00,0x00,
0x00,0x06,0x06,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00,
0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00,
0x00,0x00,0x00,0x00,0x08,0x08,0x6B,0x1C,0x1C,0x6B,0x08,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x7F,0x08,0x08,0x08,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x04,0x03,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00,
0x00,0x00,0x80,0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,0x00,
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,
0x00,0x00,0x00,0x08,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x20,0x20,0x10,0x08,0x04,0x42,0x7E,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x20,0x18,0x20,0x40,0x40,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x20,0x30,0x28,0x24,0x24,0x22,0x22,0x7E,0x20,0x20,0x78,0x00,0x00,
0x00,0x00,0x00,0x7E,0x02,0x02,0x02,0x1A,0x26,0x40,0x40,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x38,0x24,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x24,0x18,0x00,0x00,
0x00,0x00,0x00,0x7E,0x22,0x22,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x64,0x58,0x40,0x40,0x24,0x1C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x04,
0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00,
0x00,0x00,0x00,0x3C,0x42,0x42,0x46,0x40,0x20,0x10,0x10,0x00,0x18,0x18,0x00,0x00,
0x00,0x00,0x00,0x1C,0x22,0x5A,0x55,0x55,0x55,0x55,0x2D,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x08,0x08,0x18,0x14,0x14,0x24,0x3C,0x22,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x1E,0x22,0x42,0x42,0x42,0x22,0x1F,0x00,0x00,
0x00,0x00,0x00,0x7C,0x42,0x42,0x01,0x01,0x01,0x01,0x01,0x42,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x1F,0x22,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1F,0x00,0x00,
0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x42,0x42,0x3F,0x00,0x00,
0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x02,0x02,0x07,0x00,0x00,
0x00,0x00,0x00,0x3C,0x22,0x22,0x01,0x01,0x01,0x71,0x21,0x22,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x11,0x0F,
0x00,0x00,0x00,0x77,0x22,0x12,0x0A,0x0E,0x0A,0x12,0x12,0x22,0x22,0x77,0x00,0x00,
0x00,0x00,0x00,0x07,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x42,0x7F,0x00,0x00,
0x00,0x00,0x00,0x77,0x36,0x36,0x36,0x36,0x2A,0x2A,0x2A,0x2A,0x2A,0x6B,0x00,0x00,
0x00,0x00,0x00,0xE3,0x46,0x46,0x4A,0x4A,0x52,0x52,0x52,0x62,0x62,0x47,0x00,0x00,
0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x22,0x1C,0x00,0x00,
0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x42,0x3E,0x02,0x02,0x02,0x02,0x07,0x00,0x00,
0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x4D,0x53,0x32,0x1C,0x60,0x00,
0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x3E,0x12,0x12,0x22,0x22,0x42,0xC7,0x00,0x00,
0x00,0x00,0x00,0x7C,0x42,0x42,0x02,0x04,0x18,0x20,0x40,0x42,0x42,0x3E,0x00,0x00,
0x00,0x00,0x00,0x7F,0x49,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x42,0x22,0x24,0x24,0x14,0x14,0x18,0x08,0x08,0x00,0x00,
0x00,0x00,0x00,0x6B,0x49,0x49,0x49,0x49,0x55,0x55,0x36,0x22,0x22,0x22,0x00,0x00,
0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x77,0x22,0x22,0x14,0x14,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00,
0x00,0x00,0x00,0x7E,0x21,0x20,0x10,0x10,0x08,0x04,0x04,0x42,0x42,0x3F,0x00,0x00,
0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00,
0x00,0x00,0x02,0x02,0x04,0x04,0x08,0x08,0x08,0x10,0x10,0x20,0x20,0x20,0x40,0x40,
0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00,
0x00,0x38,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
0x00,0x06,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x78,0x44,0x42,0x42,0xFC,0x00,0x00,
0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x26,0x1A,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x02,0x02,0x02,0x44,0x38,0x00,0x00,
0x00,0x00,0x00,0x60,0x40,0x40,0x40,0x78,0x44,0x42,0x42,0x42,0x64,0xD8,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x02,0x02,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0xF0,0x88,0x08,0x08,0x7E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x22,0x22,0x1C,0x02,0x3C,0x42,0x42,0x3C,
0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x3A,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x38,0x20,0x20,0x20,0x20,0x20,0x20,0x22,0x1E,
0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x72,0x12,0x0A,0x16,0x12,0x22,0x77,0x00,0x00,
0x00,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x92,0x92,0x92,0x92,0x92,0xB7,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3B,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x26,0x42,0x42,0x42,0x22,0x1E,0x02,0x07,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x44,0x42,0x42,0x42,0x44,0x78,0x40,0xE0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x4C,0x04,0x04,0x04,0x04,0x1F,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x42,0x02,0x3C,0x40,0x42,0x3E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x3E,0x08,0x08,0x08,0x08,0x08,0x30,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0x42,0x42,0x42,0x42,0x62,0xDC,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x08,0x08,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEB,0x49,0x49,0x55,0x55,0x22,0x22,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x76,0x24,0x18,0x18,0x18,0x24,0x6E,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x18,0x08,0x08,0x07,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x22,0x10,0x08,0x08,0x44,0x7E,0x00,0x00,
0x00,0xC0,0x20,0x20,0x20,0x20,0x20,0x10,0x20,0x20,0x20,0x20,0x20,0x20,0xC0,0x00,
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
0x00,0x06,0x08,0x08,0x08,0x08,0x08,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x06,0x00,
0x0C,0x32,0xC2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const u8 num_4821[] PROGMEM= {
// 0(0) 1(1) 2(2) 3(3) 4(4) 5(5) 6(6) 7(7)
// 8(8) 9(9) .(10) -(11)

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0xE0,0xFF,0x00,0xF0,0xFF,
0x01,0xF0,0xFF,0x01,0xF8,0xFF,0x03,0xFC,0xFF,0x07,0xFC,0xF1,0x07,0xFC,0xE0,0x07,
0xFC,0xE0,0x07,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,
0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,
0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0xFC,0xE0,0x07,0xFC,0xE0,0x07,0xFC,0xF1,0x07,
0xFC,0xFF,0x07,0xF8,0xFF,0x03,0xF8,0xFF,0x01,0xF0,0xFF,0x01,0xE0,0xFF,0x00,0x80,
0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"0",0*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7E,
0x00,0x00,0x7F,0x00,0x80,0x7F,0x00,0xE0,0x7F,0x00,0xF8,0x7F,0x00,0xFC,0x7F,0x00,
0xFC,0x7F,0x00,0xFC,0x7E,0x00,0x3C,0x7E,0x00,0x1C,0x7E,0x00,0x04,0x7E,0x00,0x00,
0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,
0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,
0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,
0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"1",1*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0xC0,0xFF,0x01,0xE0,0xFF,
0x03,0xF0,0xFF,0x07,0xF8,0xFF,0x07,0xF8,0xFF,0x0F,0xF8,0xE1,0x0F,0xFC,0xC1,0x0F,
0xFC,0xC0,0x0F,0xFC,0xC0,0x0F,0x00,0xC0,0x0F,0x00,0xC0,0x07,0x00,0xE0,0x07,0x00,
0xE0,0x07,0x00,0xF0,0x03,0x00,0xF8,0x01,0x00,0xFC,0x00,0x00,0xFE,0x00,0x00,0x3F,
0x00,0x80,0x1F,0x00,0xC0,0x0F,0x00,0xE0,0x07,0x00,0xF0,0x03,0x00,0xF8,0x03,0x00,
0xF8,0xFF,0x0F,0xFC,0xFF,0x0F,0xFC,0xFF,0x0F,0xFC,0xFF,0x0F,0xFE,0xFF,0x0F,0xFE,
0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"2",2*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0xC0,0xFF,0x00,0xE0,0xFF,
0x01,0xF0,0xFF,0x03,0xF8,0xFF,0x03,0xF8,0xFF,0x07,0xF8,0xF1,0x07,0xFC,0xE1,0x07,
0xFC,0xE0,0x07,0xE0,0xE0,0x07,0x00,0xE0,0x03,0x00,0xF0,0x03,0x00,0xFE,0x01,0x00,
0x7E,0x00,0x00,0xFE,0x00,0x00,0xFE,0x03,0x00,0xE0,0x07,0x00,0xE0,0x07,0x00,0xC0,
0x0F,0x00,0xC0,0x0F,0x7C,0xC0,0x0F,0x7E,0xC0,0x0F,0xFE,0xE0,0x0F,0xFC,0xF1,0x0F,
0xFC,0xFF,0x07,0xF8,0xFF,0x07,0xF8,0xFF,0x03,0xF0,0xFF,0x01,0xE0,0xFF,0x00,0x80,
0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"3",3*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x01,0x00,0xF8,0x01,0x00,0xFC,
0x01,0x00,0xFC,0x01,0x00,0xFE,0x01,0x00,0xFF,0x01,0x00,0xFF,0x01,0x80,0xFF,0x01,
0x80,0xFF,0x01,0xC0,0xFF,0x01,0xE0,0xFB,0x01,0xE0,0xF9,0x01,0xF0,0xF9,0x01,0xF8,
0xF8,0x01,0x78,0xF8,0x01,0x7C,0xF8,0x01,0x3C,0xF8,0x01,0x3E,0xF8,0x01,0x1F,0xF8,
0x01,0xFF,0xFF,0x1F,0xFF,0xFF,0x1F,0xFF,0xFF,0x1F,0xFF,0xFF,0x1F,0xFF,0xFF,0x1F,
0x00,0xF8,0x01,0x00,0xF8,0x01,0x00,0xF8,0x01,0x00,0xF8,0x01,0x00,0xF8,0x01,0x00,
0xF8,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"4",4*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0x07,0xF0,0xFF,0x07,0xF0,0xFF,
0x07,0xF8,0xFF,0x07,0xF8,0xFF,0x07,0xF8,0xFF,0x07,0xF8,0x01,0x00,0xF8,0x01,0x00,
0xF8,0x01,0x00,0xFC,0x00,0x00,0xFC,0x3E,0x00,0xFC,0xFF,0x00,0xFC,0xFF,0x01,0xFC,
0xFF,0x03,0xFE,0xFF,0x07,0xFE,0xFF,0x07,0xFE,0xF0,0x0F,0x7C,0xE0,0x0F,0x00,0xC0,
0x0F,0x00,0xC0,0x0F,0x3E,0xC0,0x0F,0x3F,0xC0,0x0F,0x7F,0xE0,0x0F,0xFE,0xF0,0x07,
0xFE,0xFF,0x07,0xFC,0xFF,0x03,0xFC,0xFF,0x03,0xF8,0xFF,0x01,0xF0,0x7F,0x00,0xC0,
0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"5",5*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0xC0,0xFF,0x00,0xE0,0xFF,
0x01,0xF0,0xFF,0x01,0xF8,0xFF,0x03,0xF8,0xFF,0x03,0xFC,0xF1,0x07,0xFC,0xE0,0x07,
0x7C,0xE0,0x03,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x7E,0x7E,0x00,0x7E,
0xFF,0x00,0xFE,0xFF,0x03,0xFE,0xFF,0x03,0xFE,0xFF,0x07,0xFE,0xFF,0x07,0xFE,0xE0,
0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7C,0xC0,0x0F,0x7C,0xC0,0x0F,0xFC,0xE1,0x0F,
0xF8,0xFF,0x07,0xF8,0xFF,0x07,0xF0,0xFF,0x03,0xE0,0xFF,0x01,0xC0,0xFF,0x00,0x00,
0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"6",6*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0x0F,0xFE,0xFF,0x0F,0xFE,0xFF,
0x0F,0xFE,0xFF,0x0F,0xFE,0xFF,0x0F,0xFE,0xFF,0x07,0x00,0xE0,0x03,0x00,0xF0,0x01,
0x00,0xF0,0x01,0x00,0xF8,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x3E,0x00,0x00,
0x3F,0x00,0x00,0x1F,0x00,0x00,0x1F,0x00,0x80,0x1F,0x00,0x80,0x0F,0x00,0xC0,0x0F,
0x00,0xC0,0x0F,0x00,0xC0,0x07,0x00,0xE0,0x07,0x00,0xE0,0x07,0x00,0xE0,0x07,0x00,
0xE0,0x03,0x00,0xF0,0x03,0x00,0xF0,0x03,0x00,0xF0,0x03,0x00,0xF0,0x03,0x00,0xF0,
0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"7",7*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0x00,0xE0,0xFF,0x00,0xF0,0xFF,
0x01,0xF8,0xFF,0x03,0xF8,0xF1,0x03,0xFC,0xE0,0x07,0xFC,0xE0,0x07,0xFC,0xE0,0x07,
0xFC,0xE0,0x07,0xFC,0xE0,0x07,0xF8,0xE0,0x03,0xF8,0xF1,0x03,0xF0,0xFF,0x01,0xC0,
0x7F,0x00,0xE0,0xFF,0x00,0xF8,0xFF,0x03,0xF8,0xF1,0x03,0xFC,0xE0,0x07,0x7E,0xC0,
0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,
0xFC,0xE0,0x07,0xFC,0xF1,0x07,0xF8,0xFF,0x03,0xF0,0xFF,0x01,0xE0,0xFF,0x00,0x80,
0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"8",8*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x1F,0x00,0xE0,0x7F,0x00,0xF0,0xFF,
0x00,0xF8,0xFF,0x01,0xFC,0xFF,0x03,0xFC,0xFF,0x03,0xFE,0xF0,0x07,0x7E,0xC0,0x07,
0x7E,0xC0,0x07,0x7E,0xC0,0x0F,0x7E,0xC0,0x0F,0xFE,0xE0,0x0F,0xFC,0xFF,0x0F,0xFC,
0xFF,0x0F,0xF8,0xFF,0x0F,0xF8,0xFF,0x0F,0xE0,0xFF,0x0F,0xC0,0xCF,0x0F,0x00,0xC0,
0x0F,0x00,0xC0,0x0F,0x00,0xC0,0x0F,0xF8,0xC0,0x07,0xFC,0xE0,0x07,0xFC,0xF1,0x07,
0xF8,0xFF,0x03,0xF8,0xFF,0x03,0xF0,0xFF,0x01,0xF0,0xFF,0x00,0xE0,0x7F,0x00,0x80,
0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"9",9*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xFC,0x00,0x00,0xFC,0x00,0x00,0xFC,0x00,0x00,0xFC,0x00,0x00,0xFC,0x00,0x00,0xFC,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*".",10*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,
0xFF,0x00,0xF0,0xFF,0x00,0xF0,0xFF,0x00,0xF0,0xFF,0x00,0xF0,0xFF,0x00,0xF0,0xFF,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"-",11*/
};

const u8 cfsmb_2424[] PROGMEM= {
// ℃(0) ℉(1)

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x12,0x7E,0x00,0x12,
0x83,0x05,0x92,0x01,0x06,0xCC,0x00,0x06,0x40,0x00,0x04,0x60,0x00,0x04,0x60,0x00,
0x00,0x60,0x00,0x00,0x60,0x00,0x00,0x60,0x00,0x00,0x60,0x00,0x00,0x40,0x00,0x00,
0xC0,0x00,0x00,0xC0,0x00,0x02,0x80,0x01,0x01,0x00,0xC7,0x00,0x00,0x3C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"℃",0*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0xFF,0x03,0x19,0x01,0x03,0x11,
0x01,0x02,0x09,0x01,0x00,0x06,0x01,0x00,0x00,0x41,0x00,0x00,0x41,0x00,0x00,0x7F,
0x00,0x00,0x61,0x00,0x00,0x41,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,
0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0xC0,0x07,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"℉",1*/
0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x7E,0x00,0x00,
0x7E,0x00,0x00,0xE7,0x00,0x00,0xC3,0x00,0x80,0x81,0x01,0x80,0x81,0x01,0xC0,0x81,
0x03,0xC0,0x81,0x03,0xE0,0x81,0x07,0xE0,0xC3,0x07,0xF0,0xC3,0x0F,0xF0,0xE7,0x0F,
0xF8,0xE7,0x1F,0xF8,0xFF,0x1F,0xFC,0xFF,0x3F,0xFC,0xE7,0x3F,0xFE,0xC3,0x7F,0xFE,
0xE7,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,/*"！",2*/

};
#endif