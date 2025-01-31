/******************** LQ_K60_函数库 v1.0 ********************
 * 文件名           ：PIT.H
 * 功能             ：设置PIT工作模式
 * 备注             ：官方例程上修改
 * 日期             ：2016-09-01
 * 实验平台         ：龙丘 K60VG核心板 
 * 作者             ：龙丘技术 006
 * 淘宝店           ：https://longqiu.taobao.com
 * 龙丘智能车讨论群 ：202949437
*************************************************************/

#ifndef _PIT_H_
#define _PIT_H_


#define PIT_Flag_Clear(PITn)   PIT_TFLG(PITn)|=PIT_TFLG_TIF_MASK      //清中断标志


//模块定义
typedef enum PITn
{
    PIT0,
    PIT1,
    PIT2,
    PIT3
} PITn;

/*********************** PIT功能函数 **************************/
void PIT_Init(PITn, u32 cnt);                                            //初始化PITn，并设置定时时间(单位为bus时钟周期)
void PIT0_Interrupt();
void PIT1_Interrupt();
void PIT2_Interrupt();
void PIT3_Interrupt();

void pit_delay(PITn pitn, uint32 cnt);
void pit_delay_ms(PITn pitn, uint32 cnt);
void pit_delay_us(PITn pitn, uint32 cnt);

void pit_time_start(PITn pitn);
uint32 pit_time_get(PITn pitn);
uint32 pit_time_get_us(PITn pitn);
uint32 pit_time_get_ms(PITn pitn);

void pit_close(PITn pitn);

#endif  