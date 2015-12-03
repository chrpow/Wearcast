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
