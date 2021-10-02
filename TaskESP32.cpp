#include "Arduino.h"
#include "TaskESP32.h"

void runTask(void *pvParameters);

Task::Task() {    
}

void Task::start() {
      // Cria tarefa FreeRTOS
      xTaskCreatePinnedToCore(
        runTask,
        "Task",
        _stackSize,
        this,
        1,
        NULL, 
        ARDUINO_RUNNING_CORE
        );      
    }
    
void Task::delay(unsigned long miliseconds) {
      vTaskDelay(miliseconds);
    }
    
void Task::setup() {
    }

void Task::loop() {      
    }

void Task::setStackSize(int stackSize) {
  _stackSize = stackSize;
}

// Executa tarefa
void runTask(void *pvParameters) 
{
  Task *task = (Task *)pvParameters;
  
  task->setup();

  while (true) {
     task->loop();
  }
}


