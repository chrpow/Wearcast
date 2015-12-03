// buzzes the alarm, stopping when the alarm button is pressed or a minute has elapsed
void wakeUp(int currentMin, int currentSec) {
  const int PITCH = 1000; // pitch of alarm
  while (true) {
    // continue to show time
    displayTime(minute(), second());

    // sound buzzer every other second
    if (second() % 2 == 0) {
      tone(buzzer, 1000);
    }
    else noTone(buzzer);

    // end conditions
    if (second() > 58 || digitalRead(alarm) == HIGH) {
      noTone(buzzer);
      delay(300);
      break;
    }
  }
}

