/* We start by including the library */
#include "LedControl.h"

/* 
 * Now we create a new LedControl. 
 * We use pins 12,11 and 10 on the Arduino for the SPI interface
 * Pin 12 is connected to the DATA IN-pin of the first MAX7221
 * Pin 11 is connected to the CLK-pin of the first MAX7221
 * Pin 10 is connected to the LOAD(/CS)-pin of the first MAX7221 	
 * There will only be a single MAX7221 attached to the arduino 
 */
LedControl lc=LedControl(53,52,51,1); 

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0,8);
  lc.setLed(0,0,0,true);
}

void loop() {
  for (int i=0;i<8;i++) {
    for (int j=0;j<8;j++) {
      lc.setLed(0,i,j,false);
      delay(500);
      lc.setLed(0,i,j,true);
    }
  }
}
