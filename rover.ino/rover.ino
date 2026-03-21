#include <Servo.h>  
// Library that lets Arduino control servo motors easily

// ---------------- GRIPPER SETUP ----------------
Servo gripper;  
// Create a servo object called "gripper"

int GRIP_OPEN = 20;   
// Angle for OPEN position (you will tune this)

int GRIP_CLOSE = 90;  
// Angle for CLOSED position (you will tune this)

// ---------------- MOTOR PINS ----------------
// These connect to motor driver inputs (LEFT SIDE)

int LM1 = 5;   // Left motor forward/back pin 1
int LM2 = 6;   // Left motor forward/back pin 2

// These connect to motor driver inputs (RIGHT SIDE)

int RM1 = 9;   // Right motor forward/back pin 1
int RM2 = 10;  // Right motor forward/back pin 2

// ---------------- SPEED CONTROL ----------------
int SPEED = 180;  
// Motor speed (0 = stop, 255 = full speed)

// ---------------- SAFETY TIMEOUT ----------------
unsigned long lastCommandTime = 0;  
// Stores last time we got a command

int timeout = 500;  
// If no command for 500ms → robot stops (safety)

// ---------------- SETUP FUNCTION ----------------
void setup() {

  Serial.begin(9600);  
  // Starts communication with controller (Bluetooth / Serial Monitor)

  pinMode(LM1, OUTPUT);  
  // Left motor pin 1 set as output

  pinMode(LM2, OUTPUT);  
  // Left motor pin 2 set as output

  pinMode(RM1, OUTPUT);  
  // Right motor pin 1 set as output

  pinMode(RM2, OUTPUT);  
  // Right motor pin 2 set as output

  gripper.attach(3);  
  // Attach servo signal wire to pin 3

  gripper.write(GRIP_OPEN);  
  // Start with gripper OPEN so it's safe

  stopMotors();  
  // Make sure robot is not moving at startup
}

// ---------------- MOVEMENT FUNCTIONS ----------------

// Move forward
void forward() {

  analogWrite(LM1, SPEED);  
  // Left motors forward

  analogWrite(LM2, 0);  
  // Left motors not reversing

  analogWrite(RM1, SPEED);  
  // Right motors forward

  analogWrite(RM2, 0);  
  // Right motors not reversing
}

// Move backward
void backward() {

  analogWrite(LM1, 0);  
  // Left motors stop forward

  analogWrite(LM2, SPEED);  
  // Left motors reverse

  analogWrite(RM1, 0);  
  // Right motors stop forward

  analogWrite(RM2, SPEED);  
  // Right motors reverse
}

// Turn left
void left() {

  analogWrite(LM1, 0);  
  // Left side slows/reverses

  analogWrite(LM2, SPEED);

  analogWrite(RM1, SPEED);  
  // Right side moves forward

  analogWrite(RM2, 0);
}

// Turn right
void right() {

  analogWrite(LM1, SPEED);  
  // Left side moves forward

  analogWrite(LM2, 0);

  analogWrite(RM1, 0);  
  // Right side slows/reverses

  analogWrite(RM2, SPEED);
}

// Stop all motors
void stopMotors() {

  analogWrite(LM1, 0);  
  // Stop left motor

  analogWrite(LM2, 0);

  analogWrite(RM1, 0);  
  // Stop right motor

  analogWrite(RM2, 0);
}

// ---------------- 180 DEGREE TURN ----------------
void turn180() {

  analogWrite(LM1, 0);  
  // Left goes reverse

  analogWrite(LM2, SPEED);

  analogWrite(RM1, SPEED);  
  // Right goes forward

  analogWrite(RM2, 0);

  delay(700);  
  // Time to rotate (you will calibrate this)

  stopMotors();  
  // Stop after turn
}

// ---------------- GRIPPER FUNCTIONS ----------------

// Open gripper (release object)
void openGrip() {

  gripper.write(GRIP_OPEN);  
  // Move servo to open position
}

// Close gripper (grab object)
void closeGrip() {

  gripper.write(GRIP_CLOSE);  
  // Move servo to closed position
}

// ---------------- MAIN LOOP ----------------
void loop() {

  if (Serial.available()) {  
  // Check if remote sent a command

    char cmd = Serial.read();  
    // Read the command character

    lastCommandTime = millis();  
    // Update last active time

    Serial.print("CMD: ");  
    // Debug print

    Serial.println(cmd);  
    // Show received command

    // ---------------- MOVEMENT COMMANDS ----------------

    if (cmd == 'F') forward();  
    // Forward command

    else if (cmd == 'B') backward();  
    // Backward command

    else if (cmd == 'L') left();  
    // Turn left

    else if (cmd == 'R') right();  
    // Turn right

    else if (cmd == 'S') stopMotors();  
    // Stop robot

    else if (cmd == 'U') turn180();  
    // 180 degree turn

    // ---------------- GRIPPER COMMANDS ----------------

    else if (cmd == 'O') openGrip();  
    // Open gripper

    else if (cmd == 'C') closeGrip();  
    // Close gripper

    else if (cmd == 'X') {  
    // Emergency safety command

      stopMotors();  
      // Stop everything immediately

      openGrip();  
      // Open gripper for safety
    }
  }

  // ---------------- SAFETY STOP ----------------
  if (millis() - lastCommandTime > timeout) {  
  // If no command received recently

    stopMotors();  
    // Automatically stop rover
  }
}