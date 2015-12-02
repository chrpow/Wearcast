#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

int clothesCounts[16][2];
#define pixelPin 6

#define forwardButton A0
#define backButton A1
#define plusButton A2
#define minusButton A3
#define onButton A4
#define programButton A5
#define washButton 13

boolean sun;
boolean snow;
boolean mcloudy;
boolean pcloudy;
boolean fog;
boolean rain;
boolean pour;
boolean hail;
boolean thunder;
boolean catastrophic;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, pixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  
  // Read in values from EEPROM
  initializeCounts();
  
  pinMode(forwardButton, INPUT);
  pinMode(backButton, INPUT);
  pinMode(plusButton, INPUT);
  pinMode(minusButton, INPUT);
  pinMode(onButton, INPUT);
  pinMode(programButton, INPUT);
  pinMode(washButton, INPUT);

  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void loop() {  
  if(digitalRead(programButton)){
    programmingMode();
  }
  if(digitalRead(onButton)){
    displayStates();
  }
}
