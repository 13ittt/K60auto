/****************************************************************************************************
��ƽ    ̨������K60VG���İ�
����    д��CHIUSIR
��E-mail  ��chiusir@163.com
������汾��V1.0
�������¡�2016��09��01��
�������Ϣ�ο����е�ַ��
����    վ��http://www.lqist.cn
���Ա����̡�http://shop36265907.taobao.com
------------------------------------------------
��dev.env.��IAR7.3
��busclock��100.000MHz
��pllclock��200.000MHz
=============================================================
�ӿڶ��壺
PWM�ڶ��壺
FTM2_CH0--PTB18
FTM2_CH1--PTB19

�������壺
KEY0--PTB20
KEY1--PTB21
KEY2--PTB22

OLED�ڶ��壺
LCD_DC --PTC19
LCD_RST--PTC18
LCD_SDA--PTC17
LCD_SCL--PTC16
=============================================================
ʵ������
����K0��ռ�ձȻָ���ֵ
����K1��ռ�ձ�����
����K2��ռ�ձȼ�С
����0.96��OLED������ʾ��ֵ
=============================================================
******************************************************************************************************/
#include "include.h"
#define 22 HCSR_TRIG;
#define 23 HCSR_ECHO;

u8 PIT0_f=0;

void control(void);
void time_delay_ms(u32 ms)
{
  LPTMR_delay_ms(ms);
}

s16 a[8];

void drive_init(){
    PLL_Init(PLL200);         //��ʼ��PLLΪ200M������Ϊ100MHZ  
    LCD_Init();
    UART_Init(UART4,38400);     //����4��ʼ��
    GPIO_Init(PORTB, HCSR_TRIG, 1, 0); //������trig
    GPIO_Init(PORTB, HCSR_ECHO, 0, 0); //������echo
    EXTI_Init(PORTB,23, either_down);//��ʼ���ⲿ�ж�
                                     //��ʼ��DMA��ʱ��
    
}

//������
void main(void)
{
    DisableInterrupts;        //�ر����ж�
    
    EnableInterrupts;            //�����ж�
    
    
    while(1){
    LCD_CLS();
      
      
      time_delay_ms(100);
      UART_Put_Str(UART4, "hello");
      LCD_P6x8Str(2, 3,"hello darling");
      time_delay_ms(100);
    };
   
}

void PORTB_Interrupt()
{
  int n;
  n=HCSR_ECHO;
  if((PORTB_ISFR & (1<<n)))
  {
      PORTB_ISFR |= (1<<n); 
      /* �û���������ж��ڳ��� */
      
      
      
  } 
  n=1;
  if((PORTB_ISFR & (1<<n)))
  {
      PORTB_ISFR |= (1<<n); 
      /* �û���������ж��ڳ��� */
  } 
}