/* This file will hold the user function declarations
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1a

Video resource: https://www.youtube.com/watch?v=ma_bPt2FN8w
*/

#include <stdio.h>
/* Declaration of Variables*/


/* Declaration of Functions*/

//
void blinky_Drv(void);
void TMR0_callback(void);
void heartbeat(void);
void TMR1_IRQHandler(void);

//Lab1a part 4??????
void outStringLCD(char str[]);

//Lab1b part 1
void multiplex7segment(int num);
int nthdig(int n, int k);
