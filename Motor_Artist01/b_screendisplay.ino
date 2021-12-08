void screen1() {


  tft.fillScreen(BLACK);
  //tft.fillRect (18,80,50,20,GREEN);
  tft.drawBitmap (130, 70, right_arrow, 20, 20, BLACK, WHITE);
  //    tft.drawBitmap (10,70, left_arrow, 20, 20, BLACK, WHITE);
  tft.setTextSize(2);
  tft.setCursor(20, 35);
  tft.print(F("Welcome To \n  Art Buddy"));
  // tft.setTextSize(1);
  // tft.setCursor(20, 80);
  //  tft.print(F("Toggle RIGHT\n   for instruction"));
}

void screen2() {
  tft.fillScreen(BLACK);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
  //tft.drawBitmap (10,70, left_arrow, 20, 20, BLACK, WHITE);
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
void print_text(byte x_pos, byte y_pos, char *text, byte text_size, uint16_t color) {

}


void screen3() {

  tft.fillScreen(BLACK);

  // tft.fillScreen(BLACK);

  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Preset 1"));
  tft.drawRect(28, 32, 55, 18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Preset 2"));
  // tft.drawRect(28,48,55,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Preset 3"));
  //tft.drawRect(28,68,55,18, WHITE);
  tft.setCursor(30, 93);
  tft.print(F("Customise"));
  //tft.drawRect(28,88, 70,18, WHITE);



  //tft.drawBitmap (10,70, left_15, 15, 15, BLACK, WHITE);
  //tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
  //  tft.drawBitmap (70,90, rect_set_reset, 20, 20, WHITE, BLACK);
}

void screen4() {
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(30, 30);
  tft.print(F("Preset 1"));



  tft.setTextSize(1);
  tft.setCursor(30, 50);
  tft.print(F("RPM (min 80):"));
  tft.setCursor(120, 50);
  tft.print(100);

  tft.setTextSize(1);
  tft.setCursor(30, 60);
  tft.print(F("Clockwise:"));
  tft.setCursor(120, 60);
  tft.print(2);

  tft.setTextSize(1);
  tft.setCursor(30, 70);
  tft.print(F("Linear:"));
  tft.setCursor(120, 70);
  tft.print(2);

  tft.setTextSize(1);
  tft.setCursor(30, 80);
  tft.print(F("Anti-Clockwise:"));
  tft.setCursor(120, 80);
  tft.print(3);



  tft.setTextSize(1);
  tft.setCursor(30, 90);
  tft.print(F("Cycle:"));
  tft.setCursor(120, 90);
  tft.print(3);

  tft.drawBitmap (10, 70, left_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (70, 90, rect_set_reset, 20, 20, WHITE, BLACK);
}

void screen5() {

  tft.fillScreen(BLACK);

  tft.setTextSize(2);
  tft.setCursor(30, 30);
  tft.print(F("Preset 2"));



  tft.setTextSize(1);
  tft.setCursor(30, 50);
  tft.print(F("RPM (min 80):"));
  tft.setCursor(120, 50);
  tft.print(110);

  tft.setTextSize(1);
  tft.setCursor(30, 60);
  tft.print(F("Clockwise:"));
  tft.setCursor(120, 60);
  tft.print(3);

  tft.setTextSize(1);
  tft.setCursor(30, 70);
  tft.print(F("Linear:"));
  tft.setCursor(120, 70);
  tft.print(2);

  tft.setTextSize(1);
  tft.setCursor(30, 80);
  tft.print(F("Anti-Clockwise:"));
  tft.setCursor(120, 80);
  tft.print(4);



  tft.setTextSize(1);
  tft.setCursor(30, 90);
  tft.print(F("Cycle:"));
  tft.setCursor(120, 90);
  tft.print(2);

  tft.drawBitmap (10, 70, left_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (70, 90, rect_set_reset, 20, 20, WHITE, BLACK);
}

void screen6() {

  tft.fillScreen(BLACK);

  tft.setTextSize(2);
  tft.setCursor(30, 30);
  tft.print(F("Preset 3"));



  tft.setTextSize(1);
  tft.setCursor(30, 50);
  tft.print(F("RPM (min 80):"));
  tft.setCursor(120, 50);
  tft.print(130);

  tft.setTextSize(1);
  tft.setCursor(30, 60);
  tft.print(F("Clockwise:"));
  tft.setCursor(120, 60);
  tft.print(3);

  tft.setTextSize(1);
  tft.setCursor(30, 70);
  tft.print(F("Linear:"));
  tft.setCursor(120, 70);
  tft.print(1);

  tft.setTextSize(1);
  tft.setCursor(30, 80);
  tft.print(F("Anti-Clockwise:"));
  tft.setCursor(120, 80);
  tft.print(3);



  tft.setTextSize(1);
  tft.setCursor(30, 90);
  tft.print(F("Cycle:"));
  tft.setCursor(120, 90);
  tft.print(4);

  tft.drawBitmap (10, 70, left_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (70, 90, rect_set_reset, 20, 20, WHITE, BLACK);
}


void screen7() {
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(30, 30);
  tft.print(F("Customise1"));



  tft.setTextSize(1);
  tft.setCursor(30, 50);
  tft.print(F("RPM (min 80):"));
  tft.setCursor(120, 50);
  tft.print(rpm);

  tft.setTextSize(1);
  tft.setCursor(30, 60);
  tft.print(F("Clockwise:"));
  tft.setCursor(120, 60);
  tft.print(cw);

  tft.setTextSize(1);
  tft.setCursor(30, 70);
  tft.print(F("Linear:"));
  tft.setCursor(85, 70);
  tft.print(lin1);
  tft.print(",");
  tft.print(lin2);
  tft.print(",");
  tft.print(lin3);
  tft.print(",");
  tft.print(lin4);

  tft.setTextSize(1);
  tft.setCursor(30, 80);
  tft.print(F("Anti-Clockwise:"));
  tft.setCursor(120, 80);
  tft.print(acw);



  tft.setTextSize(1);
  tft.setCursor(30, 90);
  tft.print(F("Cycle:"));
  tft.setCursor(120, 90);
  tft.print(cyc);

  tft.drawBitmap (10, 70, left_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (70, 90, rect_set_reset, 20, 20, WHITE, BLACK);
}


void screen8() {

  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 35);
  tft.print(F("RPM \n  (min 80)"));

  tft.setCursor(40, 75);
  tft.print(rpm);;

  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
}

void screen9() {

  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 45);
  tft.print(F("Clockwise"));

  tft.setCursor(50, 75);
  tft.print(cw);



  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
}


void screen10() {

  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 50);
  tft.print(F("Linear 1"));

  tft.setCursor(50, 75);
  tft.print(lin1);


  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);

}

void screen11() {


  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 45);
  tft.print(F("Anti\n  Clockwise"));

  tft.setCursor(50, 80);
  tft.print(acw);

  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
}


void screen12() {

  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 50);
  tft.print(F("Cycle"));

  tft.setCursor(50, 75);
  tft.print(cyc);


  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
}

void screen13() {

  tft.fillScreen(BLACK);

  // tft.fillScreen(BLACK);

  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Preset 1"));
  //tft.drawRect(28,32,55,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Preset 2"));
  tft.drawRect(28, 48, 55, 18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Preset 3"));
  //tft.drawRect(28,68,55,18, WHITE);
  tft.setCursor(30, 93);
  tft.print(F("Customise"));
  //tft.drawRect(28,88, 70,18, WHITE);



}

void screen14() {

  tft.fillScreen(BLACK);

  // tft.fillScreen(BLACK);

  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Preset 1"));
  //tft.drawRect(28,32,55,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Preset 2"));
  //tft.drawRect(28,48,55,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Preset 3"));
  tft.drawRect(28, 68, 55, 18, WHITE);
  tft.setCursor(30, 93);
  tft.print(F("Customise"));
  //tft.drawRect(28,88, 70,18, WHITE);



}

void screen15() {

  tft.fillScreen(BLACK);

  // tft.fillScreen(BLACK);

  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Preset 1"));
  //tft.drawRect(28,32,55,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Preset 2"));
  //tft.drawRect(28,48,55,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Preset 3"));
  // tft.drawRect(28,68,55,18, WHITE);
  tft.setCursor(30, 93);
  tft.print(F("Customise"));
  tft.drawRect(28, 88, 70, 18, WHITE);



}

void screen16() {

  tft.fillScreen(BLACK);
  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Motor 1"));
  tft.drawRect(28,32,55,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Motor 2"));
  //tft.drawRect(28,48,55,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Motor 3"));
  // tft.drawRect(28,68,55,18, WHITE);
  tft.setCursor(30, 93);
  tft.print(F("Motor 4"));
  //tft.drawRect(28, 88, 70, 18, WHITE);



}
void screen17() {

  tft.fillScreen(BLACK);
  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Motor 1"));
  //tft.drawRect(28,32,55,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Motor 2"));
  tft.drawRect(28,48,55,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Motor 3"));
  // tft.drawRect(28,68,55,18, WHITE);
  tft.setCursor(30, 93);
  tft.print(F("Motor 4"));
  //tft.drawRect(28, 88, 70, 18, WHITE);



}
void screen18() {

  tft.fillScreen(BLACK);
  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Motor 1"));
  //tft.drawRect(28,32,55,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Motor 2"));
  //tft.drawRect(28,48,55,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Motor 3"));
  tft.drawRect(28,68,55,18, WHITE);
  tft.setCursor(30, 93);
  tft.print(F("Motor 4"));
  //tft.drawRect(28, 88, 70, 18, WHITE);



}
void screen19() {

  tft.fillScreen(BLACK);
  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Motor 1"));
  //tft.drawRect(28,32,55,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Motor 2"));
  //tft.drawRect(28,48,55,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Motor 3"));
  //tft.drawRect(28,68,55,18, WHITE);
  tft.setCursor(30, 93);
  tft.print(F("Motor 4"));
  tft.drawRect(28, 88, 55, 18, WHITE);



}
void screen20() {

  tft.fillScreen(BLACK);
  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Clockwise"));
  tft.drawRect(28,32,62,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Anti-Clockwise"));
  //tft.drawRect(28,48,97,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Linear"));
  //tft.drawRect(28,68,42,18, WHITE);

}

void screen21() {

  tft.fillScreen(BLACK);
  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Clockwise"));
  //tft.drawRect(28,32,62,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Anti-Clockwise"));
  tft.drawRect(28,48,97,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Linear"));
  //tft.drawRect(28,68,42,18, WHITE);

}

void screen22() {

  tft.fillScreen(BLACK);
  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("Clockwise"));
  //tft.drawRect(28,32,62,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Anti-Clockwise"));
  //tft.drawRect(28,48,97,18, WHITE);
  tft.setCursor(30, 73);
  tft.print(F("Linear"));
  tft.drawRect(28,68,42,18, WHITE);

}

void screen23() {

  tft.fillScreen(BLACK);
  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("RPM"));
  tft.drawRect(28,32,21,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Cycle"));


}

void screen24() {

  tft.fillScreen(BLACK);
  tft.setTextSize(1);

  tft.setCursor(30, 35);
  tft.print(F("RPM"));
  //tft.drawRect(28,32,21,18, WHITE);
  tft.setCursor(30, 53);
  tft.print(F("Cycle"));
  tft.drawRect(28,48,35,18, WHITE);

}


void screen25() {

  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 50);
  tft.print(F("Linear 2"));

  tft.setCursor(50, 75);
  tft.print(lin2);


  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);

}

 void screen26() {

  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 50);
  tft.print(F("Linear 3"));

  tft.setCursor(50, 75);
  tft.print(lin3);


  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);

}


void screen27() {

  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 50);
  tft.print(F("Linear 4"));

  tft.setCursor(50, 75);
  tft.print(lin4);


  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);

}

void screen28() {
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(30, 30);
  tft.print(F("Customise2"));



  tft.setTextSize(1);
  tft.setCursor(30, 50);
  tft.print(F("RPM (min 80):"));
  tft.setCursor(120, 50);
  tft.print(rpm);

  tft.setTextSize(1);
  tft.setCursor(30, 80);
  tft.print(F("Clockwise:"));
  tft.setCursor(120, 80);
  tft.print(cw);

  tft.setTextSize(1);
  tft.setCursor(30, 70);
  tft.print(F("Linear:"));
  tft.setCursor(85, 70);
  tft.print(lin1);
  tft.print(",");
  tft.print(lin2);
  tft.print(",");
  tft.print(lin3);
  tft.print(",");
  tft.print(lin4);

  tft.setTextSize(1);
  tft.setCursor(30, 60);
  tft.print(F("Anti-Clockwise:"));
  tft.setCursor(120, 60);
  tft.print(acw);



  tft.setTextSize(1);
  tft.setCursor(30, 90);
  tft.print(F("Cycle:"));
  tft.setCursor(120, 90);
  tft.print(cyc);

  tft.drawBitmap (10, 70, left_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (70, 90, rect_set_reset, 20, 20, WHITE, BLACK);
}
