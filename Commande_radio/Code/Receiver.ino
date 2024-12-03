//Arduino Uno R3
#include <SPI.h>
#include <RF24.h>

#define pinCE 7   // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN 8  // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
#define tunnel "PIPE1"

RF24 radio(pinCE, pinCSN);  // Instanciation du NRF24L01

const byte adresse[6] = tunnel;
const char message[] = "";
void setup() {
  Serial.begin(9600);;

  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  radio.openReadingPipe(0, adresse);
  radio.startListening();
}

void loop() {
  // On vérifie à chaque boucle si un message est arrivé
  if (radio.available()) {
    radio.read(&message, sizeof(message));  // Si un message vient d'arriver, on le charge dans la variable "message"
    Serial.print("Message reçu : ");
    Serial.println(message);  // … et on l'affiche sur le port série !
  }                           // … toutes les secondes !
}
