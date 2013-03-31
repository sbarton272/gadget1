#include "g1.h"


/*
	TODO
	X test IR
	X test buzzer
	X button inverted
	X add README
	- right buzzer duty cycle
	- hardware pwm
	- IR interupt
	- sleep mode
	X ADC for IR
		X prescaler?

 */

int main(void)
{	
	initSystem();

	while(1) {	
		
		if ( readIR() > LONG_RANGE ) {
			setLED(ON);
		} else {
			setLED(OFF);
		}

		// hold with button
		while( buttonPressed() ) {
			setLED(ON);
			_delay_ms(100);
			setLED(OFF);
			playBuzzer(1000);
			//_delay_ms(100);
		}
		
	}
	return 0;
}