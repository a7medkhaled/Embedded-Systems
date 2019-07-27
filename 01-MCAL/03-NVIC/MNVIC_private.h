#ifndef _MNVIC_PRIVATE_H_
#define _MNVIC_PRIVATE_H_



//set enable registers

#define MNVIC_ISSER0	*((volatile u32 *) 0xE000E100)
#define MNVIC_ISSER1	*((volatile u32 *) 0xE000E104)
#define MNVIC_ISSER2	*((volatile u32 *) 0xE000E108)


//clear enable registers

#define MNVIC_ICER0	*((volatile u32 *) 0xE000E180)
#define MNVIC_ICER1	*((volatile u32 *) 0xE000E184)
#define MNVIC_ICER2	*((volatile u32 *) 0xE000E188)

//set pending registers

#define MNVIC_ISPR0	*((volatile u32 *) 0xE000E200)
#define MNVIC_ISPR1	*((volatile u32 *) 0xE000E204)
#define MNVIC_ISPR2	*((volatile u32 *) 0xE000E208)

//clear pending regisers

#define MNVIC_ICPR0	*((volatile u32 *) 0xE000E280)
#define MNVIC_ICPR1	*((volatile u32 *) 0xE000E284)
#define MNVIC_ICPR2	*((volatile u32 *) 0xE000E288)

//active bits registers
/*
 *
 * read only indicating whether the interupt is active or not
 */

#define MNVIC_IABR0	*((volatile u32 *) 0xE000E300)
#define MNVIC_IABR1	*((volatile u32 *) 0xE000E304)
#define MNVIC_IABR2	*((volatile u32 *) 0xE000E308)

/*
 * interupt priority registers note there are 20 registers
 * i don;t write them all
 */

#define MNVIC_IPR0	*((volatile u32 *) 0xE000E400)

//software trigger interupt register

#define MNVIC_STIR	*((volatile u32 *) 0xE000EF00)

//SCB register we used it here to define the priority gp and sub priority bits
#define MSCB_MNVIC_AIRCR	*((volatile u32 *) 0xE000ED0C)




#endif
