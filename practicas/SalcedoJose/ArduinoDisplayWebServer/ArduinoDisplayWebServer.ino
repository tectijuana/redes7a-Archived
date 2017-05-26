/*
   Alumno: Salcedo Morales Jose Manuel (13211419)
   Web Server para arduino.
*/

/*
  Web Server

  A simple web server that shows the value of the analog input pins.
  using an Arduino Wiznet Ethernet shield.

  Circuit:
   Ethernet shield attached to pins 10, 11, 12, 13
   Analog inputs attached to pins A0 through A5 (optional)

  created 18 Dec 2009
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe
  modified 02 Sept 2015
  by Arturo Guadalupi

*/

// CONFIGURACION DISPLAY.
/*
   PINES:
   VCC a 5V
   GND a GND
   SCL a A5
   SDA a A4
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};

#define SSD1306_LCDHEIGHT 64
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


// CONFIGURACION ETHERNET.
#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
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
const String USUARIO = "Salcedo Morales Jose Manuel (13211419)";
const byte COLUMNAS_PARA_DIGITO = 4;
const byte FILAS_PARA_DIGITO = 5;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  // CONFIGURACION DISPLAY.
  // Por defecto generar 3.3 Volts.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

  // Desplegar la imagen de adafruit.
  display.display();
  delay(2000);

  // Limpiar el buffer del display.
  display.clearDisplay();

  // Mostrar el buffer en el hardware.
  display.display();
  delay(2000);
  display.clearDisplay();

  // CONFIGURACION IP.
  /*
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
  */
}


void loop() {
  for (byte numero = 0; numero < 10; numero++) {
    DesplegarDigito(numero, 1, 1);
    delay(2500);
    display.clearDisplay();
  }

  /*
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
            client.print("<p>Creador del web server: " + USUARIO + "</p>");

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
  */
}

void printIPAddress()
{
  // Definir cuantos numeros pueden haber en una ip.
  const byte CANTIDAD_NUMEROS_IP = 4;

  // Definir cuantos pixeles avanzar con respecto a las columnas dadas para un digito.
  const byte incrementoX = COLUMNAS_PARA_DIGITO + 1;

  Serial.print("Mi direccion IP es: ");
  for (byte thisByte = 0; thisByte < CANTIDAD_NUMEROS_IP; thisByte++) {
    // Obtener el numero actual.
    const byte numeroIp = Ethernet.localIP()[thisByte];

    // Desplegar en serial el valor de cada byte de la direccion IP.
    Serial.print(numeroIp, DEC);
    Serial.print(".");

    // Desplegar en display el numero actual.
    DesplegarNumeroIpEnDisplay(numeroIp, (thisByte + 1) * incrementoX, 1, incrementoX);
  }

  Serial.println();
}

void DesplegarNumeroIpEnDisplay(const byte numeroIp, const byte coordenadaX, const byte coordenadaY,
                                const byte incrementoX)
{
  // Definir numero al cual siempre reducir de tamano para obtener un digito al cual desplegar.
  byte numeroActual = numeroIp;

  // Definir la posicion de pixeles para coordenadas X.
  byte agregarColumnas = 0;

  // Desplegar en pantalla cada digito del numero dado.
  for (byte divisor = 100; divisor > 0; divisor /= 10) {
    // Definir digito a desplegar.
    const byte digitoDesplegar = numeroActual / divisor;
    DesplegarDigito(digitoDesplegar, coordenadaX + agregarColumnas, coordenadaY);

    // Cambiar el numero actual quitando el digito mas significativo.
    numeroActual %= divisor;
    // Preparar la coordenada X en donde desplegar el siguiente digito.
    agregarColumnas += incrementoX;
  }
}

// Desplegar un numero deseado.
void DesplegarDigito(const byte digito, const byte coordenadaX, const byte coordenadaY)
{
  // Definir cantidad de filas y columnas permitidas para un digito.
  const byte numeroFilas = FILAS_PARA_DIGITO;
  const byte numeroColumnas = COLUMNAS_PARA_DIGITO;

  // Continuar si el numero es de un solo digito.
  if (digito >= 0 && digito <= 9) {

    // De acuerdo al digito recibido, definir si dibujar o un un pixel en cada fila con columna.
    switch (digito) {
      case 0: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;

      case 1: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {0, 0, 0, 1},
            {0, 0, 1, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 1}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;

      case 2: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 1, 1, 1}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;

      case 3: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 1, 1}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;

      case 4: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 1}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;

      case 5: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {1, 1, 1, 1}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;

      case 6: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;

      case 7: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {1, 1, 1, 1},
            {0, 0, 0, 1},
            {0, 0, 1, 0},
            {0, 1, 0, 0},
            {1, 0, 0, 0}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;

      case 8: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1},
            {1, 0, 0, 1},
            {1, 1, 1, 1}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;

      case 9: {
          const byte coordenadas[numeroFilas][numeroColumnas] = {
            {0, 1, 1, 1},
            {0, 1, 0, 1},
            {0, 1, 1, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 1}
          };

          DesplegarDigitoEnDisplay(coordenadas, coordenadaX, coordenadaY);
        }
        break;
    }
  }
}

// Desplegar un punto en el display de acuerdo a la posicion de la esquina superior izquierda.
void DesplegarPunto(const byte coordenadaX, const byte coordenadaY)
{
  display.drawPixel(coordenadaX + 1, coordenadaY + 4, WHITE);
  display.drawPixel(coordenadaX + 2, coordenadaY + 4, WHITE);
  display.drawPixel(coordenadaX + 1, coordenadaY + 5, WHITE);
  display.drawPixel(coordenadaX + 2, coordenadaY + 5, WHITE);
  display.display();
}

// Desplegar numero en el display de acuerdo a la posicion de la esquina superior izquierda.
void DesplegarDigitoEnDisplay(const byte coordenadas[FILAS_PARA_DIGITO][COLUMNAS_PARA_DIGITO],
                              const byte coordenadaX, const byte coordenadaY)
{
  // Definir cantidad de filas y columnas permitidas para un digito.
  const byte numeroFilas = FILAS_PARA_DIGITO;
  const byte numeroColumnas = COLUMNAS_PARA_DIGITO;

  for (byte fila = 0; fila < numeroFilas; fila++) {
    for (byte columna = 0; columna < numeroColumnas; columna++) {
      const byte coordenadaActual = coordenadas[fila][columna];

      if (coordenadaActual != 0) {
        const byte valorX = coordenadaX + columna;
        const byte valorY = coordenadaY + fila;
        display.drawPixel(valorX, valorY, WHITE);
      }
    }
  }

  // Desplegar numero deseado en display.
  display.display();
}
