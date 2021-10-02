# TaskESP32
Class Task for ESP32 using FreeRTOS

Example:

	#include <TaskESP32.h>

	class BlinkTask : public Task {
	public:  
		void setup() {      
			pinMode(2, OUTPUT);
		}       
		void loop() {
			digitalWrite(2, HIGH);
			delay(1000);
			digitalWrite(2, LOW);
			delay(1000);
		}
	} blinkTask;
	
	void setup() {
		blinkTask.start();
	}
	
	void loop() {
	}
	


