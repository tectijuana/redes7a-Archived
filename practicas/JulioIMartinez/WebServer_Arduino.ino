/*Materia: Redes de computadoras
Programa: WebServer Arduino
Alumno: Martinez Reyes Julio Ismael
No. de control: 10210544
Fecha: 28 de Abril de 2017*/

/*
  Web Server

 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 02 Sept 2015
 by Arturo Guadalupi

 */

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {
  0xD8, 0xCB, 0x8A, 0x18, 0xED, 0x61
};

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):

EthernetClient client;

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

// CONSTANTES.

const String USUARIO = "Martinez Reyes Julio Ismael (10210544)";
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // Indicar necesidad de espera de puerto serial.
  Serial.println("Por favor, espere la conexion serial...");
  while (!Serial) {

    ; // wait for serial port to connect. Needed for native USB port only

  }



  // start the Ethernet connection:

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Fallo al configurar Ethernet con DHCP");
    // no point in carrying on, so do nothing forevermore:
    for (;;)
      ;
  }

  // print your local IP address:

  printIPAddress();



  // start the Ethernet connection and the server:

  server.begin();

  // Descomentar si hay una tarjeta SD conectada.
  //pinMode(4, OUTPUT);
  //digitalWrite(4, HIGH);

}

void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("Nuevo cliente.");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // Desplegar el nombre de quien programo el servidor.
          client.print("<p>Autor web server: " + USUARIO + "</p>");
          // output the value of each analog input pin
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("Ingreso analogo ");
            client.print(analogChannel);
            client.print(" es ");
            client.print(sensorReading);
            client.println("<br />");
          }
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:

    client.stop();
    Serial.println("Cliente desconectado.");
  }
}
void printIPAddress()
{
  Serial.print("Mi direccion IP es: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print(".");
  }
  Serial.println();
}
