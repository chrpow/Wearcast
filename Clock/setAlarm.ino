// set alarm time
void setAlarm() {
  byte hourMin = 0; // 0: editing the hour, 1: editing the minute
  
  while(true) {
    displayTime(alarmHour, alarmMin);

    // if alarm is pressed, move to next number or exit programming mode
    if (digitalRead(alarm) == HIGH) {
      if (hourMin == 0) {
        hourMin = 1;
        delay(200);
      }
      else {
        delay(200);
        return;
      }
    }

    // increment number
    if (digitalRead(down) == HIGH) {
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
        delay(150);
      }
    }

    // decrement number
    if (digitalRead(up) == HIGH) {
      if (hourMin == 0) {
        alarmHour = (alarmHour + 1) % 24;
        delay(200);
      }
      else {
        alarmMin = (alarmMin + 1) % 60;
        delay(150);
      }
    }
  }
}
