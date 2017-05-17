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

void setup() {
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  display.display();
  delay(2000);
  display.clearDisplay();
}


void loop() {
  // Escribir nombre personal.
  // J
  display.drawPixel(1, 4, WHITE);
  display.drawPixel(1, 5, WHITE);
  display.drawPixel(2, 5, WHITE);
  display.drawPixel(3, 5, WHITE);
  display.drawPixel(4, 1, WHITE);
  display.drawPixel(4, 2, WHITE);
  display.drawPixel(4, 3, WHITE);
  display.drawPixel(4, 4, WHITE);
  display.drawPixel(4, 5, WHITE);

  // O
  display.drawPixel(6, 1, WHITE);
  display.drawPixel(6, 2, WHITE);
  display.drawPixel(6, 3, WHITE);
  display.drawPixel(6, 4, WHITE);
  display.drawPixel(6, 5, WHITE);
  display.drawPixel(7, 1, WHITE);
  display.drawPixel(7, 5, WHITE);
  display.drawPixel(8, 1, WHITE);
  display.drawPixel(8, 5, WHITE);
  display.drawPixel(9, 1, WHITE);
  display.drawPixel(9, 2, WHITE);
  display.drawPixel(9, 3, WHITE);
  display.drawPixel(9, 4, WHITE);
  display.drawPixel(9, 5, WHITE);

  // S
  display.drawPixel(12, 1, WHITE);
  display.drawPixel(12, 2, WHITE);
  display.drawPixel(12, 3, WHITE);
  display.drawPixel(12, 5, WHITE);
  display.drawPixel(13, 1, WHITE);
  display.drawPixel(13, 5, WHITE);
  display.drawPixel(14, 1, WHITE);
  display.drawPixel(14, 5, WHITE);
  display.drawPixel(15, 1, WHITE);
  display.drawPixel(15, 3, WHITE);
  display.drawPixel(15, 4, WHITE);
  display.drawPixel(15, 5, WHITE);

  // E
  display.drawPixel(18, 1, WHITE);
  display.drawPixel(18, 2, WHITE);
  display.drawPixel(18, 3, WHITE);
  display.drawPixel(18, 4, WHITE);
  display.drawPixel(18, 5, WHITE);
  display.drawPixel(19, 1, WHITE);
  display.drawPixel(19, 3, WHITE);
  display.drawPixel(19, 5, WHITE);
  display.drawPixel(20, 1, WHITE);
  display.drawPixel(20, 3, WHITE);
  display.drawPixel(20, 5, WHITE);
  display.drawPixel(21, 1, WHITE);
  display.drawPixel(21, 3, WHITE);
  display.drawPixel(21, 5, WHITE);

  // Dibujar
  display.display();
}
