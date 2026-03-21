#include <Servo.h>
// NOTE: Servo library kept removed logically, but not needed anymore

// ---------------- MOTOR PINS ----------------

int LM1 = 5;
// Left motor input 1

int LM2 = 6;
// Left motor input 2

int RM1 = 9;
// Right motor input 1

int RM2 = 10;
// Right motor input 2

// ---------------- SETUP ----------------

void setup() {

  // Serial.begin(9600);
  // REMOVED: no remote control yet

  pinMode(LM1, OUTPUT);
  // Left motor pin 1 output

  pinMode(LM2, OUTPUT);
  // Left motor pin 2 output

  pinMode(RM1, OUTPUT);
  // Right motor pin 1 output

  pinMode(RM2, OUTPUT);
  // Right motor pin 2 output

  stopMotors();
  // Ensure robot is stopped at start
}

// ---------------- MOTOR FUNCTIONS ----------------

// Move forward
void forward() {

  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

// Move backward
void backward() {

  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

// Turn left
void left() {

  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

// Turn right
void right() {

  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

// Stop motors
void stopMotors() {

  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

// ---------------- MAIN TEST LOOP ----------------

void loop() {

  // Forward test
  forward();
  delay(2000);

  stopMotors();
  delay(1000);

  // Backward test
  backward();
  delay(2000);

  stopMotors();
  delay(1000);

  // Left turn test
  left();
  delay(1000);

  stopMotors();
  delay(1000);

  // Right turn test
  right();
  delay(1000);

  stopMotors();
  delay(2000);

  // Repeat forever
}