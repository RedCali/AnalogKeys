// include the library code:

// LCD 4884 Shield:
//https://rydepier.wordpress.com/2016/03/30/arduino-and-nokia-lcd4884-display-shield/


// include the library code:
// Include LCD Library
#include <LCD8448.h>
/*
// PIN Definitions for SPI Interface --- using Arduino NOKIA LCD shield
LCD_BL   7 // Backlight control (Arduino DIO Pin 7)
SPI_SCK  2 // Serial Clock(Master Output)
SPI_MOSI 3 // Master Output,Slave Input
LCD_DC   4 // Data/Command(command active low)
SPI_CS   5 // Chip Select,Slave Transmit Enable(active low,Master Output)
LCD_RST  6 // Reset & Reset Button
*/
LCD8448::LCD_Display _displayHighlight = LCD8448::NORMAL;
LCD8448 lcd(LCD8448::MODE_REGULAR, LCD8448::NORMAL);


#include "AnalogKeys.h"
#define JOYSTICK_PIN 0
 int  adc_key_val[5] ={
 50, 200, 400, 600, 800 }; 

AnalogKeys<130,160, 490,530, 0,60, 730,760, 320,350, false> analogKey;
uint16_t yOld;

void setup() {
  Serial.begin(115200);
  
  Serial.println("Init Display....");
  lcd.init();
  // Write constant strings into the display
  lcd.write_string(1 * 6 + 3, 0, "Hello", LCD8448::NORMAL);
  lcd.write_string(8 * 6 - 3, 0, "World", LCD8448::INVERTED);
  // Switch on the Backlight of the LCD
  lcd.setBacklightON();
  lcd.write_string(24, 3, "Press Key:", LCD8448::NORMAL);
}
void loop() {
  uint16_t x;
  x = analogRead(JOYSTICK_PIN);
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
   
    lcd.write_string(24, 4, analogKey.GetString(y), LCD8448::NORMAL);
  }
  yOld = y;
}
