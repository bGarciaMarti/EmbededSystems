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


void multiplex7segment(int first,int second,int third,int fourth){
		OpenSevenSegment(); // init 7-segment
			GPC_7=SEGMENT_ON; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(3,first); // ShowSevenSegment(uint8_t no, uint8_t number)
			DrvSYS_Delay(475); //wait 475 us
	
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_ON; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(2,second); // ShowSevenSegment(uint8_t no, uint8_t number)
			DrvSYS_Delay(475); //wait 475 us
	
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_ON; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(1,third); // ShowSevenSegment(uint8_t no, uint8_t number)
			DrvSYS_Delay(475); //wait 475 us
	
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_ON;
			ShowSevenSegment(0,fourth); // ShowSevenSegment(uint8_t no, uint8_t number)
			DrvSYS_Delay(475); //wait 475 us
		CloseSevenSegment();
}
