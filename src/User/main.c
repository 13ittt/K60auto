/****************************************************************************************************
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
#define HCSR_TRIG 22
#define HCSR_ECHO 23

void control(void);
void HCSR_pull_trig();
uint32 get_distance(uint32 cnt);



u8 PIT0_f=0;
uint32 distance=0;


void time_delay_ms(u32 ms)
{
  LPTMR_delay_ms(ms);
}

s16 a[8];

void drive_init(){
    PLL_Init(PLL200);         //��ʼ��PLLΪ200M������Ϊ100MHZ  
    LCD_Init();
    UART_Init(UART4,38400);     //����4��ʼ��
    GPIO_Init(PORTB, HCSR_TRIG, GPO, 0);          //������trig
    GPIO_Init(PORTB, HCSR_ECHO, GPI, 0);          //������echo
    EXTI_Init(PTB, HCSR_ECHO, either_down);   //��ʼ���ⲿ�ж�
    // gpio_init (PORTA, 17, 1,0);
}

//������
void main(void)
{
    DisableInterrupts;        //�ر����ж�
    drive_init();
    EnableInterrupts;            //�����ж�
    
    
    while(1){
      LCD_CLS();
      time_delay_ms(100);
      UART_Put_Str(UART4, "hello");
      LCD_PrintU16(2, 3,distance);
      HCSR_pull_trig();
      time_delay_ms(100);
    };
   
}



uint32 get_distance(uint32 cnt){
    return (uint32)cnt*(331.4+0.607*20)/2000;
}
void HCSR_pull_trig(void){
    GPIO_Ctrl(PORTB, HCSR_TRIG, 1);
    LPTMR_delay_us(20);
}


void PORTB_Interrupt()
{
  int n,cnt;
  n=HCSR_ECHO;
  if((PORTB_ISFR & (1<<n)))
  {
      PORTB_ISFR |= (1<<n); 
      /* �û���������ж��ڳ��� */
      if(GPIO_Get(PTB23)){           //�յ��ߵ�ƽ
        pit_time_get(PIT0);                     //��ն�ʱ��
        pit_time_start(PIT0);                        //�򿪶�ʱ��
      } else {                                  //������� 
        cnt = pit_time_get_us(PIT0);               //��ȡʱ������
        distance = get_distance(cnt);           //������Ϊ���׼���
      }

  }
  
}