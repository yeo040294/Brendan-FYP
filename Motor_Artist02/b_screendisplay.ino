void screen1(){


tft.fillScreen(BLACK);
//tft.fillRect (18,80,50,20,GREEN);
 tft.drawBitmap (130,70, right_arrow, 20, 20, BLACK, WHITE);
//    tft.drawBitmap (10,70, left_arrow, 20, 20, BLACK, WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 35);
 tft.print(F("Welcome To \n  Art Buddy"));
   // tft.setTextSize(1);
   // tft.setCursor(20, 80);
   //  tft.print(F("Toggle RIGHT\n   for instruction"));
}

void screen2(){
  tft.fillScreen(BLACK);
   tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
  //tft.drawBitmap (10,70, left_arrow, 20, 20, BLACK, WHITE);
    tft.setTextSize(2);
    tft.setCursor(5, 35);
    tft.print(F("Instruction"));
    tft.drawBitmap (30,55, right_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (10,55, left_15, 15, 15, BLACK, WHITE);
    tft.setTextSize(1);
    tft.setCursor(50, 60);
    tft.print(F(":NEXT PAGE"));
    tft.drawBitmap (30,72, up_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (10,72, down_15, 15, 15, BLACK, WHITE);
    tft.setTextSize(1);
    tft.setCursor(50, 77);
    tft.print(F(":CHANGE VALUE"));
    tft.drawBitmap (10,85, rect_set_reset, 20, 20, WHITE, BLACK);
    tft.drawBitmap (30,85, rect_set_reset, 20, 20, WHITE, RED);
 tft.setTextSize(1);
    tft.setCursor(50, 90);
    tft.print(F(":SET / RESET"));
}



void screen3(){

    tft.fillScreen(BLACK);
    
    // tft.fillScreen(BLACK);

    tft.setTextSize(1);
    
    tft.setCursor(30, 40);
    tft.print(F("Pattern 1"));
    tft.drawRect(28,35,55,18, WHITE);
    tft.setCursor(30, 60);
    tft.print(F("Pattern 2"));
    //tft.drawRect(28,55,55,18, WHITE);
    //tft.setCursor(30, 73);
    //tft.print(F("Preset 3"));
   //tft.drawRect(28,68,55,18, WHITE);
    tft.setCursor(30, 85);
    tft.print(F("Customise"));
    //tft.drawRect(28,80, 70,18, WHITE);

 
    
    //tft.drawBitmap (10,70, left_15, 15, 15, BLACK, WHITE);
    //tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
  //  tft.drawBitmap (70,90, rect_set_reset, 20, 20, WHITE, BLACK);

   tft.drawBitmap (90,30, up_15, 15, 15, WHITE, BLACK);
   tft.drawBitmap (90,90, down_15, 15, 15, WHITE, BLACK);
}

void screen4(){

     tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setCursor(30, 30);
    tft.print(F("Pattern 1"));



   tft.setTextSize(1);
    tft.setCursor(30, 50);
    tft.print(F("RPM (min 80):"));
    tft.setCursor(120, 50);
    tft.print(150);
    
    tft.setTextSize(1);
    tft.setCursor(30, 80);
    tft.print(F("Clockwise:"));
    tft.setCursor(120, 80);
    tft.print(10);
 
    tft.setTextSize(1);
    tft.setCursor(30, 70);
    tft.print(F("Delay:"));
    tft.setCursor(120, 70);
    tft.print(0);
    
    tft.setTextSize(1);
    tft.setCursor(30, 60);
    tft.print(F("Anti-Clockwise:"));
    tft.setCursor(120, 60);
    tft.print(10);
    
   

     tft.setTextSize(1);
    tft.setCursor(30, 90);
    tft.print(F("Cycle:"));
    tft.setCursor(120, 90);
    tft.print(cyc);

    tft.setTextSize(1);
    tft.setCursor(133, 92);
    tft.print(F("SET"));
    tft.drawRect(130,90, 22,15, WHITE);
    
    tft.drawBitmap (10,70, left_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
    
}

void screen5(){

     tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setCursor(30, 30);
    tft.print(F("Pattern 2"));



   tft.setTextSize(1);
    tft.setCursor(30, 50);
    tft.print(F("RPM (min 80):"));
    tft.setCursor(120, 50);
    tft.print(120);
    
    tft.setTextSize(1);
    tft.setCursor(30, 80);
    tft.print(F("Clockwise:"));
    tft.setCursor(120, 80);
    tft.print(15);
 
    tft.setTextSize(1);
    tft.setCursor(30, 70);
    tft.print(F("Delay:"));
    tft.setCursor(120, 70);
    tft.print(0);
    
    tft.setTextSize(1);
    tft.setCursor(30, 60);
    tft.print(F("Anti-Clockwise:"));
    tft.setCursor(120, 60);
    tft.print(15);
    
   

     tft.setTextSize(1);
    tft.setCursor(30, 90);
    tft.print(F("Cycle:"));
    tft.setCursor(120, 90);
    tft.print(cyc);

    tft.setTextSize(1);
    tft.setCursor(133, 92);
    tft.print(F("SET"));
    tft.drawRect(130,90, 22,15, WHITE);

    tft.drawBitmap (10,70, left_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
   
}

void screen7(){
   tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(30, 30);
    tft.print(F("Customise"));



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
    tft.print(F("Delay:"));
    tft.setCursor(120, 70);
    tft.print(dly);
    
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
    
     tft.setTextSize(1);
    tft.setCursor(133, 92);
    tft.print(F("SET"));
    tft.drawRect(130,90, 22,15, WHITE);
    
    tft.drawBitmap (10,70, left_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
   
    //tft.drawBitmap (70,90, rect_set_reset, 20, 20, WHITE, BLACK);
}


void screen8(){

    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 35);
    tft.print(F("RPM \n  (min 80)"));
   
    tft.setCursor(40, 75);
    tft.print(rpm);;

   tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
   tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
}

void screen9(){

    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Anti\n Clockwise"));
   
    tft.setCursor(50, 80);
    tft.print(acw);

    

    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
}


void screen10(){

    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Delay"));
   
    tft.setCursor(50, 75);
    tft.print(dly);
 
    
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
   
}

void screen11(){
 
    
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Clockwise"));
   
    tft.setCursor(50, 75);
    tft.print(cw);

    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
}


void screen12(){
  
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Cycle"));
   
    tft.setCursor(50, 75);
    tft.print(cyc);

    
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
}

void screen13(){

    tft.fillScreen(BLACK);
    
    // tft.fillScreen(BLACK);

    tft.setCursor(30, 40);
    tft.print(F("Pattern 1"));
    //tft.drawRect(28,35,55,18, WHITE);
    tft.setCursor(30, 60);
    tft.print(F("Pattern 2"));
    tft.drawRect(28,55,55,18, WHITE);
    //tft.setCursor(30, 73);
    //tft.print(F("Preset 3"));
   //tft.drawRect(28,68,55,18, WHITE);
    tft.setCursor(30, 85);
    tft.print(F("Customise"));
    //tft.drawRect(28,80, 70,18, WHITE);

 
     tft.drawBitmap (90,30, up_15, 15, 15, WHITE, BLACK);
   tft.drawBitmap (90,90, down_15, 15, 15, WHITE, BLACK);
 
}


void screen15(){

    tft.fillScreen(BLACK);
    
    // tft.fillScreen(BLACK);

   tft.setCursor(30, 40);
    tft.print(F("Pattern 1"));
    //tft.drawRect(28,35,55,18, WHITE);
    tft.setCursor(30, 60);
    tft.print(F("Pattern 2"));
    //tft.drawRect(28,55,55,18, WHITE);
    //tft.setCursor(30, 73);
    //tft.print(F("Preset 3"));
   //tft.drawRect(28,68,55,18, WHITE);
    tft.setCursor(30, 85);
    tft.print(F("Customise"));
    tft.drawRect(28,80, 70,18, WHITE);
   
  
     tft.drawBitmap (90,30, up_15, 15, 15, WHITE, BLACK);
   tft.drawBitmap (90,90, down_15, 15, 15, WHITE, BLACK);
 
 
}
