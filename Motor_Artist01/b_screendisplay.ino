void startpage() {
  tft.fillScreen(BLACK);
  tft.drawBitmap (130, 70, right_arrow, 20, 20, BLACK, WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 35);
  strcpy_P(buffer, (char *)pgm_read_word(&(mainmenu[0])));
  tft.println(buffer);
}

void instructs() {
  tft.fillScreen(BLACK);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
  //tft.drawBitmap (10,70, left_arrow, 20, 20, BLACK, WHITE);
  tft.setTextSize(1);
  tft.setCursor(30, 20);
  tft.print(F("Instruction"));
  tft.drawBitmap (30, 55, right_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (10, 55, left_15, 15, 15, BLACK, WHITE);
  tft.setTextSize(1);
  tft.setCursor(50, 60);
  tft.print(F(":NEXT PAGE"));
  tft.drawBitmap (30, 72, up_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (10, 72, down_15, 15, 15, BLACK, WHITE);
  tft.setTextSize(1);
  tft.setCursor(50, 77);
  tft.print(F(":CHANGE VALUE"));
  tft.drawBitmap (10, 85, rect_set_reset, 20, 20, BLACK, WHITE);
  tft.drawBitmap (30, 85, rect_set_reset, 20, 20, BLACK, RED);
  tft.setTextSize(1);
  tft.setCursor(50, 90);
  tft.print(F(":SET / RESET"));
}

void pattern_1() {
  menu(6, pattern1);
  tft.setCursor(100, 50);
  tft.print(200);
  tft.setCursor(100, 60);
  tft.print(10);
  tft.setCursor(100, 70);
  tft.print(2);
  tft.setCursor(100, 80);
  tft.print(10);
  tft.setCursor(100, 90);
  tft.print(2);
}

void pattern_2() {
  menu(6, pattern2);
  tft.setCursor(100, 50);
  tft.print(300);
  tft.setCursor(100, 60);
  tft.print(10);
  tft.setCursor(100, 70);
  tft.print(2);
  tft.setCursor(100, 80);
  tft.print(10);
  tft.setCursor(100, 90);
  tft.print(2);
}

void pattern_3() {
  menu(6, pattern3);
  tft.setCursor(100, 50);
  tft.print(500);
  tft.setCursor(100, 60);
  tft.print(10);
  tft.setCursor(100, 70);
  tft.print(5);
  tft.setCursor(100, 80);
  tft.print(10);
  tft.setCursor(100, 90);
  tft.print(2);
}

void custom() {
    choice(9, option_choice, se);
      tft.setCursor(20,20);
      tft.print("Customise");
      tft.setCursor(100, 40);
      tft.print(roun);
      tft.setCursor(100, 50);
      if (caw)
        tft.print("T");
      else
        tft.print("F");
      tft.setCursor(100, 62);
      if (p1)
        tft.print("T");
      else
        tft.print("F");
      tft.setCursor(100, 74);
      if (p2)
        tft.print("T");
      else
        tft.print("F");
      tft.setCursor(100, 86);
      if (p3)
        tft.print("T");
      else
        tft.print("F");
      tft.setCursor(100, 98);
      if (p4)
        tft.print("T");
      else
        tft.print("F");
      tft.setCursor(100, 110);
      tft.print(rpm);                  
}
