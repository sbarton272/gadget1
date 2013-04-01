#ifndef __GADGET1_H__
#define __GADGET1_H__

// uncomment if you're getting an error related to delay
//#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

// Some convenient definitions
#define LED PA5
#define BUTTON PA1
#define BUTTON_PC PCINT1
#define BUZZER PA7
#define SHARPIR PA0

// SHARP IR values
#define LONG_RANGE 3
#define MAX_SAMPLES 10
#define SHIFT 3

// Buzzer numbers
#define BUZZ_TIME 1000
#define FREQ 2000

#define ON 1
#define OFF 0

uint8_t sleep_status;

void initLED(void);
void initBuzzer(void);
void initButton(void);
void initADC(void);
void initSystem(void);

void setLED(uint8_t);
int buttonPressed(void);
void goToSleep(void);
void playBuzzer(uint8_t, uint8_t);
int irDetected(void);
uint8_t readIR(void);

#endif