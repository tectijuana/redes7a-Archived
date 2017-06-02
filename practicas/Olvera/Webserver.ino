#include <SPI.h>
#include <Ethernet.h>
 
// Configuración de direccion MAC e IP.
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,177);
 
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
EthernetClient client = server.available(); // Escucha a los clientes entrantes.
    if (client) { // Si un cliente se conecta al servidor:
    Serial.println("Nuevo cliente");
    boolean currentLineIsBlank = true; // Marcador para enviar la respuesta desde el servidor.
        while (client.connected()) { // Repite mientas existe clientes conectados:
            if (client.available()) {
            char c = client.read();
            Serial.write(c); // Imprime por el puerto serie la petición del cliente (caracter a caracter)
                if (c == '\n' && currentLineIsBlank) { // Se envia la respuesta a una petición de un cliente cuando a finalizado la petición:
                // Respuesta:
                client.println("HTTP/1.1 200 OK"); // Enviar un encabezado de respuesta HTTP estándar
                client.println("Content-Type: text/html");
                client.println("Connection: close"); // Se cerrará la conexiós despues de enviar la respuesta.
                client.println("Refresh: 5"); // Refrescar automáticamente la página después de 5 segundos.
                client.println();
                client.println("<!DOCTYPE HTML>"); // Tipo de documento.
                client.println("<html>"); // Etiqueta html inicio del documento. 
                client.print("Javier");
                client.print(millis()); // Tiempo de funcionamiento en ms.
                client.print("ms encendido. ");
                client.println("<br />"); // Etiqueta html salto de linea. 
                client.println("</html>"); // Etiqueta html fin del documento.
                break;
                }
                if (c == '\n') { // Si el caracter es un salto de linea:
                currentLineIsBlank = true; // La petición a terminado, se respondera a dicha peticón en el sigueitne ciclo.
                } 
                else if (c != '\r') { // Si el caracter no es un retorno de carro (la petición no a terminado).
                currentLineIsBlank = false; // Seguimos escuchando la petición.
                }
           }
       }
    delay(1); // Espera para dar tiempo al navegador a recivir los datos.
    client.stop(); // Cierra la conexión.
    Serial.println("Cliente desconectado");
    Serial.println();
    }
}