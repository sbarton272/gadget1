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
#define BUZZER PA7
#define SHARPIR PA0

#define ON 1
#define OFF 0

uint8_t sleep_status;

void initLED(void);
void setLED(uint8_t);
void initButton(void);
void goToSleep(void);

void initSystem(void);

#endif