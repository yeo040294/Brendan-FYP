
//using PROGMEM function for string array
void menu(int menu_opt ,  const char *const string_table[]) {
  updateMenu = false;
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

void choice(int choice_opt ,  const char *const string_table[], int select) {
 
  tft.fillScreen(BLACK);
  for (int i = 0; i < choice_opt; i++)
  {
    tft.setTextSize(1);
    tft.setCursor(30, 60 + i * 20 - 20);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
    tft.println(buffer);
  }
  if (select ==0)
  tft.drawRect(28, 35, 60, 18, WHITE);
  else if (select ==1)
  tft.drawRect(28, 55, 60, 18, WHITE);
  else 
  tft.drawRect(28,75, 60,18, WHITE);
  

  //tft.drawRect(130, 90, 22, 15, WHITE);
  tft.drawBitmap (90, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (90, 90, down_15, 15, 15, WHITE, BLACK);
}


void state (int menu_opt, const char *const string_table[]) {
  int i = menu_opt;
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 35);
  strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
  tft.println(buffer);
  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
}

void updatemenu() {
  switch (mode) {

    case 1:
      Serial.println("instructs");
      instructs();
      break;

    case 2:
      Serial.println("selection_pat1");
      selection_pat1();                                                                                                                       
      break;

    case 3:
      Serial.println("pattern_1");
      pattern_1();
      break;

    case 4:
      Serial.println("pattern_2");
      pattern_2();
      break;

    case 5:
      Serial.println("custom");
      custom();
      break;

    case 6:
      Serial.println("rpm_option");
      rpm_option();
      break;

    case 7:
      Serial.println("anticlockwise_option");
      anticlockwise_option();
      break;

    case 8:
      Serial.println("delay_option");
      delay_option();
      break;

    case 9:
      Serial.println("clockwise_option");
      clockwise_option();
      break;

    case 10:
      Serial.println("cycle_option");
      cycle_option();
      break;

    case 11:
      Serial.println("selection_pat2");
      selection_pat2();
      break;

    case 12:
      Serial.println("selection_custom");
      selection_custom();
      break;

    case 13:
      Serial.println("rpmoption_1");
      rpmoption_1();
      break;


     case 14:
      Serial.println("clockoption_1");
      clockoption_1();
      break;

      case 15:
      Serial.println("antioption_1");
      antioption_1();
      break;

           case 16:
      Serial.println("delayoption_2");
      delayoption_2();
      break;

      case 17:
      Serial.println("cycleoption_2");
      cycleoption_2();
      break;

      
  }

  
}

// reset button
void resetBtn() {
  if (digitalRead(buttonPin_RST) == LOW) {
    delay(250);
    Serial.println("Reset Pin Is Pressed.");
    mode = 0;
    startpage();
    int rpm = 100;
    int acw = 0;
    int dly = 0;
    int cw = 0;
    int cyc = 1;

    int spd = 100;
    int alcw = 0;
    int dlay = 0;
    int clw = 0;
    int rounds = 1;
    while (digitalRead(buttonPin_RST) == LOW);
  }
}

// Mid button
void midBtn() {
  //button spoil on my set up
  if (digitalRead(buttonPin_MID) == LOW) {
    delay(250);
    mode = 0;
    startpage();
    int rpm = 100;
    int acw = 0;
    int dly = 0;
    int cw = 0;
    int cyc = 1;

    int spd = 100;
    int alcw = 0;
    int dlay = 0;
    int clw = 0;
    int rounds = 1;
    Serial.println("Middle Pin Is Pressed.");
    while (digitalRead(buttonPin_MID) == LOW);
  }
}
