#define BLYNK_PRINT Serial
#define BLYNK_DEVICE_NAME "Prof Georgino Rodrigo IoT"
#define BLYNK_TEMPLATE_ID "SEU_TEMPLATE_ID"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "SEU_TOKEN";
char ssid[] = "SUA_REDE";
char pass[] = "SUA_SENHA";

int ventilador = 2;
int lampada = 4;

BLYNK_WRITE(V0) {
  int valor = param.asInt();
  digitalWrite(ventilador, valor);
}
BLYNK_WRITE(V1) {
  int valor = param.asInt();
  digitalWrite(lampada, valor);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(ventilador, OUTPUT);
  pinMode(lampada, OUTPUT);
}

void loop() {
  Blynk.run();
}
