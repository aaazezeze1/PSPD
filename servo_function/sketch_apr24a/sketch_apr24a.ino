#include <Wire.h>
#include <Servo.h>

Servo myservo;
int pos = 0;

// kapag 12 to magbubukas yung flap pero kapag less than 12 magsasarado siya if nasa 180 degrees na or hindi siya gagalaw
float lcdgramsmet = 4;

void setup() {
  myservo.attach(9);
}

void loop() {
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