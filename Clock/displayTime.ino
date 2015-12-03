// Writes the current time to the digital clock face
void displayTime(int currentMin, int currentSec) {
  showTime(1, currentMin / 10); // first digit
  showTime(2, currentMin % 10);                     // second digit
  if ((currentSec % 10) % 2 == 0) showTime(0, ':'); // colon
  showTime(3, currentSec / 10);                     // third digit
  showTime(4, currentSec % 10);                     // fourth digit
}

