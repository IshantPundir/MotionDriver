#include "Stepper.hpp"
#include <Arduino.h>

Stepper::Stepper() {};

Stepper::Stepper(int stepPin, int dirPin, int enablePin) :
    stepPin(stepPin), dirPin(dirPin), enablePin(enablePin)
{
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enablePin, OUTPUT);
};

Stepper::~Stepper() {};

void Stepper::setSpeed(int speed) {

};

void Stepper::turn(int angle) {
    // Make sure driver is enabled...
    if (!isEnabled) { setEnable(true); }
    // TODO: calculate steps from angle...

    targerStep = angle;
    isMoving = true;
}

void Stepper::run() {
    if (isMoving && (micros() - lastStepTime >= stepDelay)) {
        lastStepTime = micros();
        if (currentStep < targerStep) {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(stepDelay / 2);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(stepDelay / 2);
            Serial.print("*");
            currentStep ++;
        }
        else {
            isMoving = false;
            currentStep = 0;
        }
    }
}

void Stepper::setEnable(bool enable) {
    if (enable) {
        digitalWrite(enablePin, HIGH);
        isEnabled = true;
    }
    else {
        digitalWrite(enablePin, LOW);
        isEnabled = false;
    }
}
