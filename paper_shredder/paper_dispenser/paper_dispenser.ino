#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servoflap;

float lcdgrams = 12;
bool gramsmet = false;

int enB = 8;
int in4 = 7;
int in3 = 6;

void setup() {
  lcd.init();
  lcd.backlight();

  servoflap.attach(9);

  pinMode(enB, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Target: 12 grams");
  lcd.setCursor(0, 1);
  lcd.print("Weight: ");
  //dapat mag change to based sa hx711
  lcd.print(lcdgrams);
  delay(2000);

  if (gramsmet == false) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  } else {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 255);
    delay(3000);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}