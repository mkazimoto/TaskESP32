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
	

You can adjust task priority and stack size:

	#include <TaskESP32.h>
	#include <IRremote.h>

	class IrReceiverTask : public Task {
	public:
    
		void setup() {
			IrReceiver.begin(14);
		}

		void loop() {
			if (IrReceiver.decode()) {
				Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);        
				IrReceiver.resume(); 
			}          
			delay(100);
		}
	} irReceiverTask;
	
	void setup() {
		irReceiverTask.setPriority(1);
		irReceiverTask.setStackSize(4096);
		irReceiverTask.start();
	}
	
	void loop() {
	}
