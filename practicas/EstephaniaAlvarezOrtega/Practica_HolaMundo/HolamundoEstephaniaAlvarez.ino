//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Hola mundo, EstephaniaAlvarez
// 
// Made by Estephania Alvarez
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4502195-hola-mundo-estephaniaalvarez


int led = 13;


void setup() {

  pinMode(led, OUTPUT);
}


void loop() {
  digitalWrite(led, HIGH);   
  delay(1000);               
  digitalWrite(led, LOW);    
  delay(1000);               
}
