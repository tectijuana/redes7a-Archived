//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// ITT 8Sem RC 1 Hola Mundo
// 
// Made by Salcedo Jose
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4502130-itt-8sem-rc-1-hola-mundo

// CONSTANTES.
// Led a prender.
const byte LED = 2;
// Tiempo de espera entre prendido y apagado.
const unsigned int TIEMPO_ESPERA = 1000;

// the setup routine runs once when you press reset:
void setup() {
  // Configurar el unico led como salida.
  pinMode(LED, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // Prender y apagar el led de acuerdo a un tiempo de espera.
  digitalWrite(LED, HIGH);
  delay(TIEMPO_ESPERA);
  digitalWrite(LED, LOW);
  delay(TIEMPO_ESPERA);
}
