// LCD - attach sda to pin 4 & scl to pin 5
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//pwede pa tong mabago kasi depending sa weight
int lcdGrams = 0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Target: 12 grams");
  lcd.setCursor(0,1);
  // dapat magbabago to sa lcd depending sa weight 
  lcd.print("Weight: ");
  lcd.print(lcdGrams);
  lcd.print(" grams");
  delay(2000);
  lcd.clear();
}
