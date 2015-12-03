/****************************
The MIT License (MIT)

Copyright (c) 2015 by Antonio Menarde and Chris Powell

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************/

#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define pixelPin 6
#define buttons A5
#define numClothesOptions 13
#define numWeatherOptions 10

int clothesCounts[numClothesOptions][2];
//t-shirt 0, sweater 1, rain jacket 2, coat 3, pants 4, shorts 5, umbrella 6, shoes 7,
//boots 8, hat 9, sunglasses 10, gloves 11, scarf 12

boolean forwardButton;
boolean backButton;
boolean plusButton;
boolean minusButton;
boolean onButton;
boolean programButton;
boolean washButton;

boolean weather[numWeatherOptions];
//sun, snow, mcloudy, pcloudy, fog, rain, pour, hail, thunder, catastrophic
int temperature;

//Debug
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  
  // Read in values from EEPROM
  initializeCounts();

//Debug
//strip.begin();
//strip.setBrightness(255);
//strip.show();
}

void loop() { 
  yayButtons();
  
  if(programButton){
    programmingMode();
  }
  
//  if(onButton){
//    displayStates();
//  }
}
