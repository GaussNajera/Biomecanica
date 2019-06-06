// Incluímos la librería para poder controlar el servo
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
int angulo;

void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  pulgar.attach(pinServo0, pulsoMin, pulsoMax);
  indice.attach(pinServo1, pulsoMin, pulsoMax);
  medio.attach(pinServo2, pulsoMin, pulsoMax);
  anular.attach(pinServo3, pulsoMin, pulsoMax);
  menique.attach(pinServo4, pulsoMin, pulsoMax);
}
 
void loop() {
  
  // Desplazamos a la posición 0º
  pulgar.write(0);
  indice.write(0);
  medio.write(180);
  anular.write(180);
  menique.write(0);
  // Esperamos 1 segundo
  delay(1000);
    
  // Desplazamos a la posición 90º
  pulgar.write(90);
  indice.write(90);
  medio.write(90);
  anular.write(90);
  menique.write(90);
  // Esperamos 1 segundo
  delay(1000);
  
  // Desplazamos a la posición 180º
  pulgar.write(180);
  indice.write(180);
  medio.write(0);
  anular.write(0);
  menique.write(180);
  // Esperamos 1 segundo
  delay(1000);
}
