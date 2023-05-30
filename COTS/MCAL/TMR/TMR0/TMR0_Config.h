/*File Gaurd*/
#ifndef TMR0_CONFIG_H
#define TMR0_CONFIG_H

/*Mode of operation*/
/*Options: NORMAL_MODE , PWM_PHASE_CORRECT , CTC , FAST_PWM */
#define MODE    FAST_PWM

/*Fast PWM mode*/   /*options: NON_INVERTING , INVERTING */
#define FAST_PWM_MODE   NON_INVERTING

/*Phase-Correct PWM mode*/   /*options: NON_INVERTING , INVERTING */
#define PHASE_CORRECT_MODE   NON_INVERTING


/*
Clock Options: 
NO_CLK           // No clock source (Timer/Counter stopped).
PRSC_1           // CLK(I/O)/1 (No prescaling)
PRSC_8           // CLK(I/O)/8 (From prescaler)
PRSC_64          // CLK(I/O)/64 (From prescaler)   
PRSC_256         // CLK(I/O)/256 (From prescaler)
PRSC_1024        // CLK(I/O)/1024 (From prescaler)
EXT_CLK_F_E      // External clock source on T0 pin. Clock on falling edge.
EXT_CLK_R_E      // External clock source on T0 pin. Clock on rising edge.
*/

#define TMR0_CLK_SOURCE   PRSC_8


/* Overflow_Time = 256 * Prescaler/(8 MHz) */
#define OVERFLOW_TIME   256 //us

/*Desired_Time = 1 second = 1000000 us */

/* Overflow_Count = DESIRED_TIME / OVERFLOW_TIME */
#define OVERFLOW_COUNT  3907    //3906.25

/*Preload_Value = 256 * 0.75 = 192 */
#define PRELOAD_VALUE 192

/*Compare_Match_value = 200 */
#define COMP_MATCH_VAL 200

/*Compare_Match Count = 1000000/200 */
#define CTC_COUNT   5000


#endif