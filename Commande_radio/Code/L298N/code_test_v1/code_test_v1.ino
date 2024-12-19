//modification 1 blanc sur jaune
#define IN1 3
#define IN2 4
#define EN1 2

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
  delay(3500);
  delay(1000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN1, 255);
  delay(3500);
}
