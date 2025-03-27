#define M4IN3 44
#define M4IN4 46
#define M4ENB 48
#define M67IN1 38
#define M67IN2 40
#define M67ENA 42
#define M3IN1 32
#define M3IN2 34
#define M3ENA 36
#define M2IN1 26
#define M2IN2 28
#define M2ENA 30
void setup() {
  //TREUIL PHOQUE
  //RENTRER VERIN ARRIERE
    digitalWrite(M3IN1, LOW); 
    digitalWrite(M3IN2, HIGH);
    analogWrite(M3ENA, 255);
    delay(8000);
    analogWrite(M3ENA, 0);
  //TREUIL AVANT REPLIER 1ere tempo
    digitalWrite(M2IN1, LOW); 
    digitalWrite(M2IN2, HIGH);
    analogWrite(M2ENA, 255);
    delay(70000);
    analogWrite(M2ENA, 0);
  //RENTRER GRAND MAT
    digitalWrite(M4IN3, HIGH); 
    digitalWrite(M4IN4, LOW);
    analogWrite(M4ENB, 255);
    delay(21000);
    analogWrite(M4ENB, 0);
  //TREUIL AVANT REPLIER 2e tempo
  //M67
    digitalWrite(M67IN1, HIGH);
    digitalWrite(M67IN2, LOW);
    analogWrite(M67ENA, 255);
    delay(12000);
    analogWrite(M67ENA, 0);  
  
}

void loop() {

}
