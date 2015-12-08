void updateWeather(bool isAlarm) {
  // declare JSON object buffers
  char temp[20];
  char windSpeed[20];
  char weather[40];
  // clear transmission
  transmission = "";
  if (isAlarm) transmission += alarmChar; // char to symbolize alarm activation 
  // create connection w/ EthernetClient
  EthernetClient client;
  const int httpPort = 80;
  TextFinder finder(client);

  // send request
  if (client.connect(WUNDERGROUND, httpPort)) {
    Serial.println("connecting");
    
    // send the http request
    Serial.print(WUNDERGROUND_REQ);
    client.print(WUNDERGROUND_REQ);
  }
  else {
    Serial.println("disconnecting");
    return;
  }

  // parse JSON response for weather, temperature, and wind
  if (client.connected()) {
    if (finder.getString("weather\":\"", "\",", weather, 20) != 0) {
      Serial.print("Weather: ");
      Serial.println(weather);
    }
    else {
      Serial.println("No weather data");
    }
    if (finder.getString("\"temp_f\":", ",", temp, 6) != 0) {
      Serial.print("Temperature: ");
      Serial.println(temp);
    }
    else {
      Serial.println("No temperature data");
    }
    if (finder.getString("\"wind_mph\":", ",", windSpeed, 5) != 0) {
      Serial.print("Wind Speed: ");
      Serial.println(windSpeed);
    }
    else {
      Serial.println("No wind data");
    }
  }
  else {
    Serial.println("Disconnected");
  }
  // end communication
  client.stop();
  client.flush();

  // convert JSON buffers into usable data
  int tempInt = atoi(temp);
  char windChar = windToChar(atof(windSpeed));
  char weatherChar = weatherToChar(weather);

  Serial.print("tempInt: "); Serial.println(tempInt);
  Serial.print("windChar: "); Serial.println(windChar);
  Serial.print("weatherChar: "); Serial.println(weatherChar);
  Serial.println(clothesCalculator(tempInt, windChar, weatherChar));

  // append data into transmission
  transmission = transmission + tempInt; // temperature
  if (windChar != 0) {
    transmission = transmission + windChar; // wind status
  }
  transmission = transmission + weatherChar // weather
  + clothesCalculator(tempInt, windChar, weatherChar); // clothes
  
  // transmit data
  transmit(transmission);
  return;
}

// remove "Light/Heavy" from weather string
String simplifyString(String s) {
  if (s.startsWith("Light") || s.startsWith("Heavy")) {
    return s.substring(6);
  }
  else return s;
}

void transmit(String transmission) {
  BTSerial.print('<'); BTSerial.print(transmission); BTSerial.println('>');
  Serial.print('<'); Serial.print(transmission); Serial.println('>');
}

// converts weather condition char from JSON into a single char for transmission String
char weatherToChar(const char *weather) {
  String w = simplifyString(String(weather));

  if (w == "Drizzle" || w == "Spray" || w == "Rain Mist") {
    return drizzle;
  }
  else if (w == "Rain" || w == "Rain Showers" || w == "Freezing Drizzle" ||
           w == "Freezing Rain" || w == "Unknown Precipitation") {
    return rain;
  }
  else if (w == "Snow" || w == "Snow Grains" || w == "Low Drifting Snow" ||
           w == "Blowing Snow" || w == "Snow Showers" ||
           w == "Snow Blowing Snow Mist") {
    return snow;
  }
  else if (w == "Ice Crystals" || w == "Ice Pellets" || w == "Hail" ||
           w == "Ice Pellet Showers" || w == "Hail Showers" ||
           w == "Small Hail Showers" || w == "Small Hail") {
    return hail;
  }
  else if (w == "Mist" || w == "Fog" || w == "Fog Patches" ||
           w == "Freezing Fog" || w == "Patches of Fog" ||
           w == "Shallow Fog" || w == "Freezing Fog" ||
           w == "Partial Fog" || w == "Haze") {
    return fog;
  }
  else if (w == "Smoke" || w == "Volcanic Ash" || w == "Widespread Dust" ||
           w == "Sand" || w == "Dust Whirls" || w == "Sandstorm" ||
           w == "Low Drifting Widespread Dust" ||
           w == "Low Drifting Sand" || w == "Blowing Widespread Dust" ||
           w == "Blowing Sand") {
    return danger;
  }
  else if (w == "Overcast" || w == "Mostly Cloudy" ||
           w == "Funnel Cloud") {
    return cloudy;
  }
  else if (w == "Clear") {
    return sunny;
  }
  else if (w == "Partly Cloudy" || w == "Scattered Clouds") {
    return partlyCloudy;
  }
  else if (w == "Thunderstorm") {
    return lightning;
  }
  else if (w == "Thunderstorms and Rain") {
    return lightningAndRain;
  }
  else if (w == "Thunderstorms and Snow") {
    return lightningAndSnow;
  }
  else if (w == "Thunderstorms and Ice Pellets" ||
           w == "Thunderstorms with Hail" ||
           w == "Thunderstorms with Small Hail") {
    return lightningAndHail;
  }
  else return error;
}

// converts float wind speed into char for transmission String
char windToChar(float windSpeed) {
  if (windSpeed < 11) return 0;
  else if (windSpeed >= 11 && windSpeed < 34) return windy;
  else return danger;
}

