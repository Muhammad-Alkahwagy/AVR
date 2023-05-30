/*File Gaurd*/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*Private Macros*/

#define GICR_REG         *((volatile u8*)0x5B)      //General Interrupt Control Register
#define GIFR_REG         *((volatile u8*)0x5A)      //General Interrupt Flag Register
#define MCUCR_REG        *((volatile u8*)0x55)      //MCU Control Register
#define MCUCSR_REG       *((volatile u8*)0x54)      //MCU Control and Status Register

/*GICR INTx bits*/
#define GICR_INT0    6
#define GICR_INT1    7
#define GICR_INT2    5

/*GIFR INTFx bits       (Interrupt Flag)*/
#define INTF0    6
#define INTF1    7
#define INTF2    5

/*MCUCR ISCx bits       (Interrupt Sense Control)*/
//INT0 
#define ISC00    0
#define ISC01    1
//INT1
#define ISC10    2
#define ISC11    3

/*MCUCSR ISC bit(INT2)*/
#define ISC2     6


#endif