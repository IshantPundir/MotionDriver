#ifndef STEPPER_H
#define STEPPER_H

enum DIRECTION {
    RIGHT,
    LEFT
};

class Stepper {
    public:
        Stepper(int stepPin, int dirPin, int enablePin);
        Stepper();
        ~Stepper();
        
        void turn(int angle, int speed);
        void release();
        void run();
        void test();

    private:
        int stepPin;
        int dirPin;
        int enablePin;
        unsigned long lastStepTime;
        DIRECTION turningDirection; // Flag to set motor direction;

        bool isEnabled = false;
        bool isMoving = false;
        int currentStep = 0;
        int targerStep = 0;

        unsigned long  stepDelay = 500; // in microseconds...
        int stepsPerRev = 1180; // 200(steps/rev for stepper motor) * 5.9 (gear ratio)
        int stepsPerDeg = stepsPerRev / 360.0;
        
        void setEnable(bool);
        void setDirection(DIRECTION);
        void step();
};

#endif