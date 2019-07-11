#pragma once

#include <Arduino.h>
#include <Servo.h>

int toPulseMs(int degrees);
int toDegrees(int pulseMs);

struct ServoSettings
{
    int min;
    int max;
    int inputMid;
    bool escStyle;
    int deadzoneRadius;

    private:
    bool inDegrees;

    public:

    ServoSettings();

    bool isInDegrees();
    void convertUnit(bool degrees);
    int mapValue(int value, int low, int high);
    int mapDegrees(int value, int low, int high);
    int mapPulseMs(int value, int low, int high);
    void write(int value, int low, int high, Servo* servo);
};

void save_servo_settings();
void save_servo_settings(bool exists);
void try_load_servo_settings();

extern ServoSettings servoSettings[4];