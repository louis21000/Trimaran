//Arduino MEGA
#include <SPI.h>
#include <RF24.h>

#define pinCE   7             // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN  8             // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
#define tunnel  "PIPE1"

RF24 radio(pinCE, pinCSN);    // Instanciation du NRF24L01

const byte adresse[6] = tunnel;	
const char message[] = "Activer"; 


void setup() {
  radio.begin();
  radio.openWritingPipe(adresse);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
  Serial.println(message);
}

void loop() {
radio.write(&message, sizeof(message));    // Envoi de notre message
  delay(1000);  
}
