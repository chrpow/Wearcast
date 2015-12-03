void initializeCounts(){
  if(EEPROM.read(0) == 150){
    Serial.println("here1");
    delay(10);
      int j = 0;
      for(int i = 0; i < numClothesOptions * 2; i += 2){
        Serial.print("l");
        delay(5);
        clothesCounts[j][0] = EEPROM.read(i + 1) - '0';
        clothesCounts[j][1] = EEPROM.read(i + 2) - '0';
        j++;
      }
      Serial.println("here2");
      delay(10);
  }  
  else{
    Serial.print("here3");
    reset();
  }   
} 

void reset(){
  //Debug
//  for (int i=0; i < strip.numPixels(); i++) {
//        strip.setPixelColor(i, 0, 0, 0);
//  }
  EEPROM.write(0, 200);
  for(int i = 1; i < EEPROM.length(); i++){
    EEPROM.write(i, 0);
  }
  for(int i = 0; i < numClothesOptions; i++){
    clothesCounts[i][0] = 0;
    clothesCounts[i][1] = 0;
   }
}
