boolean yayButtons(){
  forwardButton = false;
  backButton = false;
  plusButton = false;
  minusButton = false;
  onButton = false;
  programButton = false;
  washButton = false;

  delay(200);
    
  if(analogRead(button1) < 500){
    forwardButton = true;
    return true;
  }
  else if(analogRead(button2) < 500){
    backButton = true;
    return true;
  }
  else if(analogRead(button3) < 500){
    plusButton = true;
    return true;
  }
  else if(analogRead(button4) < 500){
    minusButton = true;
    return true;
  }
  else if(analogRead(button5) < 500){
    onButton = true;
    return true;
  }
  else if(analogRead(button6) < 500){
    programButton = true;
    return true;
  }
  else if(!digitalRead(button7)){
    washButton = true;
    return true;
  }
  else{
    return false;
  }
}
