#include<Servo.h>
// LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// paper shredder flap
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

int pos = 0;

//pwede pa tong mabago kasi depending sa weight
char lcdGrams = 0;

void setup() {
  // lcd start
  lcd.init();
  lcd.backlight();
  // servo pin 7
  myservo.attach(7);
}

void loop() {
  // lcd 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Target: 12 grams");
  lcd.setCursor(0,1);
  // dapat magbabago to sa lcd depending sa weight 
  lcd.print(lcdGrams);
  delay(2000);
  lcd.clear();

  //shredder

  //weight

  // open the flap
for (pos=0; pos<=180; pos+=1){
  myservo.write(pos);
  delay(15);
}
  for (pos=180; pos>=0; pos-=1)
  myservo.write(pos);
  delay(15);
}