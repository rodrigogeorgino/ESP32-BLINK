#define BLYNK_PRINT Serial
#define BLYNK_DEVICE_NAME "Prof Georgino Rodrigo IoT"
#define BLYNK_TEMPLATE_ID "SEU_TEMPLATE_ID"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "SEU_TOKEN";
char ssid[] = "SUA_REDE";
char pass[] = "SUA_SENHA";

int LEDVermelho = 32;
int LEDAmarelo = 26;
int LEDVerde = 13;

BLYNK_WRITE(V0) {
  int valor = param.asInt();
  digitalWrite(LEDVermelho, valor);
}
BLYNK_WRITE(V1) {
  int valor = param.asInt();
  digitalWrite(LEDAmarelo, valor);
}
BLYNK_WRITE(V2) {
  int valor = param.asInt();
  digitalWrite(LEDVerde, valor);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(LEDVermelho, OUTPUT);
  pinMode(LEDAmarelo, OUTPUT);
  pinMode(LEDVerde, OUTPUT);
}

void loop() {
  Blynk.run();
}
