#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Greenhouse"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

String data = "";

void setup()
{
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();

  if (Serial.available())
  {
    data = Serial.readStringUntil('\n');
    data.trim();

    if (data.startsWith("DATA,"))
    {
      data.remove(0, 5);

      int firstComma = data.indexOf(',');
      int secondComma = data.indexOf(',', firstComma + 1);
      int thirdComma = data.indexOf(',', secondComma + 1);

      if (firstComma > 0 && secondComma > firstComma && thirdComma > secondComma)
      {
        float temperature = data.substring(0, firstComma).toFloat();

        float humidity = data.substring(
          firstComma + 1,
          secondComma
        ).toFloat();

        int moisture = data.substring(
          secondComma + 1,
          thirdComma
        ).toInt();

        int light = data.substring(
          thirdComma + 1
        ).toInt();

        // Send data to Blynk
        Blynk.virtualWrite(V0, temperature);
        Blynk.virtualWrite(V1, humidity);
        Blynk.virtualWrite(V2, moisture);
        Blynk.virtualWrite(V3, light);
      }
    }
  }
}
