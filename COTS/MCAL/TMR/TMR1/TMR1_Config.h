/*File Gaurd*/
#ifndef TMR1_CONFIG_H
#define TMR1_CONFIG_H

/*Mode of operation of timer1*/
/*Options:
T1_NORMAL_MODE                     
T1_PWM_PHASE_CORRECT_8_BIT         
T1_PWM_PHASE_CORRECT_9_BIT         
T1_PWM_PHASE_CORRECT_10_BIT        
T1_CTC_OCR1A                       
T1_FAST_PWM_8_BIT                  
T1_FAST_PWM_9_BIT                  
T1_FAST_PWM_10_BIT                 
T1_PWM_PHASE_AND_FREQ_CORRECT_ICR1 
T1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A
T1_PWM_PHASE_CORRECT_ICR1          
T1_PWM_PHASE_CORRECT_OCR1A         
T1_CTC_ICR1                        
T1_Reserved                        
T1_Fast_PWM_ICR1                   
T1_Fast_PWM_OCR1A                  
*/
#define T1_MODE    T1_Fast_PWM_ICR1


/*
Clock Options: 
NO_CLK           //no clock
PRSC_1           //no prescaler
PRSC_8           //prescaler =8
PRSC_64          //prescaler =64
PRSC_256         //prescaler =256
PRSC_1024        //prescaler =1024
EXT_CLK_F_E      //external clock(falling edge)
EXT_CLK_R_E      //external clock(rising edge)
*/

#define T1_CLK_SOURCE   PRSC_8


#endif
