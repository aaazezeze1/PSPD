// add the libraries needed for the components of the machine to work
#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <HX711_ADC.h>

// assign variables to be used
LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711_ADC LoadCell(4, 5);
Servo servoflap;

// smallest possible value to help stop the n20 from dispensing paper when 0 grams is detected
const float epsilon = 1E-3; 

// motor driver pins and its corresponding connection to arduino pins
int enB = 8;
int in4 = 7;
int in3 = 6;

void setup() {
  // HX711 setup
  LoadCell.begin();
  LoadCell.start(2000);
  // calibration factor to measure grams
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
  // measure weight and change lcd value
  LoadCell.update();
  float lcdgramsmet = LoadCell.getData();
  lcd.setCursor(0, 0);
  lcd.print("Weight [g]:");
  lcd.setCursor(0, 1);
  lcd.print(lcdgramsmet);

  // servo flap
  // if 12 grams is met turn the servo 0 degrees
  // if grams is not 12 then turn the servo 180 degrees or flap will stay at closed position
  if (lcdgramsmet >= 12) {
    servoflap.write(0);
  } else {
    servoflap.write(180);
  }

  // paper dispenser
  // if 12 grams is met then turn the motor on
  // if grams is 0 then stop the motor
  if (lcdgramsmet >= 12) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 255);
  } else if (lcdgramsmet <= epsilon){
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  } else {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}
