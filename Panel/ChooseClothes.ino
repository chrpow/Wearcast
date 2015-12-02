boolean[] chooseClothes(boolean[] weather){
  //Implement a point system to choose between clothes
  //sun 0, snow 1, mcloudy 2, pcloudy 3, fog 4, rain 5, pour 6, 
  //hail 7, thunder 8, catastrophic 9

  int scores[16];
  //t-shirt 0, sweater 1, rain jacket 2, coat 3, pants 4, shorts 5, umbrella 6, shoes 7,
  //boots 8, hat 9, sunglasses 10, gloves 11, scarf 12
  
  for(int i = 0; i < scores.length; i++){
    scores[i] = 0;
  }
  
  //sun
  if(weather[0]){
    scores[0] += 1; //tshirt
    scores[5] += 1; //shorts
    scores[7] += 1; //shoes
    scores[9] += 1; //hat
    scores[10] += 1; //sunglasses
  }

  //snow
  if(weather[1]){
    scores[2] += 1; //tshirt
    scores[3] += 1; //shorts
    scores[7] += 1; //shoes
    scores[9] += 1; //hat
    scores[10] += 1; //sunglasses
  }
  
}

