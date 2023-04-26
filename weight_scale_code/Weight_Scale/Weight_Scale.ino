#include <HX711_ADC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

HX711_ADC LoadCell(4, 5);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  // weight & turn on lcd
  LoadCell.begin();
  LoadCell.start(2000);
  LoadCell.setCalFactor(1000.0);
  lcd.init();
  lcd.backlight();
}

void loop(){
  LoadCell.update();
  float i = LoadCell.getData();
  lcd.setCursor(0, 0);
  lcd.print("Weight [g]:");
  lcd.setCursor(0, 1);
  lcd.print(i);
}