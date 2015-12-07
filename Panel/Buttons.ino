boolean yayButtons(){
  forwardButton = false;
  backButton = false;
  plusButton = false;
  minusButton = false;
  onButton = false;
  programButton = false;
  washButton = false;

  delay(100);
  int a = analogRead(buttons);
  //Serial.println(a); //Debug
  
  //button 1
  if(a > 800){
    forwardButton = true;
    return true;
  }
  //button 2
  else if(a > 425){
    backButton = true;
    return true;
  }
  //button 3
  else if(a > 320){
    plusButton = true;
    return true;
  }
  //button 4
  else if(a > 230){
    minusButton = true;
    return true;
  }
  //button 5
  else if(a > 185){
    onButton = true;
    return true;
  }
  //button 6
  else if(a > 150){
    programButton = true;
    return true;
  }
  //button 7
  else if(a > 130){
    washButton = true;
    return true;
  }
  else{
    return false;
  }
}
