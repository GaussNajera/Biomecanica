#include <Servo.h>

 
// Declaramos la variable para controlar el servo
Servo pulgar;
Servo indice;
Servo medio;
Servo anular;
Servo menique;

const int pinServo0 = 8;
const int pinServo1 = 9;
const int pinServo2 = 10;
const int pinServo3 = 11;
const int pinServo4 = 12;
const int pulsoMin = 650;
const int pulsoMax = 2550;

int analog1;
int analog2;
int umbralD = 150;
int umbralB = 120;

void setup() {
  Serial.begin(9600); //inicio la comunicacion serie

  pulgar.attach(pinServo0, pulsoMin, pulsoMax);
  indice.attach(pinServo1, pulsoMin, pulsoMax);
  medio.attach(pinServo2, pulsoMin, pulsoMax);
  anular.attach(pinServo3, pulsoMin, pulsoMax);
  menique.attach(pinServo4, pulsoMin, pulsoMax);
}
void cerrarDeditos() {
  pulgar.write(0);
  indice.write(180);
  medio.write(0);
  anular.write(0);
  menique.write(180); 
}

void apretar() {
  pulgar.write(180);
  indice.write(180);
  medio.write(0);
  anular.write(0);
  menique.write(180); 
}

void cerrarGordo() {
/*  pulgar.write(180);
  indice.write(0);
  medio.write(180);
  anular.write(180); 
   
  pulgar.write(180);
  indice.write(180);
  medio.write(0);
  anular.write(0);
  menique.write(180);*/
  
  pulgar.write(180);
  indice.write(0);
  medio.write(180);
  anular.write(180);
  menique.write(0);
}

void abrir(){
  pulgar.write(0);
  indice.write(0);
  medio.write(180);
  anular.write(180);
  menique.write(0);
}

void loop() {
  int analog1=analogRead(A1);  //leo un valor analogico
  int analog2=analogRead(A2);
if(analog2>= umbralB && analog1 <= umbralD){ // 1,0
    cerrarGordo();
} else if(analog2 < umbralB && analog1 > umbralD){ // 0,1
    cerrarDeditos();
} else if(analog2 < umbralB && analog1 < umbralD){ // 0,0 
    abrir();
} else if(analog2 > umbralB && analog1 > umbralD){ // 1,1 
    apretar();
}
delay(300);

  /*pulgar.write(180);
  indice.write(180);
  medio.write(0);
  anular.write(0);
  menique.write(180);*/
  
  Serial.print(umbralD);
  Serial.print(" ");
  Serial.print(umbralB);
  Serial.print(" ");
  Serial.print(0);
  Serial.print(" ");
  Serial.print(analog1);  //lo envio serialmente
  Serial.print(" ");
  Serial.println(analog2);
  delay(10);  //espero 100 milisegundos para la siguiente lectura
}
