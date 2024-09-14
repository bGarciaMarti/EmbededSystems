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
	char buffer[50];
	int count = 1;
	sprintf(buffer, "howdy world %d", count);
	outStringLCD(buffer);
	
	print_lcd(1, buffer); //void print_lcd(unsigned char line, char *str)



	int i;
	while(i<64 && str[i] != '\0')
	{
		// OutLCD(str[i],1); //output char to lcd 
		i++;
		if(i == 16)				//if string is longer than 16 char
		{
			// OutLCD(0xC0,0); //set DD address to begin of 2nd row 		
		}
		//if (i == 32)
		// begin the 3rd row
		//if (i == 48)
		// begin the fourth row
	}

} //end OutputString
