#include <AFMotor.h>

// Motors
AF_DCMotor m1(1); // Left side
AF_DCMotor m2(2); // Left side
AF_DCMotor m3(3); // Right side
AF_DCMotor m4(4); // Right side

// RF receiver pins
const int forwardPin  = 2;
const int backwardPin = 3;
const int leftPin     = 4;
const int rightPin    = 5;

// Speed settings
const int fullSpeed = 255;
const int turnSpeed = 120;

// LEFT SIDE CONTROL
void leftForward(int speed) {
  m1.setSpeed(speed);
  m2.setSpeed(speed);
  m1.run(FORWARD);
  m2.run(FORWARD);
}

void leftBackward(int speed) {
  m1.setSpeed(speed);
  m2.setSpeed(speed);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
}

void leftStop() {
  m1.run(RELEASE);
  m2.run(RELEASE);
}

// RIGHT SIDE CONTROL
void rightForward(int speed) {
  m3.setSpeed(speed);
  m4.setSpeed(speed);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void rightBackward(int speed) {
  m3.setSpeed(speed);
  m4.setSpeed(speed);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void rightStop() {
  m3.run(RELEASE);
  m4.run(RELEASE);
}

// WHOLE CAR ACTIONS
void stopCar() {
  leftStop();
  rightStop();
}

void forwardCar() {
  leftForward(fullSpeed);
  rightForward(fullSpeed);
}

void backwardCar() {
  leftBackward(fullSpeed);
  rightBackward(fullSpeed);
}

void turnLeft() {
  leftStop();
  rightForward(fullSpeed);
}

void turnRight() {
  leftForward(fullSpeed);
  rightStop();
}

void forwardLeft() {
  leftForward(turnSpeed);
  rightForward(fullSpeed);
}

void forwardRight() {
  leftForward(fullSpeed);
  rightForward(turnSpeed);
}

void backwardLeft() {
  leftBackward(turnSpeed);
  rightBackward(fullSpeed);
}

void backwardRight() {
  leftBackward(fullSpeed);
  rightBackward(turnSpeed);
}

void spinLeft() {
  leftBackward(fullSpeed);
  rightForward(fullSpeed);
}

void spinRight() {
  leftForward(fullSpeed);
  rightBackward(fullSpeed);
}

void setup() {
  pinMode(forwardPin, INPUT);
  pinMode(backwardPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);

  stopCar();
}

void loop() {
  int f = digitalRead(forwardPin);
  int b = digitalRead(backwardPin);
  int l = digitalRead(leftPin);
  int r = digitalRead(rightPin);

  // Forward combinations
  if (f && !b && !l && !r) {
    forwardCar();
  }
  else if (f && l && !b && !r) {
    forwardLeft();
  }
  else if (f && r && !b && !l) {
    forwardRight();
  }

  // Backward combinations
  else if (b && !f && !l && !r) {
    backwardCar();
  }
  else if (b && l && !f && !r) {
    backwardLeft();
  }
  else if (b && r && !f && !l) {
    backwardRight();
  }

  // In-place turning
  else if (l && !f && !b && !r) {
    spinLeft();
  }
  else if (r && !f && !b && !l) {
    spinRight();
  }

  // No valid input = stop
  else {
    stopCar();
  }
}
