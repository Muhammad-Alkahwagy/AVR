/*File Gaurd*/
#ifndef TMR0_PRIVATE_H
#define TMR0_PRIVATE_H

/*Private Macros*/

/*Timer/Counter0 registers*/
#define WDT_WDTCR_REG        *((volatile u8*)0x41)      //Watchdog Timer Control Register

#define MCUSR_REG        *((volatile u8*)0x54)          //MCU Control and Status Register

// MCUSR_REG WDT bit
#define WDT_WDRF    3       //Watchdog Reset Flag

/*WDT_WDTCR_REG bits*/
#define WDT_WDTCR_WDP0      0      //Watchdog Timer Prescaler 0
#define WDT_WDTCR_WDP1      1      //Watchdog Timer Prescaler 1
#define WDT_WDTCR_WDP2      2      //Watchdog Timer Prescaler 2
#define WDT_WDTCR_WDE       3      //Watchdog Enable
#define WDT_WDTCR_WDTOE     4      //Watchdog Turn-off Enable



/*Watchdog Timer Prescale Select*/

//Number of WDT Oscillator Cycles       //Typical time-out at VCC = 5V
#define WDT_PRSC_16K          0         //time-out = 16.3ms  
#define WDT_PRSC_32K          1         //time-out = 32.5ms  
#define WDT_PRSC_64K          2         //time-out = 65ms  
#define WDT_PRSC_128K         3         //time-out = 0.13s  
#define WDT_PRSC_256K         4         //time-out = 0.26s  
#define WDT_PRSC_512K         5         //time-out = 0.52s  
#define WDT_PRSC_1024K        6         //time-out = 1.0s  
#define WDT_PRSC_2048K        7         //time-out = 2.1s

#define CLK_MASK     0b11111000


#endif