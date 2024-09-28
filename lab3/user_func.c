#include <stdio.h>
#include "NUC1xx.h"

#include "user_func.h"
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*  */
/*  */


/* ~~~~~~~~~~~~~~~~~~keypad_input~~~~~~~~~~~~~~~~~~ */
/* keypad_input only updates it's temp variable when there is input */
/* and when the input is the first row of buttons on the NUVOTON */
/* NOTICE: this particular NUVOTON's number 2 button doesn't always register input */
void keypad_input(int* k){
	int temp;
		temp = Scankey(); //capture key value
		if(temp!=0 && temp < 4){ 
			*k=temp;
		}
		// ShowSevenSegment(0,*k); // displays the keypad matrix input when uncommented
}

/* ~~~~~~~~~~~~~~~~~~blinky~~~~~~~~~~~~~~~~~~ */
/* a function for miscellaneous testing */
/* blinks the 4 red LEDs in cherrful succession */
void toggleLEDs_on(void){
	GPC_12 = 0; //on
	GPC_13 = 0; //on
	GPC_14 = 0; //on
	GPC_15 = 0; //on
		DrvSYS_Delay(550000); //DrvSYS.h line 182, DrvSYS.c line 1310
	GPC_12 = 1; //off
	GPC_13 = 1; //off
	GPC_14 = 1; //off
	GPC_15 = 1; //off
		DrvSYS_Delay(550000);
}

void toggleLEDs_off(void){
	GPC_12 = 1; //off
	GPC_13 = 1; //off
	GPC_14 = 1; //off
	GPC_15 = 1; //off
		DrvSYS_Delay(10000000);
}
