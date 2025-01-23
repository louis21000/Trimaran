//Arduino MEGA 2250
#include <SPI.h>
#include <RF24.h>
#define pinCE 53   // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN 10  // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
#define tunnel "PIPE1"
#define led 9
#define borneENB 2
#define borneIN3 3
#define borneIN4 4 

RF24 radio(pinCE, pinCSN);  // Instanciation du NRF24L01

const byte adresse[6] = tunnel;
char message = "";
int on = '1';
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(borneIN3, OUTPUT);
  pinMode(borneIN4, OUTPUT);
  pinMode(borneENB, OUTPUT);

  Serial.println("Initialisation radio");
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.openReadingPipe(0, adresse);
  radio.startListening();

  Serial.println("Debut test moteurs");
  Serial.println("Marche avant");
  digitalWrite(borneIN3, LOW);
  digitalWrite(borneIN4, HIGH);
  analogWrite(borneENB, 255);
  delay(3000);
  Serial.println("Marche arrière");
  digitalWrite(borneIN3, HIGH);
  digitalWrite(borneIN4, LOW);
  analogWrite(borneENB, 255);
  delay(3000);
  digitalWrite(borneIN3, LOW);
  digitalWrite(borneIN4, LOW)
  Serial.println("Fin test moteurs");
  delay(500);
}

void loop() {
  // On vérifie à chaque boucle si un message est arrivé
  if (radio.available()) {
    radio.read(&message, sizeof(message));  // Si un message vient d'arriver, on le charge dans la variable "message"
    Serial.print("Message reçu : ");
    Serial.println(message);

    if (message == on) {
      Serial.println("Message correct reçu: 1");
      digitalWrite(led, HIGH);
    }
    else {
      Serial.println("Message incorrect reçu : 0");
      digitalWrite(led, LOW);
    }
  }
 }
  
