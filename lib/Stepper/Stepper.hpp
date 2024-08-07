#ifndef STEPPER_H
#define STEPPER_H

class Stepper {
    public:
        Stepper(int stepPin, int dirPin, int enablePin);
        Stepper();
        ~Stepper();
        
        void setSpeed(int speed);
        void turn(int angle);
        void run();

    private:
        int stepPin;
        int dirPin;
        int enablePin;
        unsigned long lastStepTime;

        bool isEnabled = false;
        bool isMoving = false;
        int currentStep = 0;
        int targerStep = 0;

        int stepDelay = 500; // in microseconds...
        int stepsPerRev = 200 * 5;

        void setEnable(bool);
};

#endif