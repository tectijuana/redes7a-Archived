#include <SPI.h>
#include <Ethernet.h>
 
// Configuración de direccion MAC e IP.
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10,0,10,255);
 
// Inicia la libreria Ethernet server con el puerto 80 (por defecto el puerto HTTP).
EthernetServer server(80);
 
void setup() {
// Inicia el puerto serie.
Serial.begin(9600);
 
// Inicia la conexión Ethernet y el servidor.
Ethernet.begin(mac, ip);
server.begin();
Serial.print("IP local del servidor ");
Serial.println(Ethernet.localIP());
}
 
void loop() {
EthernetClient client = server.available(); 
    if (client) { // Si un cliente se conecta al servidor:
    Serial.println("Nuevo cliente");
    boolean currentLineIsBlank = true; 
        while (client.connected()) { 
            if (client.available()) {
            char c = client.read();
            Serial.write(c); 
                if (c == '\n' && currentLineIsBlank) { 
                client.println("HTTP/1.1 200 OK"); 
                client.println("Content-Type: text/html");
                client.println("Connection: close"); 
                client.println("Refresh: 5"); 
                client.println();
                client.println("<!DOCTYPE HTML>"); 
                client.println("<html>");  
                client.print("HOLI BOLI!! - ");
                client.print(millis()); 
                client.print("ms encendido. ");
                client.println("<br />"); 
                client.println("</html>"); 
                break;
                }
                if (c == '\n') { 
                currentLineIsBlank = true; 
                } 
                else if (c != '\r') { 
                currentLineIsBlank = false; 
                }
           }
       }
    delay(1); 
    client.stop(); 
    Serial.println("Cliente desconectado");
    Serial.println();
    }
}
