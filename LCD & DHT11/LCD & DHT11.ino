#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  dht.begin();
  lcd.backlight();
  lcd.print("Hello, world!");
}

void loop() {
  lcd.clear();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  delay(1000);
}
