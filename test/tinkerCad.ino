#include <Adafruit_LiquidCrystal.h>

// C++ code
//

int rs = 7, en = 6;
int d4 = 5, d5 = 4, d6 = 3, d7 = 2;

Adafruit_LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int counter;
int counterState = 0;
int pushButton = 8;
bool previousButtonLevel = LOW;
bool currentButtonLevel = LOW;

void setup()
{
  // pinMode(LED_BUILTIN, OUTPUT);
  lcd.begin(16, 2);
  pinMode(pushButton, INPUT_PULLUP);
}

void loop()
{
  /* digitalWrite(LED_BUILTIN, HIGH);
     delay(1000); // Wait for 1000 millisecond(s)
     digitalWrite(LED_BUILTIN, LOW);
     delay(1000); // Wait for 1000 millisecond(s)
  */
  
  previousButtonLevel = currentButtonLevel;
  currentButtonLevel = digitalRead(pushButton);
  
  
  if(currentButtonLevel == LOW && previousButtonLevel == HIGH)
  {
    counter++;
  }
  
  if(counter == 34)
  {
    lcd.clear();
    counter = 0;
    counterState++;
  }
  
  switch(counterState)
  {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("Allahu akbar :");
        lcd.setCursor(7, 1);
        lcd.print(counter);
        break;
    case 1:
        lcd.setCursor(0, 0);
        lcd.print("subhanallah :");
        lcd.setCursor(7, 1);
        lcd.print(counter);
        break;
    case 2:
        lcd.setCursor(0, 0);
        lcd.print("hamdoulilah :");
        lcd.setCursor(7, 1);
        lcd.print(counter);
        break;
    case 3:
    	lcd.setCursor(5, 0);
  		lcd.print("BRAVO !");
  }
}