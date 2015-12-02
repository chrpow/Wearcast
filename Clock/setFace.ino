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
