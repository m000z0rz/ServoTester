#pragma once

#include <Arduino.h>
#include <LiquidCrystal.h>

#define MENU_UP 0;
#define MENU_DOWN 1;
#define MENU_LEFT 2;
#define MENU_RIGHT 3;

enum MenuDirection
{
    MenuDirectionNone,
    MenuDirectionUp,
    MenuDirectionDown,
    MenuDirectionLeft,
    MenuDirectionRight
};

void menu_init();

void menu_loop(int inputX, int inputY, bool changeButton);
void menu_loop_values();