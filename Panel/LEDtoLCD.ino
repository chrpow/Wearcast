void pLEDtoLCD(int currentState){
//gloves 0, boots 1, umbrella 2, glasses 3, shorts 4, pants 5
//tshirt 6, sweater 7, rainjacket 8, hat 9, shoes 10, scarf 11
//skirt 12, coat 13, longsleeve 19 
  
  lcd.clear();
  lcd.print("Programming Mode");
  lcd.setCursor(0, 1);
  
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
      lcd.print("Skirts"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); lcd.setCursor(0, 3); lcd.print("Clean: " + clothesCounts[currentState][1]);
      strip.setPixelColor(currentState, 0, 255, 0);
      break;   
    case 13: 
      lcd.print("Coats"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[currentState][0]); //lcd.setCursor(0, 3); lcd.print("Clean: " + clothesCounts[currentState][1]);
      strip.setPixelColor(currentState, 0, 255, 0);
      break;   
    case 19: 
      lcd.print("Long Sleeves"); lcd.setCursor(0, 2); lcd.print("In closet: "); lcd.print(clothesCounts[14][0]); lcd.setCursor(0, 3); lcd.print("Clean: " + clothesCounts[14][1]);
      strip.setPixelColor(currentState, 0, 255, 0);
      break; 
  }
}

