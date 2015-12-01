//T-Shirt 0
//L-Shirt 1
//Sweater 2
//Rain Jacket 3
//Coat 4
//Pants 5
//Shorts 6
//Skirt 7
//Umbrella 8
//Shoes 9
//Boots 10
//Hat 11
//Sunglasses 12
//Gloves 13
//Scarf 14

int[][] clothesCounts = new int[15][2]; //1: Max 2: Current

void setup() {
  // Read in values from EEPROM
  initializeCounts();
  
 
}

void loop() {
  if(digitalRead(programButton)){
    programmingMode();
  }
  
}
