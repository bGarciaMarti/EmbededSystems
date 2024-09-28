#include <stdio.h>
#include "NUC1xx.h"

#include "user_func.h"

#define SEGMENT_ON 1
#define SEGMENT_OFF 0

void keypad_input(int* k){
	//capture key value
	int temp;
	char Line1[15];
	sprintf(Line1, "%s", "key = "); //has 6 characters
	
	temp = Scankey();
	if(temp!=0){
		*k=temp;
	}
	
	sprintf(Line1+6, "%d", *k);
	
	ShowSevenSegment(0,*k);
}
