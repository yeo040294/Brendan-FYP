//Main Page
void startpage() {
  tft.fillScreen(BLACK);
  tft.drawBitmap (130, 70, right_arrow, 20, 20, BLACK, WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 35);
  strcpy_P(buffer, (char *)pgm_read_word(&(mainmenu[0])));
  tft.println(buffer);
}

//instruction Page
void instructs() {
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
  tft.drawBitmap (10, 85, rect_set_reset, 20, 20, BLACK, WHITE);
  tft.drawBitmap (30, 85, rect_set_reset, 20, 20, BLACK, RED);
  tft.setTextSize(1);
  tft.setCursor(50, 90);
  tft.print(F(":SET / RESET"));
}


//Selection Page
void selection_pat1() {
  choice(3, pat_choice,0);
}

//Pattern1
void pattern_1() {
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
  tft.print(1);
}

//Pattern2
void pattern_2() {
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
  tft.print(1);
}

//Customise
void custom() {
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
void rpm_option() {
  state (0, key);
  tft.setCursor(40, 75);
  tft.print(rpm);;
}

//Anticlockwise adjustment
void anticlockwise_option() {
  state (1, key);
  tft.setCursor(50, 80);
  tft.print(acw);
}

//Delay adjustment
void delay_option() {
  state (2, key);
  tft.setCursor(50, 75);
  tft.print(dly);
}

//Clockwise adjustment
void clockwise_option() {
  state (3, key);
  tft.setCursor(50, 75);
  tft.print(cw);
}

//Cycle adjustment
void cycle_option() {
  state (4, key);
  tft.setCursor(50, 75);
  tft.print(cyc);
}

//Selection Page 2
void selection_pat2() {
   choice(3, pat_choice,1); 
}

//Selection Page 3
void selection_custom() {
choice(3, pat_choice,2);
}

void rpmoption_1() {
  choice(3,option_choice1,0);
}

void clockoption_1() {
  choice(3,option_choice1,1);
}

void antioption_1() {
  choice(3,option_choice1,2);
}

void delayoption_2() {
  choice(2,option_choice2,0);
}

void cycleoption_2() {
  choice(2,option_choice2,1);
}
