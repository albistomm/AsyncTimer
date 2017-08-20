# AsyncTimer
This is an Arduino library that implements an asynchronous timer using the millis() builtin function. These timers are overflow-proof (millis overflows after 47 days).  
The timer is initialized by calling the constructor, that takes the interval of the timer as a parameter: AsyncTimer(INTERVAL). The interval can be changed later using timer.setInterval(NEW_INTERVAL).  
To check if the timer expired, please use timer.expired(). To start the timer, call timer.reset().  
  
To download and use the library, please download the .zip file by pressing the button in the top-right corner. Then extract the archive and put it in the "library" folder in your Arduino workspace.