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
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Time.h>
#include<TextFinder.h>


static char error        = '`';
static char tShirt       = 'a';
static char pants        = 'b';
static char shorts       = 'c';
static char sunglasses   = 'd';
static char umbrella     = 'e';
static char boots        = 'f';
static char gloves       = 'g';
static char sweater      = 'h';
static char rainJacket   = 'i';
static char hat          = 'j';
static char shoes        = 'k';
static char scarf        = 'l';
static char skirt        = 'm';
static char coat         = 'n';
static char longSleeve   = 'o';
static char hail         = 'p';
static char lightning    = 'q';
static char windy        = 'r';
static char fog          = 's';
static char cloudy       = 't';
static char rain         = 'u';
static char drizzle      = 'v';
static char sunny        = 'w';
static char snow         = 'x';
static char partlyCloudy = 'y';
static char danger       = 'z';
static char lightningAndRain = '{';
static char lightningAndSnow = '|';
static char lightningAndHail = '}';
static char alarmChar = '$'; // char to symbolize an alarm activation
  
// weather API info

static char respBuf[4096]; // response buffer

// API info
#define WUNDERGROUND "api.wunderground.com"
#define WU_API_KEY "0936c57b58cbf6bc" // weather underground API key
#define WU_LOCATION "19104"           // zip code of clock. could implement IP location
const char WUNDERGROUND_REQ[] =       // HTTP request
    "GET /api/" WU_API_KEY "/conditions/q/" WU_LOCATION ".json HTTP/1.1\r\n"
    "User-Agent: ESP8266/0.1\r\n"
    "Accept: */*\r\n"
    "HOST:" WUNDERGROUND "\r\n"
    "Connection: close\r\n"
    "\r\n";
    
// Bluetooth info
SoftwareSerial BTSerial ( 2 , 3 ); //RX TX

// Ethernet info
byte mac[] = { 0x90 , 0xA2 , 0xDA , 0x0E , 0x07 , 0xBE };
IPAddress ip(192, 168, 1, 104); //TODO change to real address


// assign pins
const int digit1 = 37;   // 1 = common cathode(-) digit 1
const int digit2 = 35;   // 2 = common cathode(-) digit 2
const int dots   = 31;   // 4 = common cathode(-) L1, L2, L3 --L1 and L2 are the : dots
const int digit3 = 27;   // 6 = common cathode(-) digit 3
const int digit4 = 23;   // 8 = common cathode(-) digit 4

const int A  = 32;        // 14 = anode A, L1
const int B  = 36;        // 16 = anode B, L2
const int C  = 30;        // 13 = anode C, L3
const int D  = 33;        //  3 = anode D
const int E  = 29;        //  5 = anode E
const int F  = 28;        // 11 = anode F
const int G  = 34;        // 15 = anode G
const int DP = 25;        //  7 = anode DP --decimal points

const int set   = 7;   // button to set current time
const int alarm = 6; // button to set alarm
const int down  = 5;  // button to decrement numbers on screen
const int up    = 4;    // button to increment numbers on screen

const int buzzer = 48;    // alarm buzzer
const int alarmMode = 8; // switch to turn the alarm functionality on or off

// indicator LED's
const int alarmLED   = 38;
const int timeLED    = 39;
const int weatherLED = 40;

int alarmHour; // hour of wake up time
int alarmMin;  // minute of wake up time

static String clothes = "";
static String transmission = "";

void setup() {
  // set up all digital outputs
  // positions
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(dots, OUTPUT);

  // segments
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  //buzzer
  pinMode(buzzer, OUTPUT);

  // indicator LED's
  pinMode(alarmLED, OUTPUT);
  pinMode(timeLED, OUTPUT);
  pinMode(weatherLED, OUTPUT);

  digitalWrite(alarmLED, LOW);
  digitalWrite(timeLED, LOW);
  digitalWrite(weatherLED, LOW);
  
  // set up all digital inputs
  // programming buttons
  pinMode(set, INPUT);
  pinMode(alarm, INPUT);
  pinMode(down, INPUT);
  pinMode(up, INPUT);

  // alarm on/off switch
  pinMode(alarmMode, INPUT);

  Ethernet.begin(mac, ip); // initialize Ethernet
  BTSerial.begin(115200);  // initialize bluetooth serial
  Serial.begin(9600);      // initialize hardware serial (debugging)
  BTSerial.print("$");
  BTSerial.print("$");
  BTSerial.print("$");
  delay(100);
  BTSerial.println("U,9600,N");
  BTSerial.begin(9600);
}

void loop() {
      // main loop
  while(true) {
    // update weather at top of hour
    if (minute() == 0 && second() == 0) updateWeather(0);
    // check if it is time to sound alarm
    if(hour() == alarmHour && minute() == alarmMin && second() < 5 && digitalRead(alarmMode) == HIGH) {
      updateWeather(1);
      wakeUp(hour(), minute());
    }

    // show current time
    displayTime();

    // has set time or set alarm been pushed?
    if (digitalRead(set) == LOW) {
      delay(400);
      setFace();
    }
    if (digitalRead(alarm) == LOW) {
      delay(400);
      setAlarm();
    }
  }
}
