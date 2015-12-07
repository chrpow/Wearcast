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
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h> //needs new liquidcrystal library replaced in arduino inherent lib

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define pixelPin 11
#define buttons A3
#define numClothesOptions 15
#define numWeatherOptions 11

LiquidCrystal lcd(3,2 ,4);

int clothesCounts[numClothesOptions][2];
//gloves 0, boots 1, umbrella 2, glasses 3, shorts 4, pants 5
//tshirt 6, sweater 7, rainjacket 8, hat 9, shoes 10, scarf 11
//skirt 12, coat 13, longsleeve 19

boolean weatherStates[numWeatherOptions];
//cloudy 14, fog 15, wind 16, lightning 17, hail 18, rain 20
//drizzle 21, sunny 22, snow 23, pcloudy 24, danger 25

boolean forwardButton;
boolean backButton;
boolean plusButton;
boolean minusButton;
boolean onButton;
boolean programButton;
boolean washButton;

int temperature;

//Debug
Adafruit_NeoPixel strip = Adafruit_NeoPixel(26, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  lcd.begin(20, 4);

  lcd.print("Welcome to Wearcast");
  
  // Read in values from EEPROM
  initializeCounts();

  strip.begin();
  strip.setBrightness(255);
  strip.show();
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
