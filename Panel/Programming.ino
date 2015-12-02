void programmingMode(){
  int currentState = 0;
  boolean completed = false;
  
  while(!completed){
    strip.setPixelColor(currentStateToPixel(), 0, 255, 0);
    strip.show();
    
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
      if(clothesCounts[currentState][1] > 0){
        clothesCounts[currentState][1] -= 1; 
      }
    }
    
    //leave programming mode
    if(digitalRead(programButton)){
      for (int i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, 0, 0, 0);
      }
      strip.show();    
      completed = true;
    }
  } 
}

//Fill in values --> values of clothes LEDs on board.
int currentStateToPixel(int currentState){
  switch{
  case 0
    return 5;
  case 1
    return 5;
  case 2
    return 5;
  case 3
    return 5;
  case 4
    return 5;
  case 5
    return 5;
  case 6
    return 5;
  case 7
    return 5;
  case 8
    return 5;
  case 9
    return 5;
  case 10
    return 5;
  case 11
    return 5;
  case 12
    return 5;
  case 13
    return 5;
  case 14
    return 5;
  }
}  

