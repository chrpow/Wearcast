void yayButtons(){
  forwardButton = false;
  backButton = false;
  plusButton = false;
  minusButton = false;
  onButton = false;
  programButton = false;
  washButton = false;

  delay(100);
  int a = analogRead(buttons);
  //button 1
  if(a > 800){
    forwardButton = true;
  }
  //button 2
  else if(a > 425){
    backButton = true;
  }
  //button 3
  else if(a > 320){
    plusButton = true;
    Serial.print(".");
    delay(10);
  }
  //button 4
  else if(a > 255){
    minusButton = true;
    Serial.print(".");
    delay(10);
  }
  //button 5
  else if(a > 215){
    onButton = true;
  }
  //button 6
  else if(a > 182){
    programButton = true;
  }
  //button 7
  else if(a > 100){
    washButton = true;
  }
  printlots();
}
