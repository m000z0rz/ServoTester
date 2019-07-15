#include <Arduino.h>
#include <Servo.h>
#include <EEPROM.h>
#include "ServoSettings.h"


#define SAVED_MAGIC 0x73


int toPulseMs(int degrees)
{
    return map(degrees, 0, 180, 544, 2400);
}

int toDegrees(int pulseMs)
{
    return map(pulseMs, 544, 2400, 0, 180);
}

ServoSettings servoSettings[4];



ServoSettings::ServoSettings()
{
    inDegrees = true;

    min = 0;
    max = 180;

    inputMid = 128;

    escStyle = false;

    deadzoneRadius = 20;
}


bool ServoSettings::isInDegrees()
{
    return inDegrees;
}


void ServoSettings::convertUnit(bool degrees)
{
    if (inDegrees && !degrees)
    {
        min = toPulseMs(min);
        max = toPulseMs(max);
    }
    else if (!inDegrees && degrees)
    {
        min = toDegrees(min);
        max = toDegrees(max);
    }

    inDegrees = degrees;
}

int ServoSettings::mapValue(int value, int low, int high)
{
    if (escStyle)
    {
        if (value <= inputMid + deadzoneRadius)
        {
            return min;
        }
        else
        {
            return map(value, inputMid + deadzoneRadius, high, min, max);
        }
    }
    else
    {
        if (value < inputMid - deadzoneRadius)
        {
            return map(value, low, inputMid - deadzoneRadius, min, (min + max) / 2);
        }
        else if (value > inputMid + deadzoneRadius)
        {
            return map(value, inputMid + deadzoneRadius, high, (min + max) / 2, max);
        }
        else
        {
            return (min + max) / 2;
        }
    }
}

int ServoSettings::mapDegrees(int value, int low, int high)
{
    value = inDegrees ? mapValue(value, low, high) : toDegrees(mapValue(value, low, high));
    return value;
}

int ServoSettings::mapPulseMs(int value, int low, int high)
{
    value = inDegrees ? toPulseMs(mapValue(value, low, high)) : mapValue(value, low, high);
    return value;
}

void ServoSettings::write(int value, int low, int high, Servo* servo)
{
    // value is expected to be in the range 0-1023
    value = mapValue(value, low, high);

    if (inDegrees)
    {
        servo->write(value);
    }
    else
    {
        servo->writeMicroseconds(value);    
    }
}

void save_servo_settings()
{
    save_servo_settings(true);
}

void save_servo_settings(bool exists)
{
    if (exists)
    {
        EEPROM.put(0, (uint8_t) SAVED_MAGIC);
        EEPROM.put(1, servoSettings);
    }
    else
    {
        EEPROM.put(0, 0);
    }
}

void try_load_servo_settings()
{
    uint8_t magic;
    EEPROM.get(0, magic);

    if (magic == SAVED_MAGIC)
    {
        EEPROM.get(1, servoSettings);
    }
    else
    {
        // modify the inputMid for roll/pitch
        servoSettings[2].inputMid = 0;
        servoSettings[3].inputMid = 0;
    }
    
}
