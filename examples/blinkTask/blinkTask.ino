#include <TaskESP32.h>

#define LED_BUILTIN 2

class BlinkTask : public Task {
  public:
    void setup() {      
      pinMode(LED_BUILTIN, OUTPUT);
    }

    void loop() {      
      digitalWrite(LED_BUILTIN, HIGH);   
      delay(1000);  
      digitalWrite(LED_BUILTIN, LOW);    
      delay(1000);  
    }    
} blinkTask;

class LogTask : public Task {
  private:
    int count;
  public:
    void setup() {      
      count = 0;
    }

    void loop() {      
      count++;
      Serial.println(count);
      delay(1000);  
    }       
} logTask;

void setup() {
  Serial.begin(115200);

  blinkTask.start();
  logTask.start();
}

void loop()
{
}
