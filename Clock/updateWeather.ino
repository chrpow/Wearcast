void updateWeather() {
  // create connection w/ EthernetClient
  EthernetClient client;
  const int httpPort = 80;
  // if connection fails
  if (!client.connect(WUNDERGROUND, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // This will send the http request to the server
  Serial.print(WUNDERGROUND_REQ);
  client.print(WUNDERGROUND_REQ);
  client.flush();

  // Collect http response headers and content from Weather Underground
  // HTTP headers are discarded.
  // The content is formatted in JSON and is left in respBuf.
  int respLen = 0;
  bool skip_headers = true;
  while (client.connected() || client.available()) {
    if (skip_headers) {
      String aLine = client.readStringUntil('\n');
      Serial.println(aLine);
      // Blank line denotes end of headers
      if (aLine.length() <= 1) {
        skip_headers = false;
      }
    }
    else {
      int bytesIn;
      bytesIn = client.read((uint8_t *)&respBuf[respLen], sizeof(respBuf) - respLen);
      Serial.print("bytesIn "); Serial.println(bytesIn);
      if (bytesIn > 0) {
        respLen += bytesIn;
        if (respLen > sizeof(respBuf)) respLen = sizeof(respBuf);
      }
      else if (bytesIn < 0) {
        Serial.print("read error ");
        Serial.println(bytesIn);
      }
    }
    delay(1);
  }
  client.stop();

  if (respLen >= sizeof(respBuf)) {
    Serial.print(F("respBuf overflow "));
    Serial.println(respLen);
    return;
  }
  // Terminate the C string
  respBuf[respLen++] = '\0';
  Serial.print(F("respLen "));
  Serial.println(respLen);
  //Serial.println(respBuf);

  return;
}

