#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "SEU_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "Prof Georgino Rodrigo IoT"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = "SEU_TOKEN";
char ssid[] = "SUA_REDE";
char pass[] = "SUA_SENHA";

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) return;
  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V6, t);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
