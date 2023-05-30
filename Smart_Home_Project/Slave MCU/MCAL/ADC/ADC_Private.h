/*File Gaurd*/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/*Private Macros*/

#define ADC_U8ADMUX_REG           *((volatile u8*)0x27)      //ADC Multiplexer Selection Register
#define ADC_U8ADCSRA_REG          *((volatile u8*)0x26)      //ADC Control and Status Register A
#define ADC_U8ADCH_REG            *((volatile u8*)0x25)      //ADC Data Register High Byte
#define ADC_U8ADCL_REG            *((volatile u8*)0x24)      //ADC Data Register Low Byte
#define ADC_U16ADCD_REG           *((volatile u16*)0x24)     //ADC Data Register

#define SFIOR_REG                 *((volatile u8*)0x50)      //Special Function IO Register

/*ADMUX_REG bits*/
//Analog Channel and Gain Selection Bits
#define ADMUX_MUX0       0      
#define ADMUX_MUX1       1
#define ADMUX_MUX2       2
#define ADMUX_MUX3       3
#define ADMUX_MUX4       4

//ADC Left Adjust Result bit
#define ADMUX_ADLAR      5  

//Refernce voltage Selection bits
#define ADMUX_REFS0      6      
#define ADMUX_REFS1      7


/*ADCSRA_REG bits*/    
#define ADCSRA_ADPS0     0      //ADC Prescaler Select Bit0    
#define ADCSRA_ADPS1     1      //ADC Prescaler Select Bit1
#define ADCSRA_ADPS2     2      //ADC Prescaler Select Bit2

#define ADCSRA_ADIE      3      //ADC Interrupt Enable
#define ADCSRA_ADIF      4      //ADC Interrupt Flag
#define ADCSRA_ADATE     5      //ADC Auto Trigger Enable
#define ADCSRA_ADSC      6      //ADC Start Conversion
#define ADCSRA_ADEN      7      //ADC Enable

/*SFIOR_REG bits*/
#define SFIOR_ADTS0      5
#define SFIOR_ADTS1      6   
#define SFIOR_ADTS2      7


/*Prescaler factors*/
#define PRSC2    1
#define PRSC4    2
#define PRSC8    3
#define PRSC16   4
#define PRSC32   5
#define PRSC64   6
#define PRSC128  7

#define PRESCALER_MASK  0b11111000

#define ADMUX_MASK      0b11100000


/*Reference Voltage options*/
#define AREF        0
#define AVCC        1
#define RESERVED    2
#define INTERNAL    3

/*Result Adjust*/
#define RIGHT   0
#define LEFT    1

/*ADC status*/
#define		NOTBUSY			0
#define		BUSY			1

#endif