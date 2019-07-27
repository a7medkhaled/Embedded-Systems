/*
 * MFLASH_Program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mazen Sh
 */
#ifndef LUTILS_H_
#define LUTILS_H_

#define LUTILS_U8_NO_OF_SHIFTS_FOR_HALF_REGISTER_32_BIT		16


#define SET_BIT(REG , BIT)	REG |= (1<<BIT)
#define CLEAR_BIT(REG , BIT) REG &= ~(1<<BIT)
#define GET_BIT(REG  , BIT) ((REG >> BIT)&1)
#define TOGGLE_BIT (REG , BIT) REG ^=(1<<BIT)
#define SET_REG(REG) (REG |= 0xFF)
#define CLEAR_REG(REG) (REG &= 0x00)
#define SET_VALUE_REG(REG , value) (REG = value)
#define SET_VALUE_REG_HIGH_4bit(REG , value) (REG = (value & (0b11110000))|(REG & 0b00001111))
#define SET_4_LOW_NIPPLE(REG) (REG|=0x0F)
#define SET_4_HIGH_NIPPLE(REG) (REG|=0xF0)
#define CLEAR_4_LOW_NIPPLE(REG) (REG&=0xF0)
#define CLEAR_4_HIGH_NIPPLE(REG) (REG&=0x0F)
#define Get_4_LOW_NIBBLE(REG) (REG & 0x0F)
#define Get_4_HIGH_NIBBLE(REG) (REG & 0xF0)
#define LUTILS_U32_MASK_HALF_REG(REG , PART) (REG & (~((0x0000FFFF)<<(PART*LUTILS_U8_NO_OF_SHIFTS_FOR_HALF_REGISTER_32_BIT))))
#define LUTILS_U32_MASK_NIBBLE_IN_REG(REG , STARTING_BIT) (REG & (~((0xF)<<STARTING_BIT)))
#define LUTILS_U32_MASK_8BIT_IN_REG(REG , STARTING_BIT) (REG & (~((0xFF)<<STARTING_BIT)))
#define LUTILS_U32_EXPAND_4BIT_VALUE_REPEATDLY_INTO_32BIT_VALUE(VALUE) (VALUE *(0x11111111)) 	/* (0X2) ----> (0X22222222)*/
#define LUTILS_U32_EXPAND_4BIT_VALUE_REPEATDLY_INTO_16BIT_VALUE_IN_HIGH_OR_LOW_PART(VALUE , PART) (VALUE *((0x00001111)<<(PART*LUTILS_U8_NO_OF_SHIFTS_FOR_HALF_REGISTER_32_BIT)))	/* (0X2) ----> (0X00002222) IF PART ==0 , (0X2) ----> (0X22220000) IF PART ==1*/

#endif

#include "LSTD_TYPES.h"
#include "LUTILS.h"

#include "MFLASH_Interface.h"
#include "MFLASH_Private.h"



/*
 * func desc
 *
 * used to unlock the flash or in other words
 *  unlocking the flash registers
 *
 * done by wriiting values "keys" in a reg called keyr
 *
 */
static void MFLASH_voidUnlock(void){
	MFLASH -> KEYR = MFLASH_U32_KEY1;
	MFLASH -> KEYR = MFLASH_U32_KEY2;
}

/*
 *
 * func desc
 *
 * used to lock the the flash again
 *
 * by setting the bit lock in the reg CR
 *
 */
static void MFLASH_voidLock(void){
	SET_BIT(MFLASH -> CR, MFLASH_U8_LOCK);
}


/*
 *
 * func param
 *
 * 1)Copy_u32StartAddress  : the address at where u want to write the data
 * 2)Copy_u16Data          : the data u wish to write in the flash
 *
 * desc
 * 1)unlock the flash
 * 2)set programming mode
 * 3)write the data
 * 4)wait till finissh
 * 5)lock the flash again
 *
 */
void MFLASH_voidWriteHalfWord(u32 Copy_u32StartAddress , u16 Copy_u16Data){
	MFLASH_voidUnlock();
	SET_BIT(MFLASH -> CR , MFLASH_U8_PG);
	if(!GET_BIT(MFLASH -> SR , MFLASH_U8_LOCK)){
		*((u16*)(Copy_u32StartAddress))=Copy_u16Data;
		while(GET_BIT(MFLASH -> SR , MFLASH_U8_BSY));
		CLEAR_BIT(MFLASH -> CR , MFLASH_U8_PG);
		MFLASH_voidLock();
	}
}

void MFLASH_voidWriteWord(u32 Copy_u32StartAddress , u32 Copy_u32Data){
	MFLASH_voidUnlock();
	SET_BIT(MFLASH -> CR , MFLASH_U8_PG);
	if(!GET_BIT(MFLASH -> SR , MFLASH_U8_LOCK)){
		*((u16*)(Copy_u32StartAddress))=Copy_u32Data;
		while(GET_BIT(MFLASH -> SR , MFLASH_U8_BSY));
		*((u16*)(Copy_u32StartAddress+2))=Copy_u32Data>>16;
		while(GET_BIT(MFLASH -> SR , MFLASH_U8_BSY));
		CLEAR_BIT(MFLASH -> CR , MFLASH_U8_PG);
		MFLASH_voidLock();
	}
}

/*
 *
 * param
 * 1)Copy_u8PageNumber : the index or in other words the no of the  page
 * u wish to erase ex 1,2,3,.....31
 *
 *
 * desc
 * 1)unlock the flash
 * 2)write the addres of the page in a reg
 * 3)set bit which make one page erase mode
 * 4)set start bit to begin erase
 * 5)wait
 * 6)lock the flash again
 *
 */
void MFLASH_voidEreasePage(u8 Copy_u8PageNumber){
	MFLASH_voidUnlock();
	while(GET_BIT(MFLASH -> SR , MFLASH_U8_BSY));
	SET_BIT(MFLASH -> CR  , MFLASH_U8_PER);
	MFLASH -> AR = ((u32)(Copy_u8PageNumber*MFLASH_U16_PAGE_SIZE_IN_BYTES))+MFLASH_U32_PAGE0;
	SET_BIT(MFLASH -> CR  , MFLASH_U8_STRT);
	while(GET_BIT(MFLASH -> SR , MFLASH_U8_BSY));
	CLEAR_BIT(MFLASH -> CR  , MFLASH_U8_PER);
	MFLASH_voidLock();
}
