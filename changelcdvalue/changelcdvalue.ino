#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

float lcdgramsmet = 12;

Servo myservo;
int pos = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();

  myservo.attach(9);
}

void loop() {
  // lcd.setCursor(0,0);
  // lcd.print("Target: 12 grams");
  // lcd.setCursor(0,1);
  // lcd.print("Weight [g]: ");
  // lcd.print(lcdgramsmet);

//  if (lcdgramsmet == 12) {
//     for (pos = 0; pos <= 180; pos += 1) {
//       myservo.write(pos);
//       break;
//     }
//   } else {
//       for  (pos = 180; pos >= 0; pos -= 1) {
//         myservo.write(pos);
//         break;
//       }
//   }

  if (lcdgramsmet == 12){
    for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(10000);
    break; }
  } else {
    for  (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      break;}
  }  
}