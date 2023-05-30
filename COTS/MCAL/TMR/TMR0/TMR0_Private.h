/*File Gaurd*/
#ifndef TMR0_PRIVATE_H
#define TMR0_PRIVATE_H

/*Private Macros*/

/*Timer/Counter0 registers*/
#define TMR0_OCR0_REG        *((volatile u8*)0x5C)      //Output Compare Register
#define TMR0_TCCR0_REG       *((volatile u8*)0x53)      //Timer/Counter Control Register
#define TMR0_TCNT0_REG       *((volatile u8*)0x52)      //Timer/Counter Register

#define TMR_TIMSK_REG       *((volatile u8*)0x59)      //Timer/Counter Interrupt Mask Register
#define TMR_TIFR_REG        *((volatile u8*)0x58)      //Timer/Counter Interrupt Flag Register

#define SFIOR_REG           *((volatile u8*)0x50)      //Special Function IO Register

/*TMR0_TCCR0_REG bits*/
#define TMR0_TCCR0_CS00      0      //Clock Select bit0 
#define TMR0_TCCR0_CS01      1      //Clock Select bit1
#define TMR0_TCCR0_CS02      2      //Clock Select bit2
#define TMR0_TCCR0_WGM01     3      //Waveform Generation Mode bit1
#define TMR0_TCCR0_COM00     4      //Compare Match Output Mode bit0
#define TMR0_TCCR0_COM01     5      //Compare Match Output Mode bit1
#define TMR0_TCCR0_WGM00     6      //Waveform Generation Mode bit0
#define TMR0_TCCR0_FOC0      7      //Force Output Compare

/*TMR0_TIMSK_REG bits*/
#define TMR0_TIMSK_TOIE0     0      //Timer/Counter0 Overflow Interrupt Enable bit
#define TMR0_TIMSK_OCIE0     1      //Timer/Counter0 Output Compare Match Interrupt Enable bit

/*TMR0_TIFR_REG bits*/
#define TMR0_TIFR_TOV0       0      //Timer/Counter0 Overflow Flag
#define TMR0_TIFR_OCF0       1      //Output Compare Flag 0

/*SFIOR_REG bits*/
#define TMR0_SFIOR_PSR10     0      //Prescaler Reset Timer/Counter1 and Timer/Counter0


/*Clock Select*/
#define NO_CLK            0          // No clock source (Timer/Counter stopped).
#define PRSC_1            1          // CLK(I/O)/1 (No prescaling)
#define PRSC_8            2          // CLK(I/O)/8 (From prescaler)
#define PRSC_64           3          // CLK(I/O)/64 (From prescaler)   
#define PRSC_256          4          // CLK(I/O)/256 (From prescaler)
#define PRSC_1024         5          // CLK(I/O)/1024 (From prescaler)
#define EXT_CLK_F_E       6          // External clock source on T0 pin. Clock on falling edge.
#define EXT_CLK_R_E       7          // External clock source on T0 pin. Clock on rising edge.

#define CLK_MASK     0b11111000

/*Mode of operation*/
#define NORMAL_MODE          0
#define PWM_PHASE_CORRECT    1
#define CTC                  2
#define FAST_PWM             3

/*PWM Modes*/
#define NON_INVERTING   0
#define INVERTING       1



#endif