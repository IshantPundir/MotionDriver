#include "Neck.hpp"
#include <Servo.h>


Neck::Neck(int pin, int max, int min, int center) {
    // TODO: assertions
    centerPos = center;
    maxRange = centerPos + max;
    minRange = centerPos - min;


    neckServo.attach(pin);
};

Neck::Neck() {}

Neck::~Neck() {};

void Neck::turnToAngle(int angle) {
    if (angle <= maxRange && angle >= minRange) {
        neckServo.write(angle);
    }
};

void Neck::center() {
    turnToAngle(centerPos);
}

void Neck::step(int value) {
    int angle = centerPos + value;
    if (angle > maxRange) { angle = maxRange; }
    else if (angle < minRange) { angle = maxRange; }

    turnToAngle(angle);
}