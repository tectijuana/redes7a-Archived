//Omar Villegas Castillo
//NO DE CTRL. 13211106
//Redes de Computadoras
//INSTITUTO TECNOLÓGICO DE TIJUANA
//HELLO WORLD EN ARDUINO 
//circuits.io

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello World!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis());
  delay(10); // this is necessary to run the simulation at full speed
}
