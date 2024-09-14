/* This file will hold the user function declarations
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1a

Video resource: https://www.youtube.com/watch?v=ma_bPt2FN8w
*/

#include <stdio.h>
#include "NUC1xx.h"
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include "DrvTimer.h"
#include "DrvGPIO.h"
#include "LCD_Driver.h"
#include "DrvSYS.h"
#include "Seven_Segment.h"
#include "ScanKey.h"

//
void blinky_Drv(void);
void TMR0_callback(void);
void heartbeat(void);
void TMR1_IRQHandler(void);

//Lab1a part 4??????
void outStringLCD(char str[]);

//Lab1b part 2
void multiplex7segment(int num);
int nth_digit(int n, int k);

//Lab1b part 4
void keypad_input(void);
