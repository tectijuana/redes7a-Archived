//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// a01_HolaMundo
// 
// Made by Fernando Ramirez
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4423315-a01_holamundo

/*Materia: Redes de computadoras
Programa: Arduino 01 - Hola Mundo
Alumno: Ramirez Vasquez Luis Fernando
No. de control: 13211137
Fecha: 30 de Marzo del 2017
*/

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  //Inicializar el Serial Monitor
  Serial.begin(9600);
  Serial.print("Hola mundo"); //Imprimir "Hola mundo" en Serial Monitor
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}

