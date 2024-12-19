//Arduino Uno R3
#include <SPI.h>
#include <RF24.h>

#define pinCE   7             // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN  8             // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
#define tunnel  "PIPE1"
#define btn 3

RF24 radio(pinCE, pinCSN);    // Instanciation du NRF24L01

const byte adresse[6] = {'P', 'I', 'P', 'E', '1'};
char message = '0';


void setup() {
  pinMode(btn, INPUT);
  
  radio.begin();
  radio.openWritingPipe(adresse);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  Serial.begin(9600);
  Serial.println(message);
}

void loop() {
    int etat_btn = digitalRead(btn); 
  if (etat_btn == HIGH) {
  Serial.println("Le bouton est appuyé");
  message = '1';
  } 
  else {
  Serial.println("Le bouton n'est pas appuyé");
  message = '0';
  }
  
  radio.write(&message, sizeof(message));    // Envoi de notre message
  Serial.print(message);
}
