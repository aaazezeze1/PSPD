#include <Wire.h>
#include <HX711_ADC.h>

HX711_ADC LoadCell(4, 5);

void setup() {
  
  LoadCell.begin();
  LoadCell.start(2000);
  LoadCell.setCalFactor(100.0);
}

void loop() {
  LoadCell.update();
  float i = LoadCell.getData();
  Serial.println(i);
}
