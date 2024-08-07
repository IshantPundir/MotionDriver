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
  base = Stepper(2, 3, 4);
  xAxis = Neck(5, 15, 15, 100);
  yAxis = Neck(6, 15, 15, 85);

  // Set Neck to center pos!
  xAxis.center();
  yAxis.center();
}

void loop() {
  // Read incoming serial data...
  if (Serial.available() > 0) {
    // Read incoming bytes
    command = "";
    command = Serial.readStringUntil('\n');

    int angle = command.toInt();
    Serial.print("\nTurning to ");
    Serial.println(angle);

    if (angle == 999) {
      base.release();
    }
    else {
      base.turn(angle, 100);
    }
  }

  base.run();
}