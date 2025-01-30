// Arduino NANO EVERY
// Bibliothèque
#include <SPI.h>
#include <RF24.h>

// Association des pins avec la carte
#define pinCE 7 // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN 8 // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
#define tunnel "PIPE1"
#define btnM6open 3
#define btnM6close 4

RF24 radio(pinCE, pinCSN);
const byte adresse[6] = {'P', 'I', 'P', 'E', '1'};

// Creation des messages
char msgnone = '0';
char msgbtnM6open = '1';
char msgbtnM6close = '2';
char msg = '0';

void setup() {
  // PinMode des composants
  pinMode(btnM6open, INPUT);
  pinMode(btnM6close, INPUT);

  // Instanciation radio
  radio.begin();
  radio.openWritingPipe(adresse);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening(); // car transmitter

  // Demarrage Serial
  Serial.begin(9600);
}

void loop() {
  // Etat des boutons et lecture de leur valeur :
  int etat_btnM6open = digitalRead(btnM6open);
  int etat_btnM6close = digitalRead(btnM6close);

  // Activation des moteurs :
  //MOTEUR M6 OPEN
  if (etat_btnM6open == HIGH) {
    Serial.println("bouton M6 appuyé");
    msg = msgbtnM6open;
    radio.write(&msg, sizeof(msg));
  }else if(etat_btnM6close == HIGH){  
    Serial.println("bouton M6 close appuyé");
    msg = msgbtnM6close;
    radio.write(&msg, sizeof(msg));
}

  //MOTEUR M6 CLOSE
  else {
    msg = msgnone;
    radio.write(&msg, sizeof(msg));
  }
}
