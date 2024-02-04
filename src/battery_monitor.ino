#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD I2C address
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int batteryPin = A0; 
const float fullVoltage = 1.8; 
const float emptyVoltage = 1.5;
void setup() {
  lcd.init();                     
  lcd.backlight();                 
  Serial.begin(9600);              
}

void loop() {
  int sensorValue = analogRead(batteryPin);
  float voltage = sensorValue * (5.0 / 1023.0); 
  float percentage = (voltage - emptyVoltage) / (fullVoltage - emptyVoltage) * 100;
  percentage = constrain(percentage, 0, 100); 

 
  Serial.print("Battery Voltage: ");
  Serial.print(voltage, 2); 
  Serial.print("V, Percentage: ");
  Serial.println(percentage, 0); 

 
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(voltage, 2);
  lcd.print("V");
  
  lcd.setCursor(0, 1); 
  lcd.print("Charge: ");
  lcd.print(percentage, 0);
  lcd.print("%");

  delay(2000);
}
