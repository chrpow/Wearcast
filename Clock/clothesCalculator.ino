// returns a String containing instructions for which clothes icons to light up
String clothesCalculator(int temp, char wind, char weather) {
  clothes = ""; // clear clothes String

  // fill clothes String
  // based on weather
  if (weather == rain || weather == lightningAndRain) {
    addChar(umbrella);
    addChar(rainJacket, coat);
    addChar(boots);
  }
  else if (weather == drizzle) {
    addChar(rainJacket, coat);
  }
  else if (weather == snow) {
    addChar(coat);
    addChar(boots);
  }
  else if (weather == sunny) {
    addChar(sunglasses);
  }
  else if (weather == hail) {
    addChar(coat);
    addChar(boots);
    addChar(umbrella);
    addChar(scarf);
    addChar(hat);
    addChar(pants);
    addChar(longSleeve);
  }
  
  // based on wind
  if (wind == windy) {
    addChar(longSleeve);
    addChar(pants);
  }
  
  // based on temperature
  if (temp <= 42) {
    addChar(hat);
    addChar(gloves);
    addChar(scarf);
    addChar(coat);
  }
  if (temp <= 50) {
    addChar(sweater);
  }
  if (temp <= 60) {
    addChar(pants);
    addChar(longSleeve);
  }
  if (temp > 60) {
    addChar(shorts, pants);
    addChar(tShirt, longSleeve);
    addChar(skirt, pants);
  }
  // add basic clothing articles
  if (!isPresent(boots)) {
    addChar(shoes);
  }
  if (!isPresent(longSleeve)) {
    addChar(tShirt);
  }
  

  // clean up string
  // coat has priority over rainJacket
  if (isPresent(coat)) {
    clothes.replace(rainJacket, 0);
  }
  // longSleeve has priority over tShirt
  if (isPresent(longSleeve)) {
    clothes.replace(tShirt, 0);
  }
  // pants has priority over shorts and skirt
  if (isPresent(pants)) {
    clothes.replace(shorts, 0);
    clothes.replace(skirt, 0);
  }

  return clothes;
}

bool isPresent(char c) {
  return (clothes.indexOf(c) != -1);
}

void addChar(char c) {
  if (!isPresent(c)) {
    clothes += c;
  }
}

void addChar(char c, char d) {
  if (!isPresent(c) && !isPresent(d)) {
    clothes += c;
  }
}

