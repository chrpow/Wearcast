void programmingMode(){
  lcd.clear();
  lcd.print("Programming Mode");
  
  yayButtons();
  
  int currentState = 0;
  Serial.println(currentState);
  delay(10);
  
  boolean completed = false;

//gloves 0, boots 1, umbrella 2, glasses 3, shorts 4, pants 5
//tshirt 6, sweater 7, rainjacket 8, hat 9, shoes 10, scarf 11
//skirt 12, coat 13, longsleeve 19
  
  while(!completed){
    //update clothes item
    if(forwardButton && currentState < numClothesOptions - 2){
      currentState++;
    }
    if(forwardButton && currentState == numClothesOptions - 2){
      currentState = 19;
    }
    
    if(backButton && currentState > 0 && currentState < 19){
      currentState--;
    }
    if(backButton && currentState == 19){
      currentState = numClothesOptions - 1;
    }

    //increment quantity in memory
    int modifiedState = currentState;
    if(currentState == 19){
      modifiedState = 14;
    }
    
    if(plusButton){
      clothesCounts[modifiedState][0] += 1;
      EEPROM.write(((modifiedState + 1) * 2) - 1, clothesCounts[currentState][0]);
      //also increment current clothes state
      clothesCounts[modifiedState][1] += 1;
    }
    if(minusButton && clothesCounts[modifiedState][0] > 0){
      clothesCounts[modifiedState][0] -= 1;
      EEPROM.write(((modifiedState + 1) * 2) - 1, clothesCounts[modifiedState][0]);

      //also increment current clothes state
      if(clothesCounts[modifiedState][1] > 0){
        clothesCounts[modifiedState][1] -= 1; 
      }
    }
    //leave programming mode
    yayButtons();
    if(programButton){
//      for (int i=0; i < strip.numPixels(); i++) {
//        strip.setPixelColor(i, 0, 0, 0);
//      }
//      strip.show();    
      completed = true;
    }

    pLEDtoLCD(currentState);
    
  } 
}

