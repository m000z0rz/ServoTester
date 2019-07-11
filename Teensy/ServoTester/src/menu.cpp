#include <Arduino.h>
#include <LiquidCrystal.h>
#include "menu.h"
#include "pin_assignments.h"
#include "global.h"
#include "ServoSettings.h"

#define ARROW_CHAR 0

#define NUM_SETTINGS 6
#define SETTING_STYLE 0
#define SETTING_MIN 1
#define SETTING_MAX 2
#define SETTING_MID 3
#define SETTING_DEADZONE 4
#define SETTING_DEGPMS 5

#define NUM_SYSITEMS 6
#define SYSITEM_JOYX 0
#define SYSITEM_JOYY 1
#define SYSITEM_ROLL 2
#define SYSITEM_PITCH 3
#define SYSITEM_SAVE 4
#define SYSITEM_RESET 5

// MENU_INPUT_DELAY in ms
#define MENU_INPUT_DELAY 250
#define MENU_INPUT_DEADZONE_RADIUS 10
#define MENU_INPUT_MID 144

#define COL_SERVO_CURSOR 0
#define COL_SERVO_ID COL_SERVO_CURSOR + 1
#define COL_SERVO_VALUE COL_SERVO_ID + 2
#define COL_VBAR COL_SERVO_VALUE + 5
#define COL_SETTING_CURSOR COL_VBAR + 1
#define COL_SETTING COL_SETTING_CURSOR + 1

#define COL_SYS_CURSOR 0
#define COL_SYS_ITEM 1
#define COL_SYS_VBAR COL_SYS_ITEM + 10
#define COL_SYS_SERVO_CURSOR COL_SYS_VBAR + 1
#define COL_SYS_SERVO_ID COL_SYS_SERVO_CURSOR + 1
#define COL_SYS_SERVO_VALUE COL_SYS_SERVO_ID + 2


#define LIST_SYSTEM 0
#define LIST_SERVOS 1
#define LIST_SETTINGS 2


LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_EN, PIN_LCD_D0, PIN_LCD_D1, PIN_LCD_D2, PIN_LCD_D3);

int servo = 0; // currently selected servo index, 0-3
int list = LIST_SERVOS; // current column of things; system/nunchuck, servos, settings
int systemItem = 0;
int setting = -1; // currently selected setting index. -1 if cursor is on a servo / system
int settingScroll = 0; // index of top visible setting line; 0 means scrolled to top, NUM_SETTINGS - 4 means bottom
int systemScroll = 0;

unsigned long lastInput = 0;

byte arrowChar[8] = {
  B10000,
  B11000,
  B11100,
  B11110,
  B11100,
  B11000,
  B10000,
};

/*
======================
|>1 xxxx | @srv esc  |
| 2 xxxx |*min xxxx  |
| 3 xxxx | max xxxx  |
| 4 xxxx | mid xxxx  |s
======================
|        | dzr xxxx  |
|        | @deg pms  |
*/

/*
======================
| joyx xxxx |>1 xxxx |
| joyy xxxx | 2 xxxx |
| roll xxxx | 3 xxxx |
| ptch xxxx | 4 xxxx |
======================
| save               |
| reset              |
|                    |
*/

void init_main_screen();
void init_system_screen();
void lcd_write_4(int n);
void draw_servo_ids();
void draw_servo_values();
void draw_settings();
void draw_setting(int drawSetting);
void draw_system_items();
void draw_system_item(int drawSystemItem);
void draw_vbar();
void draw_cursor();
void clear_cursor();
void clear_cursor_to_arrow();
void scroll_to_setting(int newSetting);
void scroll_to_system_item(int newSystemItem);


void menu_init()
{
    lcd.begin(20, 4);
    lcd.createChar(ARROW_CHAR, arrowChar);

    init_main_screen();
}

void init_main_screen()
{
    lcd.clear();
    draw_servo_ids();
    draw_vbar();
    draw_settings();
    draw_cursor();
}

void init_system_screen()
{
    lcd.clear();
    draw_servo_ids();
    draw_vbar();
    draw_system_items();
    draw_cursor();
}

void menu_loop(int inputX, int inputY, bool changeButton)
{
    // assume inputX and Y are 0-255, with deadzone around 128, +/- 20?

    // always draw servo values
    draw_servo_values();

    if (list == LIST_SYSTEM)
    {
        draw_system_items();
    }

    if (millis() - lastInput < MENU_INPUT_DELAY)
    {
        return;
    }

    int left, right, down, up;
    left = right = down = up = 0;
    left = inputX < MENU_INPUT_MID - MENU_INPUT_DEADZONE_RADIUS ? inputX : 0;
    right = inputX > MENU_INPUT_MID + MENU_INPUT_DEADZONE_RADIUS ? inputX : 0;
    down = inputY < MENU_INPUT_MID - MENU_INPUT_DEADZONE_RADIUS ? inputY : 0;
    up = inputY > MENU_INPUT_MID + MENU_INPUT_DEADZONE_RADIUS ? inputY : 0;
    

    // make sure there is some input
    if (!left && !right && !down && !up)
    {
        return;
    }

    // At this point, there is SOME input we'll use
    lastInput = millis();

    if (!changeButton)
    {
        MenuDirection direction = MenuDirectionNone;

        // move cursor
        if (left)
        {
            direction = MenuDirectionLeft;
        }
        else if (right)
        {
            direction = MenuDirectionRight;
        }
        else if (up)
        {
            direction = MenuDirectionUp;
        }
        else if (down)
        {
            direction = MenuDirectionDown;
        }

        if (direction == MenuDirectionRight && list == LIST_SERVOS)
        {
            // move from servo list to settings
            clear_cursor_to_arrow();
            setting = 0;
            list = LIST_SETTINGS;
            settingScroll = 0;
            draw_cursor();
        }
        else if (direction == MenuDirectionLeft && list == LIST_SETTINGS)
        {
            // move from settings list to servo list
            clear_cursor();
            setting = -1;
            list = LIST_SERVOS;
            scroll_to_setting(0);
            draw_cursor();
        }
        else if (direction == MenuDirectionLeft && list == LIST_SERVOS)
        {
            list = LIST_SYSTEM;
            systemItem = 0;
            systemScroll = 0;
            init_system_screen();
        }
        else if (direction == MenuDirectionRight && list == LIST_SYSTEM)
        {
            list = LIST_SERVOS;
            settingScroll = 0;
            init_main_screen();
        }

        else if (direction == MenuDirectionUp && list == LIST_SERVOS)
        {
            // up through servos
            clear_cursor();
            servo = (servo + 3) % 4;
            draw_cursor();
            draw_settings();
        }
        else if (direction == MenuDirectionDown && list == LIST_SERVOS)
        {
            // down through servos
            clear_cursor();
            servo = (servo + 1) % 4;
            draw_cursor();
            draw_settings();
        }
        else if (direction == MenuDirectionUp && list == LIST_SETTINGS)
        {
            // up through settings
            clear_cursor();
            setting = (setting + NUM_SETTINGS - 1) % NUM_SETTINGS;
            scroll_to_setting(setting);
            draw_cursor();
        }
        else if (direction == MenuDirectionDown && list == LIST_SETTINGS)
        {
            // down through settings
            clear_cursor();
            setting = (setting + 1) % NUM_SETTINGS;
            scroll_to_setting(setting);
            draw_cursor();
        }
        else if (direction == MenuDirectionUp && list == LIST_SYSTEM)
        {
            // up through system
            clear_cursor();
            systemItem = (systemItem + NUM_SYSITEMS - 1) % NUM_SYSITEMS;
            scroll_to_system_item(systemItem);
            draw_cursor();
        }
        else if (direction == MenuDirectionDown && list == LIST_SYSTEM)
        {
            // down through system
            clear_cursor();
            systemItem = (systemItem + 1) % NUM_SYSITEMS;
            scroll_to_system_item(systemItem);
            draw_cursor();
        }
    }
    else
    {
        // Change
        if (list == LIST_SERVOS)
        {
            return;
        }

        if (list == LIST_SETTINGS)
        {
            if (setting == SETTING_STYLE)
            {
                if (!servoSettings[servo].escStyle && right)
                {
                    servoSettings[servo].escStyle = true;
                    draw_setting(setting);
                }
                else if (servoSettings[servo].escStyle && left)
                {
                    servoSettings[servo].escStyle = false;
                    draw_setting(setting);
                }
            }
            else if (setting == SETTING_DEGPMS)
            {
                if (servoSettings[servo].isInDegrees() && right)
                {
                    servoSettings[servo].convertUnit(false);
                    draw_setting(setting);
                }
                else if (!servoSettings[servo].isInDegrees() && left)
                {
                    servoSettings[servo].convertUnit(true);
                    draw_setting(setting);
                }
            }
            else
            {
                int *settingValue = 0;
                if (setting == SETTING_MIN)
                    settingValue = &servoSettings[servo].min;
                else if (setting == SETTING_MAX)
                    settingValue = &servoSettings[servo].max;
                else if (setting == SETTING_MID)
                    settingValue = &servoSettings[servo].inputMid;
                else if (setting == SETTING_DEADZONE)
                    settingValue = &servoSettings[servo].deadzoneRadius;
                
                if (settingValue == 0)
                {
                    return;
                }

                int delta = 0;
                delta += right ? map(inputX, MENU_INPUT_MID + MENU_INPUT_DEADZONE_RADIUS, 255, 1, 3) : 0;
                delta += left ? map(inputX, 0, MENU_INPUT_MID - MENU_INPUT_DEADZONE_RADIUS, -3, -1) : 0;

                delta += up ? map(inputY, 128 + MENU_INPUT_DEADZONE_RADIUS, 255, 10, 30) : 0;
                delta += down ? map(inputY, 0, 128 - MENU_INPUT_DEADZONE_RADIUS, -10, -30) : 0;

                *settingValue = max(0, *settingValue + delta);
                draw_setting(setting);
            }
        }
        
        else if (list == LIST_SYSTEM)
        {
            Serial.println("change in system");
            if (systemItem == SYSITEM_SAVE)
            {
                Serial.println("catch save");
            }
            switch (systemItem)
            {
                case SYSITEM_SAVE:
                    Serial.println("saving");
                    save_servo_settings();
                    pinMode(11, OUTPUT);
                    digitalWrite(11, HIGH);
                    delay(1000);
                    digitalWrite(11, LOW);
                    delay(1000);
                    break;
                case SYSITEM_RESET:
                    servoSettings[0] = ServoSettings();
                    servoSettings[1] = ServoSettings();
                    servoSettings[2] = ServoSettings();
                    servoSettings[3] = ServoSettings();
                    save_servo_settings(false);
                    break;
            }
        }
        Serial.println("post change");
    }
}

void menu_loop_values()
{
    draw_servo_values();

    if (list == LIST_SYSTEM)
    {
        draw_system_items();
    }
}

void scroll_to_setting(int newSetting)
{
    int oldScroll = settingScroll;
    if (newSetting < oldScroll)
    {
        // scroll up to see it
        settingScroll = newSetting;
    }
    else if (newSetting > oldScroll + 3)
    {
        // scroll down to see it
        settingScroll = newSetting - 3;
    }
    if (oldScroll != settingScroll)
    {
        draw_settings();
    }
}

void scroll_to_system_item(int newSystemItem)
{
    int oldScroll = systemScroll;
    if (newSystemItem < oldScroll)
    {
        // scroll up to see it
        systemScroll = newSystemItem;
    }
    else if (newSystemItem > oldScroll + 3)
    {
        // scroll down to see it
        systemScroll = newSystemItem - 3;
    }

    if (oldScroll != systemScroll)
    {
        draw_system_items();
    }
}

void draw_settings()
{
    for (int i = settingScroll; i < settingScroll + 4; i++)
    {
        draw_setting(i);
    }
}

void draw_setting(int drawSetting)
{
    int row = drawSetting - settingScroll;
    lcd.setCursor(COL_SETTING, row);

    if (drawSetting == SETTING_STYLE)
    {
        if (servoSettings[servo].escStyle)
        {
            lcd.print(" srv ");
            lcd.write(byte(ARROW_CHAR));
            lcd.print("esc");
        }
        else
        {
            lcd.write(byte(ARROW_CHAR));
            lcd.print("srv  esc");
        }
    }
    else if (drawSetting == SETTING_DEGPMS)
    {
        if (servoSettings[servo].isInDegrees())
        {
            lcd.write(byte(ARROW_CHAR));
            lcd.print("deg  pms");
        }
        else
        {
            lcd.print(" deg ");
            lcd.write(byte(ARROW_CHAR));
            lcd.print("pms");
        }
    }
    else if (drawSetting == SETTING_MIN)
    {
        lcd.print("min ");
        lcd_write_4(servoSettings[servo].min);
        lcd.print(" ");
    }
    else if (drawSetting == SETTING_MAX)
    {
        lcd.print("max ");
        lcd_write_4(servoSettings[servo].max);
        lcd.print(" ");
    }
    else if (drawSetting == SETTING_MID)
    {
        lcd.print("mid ");
        lcd_write_4(servoSettings[servo].inputMid);
        lcd.print(" ");
    }
    else if (drawSetting == SETTING_DEADZONE)
    {
        lcd.print("dzr ");
        lcd_write_4(servoSettings[servo].deadzoneRadius);
        lcd.print(" ");
    }
}

void draw_system_items()
{
    for (int i = systemScroll; i < systemScroll + 4; i++)
    {
        draw_system_item(i);
    }
}

void draw_system_item(int drawSystemItem)
{
    int row = drawSystemItem - systemScroll;
    lcd.setCursor(COL_SYS_ITEM, row);

    if (drawSystemItem == SYSITEM_JOYX)
    {
        lcd.print("joyX ");
        lcd_write_4(nunchuck.getJoyX());
        lcd.print(" ");
    }
    else if (drawSystemItem == SYSITEM_JOYY)
    {
        lcd.print("joyY ");
        lcd_write_4(nunchuck.getJoyY());
        lcd.print(" ");
    }
    else if (drawSystemItem == SYSITEM_ROLL)
    {
        lcd.print("roll ");
        lcd_write_4(nunchuck.getRollAngle());
        lcd.print(" ");
    }
    else if (drawSystemItem == SYSITEM_PITCH)
    {
        lcd.print("ptch ");
        lcd_write_4(nunchuck.getPitchAngle());
        lcd.print(" ");
    }
    else if (drawSystemItem == SYSITEM_SAVE)
    {
        lcd.print("save      ");
    }
    else if (drawSystemItem == SYSITEM_RESET)
    {
        lcd.print("reset     ");
    }
}

void draw_servo_ids()
{
    int col = list == LIST_SYSTEM ? COL_SYS_SERVO_ID : COL_SERVO_ID;

    lcd.setCursor(col, 0); lcd.write('1');
    lcd.setCursor(col, 1); lcd.write('2');
    lcd.setCursor(col, 2); lcd.write('3');
    lcd.setCursor(col, 3); lcd.write('4');
}

void draw_servo_values()
{
    int col = list == LIST_SYSTEM ? COL_SYS_SERVO_VALUE : COL_SERVO_VALUE;
    for (int i = 0; i < 4; i++)
    {
        lcd.setCursor(col, i);
        if (servoSettings[i].isInDegrees())
        {
            lcd_write_4(servos[i].read());
        }
        else
        {
            lcd_write_4(servos[i].readMicroseconds());
        }
    }
}

void draw_vbar()
{
    int col = list == LIST_SYSTEM ? COL_SYS_VBAR : COL_VBAR;
    lcd.setCursor(col, 0); lcd.write('|');
    lcd.setCursor(col, 1); lcd.write('|');
    lcd.setCursor(col, 2); lcd.write('|');
    lcd.setCursor(col, 3); lcd.write('|');
}

void get_cursor_pos(int *col, int *row)
{
    if (list == LIST_SYSTEM)
    {
        *col = COL_SYS_CURSOR;
        *row = systemItem - systemScroll;
    }
    else if (list == LIST_SERVOS)
    {
        *col = COL_SERVO_CURSOR;
        *row = servo;
    }
    else
    {
        *col = COL_SETTING_CURSOR;
        *row = setting - settingScroll;
    }
}

void clear_cursor()
{
    int col, row;
    get_cursor_pos(&col, &row);
    lcd.setCursor(col, row);
    lcd.print(" ");
}

void clear_cursor_to_arrow()
{
    int col, row;
    get_cursor_pos(&col, &row);
    lcd.setCursor(col, row);
    lcd.write(byte(ARROW_CHAR));
}

void draw_cursor()
{
    int col, row;
    get_cursor_pos(&col, &row);
    lcd.setCursor(col, row);
    lcd.print(">");
}

void lcd_write_4(int n)
{
  if (n > 9999 || n < -999)
  {
      lcd.print("^^^^");
  }
  if (n > 999)
  {

  }
  else if (n > 99)
  {
    lcd.print(" ");
  }
  else if (n > 9)
  {
    lcd.print("  ");
  }
  else if (n >= 0)
  {
    lcd.print("   ");
  }
  else if (n >= -9)
  {
      lcd.print("  ");
  }
  else if (n >= -99)
  {
      lcd.print(" ");
  }
  else
  {

  }
  
  
  lcd.print(n);
}