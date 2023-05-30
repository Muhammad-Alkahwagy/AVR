/*File Gaurd*/
#ifndef TMR1_PRIVATE_H
#define TMR1_PRIVATE_H

/*Private Macros*/

/*Timer/Counter1 registers*/
#define TMR1_U8_TCCR1A_REG      *((volatile u8*)0x4F)      //Timer/Counter1 Control Register A
#define TMR1_U8_TCCR1B_REG      *((volatile u8*)0x4E)      //Timer/Counter1 Control Register B

#define TMR1_U8_TCNT1H_REG      *((volatile u8*)0x4D)      //Timer/Counter1 Register High Byte
#define TMR1_U8_TCNT1L_REG      *((volatile u8*)0x4C)      //Timer/Counter1 Register Low Byte
#define TMR1_U16_TCNT1_REG      *((volatile u16*)0x4C)     //Timer/Counter1 Register

#define TMR1_U8_OCR1AH_REG      *((volatile u8*)0x4B)      //Output Compare Register A High Byte
#define TMR1_U8_OCR1AL_REG      *((volatile u8*)0x4A)      //Output Compare Register A Low Byte
#define TMR1_U16_OCR1A_REG      *((volatile u16*)0x4A)     //Output Compare Register A


#define TMR1_U8_OCR1BH_REG      *((volatile u8*)0x49)      //Output Compare Register B High Byte
#define TMR1_U8_OCR1BL_REG      *((volatile u8*)0x48)      //Output Compare Register B Low Byte
#define TMR1_U16_OCR1B_REG      *((volatile u16*)0x48)     //Output Compare Register B


#define TMR1_U8_ICR1H_REG       *((volatile u8*)0x47)      //Input Capture Register High Byte
#define TMR1_U8_ICR1L_REG       *((volatile u8*)0x46)      //Input Capture Register Low Byte
#define TMR1_U16_ICR1_REG       *((volatile u16*)0x46)     //Input Capture Register


#define TMR_U8_TIMSK_REG       *((volatile u8*)0x59)      //Timer/Counter Interrupt Mask Register
#define TMR_U8_TIFR_REG        *((volatile u8*)0x58)      //Timer/Counter Interrupt Flag Register

#define SFIOR_REG              *((volatile u8*)0x50)      //Special Function IO Register


/*TMR1_TCCR1A_REG bits*/
#define TMR1_TCCR1A_WGM10      0      //Waveform Generation Mode 
#define TMR1_TCCR1A_WGM11      1      //Waveform Generation Mode
#define TMR1_TCCR1A_FOC1B      2      //Force Output Compare for Compare unit B
#define TMR1_TCCR1A_FOC1A      3      //Force Output Compare for Compare unit A
#define TMR1_TCCR1A_COM1B0     4      //Compare Output Mode for Compare unit B
#define TMR1_TCCR1A_COM1B1     5      //Compare Output Mode for Compare unit B
#define TMR1_TCCR1A_COM1A0     6      //Compare Output Mode for Compare unit A
#define TMR1_TCCR1A_COM1A1     7      //Compare Output Mode for Compare unit A


/*TMR1_TCCR1B_REG bits*/
#define TMR1_TCCR1B_CS10      0      //Clock Select bit0 
#define TMR1_TCCR1B_CS11      1      //Clock Select bit1
#define TMR1_TCCR1B_CS12      2      //Clock Select bit2
#define TMR1_TCCR1B_WGM12     3      //Waveform Generation Mode
#define TMR1_TCCR1B_WGM13     4      //Waveform Generation Mode
#define TMR1_TCCR1B_ICES1     6      //Input Capture Edge Select
#define TMR1_TCCR1B_ICNC1     7      //Input Capture Noise Canceler


/*TMR1_TIMSK_REG bits*/
#define TMR1_TIMSK_TOIE1     2      //Timer/Counter1 Overflow Interrupt Enable bit
#define TMR1_TIMSK_OCIE1B    3      //Timer/Counter1 Output Compare Match Interrupt Enable bit
#define TMR1_TIMSK_OCIE1A    4      //Timer/Counter1 Output Compare Match Interrupt Enable bit
#define TMR1_TIMSK_TICIE1    5      //Timer/Counter1 Overflow Interrupt Enable bit


/*TMR1_TIFR_REG bits*/
#define TMR1_TIFR_TOV1       2      //Timer/Counter1 Overflow Flag
#define TMR1_TIFR_OCF1B      3      //Timer/Counter1, Output Compare B Match Flag
#define TMR1_TIFR_OCF1A      4      //Timer/Counter1, Output Compare A Match Flag
#define TMR1_TIFR_ICF1       5      //Timer/Counter1, Input Capture Flag


/*SFIOR_REG bits*/
#define TMR1_SFIOR_PSR10     0      //Prescaler Reset Timer/Counter1 and Timer/Counter0


/*Clock Select*/
#define NO_CLK            0         // No clock source (Timer/Counter stopped).
#define PRSC_1            1         // CLK(I/O)/1 (No prescaling)
#define PRSC_8            2         // CLK(I/O)/8 (From prescaler)
#define PRSC_64           3         // CLK(I/O)/64 (From prescaler)   
#define PRSC_256          4         // CLK(I/O)/256 (From prescaler)
#define PRSC_1024         5         // CLK(I/O)/1024 (From prescaler)
#define EXT_CLK_F_E       6         // External clock source on T1 pin. Clock on falling edge.
#define EXT_CLK_R_E       7         // External clock source on T1 pin. Clock on rising edge.

#define CLK_MASK     0b11111000


/*Mode of operation*/
#define  T1_NORMAL_MODE                         0 
#define  T1_PWM_PHASE_CORRECT_8_BIT             1 
#define  T1_PWM_PHASE_CORRECT_9_BIT             2 
#define  T1_PWM_PHASE_CORRECT_10_BIT            3 
#define  T1_CTC_OCR1A                           4 
#define  T1_FAST_PWM_8_BIT                      5 
#define  T1_FAST_PWM_9_BIT                      6 
#define  T1_FAST_PWM_10_BIT                     7 
#define  T1_PWM_PHASE_AND_FREQ_CORRECT_ICR1     8 
#define  T1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A    9 
#define  T1_PWM_PHASE_CORRECT_ICR1              10
#define  T1_PWM_PHASE_CORRECT_OCR1A             11
#define  T1_CTC_ICR1                            12
#define  RESERVED                               13
#define  T1_Fast_PWM_ICR1                       14
#define  T1_Fast_PWM_OCR1A                      15

#endif