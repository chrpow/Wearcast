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
int digit1  = 37;   // 1 = common cathode(-) digit 1
int digit2  = 35;  // 2 = common cathode(-) digit 2
int dots    = 31;  // 4 = common cathode(-) L1, L2, L3 --L1 &amp; L2 are the : dots
int digit3  = 27;  // 6 = common cathode(-) digit 3
int digit4  = 23;   // 8 = common cathode(-) digit 4

int A  = 32;   // 14 = anode A, L1
int B  = 36;   // 16 = anode B, L2
int C  = 30;   // 13 = anode C, L3
int D  = 33;   //  3 = anode D
int E  = 29;   //  5 = anode E
int F  = 26;   // 11 = anode F
int G  = 34;   // 15 = anode G
int DP = 25;   //  7 = anode DP --decimal points

int set = 38;
int alarm = 39;
int down = 40;
int up = 41;

int setState = 0;
int alarmState = 0;
int downState = 0;
int upState = 0;

int alarmHour;
int alarmMin;

void setup() {
  // Setup all digital outputs
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(dots, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
  //pinMode (mode_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  while(true) {
    setState = digitalRead(set);
    alarmState = digitalRead(alarm);
    showTime(1, minute() / 10);
    showTime(2, minute() % 10);
    if ((second() % 10) % 2 == 0) showTime(0, ':');
    showTime(3, second() / 10);
    showTime(4, second() % 10);
    if (setState == HIGH) {
      delay(200);
      setFace();
    }
    if (alarmState == HIGH) {
      delay(200);
      setAlarm();
    }
  }
}
