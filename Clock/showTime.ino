// light up digit j at position k
void showTime(byte k, char j) {
  position(k);
  turn(j);
  off();
}

// selects the digit to light up
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

// turns off display in between writes
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

// writes digit num to whatever position is active
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

