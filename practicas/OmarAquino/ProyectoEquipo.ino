#define BaudRate 9600
#define LEDPin    10
char incomingOption;

//Declaración de variables
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  // serial communication
  Serial.begin(BaudRate);
}
void loop()
{
     //read from serial port getting information from VS 2013
     incomingOption = Serial.read();
     //incomingOption = '1';
     //verify incomingOption
     switch(incomingOption)
     {
        case '0':
          // Turn OFF LED
          digitalWrite(LED1, LOW);
          break;
        case '1':
          // Turn ON LED
          digitalWrite(LED1, HIGH);
          break;
        case '2':
          // Turn OFF LED
          digitalWrite(LED2, LOW);
          break;
        case '3':
          // Turn ON LED
          digitalWrite(LED2, HIGH);
          break;
        case '4':
          // Turn OFF LED
          digitalWrite(LED3, LOW);
          break;
        case '5':
          // Turn ON LED
          digitalWrite(LED3, HIGH);
          break;
     }
}
