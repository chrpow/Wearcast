void programmingMode(){
  lcd.clear();
  lcd.print("Programming Mode");
  
  boolean yay = yayButtons();
  
  int currentState = 0;
  pLEDLCD(currentState, HIGH);
  
  Serial.println(currentState);
  
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
    if(programButton){   
      completed = true;
    }

    pLEDLCD(modifiedState, yay);
    yay = yayButtons();
  } 
    lcd.clear();
    lcd.print("Welcome to Wearcast");
    lcd.setCursor(0, 1);
    lcd.print("Temperature");
    lcd.setCursor(0, 2);
    lcd.print(temperature);
      
    strip.clear();
    strip.show(); 
}

void wearStuff(){
  for(int i = 0; i < 14; i++){
    if(updateCloset && states[i]){
      clothesCounts[i][1] -= 1;
    }
  }
  if(updateCloset && states[19]){
      clothesCounts[19][1] -= 1;
  }
}

