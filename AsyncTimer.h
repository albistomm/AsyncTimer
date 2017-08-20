/*
  AsyncTimer.h - Library that implements an asynchronous timer using the Millis method.
  Created by Tommaso Ciussani, August 20, 2017.
  Released into the public domain.
*/

#include "Arduino.h"

#ifndef AsyncTimer_h
#define AsyncTimer_h

class AsyncTimer {
public:
	AsyncTimer(const unsigned long inter);
	void setInterval(const unsigned long inter);
	unsigned long getInterval() const;
	bool expired();
	void reset();
	
private:
	unsigned long _prevMillis = 0;
	unsigned long _interval = 1000;
};


#endif