/*File Gaurd*/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

//External Interrupt options
#define INT0    0
#define INT1    1
#define INT2    2

//Prebuild Enabled Interrupt
#define INT_EN      INT0

//Sense Control modes
#define LOW_LEVEL       0
#define ON_CHANGE       1
#define FALLING_EDGE    2
#define RISING_EDGE     3

#define SENSE_CONTROL   RISING_EDGE


#endif