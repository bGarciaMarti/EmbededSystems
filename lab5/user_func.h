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
#include "DrvPWM.h"
#include "DrvADC.h"

	void heartbeat(void);
	
	void keypad_input(int* k);

  void displayToUser(int* target);
	
	void calibrateLight(double *full_LED_silly, double *no_LED_silly);

