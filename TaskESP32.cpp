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
        1024,  
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

// Executa tarefa
void runTask(void *pvParameters) 
{
  Task *task = (Task *)pvParameters;
  
  task->setup();

  while (true) {
     task->loop();
  }
}


