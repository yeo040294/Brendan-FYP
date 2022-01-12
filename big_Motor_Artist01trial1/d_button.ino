int getleftright(int option, int current_option) {
  if (!digitalRead(buttonPin_SET)) return current_option;
  if (!digitalRead(buttonPin_RHT)) {
    delay(100);
    Serial.println("Right Pin Is Pressed.");
    return (current_option == option - 1) ? 0 : current_option = current_option + 1;
  }

  if (!digitalRead(buttonPin_LFT)) {
    delay(100);
    Serial.println("left Pin Is Pressed.");
    return (current_option == 0) ? option - 1 : current_option = current_option - 1;
  }
  return current_option;
}


int getupdown(int option, int current_option) {
  if (!digitalRead(buttonPin_SET)) return current_option;
  if (!digitalRead(buttonPin_DWN)) {
    Serial.println("down Pin Is Pressed.");
    delay(100);
    return (current_option == option - 1) ? 0 : ++current_option;
  }

  if (!digitalRead(buttonPin_UP)) {
    delay(100);
    return (current_option == 0) ? option - 1 : --current_option;
    Serial.println("up Pin Is Pressed.");
  }
  return current_option;
}


 
