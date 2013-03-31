#include "g1.h"


/*
	TODO
	- test IR
	- test buzzer
	X button inverted
	- add README


 */

int main(void)
{	
	initSystem();

	while(1) {	
		
		// test LED on/off
		setLED(OFF);

		// hold with button
		while( buttonPressed() ) {
			setLED(ON);
			_delay_ms(100);
			setLED(OFF);
			_delay_ms(100);
		}
		
	}
	return 0;
}