#include "Neck.hpp"

Neck::Neck(int pin, int max, int min, int center) : centerPos(center)
{
    // TODO: assertions
    maxRange = centerPos + max;
    minRange = centerPos - min;
    servo.attach(pin);
};

Neck::Neck() {}

Neck::~Neck() {
    servo.detach();
};

void Neck::turnToAngle(int angle) {
    if (angle <= maxRange && angle >= minRange) {
        servo.write(angle);
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