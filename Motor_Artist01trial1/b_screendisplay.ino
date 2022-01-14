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


void custom1() {
  menu(6, customise1);
  tft.setCursor(100, 50);
  tft.print(rpm);
  tft.setCursor(100, 60);
  tft.print(cw);
  tft.setCursor(85, 70);
  tft.print(lin1);
  tft.print(",");
  tft.print(lin2);
  tft.print(",");
  tft.print(lin3);
  tft.print(",");
  tft.print(lin4);
  tft.setCursor(100, 80);
  tft.print(acw);
  tft.setCursor(100, 90);
  tft.print(cyc);

  tft.setCursor(0, 110);
  tft.print(testing);                       // display the new sequence of codes in character
}

void rpm_option() {
  state(0, key);
  tft.setCursor(40, 75);
  tft.print(rpm);;
}

void clockwise_option () {
  state(1, key);
  tft.setCursor(50, 75);
  tft.print(cw);
}


void motor1_option() {
  state (0, motorkey);
  tft.setCursor(50, 75);
  tft.print(lin1);
}

void anticlockwise_option () {
  state(2, key);
  tft.setCursor(50, 80);
  tft.print(acw);
}


void cycle_option () {
  state(3, key);
  tft.setCursor(50, 75);
  tft.print(cyc);
}

void motor2_option() {
  state(1, motorkey);
  tft.setCursor(50, 75);
  tft.print(lin2);
}

void motor3_option() {
  state(2, motorkey);
  tft.setCursor(50, 75);
  tft.print(lin3);
}


void motor4_option() {
  state(3, motorkey);
  tft.setCursor(50, 75);
  tft.print(lin4);
}

/*void custom2() {
  menu(6, customise2);
  tft.setCursor(100, 50);
  tft.print(rpm);
  tft.setCursor(100, 80);
  tft.print(cw);
  tft.setCursor(85, 70);
  tft.print(lin1);
  tft.print(",");
  tft.print(lin2);
  tft.print(",");
  tft.print(lin3);
  tft.print(",");
  tft.print(lin4);
  tft.setCursor(100, 60);
  tft.print(acw);
  tft.setCursor(100, 90);
  tft.print(cyc);
}
*/
