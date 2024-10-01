#include <stdio.h>
#include "NUC1xx.h"

#include "user_func.h"

#define SEGMENT_ON 1
#define SEGMENT_OFF 0

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
		if(temp!=0 && temp < 3){ 
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
}

void toggleLEDs_off(void){
	GPC_12 = 1; //off
	GPC_13 = 1; //off
	GPC_14 = 1; //off
	GPC_15 = 1; //off
}

int nth_digit(int n, int k){
     while(n--)
         k/=10;
     return k%10;
}
void multiplex7segment(int num){
			CloseSevenSegment();
			GPC_7=SEGMENT_ON; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(3,nth_digit(3, num)); // thous
			DrvSYS_Delay(475); //wait 475 us
	
			CloseSevenSegment();
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_ON; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(2,nth_digit(2, num)); // hunds
			DrvSYS_Delay(475); //wait 475 us
	
			CloseSevenSegment();
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_ON; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(1,nth_digit(1, num)); // tens
			DrvSYS_Delay(475); //wait 475 us
			
			CloseSevenSegment();
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_ON;
			ShowSevenSegment(0,nth_digit(0, num)); // ones
			DrvSYS_Delay(475); //wait 475 us
		
	CloseSevenSegment();
}
