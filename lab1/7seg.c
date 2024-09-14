/* This file will hold Lab1a code:
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1b part 2, 7 segment display
Resource https://www.youtube.com/watch?v=T8_NBwYa9vo
*/

#include "user_func.h"

#include "DrvTimer.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "Seven_Segment.h"

#define SEGMENT_ON 1
#define SEGMENT_OFF 0

//~~~~~~~~~~~~~~~~~~~~~//
/*Functions that display to the 7 segment */
//~~~~~~~~~~~~~~~~~~~~~//

/*
1. turn on first display, turn off all other displays
2. print required data to first
		ms or us delay
3. turn on second display and turn off all other displays
4. print required data to second
		ms or us delay
5. repeat for third and fourth segemnt
*/

// https://stackoverflow.com/questions/9302681/c-how-to-break-apart-a-multi-digit-number-into-separate-variables
// find the nth digit in a number
int nthdig(int n, int k){
     while(n--)
         k/=10;
     return k%10;
}


void multiplex7segment(int num){

	
		OpenSevenSegment(); // init 7-segment
			GPC_7=SEGMENT_ON; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_OFF;
			
			ShowSevenSegment(3,nthdig(3, num)); // first
			DrvSYS_Delay(475); //wait 475 us
	
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_ON; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(2,nthdig(2, num)); // second
			DrvSYS_Delay(475); //wait 475 us
	
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_ON; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(1,nthdig(1, num)); // third
			DrvSYS_Delay(475); //wait 475 us
	
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_ON;
			ShowSevenSegment(0,nthdig(0, num)); // fourth
			DrvSYS_Delay(475); //wait 475 us
		CloseSevenSegment();
}
