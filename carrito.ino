const int controlPin1 = 2;
const int controlPin2 = 3;
const int controlPin3 = 4;
const int controlPin4 = 5;
void setup() {
  // put your setup code here, to run once:
 pinMode(controlPin1, OUTPUT);
 pinMode(controlPin2, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(8, INPUT);
 Serial.begin(9600);
}

void adelante(){
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH);
}
void atras(){
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW);
}
void izquierda(){
  digitalWrite(controlPin3, HIGH);
  digitalWrite(controlPin4, LOW);
}
void derecha(){
  digitalWrite(controlPin3, LOW);
  digitalWrite(controlPin4, HIGH);
}
void apagaV(){
  digitalWrite(controlPin3, LOW);
  digitalWrite(controlPin4, LOW);
}
void apagaT(){
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, LOW);
}
int conta=0;
long duration,distance;
void loop() {
  digitalWrite(9,LOW);
  delayMicroseconds(5);
  digitalWrite(9,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(8,HIGH);
  distance=int(0.017*duration);
  Serial.println(distance);
 if(distance<=150&distance>0){
   apagaT();
   derecha();
   atras(); 
} 
 else if(distance>150){
   apagaV();
   adelante();
 }
}
