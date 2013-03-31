#include "g1.h"

volatile uint8_t led = OFF;

/* ==========================
 * ===== Init Functions =====
 * ========================== */

/* In this function you should set the LED pins to be outputs and
   set them high to turn them off (because our LEDs are active low)
   Lastly, you should initialize timer 0's interrupts and prescalar
   to enable software PWM  */
void initLED()
{
	// Set LED pin direction to output
	DDRA |= _BV(LED);
	
	// Start pins off active high (which corresponds to LED off)
	setLED(OFF);
	
}

/*  In this function you should set the button pin to be an input */
void initButton()
{
	// Set button as input
	DDRA &= ~_BV(BUTTON);
	
}

/*  Set buzzer as output */
void initBuzzer()
{

	DDRA |= _BV(BUZZER);
	
}

// You do not need to modify this function
void initSystem()
{
	initBuzzer();
	initLED();  // Turn on our LED
	initButton(); // Turn on button interrupts
	sei();        // Nothing's gonna interrupt until we turn on global interrupts
}

/* ==========================
 * ===== LED Controls =======
 * ========================== */

/*  set the led value */
void setLED(uint8_t led)
{
	if(led) {
		PORTA |= _BV(LED);
	}
	else {
		PORTA &= ~_BV(LED);
	}
}

/* ==========================
 * ===== Button Controls ====
 * ========================== */

/*  In this function, return a non-zero value if the button was pressed, and 0
    if it is not pressed. */
int buttonPressed()
{
	return !!(PINA & _BV(BUTTON));
}

/* ==========================
 * ===== Buzzer Controls ====
 * ========================== */

 /* Play buzzer for 1/2 duty cycle for specified time */
void playBuzzer(uint8_t time)
{
	uint8_t t;

	for (t = 0; t < time; t++)
	{
		/* on for even times, off for odd times */
		if( (t % 3) == 0 ) {
			PORTA |= _BV(BUZZER);
		}
		else {
			PORTA &= ~_BV(BUZZER);
		}
	}
}

