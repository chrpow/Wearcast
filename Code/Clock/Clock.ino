const byte places[4][7] = { // arrays of pin allocations for each place
 //A   B   C   D   E   F   G
 {22, 23, 24, 25, 26, 27, 28}, // first digit (far left)
 {29, 30, 31, 32, 33, 34, 35}, // second digit
 {36, 37, 38, 39, 40, 41, 42}, // third digit
 {43, 44, 45, 46, 47, 48, 49}  // fourth digit (far right)
};

const byte digits[10][7] = { // arrays of pin states for each digit
 //A  B  C  D  E  F  G
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // set all LED pins to OUTPUT
  for (int i = 0; i < sizeof(places) / sizeof(places[0]); i++) {
    for (int j = 0; j < sizeof(places[0]); j++) {
    pinMode(places[i][j], OUTPUT);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

// displays the given digit in the given place (1 through 4) on the clock
void writeDigit(byte place, byte digit) {
  // write each segment to its corresponding state based on the given digit
  for (int i = 0; i < sizeof(places[0]); i++) {
    digitalWrite(places[place][i], digits[digit][i]);
  }
}

