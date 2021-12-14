
//using PROGMEM function for string array
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
      Serial.println("Screen2");
      screen2();
      break;

    case 2:
      Serial.println("Screen3");
      screen3();
      break;

    case 3:
      Serial.println("Screen4");
      screen4();
      break;

    case 4:
      Serial.println("Screen5");
      screen5();
      break;

    case 5:
      Serial.println("Screen6");
      screen6();
      break;

    case 6:
      Serial.println("Screen7");
      screen7();
      break;

    case 7:
      Serial.println("Screen8");
      screen8();
      break;

    case 8:
      Serial.println("Screen9");
      screen9();
      break;

    case 9:
      Serial.println("Screen10");
      screen10();
      break;

    case 10:
      Serial.println("Screen11");
      screen11();
      break;

    case 11:
      Serial.println("Screen12");
      screen12();
      break;

    case 12:
      Serial.println("Screen13");
      screen13();
      break;

  }
}

// reset button
void resetBtn() {
  if (digitalRead(buttonPin_RST) == LOW) {
    delay(250);
    Serial.println("Reset Pin Is Pressed.");
    mode = 0;
    screen1();
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
    Serial.println("Middle Pin Is Pressed.");
    while (digitalRead(buttonPin_MID) == LOW);
  }
}
