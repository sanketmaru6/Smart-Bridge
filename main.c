#include <Servo.h>

#define Grove_Water_Sensor 8 // Attach Water sensor to Arduino Digital Pin 8
#define Green_LED_Pin 6      // Connect Green LED to Digital Pin 9
#define Red_LED_Pin 5        // Connect Red LED to Digital Pin 10

// Define the Servo pins
int servoPin1 = 3;
int servoPin2 = 4;

// Create Servo objects
Servo Servo1, Servo2;

// Define water sensor levels for servo control
int lowWaterLevel = 200;  // Adjust this value based on sensor readings
int highWaterLevel = 500; // Adjust this value based on sensor readings

void setup() {
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);

  pinMode(Grove_Water_Sensor, INPUT);  // The Water Sensor is an Input
  pinMode(Green_LED_Pin, OUTPUT);     // Green LED is an Output
  pinMode(Red_LED_Pin, OUTPUT);       // Red LED is an Output
  pinMode(servoPin1, OUTPUT);         // The Servo1 control pin is an Output
  pinMode(servoPin2, OUTPUT);         // The Servo2 control pin is an Output
}

void loop() {
  int sensorValue = analogRead(Grove_Water_Sensor); // Read sensor value

  if (sensorValue <= lowWaterLevel) {
    // Water level is low
    digitalWrite(Green_LED_Pin, HIGH); // Turn on Green LED
    digitalWrite(Red_LED_Pin, LOW);   // Turn off Red LED
    Servo1.write(80);                // Set servos to default positions
    Servo2.write(73);
  } else if (sensorValue >= highWaterLevel) {
    // Water level is high
    digitalWrite(Green_LED_Pin, LOW);   // Turn off Green LED
    digitalWrite(Red_LED_Pin, HIGH);   // Turn on Red LED
    Servo1.write(30);                // Activate servos
    Servo2.write(30);
  } else {
    // Water level is between low and high, adjust servos as needed
    // (You can add logic for intermediate servo positions here)
  }

  delay(1000); // Adjust delay as needed
}
