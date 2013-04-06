/* 
	Dog on the Counter Again
	16-250 Gadget 1
	Spencer Barton
 */

#include "g1.h"

int main(void)
{	
	uint8_t ir_avrg = 0;
	uint8_t samples, read;
	initSystem();

	while(1) {	

		samples = 0;
		while ( (samples < MAX_SAMPLES) && !sleep_status) {
			if ( read = readIR() ) {
				// move bits over to help with reading small values
				ir_avrg = ((read << SHIFT) / MAX_SAMPLES) >> SHIFT;
				samples++;
			}
		}

		if ( ir_avrg > LONG_RANGE ) {
			playBuzzer(FREQ, BUZZ_TIME);
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