#include "Stepper.hpp"
#include <Arduino.h>

Stepper::Stepper() {};

Stepper::Stepper(int stepPin, int dirPin, int enablePin) :
    stepPin(stepPin), dirPin(dirPin), enablePin(enablePin)
{
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    setDirection(DIRECTION::RIGHT);
};

Stepper::~Stepper() {};

void Stepper::setDirection(DIRECTION direction) {
    if (turningDirection == direction) return;
    turningDirection = direction;

    switch (turningDirection)
    {
        case DIRECTION::RIGHT:
            digitalWrite(dirPin, HIGH);
            break;
        default:
            digitalWrite(dirPin, LOW);
            break;
    }
};

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

void Stepper::release() {
    currentStep = 0;
    isMoving = false;
    setEnable(false);
};

void Stepper::step() {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
}

void Stepper::turn(int angle, int speed) {
    // Make sure driver is enabled...
    if (!isEnabled) { setEnable(true); }

    targerStep = angle * stepsPerDeg;
    isMoving = true;
}

void Stepper::run() {
    if (isMoving && (micros() - lastStepTime >= stepDelay)) {
        lastStepTime = micros();
        if (currentStep < targerStep) {            
            setDirection(DIRECTION::RIGHT);
            currentStep ++;
        }
        else if (currentStep > targerStep) {
            setDirection(DIRECTION::LEFT);
            currentStep --;
        }
        else {
            isMoving = false;
            return;
        }

        step();
        Serial.print(currentStep);
        Serial.print(" ");
    }
}


void Stepper::test() {
    setEnable(true);
    for (int i = 0; i < stepsPerRev; i++) {
        step();
    }
    setEnable(false);
}