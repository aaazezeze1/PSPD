#include <HX711_ADC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

HX711_ADC LoadCell(4, 5);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  LoadCell.begin();
  LoadCell.start(2000);
  LoadCell.setCalFactor(0.00);
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





// #include <HX711_ADC.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// HX711_ADC LoadCell(4, 5);
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// int taree = 6;
// int a = 0;
// float b = 0;

// void setup() {
//   pinMode(taree, INPUT_PULLUP);
//   LoadCell.begin();
//   LoadCell.start(1000);
//   LoadCell.setCalFactor(500);

//   lcd.backlight();
//   lcd.setCursor(1, 0);
//   lcd.print("Digital Scale ");
//   lcd.setCursor(0, 1);
//   lcd.print(" 1 KG MAX LOAD");
//   delay(3000);
//   lcd.clear();
// }

// void loop() {
//   lcd.setCursor(1, 0); // set cursor to first row
//   lcd.print("Digital Scale "); // print out to LCD 
//   LoadCell.update(); // retrieves data from the load cell
//   float i = LoadCell.getData(); // get output value
//  if (i<0)
//  {
//   i = i * (-1);
//   lcd.setCursor(0, 1);
//   lcd.print("-");
//    lcd.setCursor(8, 1);
//   lcd.print("-");
//  }
//  else
//  {
//    lcd.setCursor(0, 1);
//   lcd.print(" ");
//    lcd.setCursor(8, 1);
//   lcd.print(" ");
//  }
  
//   lcd.setCursor(1, 1); // set cursor to secon row
//   lcd.print(i, 1); // print out the retrieved value to the second row
//   lcd.print("g ");
//   float z = i/28.3495;
//   lcd.setCursor(9, 1);
//   lcd.print(z, 2);
//   lcd.print("oz ");

//   if (i>=5000)
//   {
//     i=0;
//   lcd.setCursor(0, 0); // set cursor to secon row
//   lcd.print("  Over Loaded   "); 
//   delay(200);
//   }
//   if (digitalRead (taree) == LOW)
//   {
//     lcd.setCursor(0, 1); // set cursor to secon row
//     lcd.print("   Taring...    ");
//     LoadCell.start(1000);
//     lcd.setCursor(0, 1);
//     lcd.print("                ");
//   }
// }
