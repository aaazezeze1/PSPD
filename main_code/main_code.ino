#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <HX711_ADC.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

int pos = 0;

void setup() {
  // HX711 setup
  LoadCell.begin();
  LoadCell.start(2000);
  LoadCell.setCalFactor(1000.0);
  lcd.init();
  lcd.backlight();

  // flap setup
  myservo.attach(9);
}

void loop() {
  // weight scale
  LoadCell.update();
  float lcdgramsmet = LoadCell.getData();
  lcd.setCursor(0, 0);
  lcd.print("Weight [g]:");
  lcd.setCursor(0, 1);
  lcd.print(lcdgramsmet);

  /* flap opens when 12 grams. if not 12 grams but at a 180 degree angle flap closes. 
  if grams is not 12 grams and at starting position then the flap stays closed */
  if (lcdgramsmet == 12) {
    for  (pos = 0; pos <= 180; pos += 1) {
      myservo.write(pos);
      break;
    }
  } else {
      for (pos = 180; pos >= 0; pos -= 1) {
        myservo.write(pos);
        break;
      }
  }
}
