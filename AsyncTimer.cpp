/*
  AsyncTimer.cpp - Library that implements an asynchronous timer using the Millis method.
  Created by Tommaso Ciussani, August 20, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "AsyncTimer.h"

AsyncTimer::AsyncTimer(const unsigned long inter) {
	_interval = inter;
	reset();
}

void AsyncTimer::setInterval(const unsigned long inter) {
	_interval = inter;
}

unsigned long AsyncTimer::getInterval() const {
	return _interval;
}

bool AsyncTimer::expired() {
	if ((millis() - _prevMillis) >= _interval) {
		//If _interval milliseconds passed after the _prevMillis point (timer expired):
		return true;
	}
	return false;
}

void AsyncTimer::reset() {
	_prevMillis = millis();
}