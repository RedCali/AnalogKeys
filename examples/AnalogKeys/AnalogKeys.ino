// include the library code:

// LCD 4884 Shield:
//https://rydepier.wordpress.com/2016/03/30/arduino-and-nokia-lcd4884-display-shield/


// LCD 44780 shield
#include "AnalogKeys.h"
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

AnalogKeys<720,730, 0,10, 480,490, 130,140, 310,320, false> analogKey;
uint16_t yOld;


void setup() {
  Serial.begin(115200);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("LCD Key Shield");
  Serial.println("LCD Key Shield start");
  lcd.setCursor(0, 1);
  lcd.print("Press Key:");
}
void loop() {
  uint16_t x;
  x = analogRead(0);
  uint16_t y = analogKey.Read(x);
  
  if (y != yOld) {
    Serial.print("x = ");
    Serial.println(x);
    Serial.print("analogKey = " );
    Serial.print(y);
    Serial.print(" / ");
    Serial.print(yOld);
    Serial.print(" / ");
    Serial.println(analogKey.GetString(y));

    lcd.setCursor(10, 1);
    lcd.print(analogKey.GetString(y));
  }
  yOld = y;
}
