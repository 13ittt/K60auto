/****************************************************************************************************
【平    台】龙邱K60VG核心板
【编    写】CHIUSIR
【E-mail  】chiusir@163.com
【软件版本】V1.0
【最后更新】2016年09月01日
【相关信息参考下列地址】
【网    站】http://www.lqist.cn
【淘宝店铺】http://shop36265907.taobao.com
---------------------------------------------------*/
#ifndef __LQ12864_H__
#define __LQ12864_H__

extern void LCD_Init(void);
extern void LCD_CLS(void);
extern void LCD_P6x8Str(unsigned char x,unsigned char y,unsigned char ch[]);
extern void LCD_P8x16Str(unsigned char x,unsigned char y,unsigned char ch[]);
extern void LCD_P14x16Str(unsigned char x,unsigned char y,unsigned char ch[]);
extern void LCD_Print(unsigned char x, unsigned char y, unsigned char ch[]);
extern void LCD_PutPixel(unsigned char x,unsigned char y);
extern void LCD_Rectangle(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char gif);
extern void Draw_LQLogo(void);
extern void Draw_LibLogo(void);
extern void Draw_BMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char * bmp); 
extern void Draw_Road(void);
extern void LCD_PrintU16(unsigned char x,unsigned char y,unsigned int num);



#endif

