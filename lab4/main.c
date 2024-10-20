/* This file will hold Lab4
Created by: Brenardo Garcia Marti
For ECE 4330

*/

#include <stdio.h>
#include "NUC1xx.h"

#include "user_func.h"

int main (void) {
	int count = 0;
	float voltage = 0;
	double analog = 0;
	char output[15];
	
	heartbeat();
	
	//initialize the internal clock
	UNLOCKREG();
		SYSCLK->PWRCON.XTL12M_EN=1;
		SYSCLK->CLKSEL0.HCLK_S=0;
	LOCKREG();
	
	DrvGPIO_DisableDigitalInputBit(E_GPA,0);
	DrvADC_Open(ADC_SINGLE_END, ADC_SINGLE_OP,0x1,INTERNAL_HCLK,0); //init ADC
	
	// configure ADC pins as input
	GPIOA->PMD.PMD0 = 0; // set pin 0 of Port A as an input
	// configure 2 pints to drive DAC
	GPIOD->PMD.PMD0 = 1; // set pin 0 of Port D as an output
	GPIOD->PMD.PMD1 = 1; // set pin 1 of Port D as an output
	
	// init the LCD
	Initial_panel();
	DrvGPIO_ClrBit(E_GPD,14); //backlight LCD
	clr_all_panel(); //clear the LCD
	
	while(1){
		for(count =0; count<4; count++){ // loop from b00, b01, b10, b11
		/* Loop from b00, b01, b10, b11 (binary count same as 0-3).
		Mask port D bits 15:2 //must mask rest of pins in Port D */
			
	
	DrvGPIO_SetPortMask(E_GPD,0xfffc); // write protect 
	DrvGPIO_SetPortBits(E_GPD, count); 
			
		/* GPD_0 = count & 1; //LSB
		GPD_1 = (count >> 1) & 1; //2nd bit */
			
			/*
		port D = count;
		When ADC is ready, get ADC value
		Convert ADC value to voltage (Vref = 3.3V) */
			DrvADC_StartConvert();
			while(!DrvADC_IsConversionDone());
			DrvSYS_Delay(1000000);
			while(DrvADC_IsDataValid(0)) //validate data, pg 141
			analog = DrvADC_GetConversionData(0); //get the conversion results of channel 0

		/* Print the binary count to screen
		Print raw ADC value (0-4095) to screen
		Print the voltage to the screen.
		Repeat for next binary count. */
		sprintf(output, "%d binary count", count);
		print_lcd(1, output);
		
		sprintf(output, "%.1f ADC value", analog);
		print_lcd(2, output);
		
		//analog = (digital / 4096.0) * 3.3; //bouncy Vin
		voltage =	analog * 3.3/(4095) ;
		sprintf(output, " %.2f V", voltage);
		print_lcd(0, output);
			
		analog = 0;
		voltage = 0;
		
		DrvSYS_Delay(1000000);
		
	} // end of for-loop binary count
		count = 0;
	}//end while
} //end main
