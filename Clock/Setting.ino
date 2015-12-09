// set current time on clockface
void setFace() {
  // turn on light
  digitalWrite(timeLED, HIGH);
  
  byte hourMin = 0; // 0: editing the hour, 1: editing the minute
  
  int currentHour = hour();
  int currentMin = minute();
  
  while(true) {    
    displayTime(currentHour, currentMin);

    // if set is pressed, move to next digit or end programming mode
    if (digitalRead(set) == LOW) {
      if (hourMin == 0) {
        hourMin = 1;
        delay(350);
      }
      else {
        setTime(currentHour, currentMin, 0, 0, 0, 2015);
        digitalWrite(timeLED, LOW);
        delay(1100);
        return;
      }
    }

    // decrement number
    if (digitalRead(down) == LOW) {
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
        delay(200);
      }
    }

    // increment number
    if (digitalRead(up) == LOW) {
      if (hourMin == 0) {
        currentHour = (currentHour + 1) % 24;
        delay(200);
      }
      else {
        currentMin = (currentMin + 1) % 60;
        delay(200);
      }
    }
  }
}

// set alarm time
void setAlarm() {
  // turn on light
  digitalWrite(alarmLED, HIGH);
  
  byte hourMin = 0; // 0: editing the hour, 1: editing the minute
  
  while(true) {
    displayTime(alarmHour, alarmMin);

    // if alarm is pressed, move to next number or exit programming mode
    if (digitalRead(alarm) == LOW) {
      if (hourMin == 0) {
        hourMin = 1;
        delay(350);
      }
      else {
        digitalWrite(alarmLED, LOW);
        delay(1100);
        return;
      }
    }

    // increment number
    if (digitalRead(down) == LOW) {
      if (hourMin == 0) {
        alarmHour--;
        if (alarmHour == -1) {
          alarmHour = 23;
        }
        delay(200);
      }
      else {
        alarmMin--;
        if (alarmMin == -1) {
          alarmMin = 59;
        }
        delay(200);
      }
    }

    // decrement number
    if (digitalRead(up) == LOW) {
      if (hourMin == 0) {
        alarmHour = (alarmHour + 1) % 24;
        delay(200);
      }
      else {
        alarmMin = (alarmMin + 1) % 60;
        delay(200);
      }
    }
  }
}
