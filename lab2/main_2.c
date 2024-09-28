/* This file will hold Lab2
first program should use the continuous mode operation
Created by: Brenardo Garcia Marti
For ECE 4330
resource: https://www.youtube.com/watch?app=desktop&v=j5Y-odURLaM
*/

#include <stdio.h>
#include "NUC1xx.h"
#include <stdlib.h>

#include "user_func.h"

// Function to perform selection sort
// https://www.geeksforgeeks.org/recursive-bubble-sort/
void swap(int* a, int* b) {
    float t = *a;
    *a = *b;
   *b = t;
}
void bubbleSort(int arr[], int n) {
   int i, j;
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
					}
		}
}


int main (void) {
	int i=0;
	int digital = 0;
	float analog = 0;
	char output[15];
	int noiseReducArr[4];

	UNLOCKREG();
		SYSCLK->PWRCON.XTL12M_EN=1;
		SYSCLK->CLKSEL0.HCLK_S=0;
	LOCKREG();
	
	heartbeat();
	
	DrvGPIO_DisableDigitalInputBit(E_GPA,0);	
	DrvADC_Open(ADC_SINGLE_END, ADC_CONTINUOUS_OP,0x1,INTERNAL_HCLK,0); //init ADC
	
		// init the LCD
	Initial_panel();
	DrvGPIO_ClrBit(E_GPD,14); //backlight LCD
	clr_all_panel(); //clear the LCD
	print_lcd(3, "LAB2 ADC: Continuous");
	
	DrvADC_StartConvert();	
	// the 2 lines below were called in the while loop causing errors and no value to be displayed at all
	while(!DrvADC_IsConversionDone());
	while(DrvADC_IsDataValid(0)) //validate data, pg 141
	
	while(1){
		
		for(i =0; i<4; i++){ // noise reduction+
			/* these 2 lines of code below are what was causing the original bottle-necking, moving them up to lines 57,58 resolved the issue
			while(!DrvADC_IsConversionDone());
			while(DrvADC_IsDataValid(0)) 
			*/
			digital = DrvADC_GetConversionData(0); //get the conversion results of channel 0
			noiseReducArr[i] = digital;
		}
		bubbleSort(noiseReducArr,4);

		sprintf(output, "%d raw digital value", digital);
		print_lcd(1, output);
		
		sprintf(output, " %5.2f %%", 	(digital/4095.0)*100	);
		print_lcd(2, output);
		
		//analog = (digital / 4096.0) * 3.3; //bouncy Vin
		analog =	(	((noiseReducArr[1] + noiseReducArr[2] ) /2) / 4096.0) * 3.3 ;
		sprintf(output, " %.2f V", analog);
		print_lcd(0, output);
		
		analog = 0;
		digital = 0;
		
		DrvSYS_Delay(1000000);

	}//end while
} //end main
