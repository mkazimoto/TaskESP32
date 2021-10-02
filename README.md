# TaskESP32
Class Task for ESP32 using FreeRTOS

Example:

	#include <TaskESP32.h>

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
	
	void setup() {
		blinkTask.start();
	}
	
	void loop() {
	}
	


