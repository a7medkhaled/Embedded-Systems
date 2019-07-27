#include "LSTD_TYPES.h"
#include "LUTILS.h"

#include "MNVIC_private.h"
#include "MNVIC_interface.h"
#include "MNVIC_config.h"




void MNVIC_void_EnableExternalInterupt(u8 interupt_id)
{
	u8 reg_no = interupt_id / 32;
	u8 bit_no = interupt_id % 32;

 switch(reg_no)
 {
 case 0:
	 MNVIC_ISSER0 = 1<<bit_no;

	 break;
 case 1:
	 MNVIC_ISSER1 = 1<<bit_no;

	 break;
 case 2:
	 MNVIC_ISSER2 = 1<<bit_no;

	 break;
 }

}

void MNVIC_void_SetPendingFlagExternalInterupt(u8 interupt_id)
{
	u8 reg_no = interupt_id / 32;
	u8 bit_no = interupt_id % 32;

	 switch(reg_no)
	 {
	 case 0:
		 MNVIC_ISPR0 = 1<<bit_no;

		 break;
	 case 1:
		 MNVIC_ISPR1 = 1<<bit_no;

		 break;
	 case 2:
		 MNVIC_ISPR2 = 1<<bit_no;

		 break;
	 }

}

void MNVIC_void_ClearPendingFlagExternalInterupt(u8 interupt_id)
{
	u8 reg_no = interupt_id / 32;
	u8 bit_no = interupt_id % 32;

	 switch(reg_no)
	 {
	 case 0:
		 MNVIC_ICPR0 = 1<<bit_no;

		 break;
	 case 1:
		 MNVIC_ICPR1 = 1<<bit_no;

		 break;
	 case 2:
		 MNVIC_ICPR2 = 1<<bit_no;

		 break;
	 }

}

/*
 * this function makes the gp and suppriorty 2 bits for each
 * using the SCB System control block cor peripheral register
 *
 */

 void MNVIC_MSCB_intialize_priorities()
{
	MSCB_MNVIC_AIRCR =((MSCB_MNVIC_AIRCR & 0x0000FFFF) | 0x05FA0000);
	LUTILS_CLR_BIT(MSCB_MNVIC_AIRCR , 9);
	LUTILS_SET_BIT(MSCB_MNVIC_AIRCR , 10);
	LUTILS_SET_BIT(MSCB_MNVIC_AIRCR , 8);
}


void MNVIC_void_SetPriorty(u8 interupy_id , u8 gp_priority , u8 sub_priority )
{
	u8 reg_no = interupy_id / 4; //each reg handles 4 interupts
	u8 offset = interupy_id % 4; //offset inside these reg
	//MNVIC_IPR0  this reg is the 1st reg only
	u8 * ptr_priorityReg = &MNVIC_IPR0 + reg_no;
	ptr_priorityReg[offset] = ((((gp_priority&0b00000011)<<2) | (sub_priority &0b00000011))<<4);
}
