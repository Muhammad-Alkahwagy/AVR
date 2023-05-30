#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define KPD_PORT    PORTB

#define KPD_C3_pin    PIN0
#define KPD_C2_pin    PIN1
#define KPD_C1_pin    PIN2
#define KPD_C0_pin    PIN3

#define KPD_R0_pin    PIN4
#define KPD_R1_pin    PIN5
#define KPD_R2_pin    PIN6
#define KPD_R3_pin    PIN7

#define NO_OF_ROWS    4
#define NO_OF_COLS    4

#define COLUMNS      {KPD_C0_pin, KPD_C1_pin, KPD_C2_pin, KPD_C3_pin}
#define ROWS         {KPD_R0_pin, KPD_R1_pin, KPD_R2_pin, KPD_R3_pin}

#define KPD_KEYSET   { {'7','8','9','/'}, \
                       {'4','5','6','*'}, \
                       {'1','2','3','-'}, \
                       {'C','0','=','+'} }

#endif
