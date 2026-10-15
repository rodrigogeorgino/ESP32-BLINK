# ESP32-BLINK
🚀 Repositório didático IOT Usando ESP32 Android Studio e Blink. Para controle via Wi-Fi (Vamos precisar de testers).
# Material de Apoio: Internet das Coisas para Iniciantes com ESP-32

Bem-vindo ao repositório oficial do material prático de **Internet das Coisas (IoT)**, adaptado e supervisionado pelo **Prof. Georgino, Rodrigo (IoT)**.

Este repositório contém todo o conteúdo teórico, diagramas de pinagem, esquemas de montagem e códigos-fonte desenvolvidos para guiar estudantes, hobistas e *makers* no aprendizado prático de automação residencial e sistemas embarcados utilizando a placa **ESP-32**.

---
<img width="1307" height="503" alt="image" src="https://github.com/user-attachments/assets/c34b31cd-aaf3-4dcd-a6ca-c045d4fd782d" />


## 🛠️ Conteúdo do Repositório

O material está estruturado em projetos práticos e progressivos integrados ao aplicativo e à nuvem do **Blynk**:

1. **Sequencial de LEDs:** Controle individual de LEDs via Wi-Fi utilizando pinos digitais do ESP-32.
2. **Ligando Lâmpada e Ventilador:** Acionamento de cargas de potência (corrente alternada) através de Módulo Relé de 2 canais.
3. **Monitoramento de Temperatura e Umidade:** Leitura de dados ambientais em tempo real utilizando o sensor DHT11.
4. **Alerta de Chuva:** Sistema automatizado de detecção de precipitação e envio de alertas/notificações.
5. **Display LCD 16x2 I2C:** Exibição de mensagens customizadas no visor utilizando o protocolo de comunicação I2C.
6. **Controle de Acesso com RFID:** Sistema de segurança residencial utilizando leitor RFID MFRC522 (13,56MHz), tags e sinalização sonora (Buzzer).
7. **Irrigação Automática:** Automação inteligente do cuidado com plantas unindo o sensor de umidade de solo FC-28 e uma mini bomba de água submersa.

---

## 📋 Pré-requisitos e Configuração

Para compilar e enviar os códigos para a sua placa ESP-32, certifique-se de possuir:

* **IDE do Arduino** instalada em sua máquina.
* Pacote de placas **ESP32 by Espressif Systems** configurado no Gerenciador de Placas.
* A biblioteca do **Blynk** (versão de *Volodymyr Shymanskyy*) instalada na IDE.
* Bibliotecas adicionais para os sensores específicos (como `DHT sensor library`, `LiquidCrystal_I2C` e `MFRC522`), dependendo do projeto que deseja executar.

---

## 🚀 Como Utilizar

1. Clone ou baixe este repositório para o seu computador.
2. Abra a pasta do projeto desejado na IDE do Arduino.
3. Substitua as credenciais de rede e os tokens do Blynk (`ssid`, `pass`, `BLYNK_AUTH_TOKEN`) pelos dados gerados na sua conta do Blynk Cloud.
4. Conecte o ESP-32 via cabo USB, selecione a placa correta (`ESP32 Dev Module`) e a porta COM correspondente.
5. Faça o upload do código para a placa (pressionando o botão **BOOT** do ESP-32 caso necessário durante a mensagem de *Connecting*).

---

---
     1. LED (Diodo Emissor de Luz):
     Anodo (+) ----|>|---- Catodo (-)
                    ▲
                    │ (Emissão de Luz)
      2. Resistor:
     -------/\/\/\-------
          ( 1kΩ )

    3. Protoboard (Visão Interna das Trilhas):
     +-----------------------------------------+
     | [ ] [ ] [ ] [ ] [ ]   [ ] [ ] [ ] [ ] [ ] | <-- Trilhas de Alimentação (+)
     | [ ] [ ] [ ] [ ] [ ]   [ ] [ ] [ ] [ ] [ ] | <-- Trilhas de Alimentação (-)
     |-----------------------------------------|
     | [ ] [ ] [ ] [ ] [ ]   [ ] [ ] [ ] [ ] [ ] | <-- Linhas Verticais (A-E)
     | [ ] [ ] [ ] [ ] [ ]   [ ] [ ] [ ] [ ] [ ] | <-- Linhas Verticais (F-J)
     +-----------------------------------------+

     4. Jumper (Cabo de Conexão):
     [Pino ESP32] ===== (Jumper Macho-Macho) ===== [Protoboard]

     ==================================================
         EXEMPLO DE CIRCUITO (LED + ESP32)
     ==================================================

     +-------------+
     |   ESP-32    |
     |             |
     |    GPIO32 --+---(Jumper)---> [ Resistor 1kΩ ] ---> [ Anodo (+) LED ]
     |             |                                            |
     |       GND --+---(Jumper)-------------------------------> [ Catodo (-) LED ]
     +-------------+

 
     +-------------+
     ==================================================
              BOTÃO (PUSH-BUTTON)
     ==================================================

     1. Esquema Físico do Botão Táctil (4 Terminais):
         Terminal 1 o-------o Terminal 2
                    |       |
                    |   +   |  <-- Pressionar fecha o contato interno
                    |       |
         Terminal 3 o-------o Terminal 4


     2. Exemplo de Circuito de Botão com Pull-up Interno no ESP-32:
         
         +----------------------------------+
         |              ESP-32              |
         |                                  |
         |                     3V3 ---+     |
         |                            |     |
         |                          [10kΩ]  |  <-- Resistor de Pull-up (Opcional)
         |                            |     |
         |                 GPIO 23 ---+-----o (Terminal 1 do Botão)
         |                            |     
         |                            +-----o (Terminal 3 do Botão)
         |                                  |
         |                         GND -----+
         +----------------------------------+
     
---

<img width="422" height="219" alt="image" src="https://github.com/user-attachments/assets/1c1cbdad-7db0-4e1c-80b7-9d648e77e6ad" />


## 👤 Autoria e Supervisão

Material adaptado e mantido sob a supervisão do **Prof. Georgino, Rodrigo (IoT)** para fins educacionais e difusão do movimento *maker*.
