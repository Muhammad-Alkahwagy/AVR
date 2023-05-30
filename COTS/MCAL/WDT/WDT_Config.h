/*File Gaurd*/
#ifndef WDT_CONFIG_H
#define WDT_CONFIG_H

/*Watchdog Timer Prescale Select

Options:            //Typical time-out at VCC = 5V
WDT_PRSC_16K        //16.3ms  
WDT_PRSC_32K        //32.5ms  
WDT_PRSC_64K        //65ms  
WDT_PRSC_128K       //0.13s  
WDT_PRSC_256K       //0.26s  
WDT_PRSC_512K       //0.52s  
WDT_PRSC_1024K      //1.0s  
WDT_PRSC_2048K      //2.1s
*/

#define WDT_CLK     WDT_PRSC_2048K


#endif
