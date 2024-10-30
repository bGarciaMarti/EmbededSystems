/* This file will hold TEMPLATE for all projects, with heartbeat function included
number example
Created by: Brenardo Garcia Marti
For ECE 4330
https://gist.github.com/mavif/8da21982d16d708344df
https://github.com/RonBenDavid/Fire-Engine-Control-System-with-PS4-Remote-and-Computer-Vision-On-Nu-LB-NUC140/blob/main/Nu-LB-NUC140_UART0_HC05/Smpl_UART0_HC05.c

brown wire to GPA15
yellow to GPA6
orange to 3.3 V 

*/

#include <stdio.h>
#include "NUC1xx.h"

#include "user_func.h"

#define  PWM_CLKSRC_SEL   3        //0: 12M, 1:32K, 2:HCLK, 3:22M
int prevInputKeypad = 0;
int update = 0;
double no_LED = 0.0;
double full_LED = 0.0;
double target_reading = 0.0;
double kp = 1.0;
int new_duty = 0; // set to initial duty value


int main (void) {
	char output[15];
	double iMeas = 0;
	double voltage = 0.0;
	double error = 0.0;
	double temp_error = 0.0;
	
	/* declare PWM's sPt struct */
	S_DRVPWM_TIME_DATA_T sPt;
		sPt.u32Frequency = 1000; // Set 1KHz to PWM timer output frequency

		sPt.u8Mode = DRVPWM_AUTO_RELOAD_MODE;
	
		sPt.u8HighPulseRatio = 20; /* High Pulse peroid : Total Pulse peroid = 20 : 100 */ 
		sPt.i32Inverter = 0; // disabled
	
		sPt.u8ClockSelector = DRVPWM_CLOCK_DIV_1; //  takes effect when u32Frequency = 0
		sPt.u8PreScale = 22;      // clock is divided by (PreScaler + 1)
		sPt.u32Duty = 1000;
	
	heartbeat();
	
		/* initialize peripheral hardware */
	OpenKeyPad();
	Initial_panel(); // init the LCD
	DrvGPIO_ClrBit(E_GPD,14); //backlight LCD
	clr_all_panel(); //clear the LCD
	
	DrvADC_Open(ADC_SINGLE_END, ADC_SINGLE_OP,0x40,INTERNAL_HCLK,1); //init ADC
	DrvADC_SetADCChannel(0x40);
	DrvGPIO_DisableDigitalInputBit(E_GPA,6); // configure ADC pins as input

	/* init PWM */
	DrvGPIO_InitFunction(E_FUNC_PWM3);
	DrvPWM_Open();
	DrvPWM_SelectClockSource(DRVPWM_TIMER3, DRVPWM_HCLK); //Select PWM timer 2 and PWM timer 3 engine clock source from HCLK
	DrvPWM_SetTimerClk(DRVPWM_TIMER3, &sPt);
	DrvPWM_SetTimerIO(DRVPWM_TIMER3,1);
	DrvPWM_Enable(DRVPWM_TIMER3, 1);
	

	calibrateLight(&full_LED, &no_LED);
	kp = (no_LED/full_LED); // directly proportional
	//kp = (full_LED*no_LED); // OR inversely proportional
	prevInputKeypad = 3; // initial value to 50%
	
	clr_all_panel(); //clear the LCD
	
	while(1){
			DrvADC_StartConvert();
			while(!DrvADC_IsConversionDone());
			DrvSYS_Delay(1000000);
			while(DrvADC_IsDataValid(6)) //validate data, pg 141
			iMeas = DrvADC_GetConversionData(6); //get the conversion results of channel 6

			// Limit error to +/-5
			temp_error = target_reading-iMeas;
			error = (temp_error)*kp/(full_LED-no_LED)*100;
			
			if (error > 5) { error = 5; }
			else if (error < -5) { error = -5; }

			new_duty = sPt.u8HighPulseRatio + error * 1.2;
			if (new_duty > 100){ new_duty = 100;	}
			else if (new_duty < 1) {new_duty = 1; }
			
			sPt.u8HighPulseRatio = new_duty; //changes the value
			DrvPWM_SetTimerClk(DRVPWM_TIMER3 , &sPt); //applies the value to the PWM
			DrvSYS_Delay(100000); // wait 50 ms
			
			voltage =	(iMeas / 4096.0) * 3.3 ;
			sprintf(output, " %.2f V %.1f", voltage, iMeas); // the measured intensity (ADC input in volts, digital, and in percentage)
			print_lcd(0, output);
			
			sprintf(output, " %.2f V %5.2f ", ((target_reading / 4096.0) * 3.3), target_reading);
			print_lcd(1, output);
			
			sprintf(output, "%.1f %% error", error);
			print_lcd(2, output);
			
			sprintf(output, "%d duty cycle", new_duty);
			print_lcd(3, output);
			
			
		keypad_input(&prevInputKeypad);
		switch(prevInputKeypad){
			case 1: // 100%
				target_reading = full_LED;
				displayToUser(&prevInputKeypad);
				break;
			case 2: // %75
				target_reading = no_LED +((full_LED - no_LED)*3/4);
				displayToUser(&prevInputKeypad);
			break;
			case 3: // %50
				target_reading = no_LED +((full_LED - no_LED)/2);
				displayToUser(&prevInputKeypad);
			break;
			case 4: // %25
				target_reading = no_LED +((full_LED - no_LED)*1/4);
				displayToUser(&prevInputKeypad);
			break;
			case 5: // %0
				target_reading = no_LED;
				displayToUser(&prevInputKeypad);
			break;
			default:
				target_reading = no_LED;
				displayToUser(&prevInputKeypad);
			break;
		}
		
	CloseKeyPad();
		
	}//end while
} //end main
