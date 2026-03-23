#include <AFMotor.h>
// Include Adafruit Motor Shield library (L293D shield v1)

// ---------------- MOTOR SETUP ----------------

// Create motor objects (M1–M4 ports on shield)

AF_DCMotor FL(1);
// Front Left motor on M1

AF_DCMotor BL(2);
// Back Left motor on M2

AF_DCMotor FR(3);
// Front Right motor on M3

AF_DCMotor BR(4);
// Back Right motor on M4

// ---------------- SPEED ----------------

int SPEED = 180;
// Motor speed (0 = stop, 255 = full power)

// ---------------- SETUP ----------------

void setup() {

  // No pinMode needed (library handles everything)

  stopMotors();
  // Ensure all motors are stopped at startup
}

// ---------------- MOVEMENT FUNCTIONS ----------------

// Move forward (all motors forward)
void forward() {

  FL.setSpeed(SPEED);
  BL.setSpeed(SPEED);
  FR.setSpeed(SPEED);
  BR.setSpeed(SPEED);

  FL.run(FORWARD);
  BL.run(FORWARD);
  FR.run(FORWARD);
  BR.run(FORWARD);
}

// Move backward (all motors backward)
void backward() {

  FL.setSpeed(SPEED);
  BL.setSpeed(SPEED);
  FR.setSpeed(SPEED);
  BR.setSpeed(SPEED);

  FL.run(BACKWARD);
  BL.run(BACKWARD);
  FR.run(BACKWARD);
  BR.run(BACKWARD);
}

// Turn left (left side backward, right side forward)
void left() {

  FL.setSpeed(SPEED);
  BL.setSpeed(SPEED);
  FR.setSpeed(SPEED);
  BR.setSpeed(SPEED);

  FL.run(BACKWARD);
  BL.run(BACKWARD);

  FR.run(FORWARD);
  BR.run(FORWARD);
}

// Turn right (left side forward, right side backward)
void right() {

  FL.setSpeed(SPEED);
  BL.setSpeed(SPEED);
  FR.setSpeed(SPEED);
  BR.setSpeed(SPEED);

  FL.run(FORWARD);
  BL.run(FORWARD);

  FR.run(BACKWARD);
  BR.run(BACKWARD);
}

// Stop all motors
void stopMotors() {

  FL.run(RELEASE);
  BL.run(RELEASE);
  FR.run(RELEASE);
  BR.run(RELEASE);
}

// ---------------- MAIN TEST LOOP ----------------

void loop() {

  forward();
  // Move forward

  delay(2000);
  // Wait 2 seconds

  stopMotors();
  // Stop

  delay(1000);

  backward();
  // Move backward

  delay(2000);

  stopMotors();
  // Stop

  delay(1000);

  left();
  // Turn left

  delay(1000);

  stopMotors();
  // Stop

  delay(1000);

  right();
  // Turn right

  delay(1000);

  stopMotors();
  // Stop

  delay(2000);
}