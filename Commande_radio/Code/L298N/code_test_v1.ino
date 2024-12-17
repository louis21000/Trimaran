#define IN1 9
#define IN2 10
#define EN1 8

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN1, OUTPUT);
  Serial.println("Initialisation");

}

void loop() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, 255);
  Serial.println("Moteur en marche");
  delay(2000);
  Serial.println("Arret moteur");
  analogWrite(EN1, 0);
  delay(1000);

}
