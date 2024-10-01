/* This file will hold the user function declarations
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1a

Video resource: https://www.youtube.com/watch?v=ma_bPt2FN8w
*/

#include <stdio.h>
#include <stdbool.h>
#include "NUC1xx.h"
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include "DrvGPIO.h"
#include "LCD_Driver.h"
#include "DrvSYS.h"
#include "Seven_Segment.h"
#include "ScanKey.h"
#include "DrvTIMER.h"

	
	/* ~~~~~~~~~~~input functions~~~~~~~~~~~~~~~~ */
	void keypad_input(int* k);
	
	
	
	/* ~~~~~~~~~~~~~LED functions ~~~~~~~~~~~~~~ */
	void toggleLEDs_on(void);
	void toggleLEDs_off(void);
	void heartbeat(void);

	/* ~~~~~~~~~~~~~7seg functions ~~~~~~~~~~~~~~ */
int nth_digit(int n, int k);
void multiplex7segment(int num);
