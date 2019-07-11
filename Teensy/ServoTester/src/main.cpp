#include <Arduino.h>
#include <WiiChuck.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include "ServoSettings.h"
#include "menu.h"
#include "pin_assignments.h"
#include "global.h"

#define NUNCHUCK_REBEGIN_DELAY 3000

uint32_t last_nunchuck_begin = 0;

void setup() {
  Serial.begin(115200);

  try_load_servo_settings();

  nunchuck.begin();
  nunchuck.type = NUNCHUCK;
  if (nunchuck.type == Unknown)
  {
    nunchuck.type = NUNCHUCK;
  }

  menu_init();
}

void attachServos()
{
  servos[0].attach(PIN_SERVO_1);
  servos[1].attach(PIN_SERVO_2);
  servos[2].attach(PIN_SERVO_3);
  servos[3].attach(PIN_SERVO_4);
}

void detachServos()
{
  servos[0].detach();
  servos[1].detach();
  servos[2].detach();
  servos[3].detach();
}

bool lastButtonZ = false;

void loop() {
  // if (last_nunchuck_begin + NUNCHUCK_REBEGIN_DELAY > millis())
  // {
  //   nunchuck.begin();
  //   last_nuchuck_begin = millis();
  // }

  nunchuck.readData();
  Serial.println("hihihi");
  
  // nunchuck.getJoyX(); // 0-1024 for most of these?
  // nunchuck.getJoyY();
  // nunchuck.getRollAngle(); // also, AccelX/Y/Z
  // nunchuck.getPitchAngle();
  // nunchuck.getButtonC();
  // nunchuck.getButtonZ();

  //nunchuck.printInputsNunchuck();

  if (nunchuck.getButtonZ())
  {
    if (lastButtonZ == false)
    {
      // buttonZDown
      attachServos();
    }
    lastButtonZ = true;

    // drive servos
    servoSettings[0].write(nunchuck.getJoyX(), 0, 255, &servos[0]);
    servoSettings[1].write(nunchuck.getJoyY(), 0 , 255, &servos[1]);
    servoSettings[2].write(nunchuck.getRollAngle(), -45, 45, &servos[2]);
    servoSettings[3].write(nunchuck.getPitchAngle(), -45, 45, &servos[3]);

    menu_loop_values();
  }
  else {
    if (lastButtonZ == true)
    {
      // buttonZUp
      detachServos();
    }
    lastButtonZ = false;

    // navigate menu
    menu_loop(nunchuck.getJoyX(), nunchuck.getJoyY(), nunchuck.getButtonC());
  }
}
