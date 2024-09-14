/* This file will hold the second tutorial for ECE4330 containing both the LED and the 7 segment
number example
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1c

Resource:
https://github.com/hoangdesu/BONK-game-NUC140/blob/main/src/main.c
*/

#include <stdio.h>
#include "NUC1xx.h"
#include "LCD_Driver.h"
#include "user_func.h"

//~~~~~~~~~~~~~~~~~~~~~//
/*Functions that display a string to the LCD */
//~~~~~~~~~~~~~~~~~~~~~//

void outStringLCD(char str[]){
	char buffer[16];
	int count = 1;
	sprintf(buffer, str, count);
	outStringLCD(buffer);
	
	print_lcd(1, buffer); //void print_lcd(unsigned char line, char *str)

} //end OutputString
