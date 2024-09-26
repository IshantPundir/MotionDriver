#include <Arduino.h>
#include "Stepper.hpp"
#include "Neck.hpp"

// TODO: Config...
Stepper base;
Neck xAxis;
Neck yAxis;

String command = "";

void setup() {
  // Start serial communication at 9600 baud rate;
  Serial.begin(9600);

  // Initialize motors...
  base = Stepper(2, 3, 4); // Step-pin, Dir-pin, Enable-pin
  xAxis = Neck(5, 15, 15, 100); // Servo-pin, max-range, min-range, center-position;
  yAxis = Neck(6, 15, 25, 85);

  // Set Neck to center pos!
  xAxis.center();
  yAxis.center();
}

void handleStepperCommand(char action, String parameters) {
  int angle, speed;
  switch (action) {
    case 'T':
      sscanf(parameters.c_str(), "%d %d", &angle, &speed);
      base.turn(angle, speed);
      break;
    case 'R':
      base.release();
      break;
    default:
      Serial.println("Invalid Stepper Action");
      base.test();
  }
}

void handleServoCommand(Neck& servo, char action, String parameters) {
  int value;
  switch (action) {
    case 'C':
      servo.center();
      break;
    case 'T':
      value = parameters.toInt();
      servo.turnToAngle(value);
      break;
    case 'S':
      value = parameters.toInt();
      servo.step(value);
      break;
    default:
      Serial.println("Invalid Servo Action");
  }
}

void processCommand(String command) {
  char motorType = command.charAt(0);
  char action = command.charAt(2);
  
  switch (motorType) {
    case 'S':
      handleStepperCommand(action, command.substring(4));
      break;
    case 'X':
      handleServoCommand(xAxis, action, command.substring(4));
      break;
    case 'Y':
      handleServoCommand(yAxis, action, command.substring(4));
      break;
    default:
      Serial.println("Invalid Motor Type");
  }
}

void loop() {
  // Read incoming serial data...
  if (Serial.available() > 0) {
    // Read incoming bytes
    command = "";
    command = Serial.readStringUntil('\n');
    processCommand(command);
  }

  base.run();
}