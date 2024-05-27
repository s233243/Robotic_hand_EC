#include <Servo.h>
#include <Arduino.h>

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

const int servo1Pin = 2;
const int servo2Pin = 3;
const int servo3Pin = 4;
const int servo4Pin = 5;
const int servo5Pin = 6;

int currentServo = -1; // No servo is activated initially
int delayTime = 500; // Delay time in milliseconds

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bps
  Serial.println("Ready to receive data...");

  servo0.attach(2); // Attach servo motor to pin 2
  servo1.attach(3); // Attach servo motor to pin 3
  servo2.attach(4); // Attach servo motor to pin 4
  servo3.attach(5); // Attach servo motor to pin 5
  servo4.attach(6); // Attach servo motor to pin 6

  servo0.write(80);
  servo1.write(150);
  servo2.write(150);
  servo3.write(150);
  servo4.write(150);

}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n'); // Read incoming data until newline
    float receivedNumber = data.toFloat();
    Serial.print("Received data: ");
    Serial.println(receivedNumber);

        // Reset all servos to 0 position
    servo0.write(80);
    servo1.write(150);
    servo2.write(150);
    servo3.write(150);
    servo4.write(150);

    delay(2000);  // Ensure the previous servo has time to reset before the next activation


    // Activate the new servo based on the received number
    if (receivedNumber == 0.0) {
      activateServo(0);
      currentServo = 0;
    } else if (receivedNumber == 1.0) {
      activateServo(1);
      currentServo = 1;
    } else if (receivedNumber == 2.0) {
      activateServo(2);
      currentServo = 2;
    } else if (receivedNumber == 3.0) {
      activateServo(3);
      currentServo = 3;
    } else if (receivedNumber == 4.0) {
      activateServo(4);
      currentServo = 4;
    } else if (receivedNumber == 5.0) {
      activateServo(5);
      currentServo = 5;
    } else if (receivedNumber == 6.0) {
      activateServo(6);
      currentServo = 6;
    } 
    delay(2000);
  }
  else {
    servo0.write(80);
    servo1.write(150);
    servo2.write(150);
    servo3.write(150);
    servo4.write(150);
    }
}

void activateServo(int servoNumber) {
  switch (servoNumber) {
    case 0: // opening
      servo0.write(80);
      servo1.write(180);
      servo2.write(250);
      servo3.write(180);
      servo4.write(180);
      Serial.println("No servo activated");
      break;
    case 1: // closing
      servo0.write(0); // Adjust angle as needed
      servo1.write(100); // Adjust angle as needed
      servo2.write(100); // Adjust angle as needed
      servo3.write(100); // Adjust angle as needed
      servo4.write(100); // Adjust angle as needed
      Serial.println("All servo activated");
      break;
    case 2: // thumb
      servo0.write(0); // Adjust angle as needed
      Serial.println("Servo 0 activated");
      break;
    case 3: // index
      servo1.write(100); // Adjust angle as needed
      Serial.println("Servo 1 activated");
      break;
    case 4: // major
      servo2.write(100); // Adjust angle as needed
      Serial.println("Servo 2 activated");
      break;
    case 5: // ring finger
      servo3.write(100); // Adjust angle as needed
      Serial.println("Servo 3 activated");
      break;
    case 6: // little finger
      servo4.write(100); // Adjust angle as needed
      Serial.println("Servo 4 activated");
      break;
  }
}

