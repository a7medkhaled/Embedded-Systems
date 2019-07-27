#ifndef _MSysTick_PRIVATE_H_
#define _MSysTick_PRIVATE_H_


/*
 *
 * reg description
 *
 *
 * A)STK_CTRL  :
 * ----------------------------------
 * 1)enable the peripheral
 * 2)enable interupt
 * 3)select the clk source
 * 4)flag indicating if the counter reaches 0
 *
 *
 * B)STK_LOAD
 * -----------------------------------
 * laoad the value u wish to start with it
 *
 *
 * C)STK_VAL
 * -----------------------------------
 * u can read it it contains the current value of the counter
 * if u write on it the counter value will be zero
 *
 *
 *
 *
 *
 */


typedef struct{
	u32 STK_CTRL;       //system ctrl and status reg
	u32 STK_LOAD;       //reload value reg
	u32 STK_VAL;        //current value reg
	u32 STK_CALIB;      //calibration value reg

}SysTick;

#define MSYSTiCK	((volatile SysTick *) 0xE000E010)

/*
 *
 * bits names
 */

//bits of STK_CTRL
#define COUNTFLAG  16
#define CLKSOURCE  2
#define TICKINT    1
#define ENABLE     0






#endif
