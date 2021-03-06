//menu display
void mainscreenoption()
{
  option = getleftright(10, option);
  while (option != newoption  )
  {
    switch (option) {
      case 0:
        startpage();
        break;
      case 1: instructs();
        break;
      case 2: sel = 0;
        choice(4, pat_choice, sel);               // pattern selection page

        break;
      case 30: pattern_1();
        break;
      case 40: pattern_2();
        break;
      case 50: pattern_3();
        break;
      case 60: se = 0;
        custom();
        break;
      default : if ( option > 10)
        {
          option = round(option / 10) * 10;
        }
        else if (option < 0)
          option = 0;
        else
          option = 2;
    }
    newoption = option;
  }
}

void menu(int menu_opt ,  const char *const string_table[]) {
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  //  if (string_table == customise1 || string_table == customise2)
  if (string_table == customise1)
  {
    tft.setCursor(20, 10);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[0])));
  }
  else
  {
    tft.setCursor(10, 10);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[0])));
  }
  tft.println(buffer);
  for (int i = 1; i < menu_opt; i++)
  {
    tft.setTextSize(1);
    tft.setCursor(10, 50 + i * 10 - 10);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
    tft.println(buffer);
  }
  tft.setTextSize(1);
  tft.setCursor(100, 110);
  tft.print(F("SET"));
  tft.drawRect(98, 106, 22, 15, WHITE);
  tft.drawBitmap (10, 130, left_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (110, 130, right_15, 15, 15, BLACK, WHITE);
}

void choice(int choice_opt ,  const char *const string_table[], int select) {
  //if (!updateMenu) return;
  tft.fillScreen(BLACK);
  if (choice_opt == 4)  {
    for (int i = 0; i < choice_opt; i++)
    {
      tft.setTextSize(1);
      tft.setCursor(30, 55 + i * 30 - 30);
      strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
      tft.println(buffer);
    }
    if (select == 0)
      tft.drawRect(28, 18, 60, 18, WHITE);
    else if (select == 1)
      tft.drawRect(28, 48, 60, 18, WHITE);
    else if (select == 2)
      tft.drawRect(28, 78, 60, 18, WHITE);
    else
      tft.drawRect(28, 108, 60, 18, WHITE);
  }
  else  {
    for (int i = 0; i < choice_opt; i++)
    {
      if (i < 9) {
        tft.setTextSize(1);
        tft.setCursor(15, 50 + i * 12 - 12);
        strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
        tft.println(buffer);
      }
    }
    if (select == 0)
      tft.drawRect(13, 52 + select * 12 - 12 - 7, 60, 13, WHITE);
    else if (select == 1)
      tft.drawRect(13, 52 + select * 12 - 12 - 7, 60, 13, WHITE);
    else if (select == 2)
      tft.drawRect(13, 52 + select * 12 - 12 - 7, 60, 13, WHITE);
    else if (select == 3)
      tft.drawRect(13, 52 + select * 12 - 12 - 7, 60, 13, WHITE);
    else if (select == 4)
      tft.drawRect(13, 52 + select * 12 - 12 - 7, 60, 13, WHITE);
    else if (select == 5)
      tft.drawRect(13, 52 + select * 12 - 12 - 7, 60, 13, WHITE);
    else if (select == 6)
      tft.drawRect(13, 52 + select * 12 - 12 - 7, 60, 13, WHITE);
    else if (select == 7)
      tft.drawRect(13, 52 + select * 12 - 12 - 7, 30, 13, WHITE);
    else
      tft.drawRect(13, 52 + select * 12 - 12 - 7, 60, 13, WHITE);
  }
  tft.drawBitmap (90, 5, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (90, 140, down_15, 15, 15, WHITE, BLACK);

}

//update of customise variable ( rpm / clockwise / anticlockwise / delay / cycle )
int dataupdates( int opt)
{

  updateMenu = false;
  suboption = opt;

  //rounds update
  if (digitalRead(buttonPin_RHT) == LOW && suboption == 0)
  {
    updateMenu = true;
    roun = roun  + 1;
    delay(100);

  }
  else if ((digitalRead(buttonPin_LFT) == LOW) && roun  > 0 && suboption == 0)
  {
    updateMenu = true;
    roun = roun  - 1;
    delay(100);
  }

  // clockwise/anticlockwise T/F update
  if (digitalRead(buttonPin_SET) == LOW && caw == true && suboption == 1)
  {
    caw = false;
  }
  else if ((digitalRead(buttonPin_SET) == LOW) && caw == false && suboption == 1)
  {
    caw = true;
  }

  // Lin 1 T/F
  if (digitalRead(buttonPin_SET) == LOW && p1 == true && suboption == 2)
  {
    p1 = false;
  }
  else if ((digitalRead(buttonPin_SET) == LOW) && p1 == false && suboption == 2)
  {
    p1 = true;
  }

  // Lin 2 T/F
  if (digitalRead(buttonPin_SET) == LOW && p2 == true && suboption == 3)
  {
    p2 = false;
  }
  else if ((digitalRead(buttonPin_SET) == LOW) && p2 == false && suboption == 3)
  {
    p2 = true;
  }

  // Lin 3 T/F
  if (digitalRead(buttonPin_SET) == LOW && p3 == true && suboption == 4)
  {
    p3 = false;
  }
  else if ((digitalRead(buttonPin_SET) == LOW) && p3 == false  && suboption == 4)
  {
    p3 = true;
  }

  // Lin 4 T/F
  if (digitalRead(buttonPin_SET) == LOW && p4 == true && suboption == 5)
  {
    p4 = false;
  }
  else if ((digitalRead(buttonPin_SET) == LOW) && p4 == false && suboption == 5)
  {
    p4 = true;
  }
  // RPM
  if (digitalRead(buttonPin_RHT) == LOW && rpm < 650 && suboption == 6)
  {
    updateMenu = true;
    rpm = rpm  + 10;
    delay(100);
  }
  else if ((digitalRead(buttonPin_LFT) == LOW) && rpm > 0 && suboption == 6)
  {
    updateMenu = true;
    rpm = rpm  - 10;
    delay(100);
  }

}

void state (int menu_opt, const char *const string_table[]) {
  int i = menu_opt;
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 35);
  strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
  tft.println(buffer);
  tft.drawBitmap (70, 5, up_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (70, 140, down_15, 15, 15, BLACK, WHITE);
  tft.setTextSize(1);
  tft.setCursor(100, 110);
  tft.print(F("SET"));
  tft.drawRect(98, 106, 22, 15, WHITE);
  tft.setTextSize(2);
}

void relay_init(void)//initialize the relay
{
  //set all the relays OUTPUT
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  relay_SetStatus(OFF, OFF, OFF, OFF); //turn off all the relay
}

//set the status of relays
void relay_SetStatus( unsigned char status_1,  unsigned char status_2, unsigned char status_3, unsigned char status_4)
{
  digitalWrite(IN1, status_1);
  digitalWrite(IN2, status_2);
  digitalWrite(IN3, status_3);
  digitalWrite(IN4, status_4);
}


int getleftright(int option, int current_option) {
  if (!digitalRead(buttonPin_SET)) return current_option;
  if (!digitalRead(buttonPin_RHT)) {
    delay(100);
    updateMenu = true;
    Serial.println("Right Pin Is Pressed.");
    return (current_option == option - 1) ? 0 : current_option = current_option + 1;
  }

  if (!digitalRead(buttonPin_LFT)) {
    delay(100);
    updateMenu = true;
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
    updateMenu = true;
    return (current_option == option - 1) ? 0 : ++current_option;
  }

  if (!digitalRead(buttonPin_UP)) {
    delay(100);
    updateMenu = true;
    return (current_option == 0) ? option - 1 : --current_option;
    Serial.println("up Pin Is Pressed.");
  }
  return current_option;
}
