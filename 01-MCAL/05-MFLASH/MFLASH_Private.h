/*
 * MFLASH_Private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mazen Sh
 */

#ifndef MFLASH_PRIVATE_H_
#define MFLASH_PRIVATE_H_
////////////////////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////////
#define MFLASH_U32_KEY1									0x45670123
#define MFLASH_U32_KEY2									0xCDEF89AB
#define MFLASH_U32_PAGES_STARTING_ADDRESS				0x08000000

/////////////////////////////////////////////////////////////////////////////////////////////////
/*MFLASH_CR bits*/
#define MFLASH_U8_EOPIE                                 12
#define MFLASH_U8_ERRIE                                 10
#define MFLASH_U8_OPTWR_E                               9
#define MFLASH_U8_LOCK                                  7
#define MFLASH_U8_STRT                                  6
#define MFLASH_U8_OPTER                                 5
#define MFLASH_U8_OPT_PG                                4
#define MFLASH_U8_MER                                   2
#define MFLASH_U8_PER                                   1
#define MFLASH_U8_PG									0
/////////////////////////////////////////////////////////////////////////////////////////////////
/*MFLASH_SR bits*/
#define MFLASH_U8_EOP                                   5
#define MFLASH_U8_WRPRT_ERR                             4
#define MFLASH_U8_PG_ERR                                2
#define MFLASH_U8_BSY									0
/////////////////////////////////////////////////////////////////////////////////////////////////
/*REGISTERS*/
typedef struct{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;
	u32 Dummy;
	u32 OBR;
	u32 WRPR;
}MFLASH_REG;

////////////////////////////////////////////////////////////////////////////////////////////////////
#define MFLASH ((volatile MFLASH_REG*)(0x40022000))

/////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* MFLASH_PRIVATE_H_ */
