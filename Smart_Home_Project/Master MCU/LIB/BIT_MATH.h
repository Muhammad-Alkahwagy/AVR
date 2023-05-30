#ifndef BIT_MATH_H
#define BTT_MATH_H

#define SET_BIT(REG,BIT_NO)         REG |=  (1<<BIT_NO)     //set the bit number BIT_NO in variable REG to 1
#define CLR_BIT(REG,BIT_NO)         REG &= ~(1<<BIT_NO)     //set the bit number BIT_NO in variable REG to 0
#define TOG_BIT(REG,BIT_NO)         REG ^=  (1<<BIT_NO)     //invert bit's state (1 to 0) or (0 to 1)
#define GET_BIT(REG,BIT_NO)         ((REG>>BIT_NO) & 1)     //get the value of bit number BIT_NO in variable REG

#define SET_REG(REG)                REG = 0xFF           //sets the whole register to ones (0b11111111) 0xFF
#define CLR_REG(REG)                REG = 0x00           //sets the whole register to zero (0b00000000) 0x00

#endif
