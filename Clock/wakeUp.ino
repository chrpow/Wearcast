// buzzes the alarm, stopping when the alarm button is pressed or a minute has elapsed
void wakeUp(int currentMin, int currentSec) {
  const int PITCH = 1000; // pitch of alarm
  while (true) {
    // continue to show time
    displayTime();

    // sound buzzer every other second
    if (second() % 2 == 0) {
      tone(buzzer, 1000);
    }
    else noTone(buzzer);

    // end conditions
    if (second() > 58) {
      noTone(buzzer);
      break;
    }
    else if (digitalRead(alarm) == LOW || digitalRead(alarmMode) == LOW) {
      noTone(buzzer);
      delay(350);
      break;
    }
  }
}

