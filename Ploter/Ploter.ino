-void setup() {
  Serial.begin(9600); //inicio la comunicacion serie
}

void loop() {
  int analog1=analogRead(A1);  //leo un valor analogico
  Serial.print(500);
  Serial.print(" ");
  Serial.print(450);
  Serial.print(" ");
  Serial.println(analog1);  //lo envio serialmente
  delay(10);  //espero 100 milisegundos para la siguiente lectura
}
