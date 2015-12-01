void programmingMode(){
  if(digitalRead(resetButton)){
    reset();
  }
  int currentState = 0;
  boolean completed = false;
  
  while(!completed){
    //update clothes item
    if(digitalRead(forwardButton) && currentState < 14){
      currentState++;
    }
    if(digitalRead(backButton) && currentState > 0){
      currentState--;
    }

    //increment quantity in memory
    if(digitalRead(plusButton)){
      clothesCounts[currentState][0] += 1;
      EEPROM.write(((currentState + 1) * 2) - 1, clothesCounts[currentState][0]);

      //also increment current clothes state
      clothesCounts[currentState][1] += 1;
    }
    if(digitalRead(minusButton) && clothesCounts[currentState][0] > 0){
      clothesCounts[currentState][0] -= 1;
      EEPROM.write(((currentState + 1) * 2) - 1, clothesCounts[currentState][0]);

      //also increment current clothes state
      clothesCounts[currentState][1] -= 1;
    }
    
    //leave programming mode
    if(digitalRead(programmingButton)){
      completed = true;
    }
  } 
  
}

void reset(){
  EEPROM.write(0, 200);
  for(int i = 1; i < EEPROM.length; i++){
    EEPROM.write(i, 0);
  }
}

