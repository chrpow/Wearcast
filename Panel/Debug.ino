void printlots(){
  for(int i = 0; i < numClothesOptions; i++){
    Serial.print(clothesCounts[i][0]);
  }
  Serial.println();
  for(int i = 0; i < numClothesOptions; i++){
    Serial.print(clothesCounts[i][1]);
  }
  Serial.println();
  Serial.println();
  delay(20);
  
}

