//Arduino MEGA 2250
#include <SPI.h>
#include <RF24.h>
#define pinCE 53   // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN 10  // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
#define tunnel "PIPE1"
#define led 9
//modification 1 blanc sur jaune
#define IN1 3
#define IN2 4
#define EN1 2
int Avancer (){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, 255);
  delay(3500);

}
int Reculer (){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN1, 255);
  delay(3500);

}
int ArretMoteur (){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(EN1, 0);
}

RF24 radio(pinCE, pinCSN);  // Instanciation du NRF24L01

const byte adresse[6] = tunnel;
char message = "";
int on = '1';
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);

  Serial.println("Initialisation radio");
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.openReadingPipe(0, adresse);
  radio.startListening();
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
      Avancer();
      delay(1000);
      Reculer();
      ArretMoteur();
    }
    else {
      Serial.println("Message incorrect reçu : 0");
      digitalWrite(led, LOW);
      ArretMoteur();

    }
  }
 }
  
