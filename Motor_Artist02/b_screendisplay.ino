//Main Page
void screen1() {
  tft.fillScreen(BLACK);
  tft.drawBitmap (130, 70, right_arrow, 20, 20, BLACK, WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 35);
  strcpy_P(buffer, (char *)pgm_read_word(&(mainmenu[0])));
  tft.println(buffer);
}

//instruction Page
void screen2() {
  tft.fillScreen(BLACK);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
  tft.setTextSize(2);
  tft.setCursor(5, 35);
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
  tft.drawBitmap (10, 85, rect_set_reset, 20, 20, WHITE, BLACK);
  tft.drawBitmap (30, 85, rect_set_reset, 20, 20, WHITE, RED);
  tft.setTextSize(1);
  tft.setCursor(50, 90);
  tft.print(F(":SET / RESET"));
}


//Selection Page
void screen3() {
  tft.fillScreen(BLACK);
  tft.setTextSize(1);
  tft.setCursor(30, 40);
  tft.print(F("Pattern 1"));
  tft.drawRect(28, 35, 55, 18, WHITE);
  tft.setCursor(30, 60);
  tft.print(F("Pattern 2"));
  //tft.drawRect(28,55,55,18, WHITE);
  tft.setCursor(30, 85);
  tft.print(F("Customise"));
  //tft.drawRect(28,80, 70,18, WHITE);
  tft.drawBitmap (90, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (90, 90, down_15, 15, 15, WHITE, BLACK);
}

//Pattern1
void screen4() {
  menu(6, pattern1);
  tft.setCursor(120, 50);
  tft.print(200);
  tft.setCursor(120, 80);
  tft.print(10);
  tft.setCursor(120, 70);
  tft.print(0);
  tft.setCursor(120, 60);
  tft.print(10);
  tft.setCursor(120, 90);
  tft.print(cyc);
}

//Pattern2
void screen5() {
  menu(6, pattern2);
  tft.setCursor(120, 50);
  tft.print(500);
  tft.setCursor(120, 80);
  tft.print(15);
  tft.setCursor(120, 70);
  tft.print(0);
  tft.setCursor(120, 60);
  tft.print(15);
  tft.setCursor(120, 90);
  tft.print(cyc);
}

//Customise
void screen6() {
  menu(6, customise);
  tft.setCursor(120, 50);
  tft.print(rpm);
  tft.setCursor(120, 80);
  tft.print(cw);
  tft.setCursor(120, 70);
  tft.print(dly);
  tft.setCursor(120, 60);
  tft.print(acw);
  tft.setCursor(120, 90);
  tft.print(cyc);
  tft.drawBitmap (10, 70, left_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
}

//RPM adjustment
void screen7() {
  state (0, key);
  tft.setCursor(40, 75);
  tft.print(rpm);;
}

//Anticlockwise adjustment
void screen8() {
  state (1, key);
  tft.setCursor(50, 80);
  tft.print(acw);
}

//Delay adjustment
void screen9() {
  state (2, key);
  tft.setCursor(50, 75);
  tft.print(dly);
}

//Clockwise adjustment
void screen10() {
  state (3, key);
  tft.setCursor(50, 75);
  tft.print(cw);
}

//Cycle adjustment
void screen11() {
  state (4, key);
  tft.setCursor(50, 75);
  tft.print(cyc);
}

//Selection Page 2
void screen12() {
  tft.fillScreen(BLACK);
  tft.setCursor(30, 40);
  tft.print(F("Pattern 1"));
  //tft.drawRect(28,35,55,18, WHITE);
  tft.setCursor(30, 60);
  tft.print(F("Pattern 2"));
  tft.drawRect(28, 55, 55, 18, WHITE);
  tft.setCursor(30, 85);
  tft.print(F("Customise"));
  //tft.drawRect(28,80, 70,18, WHITE);
  tft.drawBitmap (90, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (90, 90, down_15, 15, 15, WHITE, BLACK);

}

//Selection Page 3
void screen13() {
  tft.fillScreen(BLACK);
  tft.setCursor(30, 40);
  tft.print(F("Pattern 1"));
  //tft.drawRect(28,35,55,18, WHITE);
  tft.setCursor(30, 60);
  tft.print(F("Pattern 2"));
  //tft.drawRect(28,55,55,18, WHITE);
  tft.setCursor(30, 85);
  tft.print(F("Customise"));
  tft.drawRect(28, 80, 70, 18, WHITE);
  tft.drawBitmap (90, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (90, 90, down_15, 15, 15, WHITE, BLACK);
}
