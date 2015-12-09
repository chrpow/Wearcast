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
#include <SoftwareSerial.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define pixelPin 11
#define button1 A0
#define button2 A1
#define button3 A2
#define button4 A3
#define button5 A4
#define button6 A5
#define button7 7

#define numClothesOptions 15
#define numWeatherOptions 11

LiquidCrystal lcd(3, 2 ,4); //data, clock, latch
SoftwareSerial bluetooth(12, 13);

int clothesCounts[numClothesOptions][1]; //0: in closet, 1: clean
//gloves 0, boots 1, umbrella 2, glasses 3, shorts 4, pants 5
//tshirt 6, sweater 7, rainjacket 8, hat 9, shoes 10, scarf 11
//skirt 12, coat 13, longsleeve 19

boolean states[numWeatherOptions + numClothesOptions];
//gloves 0, boots 1, umbrella 2, glasses 3, shorts 4, pants 5
//tshirt 6, sweater 7, rainjacket 8, hat 9, shoes 10, scarf 11
//skirt 12, coat 13, longsleeve 19
//cloudy 14, fog 15, wind 16, lightning 17, hail 18, rain 20
//drizzle 21, sunny 22, snow 23, pcloudy 24, danger 25

boolean forwardButton = false;
boolean backButton = false;
boolean plusButton = false;
boolean minusButton = false;
boolean onButton = false;
boolean programButton = false;
boolean washButton = false;

boolean lightsOn = true;
boolean updateCloset = false;
String temperature = "";
boolean newTemp = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(26, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  
  Serial.begin(9600);
  lcd.begin(20, 4);
  bluetooth.begin(9600);

  lcd.print("Welcome to Wearcast");
  
  // Read in values from EEPROM
  initializeCounts();

  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void loop() { 
  
  updateCloset = false;
  checkBluetooth();
  bLEDLCD();

  wearStuff;
  updateCloset = false;
  
  yayButtons();
  
  if(programButton){
    programmingMode();
  }
  
  if(onButton){
    if(lightsOn){
      lightsOn = false;
      strip.setBrightness(0);
    }
    else{
      lightsOn = true;
      strip.setBrightness(0);
    }
  }

  if(newTemp || programButton){
    newTemp = false;
    lcd.setCursor(0, 1);
    lcd.print("Temperature");
    lcd.setCursor(0, 2);
    lcd.print(temperature);
  }
}
