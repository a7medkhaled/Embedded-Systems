/*
 * MFLASH_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mazen Sh
 */

#ifndef MFLASH_INTERFACE_H_
#define MFLASH_INTERFACE_H_
////////////////////////////////////////////////////////////////////////////////
#define MFLASH_U32_PAGE0										0x08000000
#define MFLASH_U16_PAGE_SIZE_IN_BYTES							1024
#define MFLASH_U8_NO_OF_PAGES									128
////////////////////////////////////////////////////////////////////////////////
void MFLASH_voidWriteHalfWord(u32 Copy_u32StartAddress , u16 Copy_u16Data);

void MFLASH_voidEreasePage(u8 Copy_u8PageNumber);

void MFLASH_voidWriteWord(u32 Copy_u32StartAddress , u32 Copy_u32Data);

#endif /* MFLASH_INTERFACE_H_ */
