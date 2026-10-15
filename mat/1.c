//Projeto 1: Sequencial de LEDs
//Controlaremos três LEDs (Vermelho, Amarelo e Verde) utilizando o aplicativo Blynk via Wi-Fi.
/*
LED Vermelho: Porta digital D32 (com resistor de 1kΩ). Pino Virtual: V0.
LED Amarelo: Porta digital D26 (com resistor de 1kΩ). Pino Virtual: V1.
LED Verde: Porta digital D13 (com resistor de 1kΩ). Pino Virtual: V2.

*/  
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
