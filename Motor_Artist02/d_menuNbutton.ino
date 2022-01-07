//menu display
void mainscreenoption()
{
  option = getleftright(8, option);
  while (option != newoption  )
  {
    switch (option) {
      case 0:
        startpage();
        break;
      case 1: instructs();
        break;
      case 2: sel = 0;
        choice(3, pat_choice, sel);                // pattern selection page
        break;
      case 3: pattern_1();
        //motorcode1();
        break;
      case 4: pattern_2();
        // motorcode2();
        break;
      case 5: selec = 0;
        choice(3, option_choice1, selec);         //rpm selection page
        break;
      case 6: sele = 0;
        choice(2, option_choice2, sele);         // delay selection page
        break;
      case 7:
        custom();
        break;
      default : break;
    }
    newoption = option;
  }
}

//menu setting
void menu(int menu_opt ,  const char *const string_table[]) {
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(30, 30);
  strcpy_P(buffer, (char *)pgm_read_word(&(string_table[0])));
  tft.println(buffer);
  for (int i = 1; i < menu_opt; i++)
  {
    tft.setTextSize(1);
    tft.setCursor(30, 50 + i * 10 - 10);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
    tft.println(buffer);
  }
  tft.setTextSize(1);
  tft.setCursor(133, 92);
  tft.print(F("SET"));
  tft.drawRect(130, 90, 22, 15, WHITE);
  tft.drawBitmap (10, 70, left_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
}

// option selection
void choice(int choice_opt ,  const char *const string_table[], int select) {

  tft.fillScreen(BLACK);
  for (int i = 0; i < choice_opt; i++)
  {
    tft.setTextSize(1);
    tft.setCursor(30, 60 + i * 20 - 20);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
    tft.println(buffer);
  }
  if (select == 0)
    tft.drawRect(28, 35, 60, 18, WHITE);
  else if (select == 1)
    tft.drawRect(28, 55, 60, 18, WHITE);
  else
    tft.drawRect(28, 75, 60, 18, WHITE);

  tft.setTextSize(1);
  tft.setCursor(133, 92);
  tft.print(F("SET"));
  tft.drawRect(130, 90, 22, 15, WHITE);
  //tft.drawRect(130, 90, 22, 15, WHITE);
  tft.drawBitmap (90, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (90, 90, down_15, 15, 15, WHITE, BLACK);
}

//customise variable
void state (int menu_opt, const char *const string_table[]) {
  int i = menu_opt;
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 35);
  strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
  tft.println(buffer);

  tft.setTextSize(1);
  tft.setCursor(133, 92);
  tft.print(F("SET"));
  tft.setTextSize(2);
  tft.drawRect(130, 90, 22, 15, WHITE);
  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
}

//update of customise variable ( rpm / clockwise / anticlockwise / delay / cycle )
int dataupdates( int opt)
{
  suboption = opt;

  //RPM update
  if (digitalRead(buttonPin_UP) == LOW && suboption == 0)
  {
    rpm = rpm  + 10;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && rpm  > 0 && suboption == 0)
  {
    rpm = rpm  - 10;
    delay(100);
  }

  // clockwise update
  if (digitalRead(buttonPin_UP) == LOW && suboption == 1)
  {
    cw = cw  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && cw  > 0 && suboption == 1)
  {
    cw = cw  - 1;
    delay(100);
  }

  // anticlockwise update
  if (digitalRead(buttonPin_UP) == LOW && suboption == 2)
  {
    acw = acw  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && acw  > 0 && suboption == 2)
  {
    acw = acw  - 1;
    delay(100);
  }

  //delay update
  if (digitalRead(buttonPin_UP) == LOW && suboption == 3)
  {
    dly = dly  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && dly  > 0 && suboption == 3)
  {
    dly = dly  - 1;
    delay(100);
  }

  // cycle update
  if (digitalRead(buttonPin_UP) == LOW && suboption == 4)
  {
    cyc = cyc  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && cyc  > 0 && suboption == 4)
  {
    cyc = cyc  - 1;
    delay(100);
  }

}

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
