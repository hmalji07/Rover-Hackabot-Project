#include <AFMotor.h>

AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4);

void setup() {
  Serial.begin(9600);

  m1.setSpeed(255);
  m2.setSpeed(255);
  m3.setSpeed(255);
  m4.setSpeed(255);

  stopCar();
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    if (cmd == 'F') {
      forward();
    }
    else if (cmd == 'B') {
      backward();
    }
    else if (cmd == 'L') {
      left();
    }
    else if (cmd == 'R') {
      right();
    }
    else if (cmd == 'S') {
      stopCar();
    }
  }
}

void forward() {
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void backward() {
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void left() {
  m1.run(BACKWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
}

void right() {
  m1.run(FORWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
}

void stopCar() {
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
}