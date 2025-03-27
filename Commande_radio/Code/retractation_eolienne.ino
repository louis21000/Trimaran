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
    //M67
    digitalWrite(M67IN1, LOW);
    digitalWrite(M67IN2, HIGH);
    analogWrite(M67ENA, 255);
    delay(8000);
    analogWrite(M67ENA, 0);  
          
    //DEPLOIEMENT GRAND MAT    
    digitalWrite(M4IN3, LOW); 
    digitalWrite(M4IN4, HIGH);
    analogWrite(M4ENB, 255);
    delay(21000);
    analogWrite(M4ENB, 0);

    //TREUIL AVANT
    digitalWrite(M2IN1, HIGH); 
    digitalWrite(M2IN2, LOW);
    analogWrite(M2ENA, 255);
    delay(70000);
    analogWrite(M2ENA, 0);
    
    //VERIN ARRIERE
    digitalWrite(M3IN1, HIGH); 
    digitalWrite(M3IN2, LOW);
    analogWrite(M3ENA, 255);
    delay(12000);
    analogWrite(M3ENA, 0);
    //TREUIL PHOQUE
}

void loop() {

}
