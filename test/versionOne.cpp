#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

int rs = 7, en = 6;
int d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int counter;
int counterState = 0;
int pushButton = 8;
bool previousButtonLevel = LOW;
bool currentButtonLevel = LOW;

void setup()
{
  lcd.begin(16, 2);
  pinMode(pushButton, INPUT_PULLUP);
}

void loop()
{
  previousButtonLevel = currentButtonLevel;
  currentButtonLevel = digitalRead(pushButton);

  if (currentButtonLevel == LOW && previousButtonLevel == HIGH)
  {
    counter++;
  }

  if (counter == 34)
  {
    lcd.clear();
    counter = 0;
    counterState++;
  }
  
  switch (counterState)
  {
  case 0:
    lcd.setCursor(0, 0);
    lcd.print("Allahu Akbar :");
    lcd.setCursor(7, 1);
    lcd.print(counter);
    break;
  
  case 1:
    lcd.setCursor(0, 0);
    lcd.print("Subhanallah :");
    lcd.setCursor(7, 1);
    lcd.print(counter);
    break;
  
  case 2:
    lcd.setCursor(0, 0);
    lcd.print("Hamdoulilah :");
    lcd.setCursor(7, 1);
    lcd.print(counter);
    break;

  case 3:
    lcd.setCursor(5, 0);
    lcd.print("BRAVO !");
  }
  
}