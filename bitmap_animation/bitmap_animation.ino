#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <avr/pgmspace.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

int wait = 100;
const int pinRandom = A0;
PROGMEM const unsigned char bitmap1[] = {0xc3, 0x81, 0x00, 0x42, 0x00, 0xff, 0x81, 0xa5};
PROGMEM const unsigned char bitmap2[] = {0x1C, 0xD6, 0xDF, 0x5F, 0x5F, 0xDF, 0xD6, 0x1C};
PROGMEM const unsigned char bitmap3[] = {0x00, 0x0C, 0x0C, 0x30, 0x50, 0x18, 0x14, 0x24};
PROGMEM const unsigned char bitmap4[] = {0x00, 0x0C, 0x0C, 0x30, 0x50, 0x18, 0x28, 0x08};
PROGMEM const unsigned char bitmap5[] = {0x0C, 0x0C, 0x30, 0x50, 0x18, 0x14, 0x18, 0x10};

void setup() {
  matrix.setIntensity(1); // Set brightness between 0 and 15
  //randomSeed(analogRead(pinRandom));
}

void loop() {
  /*
  int c_x = random(8);
  int c_y = random(8);
  
  for (int i=0;i<8;i++) {
    matrix.drawCircle(c_x, c_y, i, HIGH);
    matrix.write();
    delay(wait+i*10);
    matrix.drawCircle(c_x, c_y, i, LOW);
    matrix.write();
  }
  delay(wait);*/
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0, 0, bitmap3, 8, 8, HIGH);
  matrix.write();  
  delay(wait);
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0, 0, bitmap4, 8, 8, HIGH);
  matrix.write();  
  delay(wait);  
  matrix.fillScreen(LOW);
  matrix.drawBitmap(0, 0, bitmap5, 8, 8, HIGH);
  matrix.write();  
  delay(wait);  
}
