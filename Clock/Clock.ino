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

#include <SPI.h>
#include <Ethernet.h>
#include <Time.h>

// assign pins
const int digit1  = 37;   // 1 = common cathode(-) digit 1
const int digit2  = 35;   // 2 = common cathode(-) digit 2
const int dots    = 31;   // 4 = common cathode(-) L1, L2, L3 --L1 and L2 are the : dots
const int digit3  = 27;   // 6 = common cathode(-) digit 3
const int digit4  = 23;   // 8 = common cathode(-) digit 4

const int A  = 32;        // 14 = anode A, L1
const int B  = 36;        // 16 = anode B, L2
const int C  = 30;        // 13 = anode C, L3
const int D  = 33;        //  3 = anode D
const int E  = 29;        //  5 = anode E
const int F  = 26;        // 11 = anode F
const int G  = 34;        // 15 = anode G
const int DP = 25;        //  7 = anode DP --decimal points

const int set = 38;   // button to set current time
const int alarm = 39; // button to set alarm
const int down = 40;  // button to decrement numbers on screen
const int up = 41;    // button to increment numbers on screen

const int buzzer = 48;    // alarm buzzer
const int alarmMode = 42; // switch to turn the alarm functionality on or off

int alarmHour; // hour of wake up time
int alarmMin;  // minute of wake up time

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
  
  // set up all digital inputs
  // programming buttons
  pinMode(set, INPUT);
  pinMode(alarm, INPUT);
  pinMode(down, INPUT);
  pinMode(up, INPUT);

  // alarm on/off switch
  pinMode(alarmMode, INPUT);

  // initialize serial (debugging)
  Serial.begin(9600);
}

void loop() {
  // main loop
  while(true) {
      // need an "alarm enable" switch
      // check if it is time to sound alarm
    if(hour() == alarmHour && minute() == alarmMin && digitalRead(alarmMode) == HIGH) {
      wakeUp(hour(), minute());
    }

    // show current time
    displayTime(minute(), second());

    // has set time or set alarm been pushed?
    if (digitalRead(set) == HIGH) {
      delay(200);
      setFace();
    }
    if (digitalRead(alarm) == HIGH) {
      delay(200);
      setAlarm();
    }
  }
}
