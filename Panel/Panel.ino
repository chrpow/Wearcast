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
