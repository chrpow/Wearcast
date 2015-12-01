void initializeCounts(){
  if(EEPROM.read(0) == 200){
      int i = 0;
      while(i < 30){
        clothesCounts[i][0] = EEPROM.read(i + 1);
        clothesCounts[i][1] = EEPROM.read(i + 2);

        i += 2;
      }
      else{
        reset();
      }
  }    
}  
