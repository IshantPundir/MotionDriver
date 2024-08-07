#include <Arduino.h>
#include "Stepper.hpp"

// TODO: Config...
Stepper base;
String command = "";

void setup() {
  // Start serial communication at 9600 baud rate;
  Serial.begin(9600);

  // Initialize base stepper motor...
  base = Stepper(2, 3, 4); 
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