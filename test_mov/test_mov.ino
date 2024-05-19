#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  Serial.begin(9600); // Start serial communication
  
  // Attach servo motors to corresponding pins
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);
  servo5.attach(13);
}

void loop() {
  // Read data from serial port
  int servoNumber = Serial.parseInt();
  // int servoNumber = receivedChar - '0'; // Convert char to integer
  Serial.println(servoNumber);
  // Control servo motors based on received data
  switch (servoNumber) {
    case 1:
      // moveServo(servo1, 0); // Move servo 1 to position 0 degrees
      Serial.println("Received: Servo 1");
      break;
    // case 2:
    //   // moveServo(servo2, 45); // Move servo 2 to position 45 degrees
    //   Serial.println("Received: Servo 2");
    //   break;
    // case 3:
    //   // moveServo(servo3, 90); // Move servo 3 to position 90 degrees
    //   Serial.println("Received: Servo 3");
    //   break;
    // case 4:
    //   // moveServo(servo4, 135); // Move servo 4 to position 135 degrees
    //   Serial.println("Received: Servo 4");
    //   break;
    // case 5:
    //   // moveServo(servo5, 180); // Move servo 5 to position 180 degrees
    //   Serial.println("Received: Servo 5");
    //   break;
    default:
      // Invalid servo number
      break;
  }
}

// Function to move a servo to a specified angle
void moveServo(Servo servo, int angle) {
  if (angle >= 0 && angle <= 180) {
    servo.write(angle); // Move the servo to the specified angle
    delay(500); // Delay to allow the servo to reach its position
  }
}

