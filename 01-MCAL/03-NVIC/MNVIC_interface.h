#ifndef _MNVIC_INTERFACE_H_
#define _MNVIC_INTERFACE_H_


/*
 * the external interupts ids
 */
#define EXTI0_ID  6
#define EXTI1_ID  7





/*
 *
 * this function is used to enable an exernal peripheral interpt
 *
 * paraam
 * 1)interupt_id  the id of the desired interupt from the data sheet
 * example the watch dog is 0
 */

void MNVIC_void_EnableExternalInterupt(u8 interupt_id);

/*
 *
 * these function used to set pending flag
 * which is used to fire an interupt by forcing
 *
 * params
 * same as the previous func
 *
 */
void MNVIC_void_SetPendingFlagExternalInterupt(u8 interupt_id);

/*
 *
 * these function used to clear pending flag
 * which is used to disable an interupt by forcing
 *
 * params
 * same as the previous func
 *
 */
void MNVIC_void_ClearPendingFlagExternalInterupt(u8 interupt_id);
/*
 *
 * these function is used to set the gp priority and the sub priority
 * of an external interupt
 *
 * params
 * 1)id the interupt id
 * 2)gp priority
 * 3)sub priority
 *
 */

void MNVIC_void_SetPriorty(u8 interupy_id , u8 gp_priority , u8 sub_priority );

/*
 * this function makes the gp and suppriorty 2 bits for each
 * using the SCB System control block cor peripheral register
 *
 */

 void MNVIC_MSCB_intialize_priorities();


#endif
