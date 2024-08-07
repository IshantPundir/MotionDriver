#ifndef NECK_H
#define NECK_H
#include <Servo.h>

class Neck {
    public:
        Neck(int pin, int max, int min, int center);
        Neck();
        ~Neck();

        void center();
        void turnToAngle(int angle);
        void step(int value);

    private:
        Servo neckServo;
        int servoPin;
        int maxRange;
        int minRange;
        int centerPos;
};
#endif