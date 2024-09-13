/* This file will hold the second tutorial for ECE4330 containing both the LED and the 7 segment
number example
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1b
*/

#include <stdio.h>
#include "NUC1xx.h"
#include "LCD_Driver.h"

#include "user_func.h"

//~~~~~~~~~~~~~~~~~~~~~//
/*Functions that us timer/ "Driver method" to blind the green RGB LEDs */
//~~~~~~~~~~~~~~~~~~~~~//
void LCD_display(void){
	clr_all_panel();
	
	char s[15];
	sprintf(s, "howdy world %d", count);
}