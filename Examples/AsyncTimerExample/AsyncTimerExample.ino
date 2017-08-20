/*
  AsyncTimerExample.ino - Library that implements an asynchronous timer using the Millis method.
  Created by Tommaso Ciussani, August 20, 2017.
  Released into the public domain.
  
  To run this example connect two LEDs at pins 4 and 5 of your Arduino board.
*/

#include "AsyncTimer.h"

//Define directives
#define INTERVAL1 500
#define INTERVAL2 2000

#define LED1 4
#define LED2 5

//Global variables
bool led1Status = false;
bool led2Status = false;
int counter = 0;

// Create two timers
AsyncTimer timer1 (INTERVAL1);
AsyncTimer timer2 (INTERVAL2);


void setup() {
  Serial.begin(115200);
  //Set up the pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}


void loop() {
  //Test if the timers have expired and blink the leds.
  if(timer1.expired()) {
    led1Status = !led1Status;
    digitalWrite(LED1, led1Status);
    timer1.reset();
    counter++;
  }

  if(timer2.expired()) {
    led2Status = !led2Status;
    digitalWrite(LED2, led2Status);
    timer2.reset();
  }
  
  if(counter == 5) {
	if(timer1.getInterval() == 500) {
	  timer1.setInterval(1000);
	} else {
	  timer1.setInterval(500);
	}
	Serial.println(timer1.getInterval());
	counter = 0;
  }

}