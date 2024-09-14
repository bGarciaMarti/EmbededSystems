/* This file will hold Lab 1a code for ECE4330
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1a: Part 4 the LCD

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
	
	print_lcd(0, buffer); //void print_lcd(unsigned char line, char *str)
	
} //end OutputString
