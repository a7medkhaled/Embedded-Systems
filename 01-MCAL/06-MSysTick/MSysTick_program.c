#include "LSTD_TYPES.h"
#include "LUTILS.h"

#include "MSysTick_private.h"
#include "MSysTick_interface.h"
#include "MSysTick_config.h"

void (*MSYSTICK_PTR) (void);

/*
 *
 * used to start the timer
 *
 */
//u8 CLK_After_Prescaling;

#if (EnableDisablePrescaler==1)


u8 CLK_After_Prescaling = CLK_MH / 8;

#else

u8 CLK_After_Prescaling = CLK_MH;


#endif

void MSysTick_void_StartTimer()
{
	LUTILS_SET_BIT(MSYSTiCK->STK_CTRL , ENABLE);
}

/*
 *
 * used to stop the timer
 *
 */
void MSysTick_void_StopTimer()
{
	LUTILS_CLR_BIT(MSYSTiCK->STK_CTRL , ENABLE);
}
/*
 * used to enable the peripheral interupt
 *
 */
void MSysTick_void_EnablePheripheralINt()
{
	LUTILS_SET_BIT(MSYSTiCK->STK_CTRL , TICKINT);
}
/*
 * used to disable the peripheral interupt
 *
 */
void MSysTick_void_DisablePheripheralINt()
{
	LUTILS_CLR_BIT(MSYSTiCK->STK_CTRL , TICKINT);
}

/*
 *
 * used to make prescaler or not
 *
 * options
 * 1)prescaler8 there for the clk will be ahb/8
 * 2)noprescaler the clk will be same with no prescaler AHB
 *
 */
void MSysTick_void_SetClkSource(u8 value)
{
	if(value == 0)
	{
	LUTILS_CLR_BIT(MSYSTiCK->STK_CTRL , CLKSOURCE);

	}
	else
	{
	LUTILS_SET_BIT(MSYSTiCK->STK_CTRL , CLKSOURCE);
	}
}

/*
 * used to read the counter flag which indicate whether
 * the timer reached zero or not
 *
 * return :
 * ------------
 * 0 notyet
 * 1 reached zero
 */
u8 MSysTick_u8_ReadTimerFlag()
{
	return LUTILS_GET_BIT(MSYSTiCK->STK_CTRL , COUNTFLAG);
}

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


void MSysTick_void_SetPreloadValue(u32 Preload_Cycles)
{
	MSYSTiCK->STK_LOAD&=0xff000000;
	MSYSTiCK->STK_LOAD|=(0x00ffffff&Preload_Cycles);

}

/*
 * used to read the value of the systick timer register counter
 */
u32 MSysTick_u32_ReadcurrentTimerValue()
{
	return MSYSTiCK->STK_VAL;
}


/*
 *
 * used to set the desired delay in microseconds
 */
void MSysTick_void_SetDesiredDelay_Micro(u32 time_micro)
{
	//CLK_After_Prescaling is in Mhz so if = 1 this means 1mhz
	u32 ticktime = 1000/CLK_After_Prescaling;  //in nanoseconds

	/*
	 * if ticktime =2000nano and desired delay = 1000micro
	 * then the preload value 500 which means 500 cycle and each cycle
	 * is 2 micro
	 *
	 */
	u32 PreloadValue = (time_micro*1000) / ticktime;

	MSysTick_void_SetPreloadValue(PreloadValue);



}
/*
 *
 * used to set the desired delay in meliroseconds
 */

void MSysTick_void_SetDesiredDelay_Meli(u32 time_meli)
{
	//CLK_After_Prescaling is in Mhz so if = 1 this means 1mhz
	u32 ticktime = 1000/CLK_After_Prescaling;  //in nanoseconds

	/*
	 * if ticktime =2000nano and desired delay = 1000meli
	 * then the preload value 500000 which means 500000 cycle and each cycle
	 * is 2 micro
	 *
	 */
	u32 PreloadValue = (time_meli*1000000) / ticktime;

	MSysTick_void_SetPreloadValue(PreloadValue);

}
/*
 * these func makes busy loop before using this function u must use
 * set desired time function
 */

void MSystick_void_MakeBusyLoopPolling()
{
	volatile u32 data = MSysTick_u32_ReadcurrentTimerValue();

	MSysTick_void_StartTimer();

	while(MSysTick_u8_ReadTimerFlag()==0)
	{
		data = MSysTick_u32_ReadcurrentTimerValue();
		asm("NOP");
	}


}
void MSYSTICK_voidSetCallBack(void(*CallBackPTR)(void)){

	MSYSTICK_PTR = CallBackPTR;

}

void SysTick_Handler(void){
	MSYSTICK_PTR();
}



