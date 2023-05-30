#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define DATA_REG   PORTC  //data register is connected to port C on the MCU (pins C0-C7)
#define CTRL_REG   PORTD  //Control register is connected to port A on the MCU (pins A0-A2)

#define RS_PIN     PIN2   //register select pin
#define RW_PIN     PIN3   //read/write pin
#define EN_PIN     PIN4   //enable pin

#define FUNC_SET         0b00111000  //desired configuration for Function set (8-bit mode, 2-lines, 5*7 resoulution)
#define DISPLAY_ON       0b00001100  //desired configuration for display(ON, cursor off, blink off)
#define CLEAR_DISPLAY    0b00000001  //clear LCD display
#define ENTRY_MODE       0b00000110  //desired configuration for entry mode (increment, no shifting)

#endif
