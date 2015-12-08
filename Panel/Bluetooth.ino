void checkBluetooth(){
  Serial.print(".");
  String info = "";
  
  while(bluetooth.available() > 0){
    info += (char)bluetooth.read();
  }
  Serial.print(info);

  // info = "<$45abcdefghkfnt>"; //DEBUG


  temperature = "";
  if(info.length() > 0){
    newTemp = true;
    for(int i = 0; i < info.length(); i++){
      if(info.charAt(i) >= '0' && info.charAt(i) <= '9'){
        temperature += info.charAt(i);
      }
    }
  }

  Serial.print(temperature);

  for(int i = 0; i < info.length(); i++){   
    switch(info.charAt(i)){
//gloves 0, boots 1, umbrella 2, glasses 3, shorts 4, pants 5
//tshirt 6, sweater 7, rainjacket 8, hat 9, shoes 10, scarf 11
//skirt 12, coat 13, longsleeve 19
      case '$': updateCloset = true;
      break;
      case 'a': states[6] = true;
      break;
      case 'b': states[5] = true;
      break;
      case 'c': states[4] = true;
      break;
      case 'd': states[3] = true;
      break;
      case 'e': states[2] = true;
      break;
      case 'f': states[1] = true;
      break;
      case 'g': states[0] = true;
      break;
      case 'h': states[7] = true;
      break;
      case 'i': states[8] = true;
      break;
      case 'j': states[9] = true;
      break;
      case 'k': states[10] = true;
      break;
      case 'l': states[11] = true;
      break;
      case 'm': states[12] = true;
      break;
      case 'n': states[13] = true;
      break;
      case 'o': states[19] = true;
      break;
//cloudy 14, fog 15, wind 16, lightning 17, hail 18, rain 20
//drizzle 21, sunny 22, snow 23, pcloudy 24, danger 25        
      case 'p':  states[18] = true;
      break;
      case 'q': states[17] = true;
      break;
      case 'r': states[16] = true;
      break;
      case 's': states[15] = true;
      break;
      case 't': states[14] = true;
      break;
      case 'u': states[20] = true;
      break;
      case 'v': states[21] = true;
      break;
      case 'w': states[22] = true;
      break;
      case 'x': states[23] = true;
      break;
      case 'y': states[24] = true;
      break;
      case 'z': states[25] = true;
      break;
      default:
        break;
    }
  }
}

