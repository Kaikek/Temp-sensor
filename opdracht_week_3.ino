#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTPIN1 7

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
DHT dhtt(DHTPIN1, DHTTYPE);

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x3F
#define BACKLIGHT_PIN 3
LiquidCrystal_I2C lcd(0x27,16,2);

//LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  Serial.begin(9600);
  dht.begin();
  dhtt.begin();

  lcd.init();      
  lcd.backlight();
  lcd.setBacklight(HIGH);
}

void loop() {
  
  delay(2000);

  float t = dht.readTemperature();
  delay(1000);
  float x =  dhtt.readTemperature();

  lcd.setCursor(0,0);
  Serial.print(F("Temperature: "));
  lcd.print(t);
  Serial.print(t);
  Serial.print(F("*C\n"));
  lcd.print("*C");

  lcd.setCursor(0,1);
  Serial.print(F("Temperature: "));
  Serial.print(x);
  lcd.print(x);
  Serial.print(F("*C\n"));
  lcd.print("*C");
  Serial.print("\n");
}