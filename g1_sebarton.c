/* 
	Dog on the Counter Again
	16-250 Gadget 1
	Spencer Barton
 */



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
		
		if ( irDetected() ) {
			playBuzzer(10000);
		}
			
		// Check if the button has been pressed, if so, nighty-night gadget!
		if(sleep_status == ON )
		{
		    /* Goodnight Moon:
			...Goodnight room
			Goodnight moon
			Good night cow jumping over the moon
			Goodnight light
			And the red balloon
			Goodnight bears
			Goodnight chairs
			Goodnight kittens
			And goodnight mittens
			Goodnight clocks
			And goodnight socks
			Goodnight little house
			And goodnight mouse
			Goodnight comb
			And goodnight brush
			Goodnight nobody
			Goodnight mush
			And goodnight to the old lady
			whispering "hush"
			Goodnight stars
			Goodnight air
			Goodnight noises everywhere */
			goToSleep(); 
		}

	}
	return 0;
}