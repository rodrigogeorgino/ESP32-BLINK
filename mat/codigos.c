//Projeto 1: Sequencial de LEDs
//Controlaremos três LEDs (Vermelho, Amarelo e Verde) utilizando o aplicativo Blynk via Wi-Fi.
/*LED Vermelho: Porta digital D32 (com resistor de 1kΩ). Pino Virtual: V0.
LED Amarelo: Porta digital D26 (com resistor de 1kΩ). Pino Virtual: V1.
LED Verde: Porta digital D13 (com resistor de 1kΩ). Pino Virtual: V2.*/
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

//Projeto 2: Ligando Lâmpada e Ventilador (Módulo Relé)
//Utiliza um Módulo Relé de 2 canais para acionar cargas de potência (lâmpada e ventilador).

//VCC (Relé): Conectado ao pino Vin (5V).
//GND (Relé): Conectado ao GND.
//IN1 (Relé): Conectado ao pino digital D4 (Lâmpada). Pino Virtual: V1.
//IN2 (Relé): Conectado ao pino digital D2 (Ventilador). Pino Virtual: V0.
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

//O 3 Projeto
//Projeto 3: Estação de Monitoramento de Temperatura e Umidade (DHT11)
//O sensor DHT11 permite medir a temperatura ambiente e a umidade relativa do ar através de um barramento digital único.
//
//Esquema de Montagem:
//VCC (DHT11): 3V3 do ESP-32
//DATA / OUT: GPIO 4 do ESP-32
//GND: GND do ESP-32
//Instalação das Bibliotecas Necessárias:
//Instale no Gerenciador de Bibliotecas: DHT sensor library por Adafruit e Adafruit Unified Sensor.

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
