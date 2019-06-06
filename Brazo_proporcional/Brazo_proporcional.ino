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

int analog1, aux1;
int analog2, aux2;

void setup() {
  Serial.begin(9600); //inicio la comunicacion serie

  pulgar.attach(pinServo0, pulsoMin, pulsoMax);
  indice.attach(pinServo1, pulsoMin, pulsoMax);
  medio.attach(pinServo2, pulsoMin, pulsoMax);
  anular.attach(pinServo3, pulsoMin, pulsoMax);
  menique.attach(pinServo4, pulsoMin, pulsoMax);
}

void loop() {
  int analog1=analogRead(A1);  //leo un valor analogico
  int analog2=analogRead(A2);
  aux1 = map(max(min(200,analog1), 20),20,250, 0,180);
  aux2 = map(max(min(200,analog2), 20),20,200, 0,180);

  pulgar.write(aux2);
  indice.write(aux1);
  delay(20);

  /*pulgar.write(180);
  indice.write(180);
  medio.write(0);
  anular.write(0);
  menique.write(180);*/
  
  Serial.print(500);
  Serial.print(" ");
  Serial.print(0);
  Serial.print(" ");
  Serial.print(analog1);  //lo envio serialmente
  Serial.print(" ");
  Serial.println(analog2);
  //delay(10);  //espero 100 milisegundos para la siguiente lectura
}
