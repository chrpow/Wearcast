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

void setFace() {
  int hourMin = 0;
  int currentHour = 0;
  int currentMin = 0;
  while(true) {
    setState =   digitalRead(set);
    downState =  digitalRead(down);
    upState =    digitalRead(up);
    
    showTime(1, currentHour / 10);
    showTime(2, currentHour % 10);
    showTime(3, currentMin / 10);
    showTime(4, currentMin % 10);
    if (setState == HIGH) {
      if (hourMin == 0) {
        hourMin = 1;
        delay(200);
      }
      else {
        setTime(currentHour, currentMin, 0, 0, 0, 2015);
        Serial.print(hour());
        Serial.print(":");
        Serial.println(minute());
        delay(200);
        return;
      }
    }
    if (downState == HIGH) {
      if (hourMin == 0) {
        currentHour--;
        if (currentHour == -1) {
          currentHour = 23;
        }
        delay(200);
      }
      else {
        currentMin--;
        if (currentMin == -1) {
          currentMin = 59;
        }
        delay(150);
      }
    }
    if (upState == HIGH) {
      if (hourMin == 0) {
        currentHour = (currentHour + 1) % 24;
        delay(200);
      }
      else {
        currentMin = (currentMin + 1) % 60;
        delay(150);
      }
    }
  }
}
void setAlarm() {
  int hourMin = 0;
  int currentHour = alarmHour;
  int currentMin = alarmMin;
  while(true) {
    alarmState =   digitalRead(alarm);
    downState =  digitalRead(down);
    upState =    digitalRead(up);
    
    showTime(1, currentHour / 10);
    showTime(2, currentHour % 10);
    showTime(3, currentMin / 10);
    showTime(4, currentMin % 10);
    if (alarmState == HIGH) {
      if (hourMin == 0) {
        hourMin = 1;
        delay(200);
      }
      else {
        alarmHour = currentHour;
        alarmMin = currentMin;
        Serial.print(alarmHour);
        Serial.print(":");
        Serial.println(alarmMin);
        delay(200);
        return;
      }
    }
    if (downState == HIGH) {
      if (hourMin == 0) {
        currentHour--;
        if (currentHour == -1) {
          currentHour = 23;
        }
        delay(200);
      }
      else {
        currentMin--;
        if (currentMin == -1) {
          currentMin = 59;
        }
        delay(150);
      }
    }
    if (upState == HIGH) {
      if (hourMin == 0) {
        currentHour = (currentHour + 1) % 24;
        delay(200);
      }
      else {
        currentMin = (currentMin + 1) % 60;
        delay(150);
      }
    }
  }
}

// LIGHT-UP A DIGIT
// (Combines the next 3 functions into 1 simple call)
void showTime(byte k, char j) {
  position(k);
  turn(j);
  off();
}

// 7-SEGMENT DIGIT SELECTOR
void position(byte pos) {
  // DIGIT 1 --------------------
  if (pos == 1)
  {
    digitalWrite(digit1, HIGH);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
    digitalWrite(dots, LOW);
  }

  // DIGIT 2 --------------------
  if (pos == 2)
  {
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, HIGH);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
    digitalWrite(dots, LOW);
  }

  // COLON ----------------------
  if (pos == 0)
  {
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
    digitalWrite(dots, HIGH);
  }

  // DIGIT 3 --------------------
  if (pos == 3)
  {
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, HIGH);
    digitalWrite(digit4, LOW);
    digitalWrite(dots, LOW);
  }

  // DIGIT 4 --------------------
  if (pos == 4)
  {
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, HIGH);
    digitalWrite(dots, LOW);
  }
}

// TURN OFF DISPLAY
// (Eliminates "Light Shadows" from one digit to the next)
void off() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, HIGH);
  delayMicroseconds(50);
}
// DIGIT CREATION FUNCTIONS ------------
void turn(char num) {
  //-----------------------------// 0
  if (num == 0)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// 1
  if (num == 1)
  {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// 2
  if (num == 2)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// 3
  if (num == 3)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// 4
  if (num == 4)
  {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// 5
  if (num == 5)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// 6
  if (num == 6)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// 7
  if (num == 7)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// 8
  if (num == 8)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// 9
  if (num == 9)
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
    delay(1);
  }

  //-----------------------------// :
  if (num == ':')
  {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
    delay(1);
  }
}

