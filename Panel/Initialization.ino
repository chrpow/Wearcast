void initializeCounts(){
  if(EEPROM.read(0) == 200){
      int i = 0;
      while(i < 30){
        EEPROM.get(i + 1, clothesCounts[i][0]);
        EEPROM.get(i + 2, clothesCounts[i][1]);
        i = i + 2;
      }
  }  
  else{
    reset();
  }   
} 

void reset(){
  for (int i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 0, 0);
  }
  EEPROM.write(0, 200);
  for(int i = 1; i < EEPROM.length(); i++){
    EEPROM.write(i, 0);
  }
}
