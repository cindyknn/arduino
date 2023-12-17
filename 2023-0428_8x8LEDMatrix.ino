#include <LedControl.h>
#include "binary.h"

LedControl lc=LedControl(10,12,11,0);
byte hf[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};

//let use input eqt & ans, if correct happy face, if wrong, display right ans & sad face

void setup() {
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,15);
  // Clear the display
  lc.clearDisplay(0);  
}

void loop() {
  lc.setRow(0,0,hf[0]);
  lc.setRow(0,1,hf[1]);
  lc.setRow(0,2,hf[2]);
  lc.setRow(0,3,hf[3]);
  lc.setRow(0,4,hf[4]);
  lc.setRow(0,5,hf[5]);
  lc.setRow(0,6,hf[6]);
  lc.setRow(0,7,hf[7]);
  
}
