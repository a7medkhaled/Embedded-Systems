#ifndef _MSysTick_INTERFACE_H_
#define _MSysTick_INTERFACE_H_


/*
 * used by function SetClk to select which prescaller desired
 */
#define Prescaler8   0
#define NoPrescaler  1

/*
 * driver usage mannual
 *
 *
 * A)using polling delay
 * 1)set_desired_time
 * 2)Function polling
 *
 *
 * B)using delays with interupts
 *
 *
 *
 */

/*
 * set call back function used by interupts
 */
void MSYSTICK_voidSetCallBack(void(*CallBackPTR)(void));



/*
 *
 * used to start the timer
 *
 */

void MSysTick_void_StartTimer();
/*
 *
 * used to stop the timer
 *
 */
void MSysTick_void_StopTimer();
/*
 * used to enable the peripheral interupt
 *
 */
void MSysTick_void_EnablePheripheralINt();
/*
 * used to disable the peripheral interupt
 *
 */
void MSysTick_void_DisablePheripheralINt();
/*
 *
 * used to make prescaler or not
 *
 * options
 * 1)prescaler8 there for the clk will be ahb/8
 * 2)noprescaler the clk will be same with no prescaler AHB
 *
 */
void MSysTick_void_SetClkSource(u8 value);
/*
 * used to read the counter flag which indicate whether
 * the timer reached zero or not
 *
 * return :
 * ------------
 * 0 notyet
 * 1 reached zero
 */
u8 MSysTick_u8_ReadTimerFlag();
/*
 *
 * this fn used to set the intial value which the
 * counter will start count down from it
 *
 * only 24 bits allowed
 *
 * example
 * if value is 1 then the counter will only count one cycle
 *
 */


void MSysTick_void_SetPreloadValue(u32 Preload_Cycles);
/*
 * used to read the value of the systick timer register counter
 */
u32 MSysTick_u32_ReadcurrentTimerValue();

/*
 *
 * used to set the desired delay in microseconds
 */
void MSysTick_void_SetDesiredDelay_Micro(u32 time_micro);
/*
 *
 * used to set the desired delay in meliroseconds
 */

void MSysTick_void_SetDesiredDelay_Meli(u32 time_meli);

/*
 * these func makes busy loop before using this function u must use
 * set desired time function
 */

void MSystick_void_MakeBusyLoopPolling();



#endif
