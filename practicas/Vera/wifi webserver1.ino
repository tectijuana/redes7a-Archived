//Se importan las librerías para la conexión
#include <SPI.h>
#include <Ethernet.h>
 
//Se inicializa la conexión Mac y la IP
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10,0,10,253);
 
//Se establece la conexión
EthernetServer server(80);
 
void setup() {
Serial.begin(9600);

//Conexión
Ethernet.begin(mac, ip);
server.begin();
Serial.print("IP local del servidor ");
Serial.println(Ethernet.localIP());
}
 
void loop() {
EthernetClient client = server.available(); 
    
    if (client) { //Por si un cliente se conecta al servidor:
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
                client.println("Refresh: 2"); // Refrescar cada 2 segundos.
                client.println();
               
               client.println("<!DOCTYPE HTML>"); 
                client.println("<html>"); 
                client.print("Vera Maldonado Ernesto");
                client.print(millis());
                client.print("MS encendido. ");
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
    //Fin de la conexión
    client.stop(); 
    Serial.println("Cliente desconectado");
    Serial.println();
    }
}
