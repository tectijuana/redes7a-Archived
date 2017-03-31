void setup(){
pinMode(13, OUTPUT); // Pin 13 como Salida.
}

void loop(){
digitalWrite(13, HIGH); // Pone la salida 13 a ON
delay(1000);            // Espera un segundo
digitalWrite(13, LOW);  // Pone la salida 13 a OFF
delay(1000);            // Espera un segundo
}
