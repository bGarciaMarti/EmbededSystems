/* This file will hold Lab2
first program should use the single mode operation
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
	
	heartbeat();
	DrvGPIO_DisableDigitalInputBit(E_GPA,0);
	DrvADC_Open(ADC_SINGLE_END, ADC_SINGLE_OP,0x1,INTERNAL_HCLK,0); //init ADC
	
	// configure ADC pins as input
	GPIOA->PMD.PMD0 = 0; // set pin 0 of Port A as an input
	
	// init the LCD
	Initial_panel();
	DrvGPIO_ClrBit(E_GPD,14); //backlight LCD
	clr_all_panel(); //clear the LCD
	
	
	while(1){
	

		for(i =0; i<4; i++){ // noise reduction
			DrvADC_StartConvert();
			while(!DrvADC_IsConversionDone());
			DrvSYS_Delay(1000000);
			while(DrvADC_IsDataValid(0)) //validate data, pg 141
			digital = DrvADC_GetConversionData(0); //get the conversion results of channel 0
			noiseReducArr[i] = digital;
		}
		bubbleSort(noiseReducArr,4);

		
		/*
		Show_Word(0, 5, digital/1000+'0'); 			//thous
		Show_Word(0, 6, digital%1000/100+'0');	// hunds
		Show_Word(0, 7, digital/100/10+'0');		// tens
		Show_Word(0, 8, digital%10+'0');				// ones
		*/
		
		sprintf(output, "%d raw digital value", digital);
		print_lcd(1, output);
		
		sprintf(output, " %5.2f %%", 	(digital/4095.0)*100	);
		print_lcd(2, output);
		
		//analog = (digital / 4096.0) * 3.3; //bouncy Vin
		analog =	(	((noiseReducArr[1] + noiseReducArr[2] ) /2) / 4096.0) * 3.3 ;
		sprintf(output, " %.2f V", analog);
		print_lcd(0, output);

	}//end while
} //end main
