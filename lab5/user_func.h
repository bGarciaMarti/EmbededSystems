/* This file will hold the user function declarations
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1a

Video resource: https://www.youtube.com/watch?v=ma_bPt2FN8w
*/

#include <stdio.h>
#include "NUC1xx.h"
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include "DrvGPIO.h"
#include "LCD_Driver.h"
#include "DrvSYS.h"
#include "Seven_Segment.h"
#include "ScanKey.h"
#include "DrvTIMER.h"

	void heartbeat(void);
	
	void keypad_input(int* k);

	void zero_percent(void);
	void twentyfive_percent(void);
	void fifty_percent(void);
	void seventyFive_percent(void);
	void oneHund_percent(void);
