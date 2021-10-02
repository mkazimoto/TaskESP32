#ifndef TASK_H
#define TASK_H

#include "Arduino.h"

#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

class Task {
  public:
    Task();
    void start();    
    void delay(unsigned long miliseconds);    
    virtual void setup();
    virtual void loop();
};

#endif
