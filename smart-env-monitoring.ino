#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT setup
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Output pins
#define TEMP_PIN 2
#define LDR_PIN 3
#define HUM_PIN 4
#define MOIS_PIN 5

void setup()
{
  Serial.begin(9600);

  pinMode(TEMP_PIN, OUTPUT);
  pinMode(LDR_PIN, OUTPUT);
  pinMode(HUM_PIN, OUTPUT);
  pinMode(MOIS_PIN, OUTPUT);

  // LCD init
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Initializing...");

  dht.begin();
  delay(2000);
}

void loop()
{
  // Read DHT sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check sensor error
  if (isnan(h) || isnan(t))
  {
    Serial.println("DHT Error!");
    return;
  }

  // Read Moisture
  int mois = analogRead(A1);
  mois = map(mois, 0, 1023, 0, 100);

  // Read LDR
  int ldr = analogRead(A0);
  ldr = map(ldr, 0, 1023, 0, 100);

  // LCD Display
  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(h, 0);
  lcd.print("% ");

  lcd.print("M:");
  lcd.print(mois);
  lcd.print("% ");

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(t, 0);
  lcd.print("C ");

  lcd.print("L:");
  lcd.print(ldr);
  lcd.print("% ");

  // Control Logic - SAME AS ORIGINAL
  digitalWrite(TEMP_PIN, (t > 40) ? HIGH : LOW);
  digitalWrite(HUM_PIN, (h > 50) ? HIGH : LOW);
  digitalWrite(MOIS_PIN, (mois < 60) ? HIGH : LOW);
  digitalWrite(LDR_PIN, (ldr < 70) ? HIGH : LOW);

  // Serial Output
  Serial.print("DATA,");
  Serial.print(t);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.print(mois);
  Serial.print(",");
  Serial.println(ldr);

  delay(2000);
}
