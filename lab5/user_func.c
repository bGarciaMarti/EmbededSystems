#include <stdio.h>
#include "NUC1xx.h"

#include "user_func.h"

#define SEGMENT_ON 1
#define SEGMENT_OFF 0

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*  */

void calibrateLight(double *full_LED_silly, double *no_LED_silly){
	char output[15];
	int i = 0;
		// Find ambient light with no LED output
	PWMA->CMR3=0; //set CMR to 0; (PWM->CMRx = 0;)
  DrvSYS_Delay(100000000); //set a delay to allow the light to dim
		DrvADC_StartConvert();
		while(!DrvADC_IsConversionDone());
		DrvSYS_Delay(1000000);
		while(DrvADC_IsDataValid(6)) //validate data, pg 141
		*no_LED_silly = DrvADC_GetConversionData(6); //get the conversion results of channel 6

	// Find ambient light with full LED output
	PWMA->CMR3=0xFFFF;//set CMR to 0xFFFF;
  DrvSYS_Delay(100000000);//set a delay to allow the light to get brighter
		DrvADC_StartConvert();
		while(!DrvADC_IsConversionDone());
		DrvSYS_Delay(1000000);
		while(DrvADC_IsDataValid(6)) //validate data, pg 141
		*full_LED_silly = DrvADC_GetConversionData(6); //get the conversion results of channel 6
	
		sprintf(output, "full_LED %5.2f ", *full_LED_silly );
		print_lcd(0, output);
		
		sprintf(output, "no_LED %5.2f ", *no_LED_silly);
		print_lcd(3, output);
		
		for(i = 0; i < 15; i++){
		DrvSYS_Delay(1000000);
		}
}

/* ~~~~~~~~~~~~~~~~~~keypad_input~~~~~~~~~~~~~~~~~~ */
/* keypad_input only updates it's temp variable when there is input */
/* and when the input is the first row of buttons on the NUVOTON */
/* NOTICE: this particular NUVOTON's number 2 button doesn't always register input */
void keypad_input(int* k){
	int temp;
		temp = Scankey(); //capture key value
		if(temp!=0 && temp < 6){ 
			*k=temp;
		}
		// ShowSevenSegment(0,*k); // displays the keypad matrix input when uncommented
		
}

/* ~~~~~~~~~~~~~~~~~~blinky~~~~~~~~~~~~~~~~~~ */
/* a function for miscellaneous testing */
/* blinks the 4 red LEDs in cherrful succession */
void displayToUser(int* target){
	if(*target == 5){ // %0
		GPC_12 = 1; //off
		GPC_13 = 1; //off
		GPC_14 = 1; //off
		GPC_15 = 1; //off
		}
	else if (*target == 4){ // %25
		GPC_12 = 0; //on
		GPC_13 = 1; //off
		GPC_14 = 1; //off
		GPC_15 = 1; //off	
		}
	else if (*target == 3){ // %50
		GPC_12 = 0; //on
		GPC_13 = 0; //on
		GPC_14 = 1; //off
		GPC_15 = 1; //off
		}
	else if (*target == 2){ //%75
		GPC_12 = 0; //on
		GPC_13 = 0; //on
		GPC_14 = 0; //on
		}
	else if (*target == 1){ //%100
		GPC_12 = 0; //on
		GPC_13 = 0; //on
		GPC_14 = 0; //on
		GPC_15 = 0; //on
		}
}

