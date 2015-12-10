void pLEDLCD(int currentState, boolean yay){
//gloves 0, boots 1, umbrella 2, glasses 3, shorts 4, pants 5
//tshirt 6, sweater 7, rainjacket 8, hat 9, shoes 10, scarf 11
//skirt 12, coat 13, longsleeve 19 
  
  if(yay){
    lcd.clear();
    lcd.print("Programming Mode");
    lcd.setCursor(0, 1);

    strip.clear();
    switch(currentState){
      case 0: 
        lcd.print("Gloves"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]);
        strip.setPixelColor(currentState, 0, 255, 0);
        strip.show();
        break;
      case 1: 
        lcd.print("Boots"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;
      case 2: 
        lcd.print("Umbrella"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;   
      case 3: 
        lcd.print("Sun-Glasses"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;    
      case 4: 
        lcd.print("Shorts"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); lcd.setCursor(0, 3); lcd.print("Clean: "); lcd.print(clothesCounts[currentState][1]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;    
      case 5: 
        lcd.print("Pants"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); lcd.setCursor(0, 3); lcd.print("Clean: "); lcd.print(clothesCounts[currentState][1]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;    
      case 6: 
        lcd.print("T-shirts"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); lcd.setCursor(0, 3); lcd.print("Clean: "); lcd.print(clothesCounts[currentState][1]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;    
      case 7: 
        strip.setPixelColor(currentState, 0, 255, 0);
        lcd.print("Sweaters"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); lcd.setCursor(0, 3); lcd.print("Clean: "); lcd.print(clothesCounts[currentState][1]);
      break;    
      case 8: 
        strip.setPixelColor(currentState, 0, 255, 0);
        lcd.print("Rain Jackets"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]);
        break;    
      case 9: 
        lcd.print("Hats"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;    
      case 10: 
        lcd.print("Shoes"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); //lcd.setCursor(0, 3); lcd.print("Clean: " + clothesCounts[currentState][1]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;    
      case 11: 
        lcd.print("Scarves"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); //lcd.setCursor(0, 3); lcd.print("Clean: " + clothesCounts[currentState][1]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;    
      case 12: 
        lcd.print("Skirts"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); lcd.setCursor(0, 3); lcd.print("Clean: "); lcd.print(clothesCounts[currentState][1]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;   
      case 13: 
        lcd.print("Coats"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); //lcd.setCursor(0, 3); lcd.print("Clean: " + clothesCounts[currentState][1]);
        strip.setPixelColor(currentState, 0, 255, 0);
        break;   
      case 14: 
        lcd.print("Long Sleeves"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[14][0]); lcd.setCursor(0, 3); lcd.print("Clean: "); lcd.print(clothesCounts[14][1]);
        strip.setPixelColor(19, 0, 255, 0);
        break; 
    } 
    strip.show();  
  }
}

void bLEDLCD(){
  strip.clear();
  for(int i = 0; i < numClothesOptions + numWeatherOptions; i++){
    if(states[i]){
      if((i < 14 && i >= 0) || i == 19){
        if(clothesCounts[i][1] < 2){
          strip.setPixelColor(i, 255, 0, 0);
        }
        else if(clothesCounts[i][1] < 5){
          strip.setPixelColor(i, 255, 255, 0);
        }
        else{
          strip.setPixelColor(i, 0, 255, 0);
        }

        if(clothesCounts[14][1] < 2){
          strip.setPixelColor(19, 255, 0, 0);
        }
        else if(clothesCounts[14][1] < 5){
          strip.setPixelColor(19, 255, 255, 0);
        }
        else{
          strip.setPixelColor(19, 0, 255, 0);
        }
      }
      else if(i == 22 || i == 17 || i == 15 || i == 14 || i == 24 || i == 25){
        if(states[22]){
          strip.setPixelColor(22, 255, 255, 0);
        }
        if(states[17]){
          strip.setPixelColor(17, 255, 255, 0);
        }
        if(states[15]){
          strip.setPixelColor(15, 255, 255, 255);
        }
        if(states[14]){
          strip.setPixelColor(14, 255, 255, 255);
        }
        if(states[24]){
          strip.setPixelColor(24, 255, 255, 255);
        }
        if(states[25]){
          strip.setPixelColor(25, 255, 0, 0);
        }
      }
      else{
        strip.setPixelColor(i, 0, 0, 255);
      }
    }
  }
  strip.show();
}


