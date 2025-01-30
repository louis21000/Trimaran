// Arduino MEGA 2250
// MARCHE AVANT : ROUGE / ROUGE et JAUNE / NOIR
#include <SPI.h>
#include <RF24.h>

#define pinCE 53   // On associe la broche "CE" du NRF24L01 à la sortie digitale D53 de l'arduino MEGA
#define pinCSN 10  // On associe la broche "CSN" du NRF24L01 à la sortie digitale D10 de l'arduino MEGA
#define tunnel "PIPE1"
#define led 9
#define borneENACROSS 2
#define borneIN1CROSS 3
#define borneIN2CROSS 4 

RF24 radio(pinCE, pinCSN);  // Instanciation du NRF24L01

const byte adresse[6] = tunnel;
char msg = '0';  // On initialise avec un message par défaut

int avancerCrossA(){
    digitalWrite(borneIN1CROSS, LOW);
    digitalWrite(borneIN2CROSS, HIGH);
    analogWrite(borneENACROSS, 255);
    delay(2000);
    digitalWrite(borneIN1CROSS, LOW);
    digitalWrite(borneIN2CROSS, LOW);
    analogWrite(borneENACROSS, 0);
}

int fermerCrossA(){
     digitalWrite(borneIN1CROSS, HIGH);
    digitalWrite(borneIN2CROSS, LOW);
    analogWrite(borneENACROSS, 255);
    delay(2000);
    digitalWrite(borneIN1CROSS, LOW);
    digitalWrite(borneIN2CROSS, LOW);
    analogWrite(borneENACROSS, 0);
}

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(borneIN1CROSS, OUTPUT);
  pinMode(borneIN2CROSS, OUTPUT);
  pinMode(borneENACROSS, OUTPUT);

  Serial.println("Initialisation radio");
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.openReadingPipe(1, adresse);  // Pipe 1, pour écouter sur PIPE1
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&msg, sizeof(msg));  // Lire le message de la radio

    if (msg == '0') {
      Serial.println("Message : 0 - Ne rien faire");
    } else if (msg == '1') {
      Serial.println("Message : 1 - Déploiement du vérin");
      avancerCrossA();
    } else if (msg == '2') {
      Serial.println("Message : 2 - Rétractation du vérin");
      fermerCrossA();
    } else {
      Serial.println("Message inconnu");
    }
  } else {
    Serial.println("Radio indisponible");
  }
}
