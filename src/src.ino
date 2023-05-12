#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <HX711_ADC.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711_ADC LoadCell(4, 5);
Servo servoflap;

int enB = 8;
int in4 = 7;
int in3 = 6;

void setup() {
  // HX711 setup
  LoadCell.begin();
  LoadCell.start(2000);
  LoadCell.setCalFactor(1816.64);
  lcd.init();
  lcd.backlight();

  // flap setup
  servoflap.attach(9);

  //paper dispenser setup
  pinMode(enB, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);

}

void loop() {
  // weight scale
  LoadCell.update();
  float lcdgramsmet = LoadCell.getData();
  lcd.setCursor(0, 0);
  lcd.print("Weight [g]:");
  lcd.setCursor(0, 1);
  lcd.print(lcdgramsmet);

  // servo flap
  if (lcdgramsmet >= 12) {
    servoflap.write(0);
  } else {
    servoflap.write(180);
  }

  //paper dispenser
  if (lcdgramsmet == 12) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 255);
    delay(3000);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
   } else {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

}