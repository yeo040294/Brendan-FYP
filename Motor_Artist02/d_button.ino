// reset button

void resetBtn() {
   if(digitalRead(buttonPin_RST) == LOW) {
    delay(250);
    Serial.println("Reset Pin Is Pressed.");
    mode = 0;
    screen1();
    int rpm = 80;   
    int acw = 0;
    int dly =0;
    int cw =0;
    int cyc = 1;

    int spd = 80;   
    int alcw = 0;
    int dlay =0;
    int clw =0;
    int rounds = 1;
    while(digitalRead(buttonPin_RST) == LOW);
  }
}

// set button
void setBtn(){
  if(digitalRead(buttonPin_SET) == LOW) {
    delay(250);
   
   Serial.println("Set Pin Is Pressed.");

   switch (mode){
    case 0: 
        Serial.println("Screen1");
        break;
    
    case 1:
        Serial.println("Screen2");        
        break;

    case 2:
        Serial.println("Screen3");
        mode = 3;
        screen4();
        break;

   case 3:
        Serial.println("Screen4");
        motorcode1();
        break;

   case 4:
        Serial.println("Screen5");
        motorcode2();
        break;
 
   case 6:
        Serial.println("Screen7");
        motorcode5(rpm, acw, dly, cw, cyc);
        break;

   case 7: 
        Serial.println("Screen8");
        screen7();
        mode=6;
        break;
       
   case 8:
        Serial.println("Screen9");
        screen7();
        mode=6;
        break;

   case 9:
        Serial.println("Screen10");
        screen7();
        mode=6;
        break;

   case 10:
        Serial.println("Screen11");
        screen7();
        mode=6;
        break;
      
   case 11:
        Serial.println("Screen12");
        screen7();
        mode=6;
        break;

   case 12:
        Serial.println("Screen13");
        mode = 4;
        screen5();
        break;
      
   case 14:
        Serial.println("Screen15");
        screen7();
        mode=6;
        break;
 }
   
 
}
  while(digitalRead(buttonPin_SET) == LOW);
  }

// right button
  void rightBtn(){
  if(digitalRead(buttonPin_RHT) == LOW) {
    delay(250);
    Serial.println("Right Pin Is Pressed.");

    switch (mode){
    case 0: 
        screen2();
        mode =1 ;
        break;
    
    case 1:
        screen3();
        mode = 2;     
        break;

    case 2:
        screen4();
         mode = 3;
        break;

   case 3:
        screen5();
        mode = 4;
        break;

   case 4:
        screen7();
         mode = 6;
        break;
 
   case 6:
        screen8();
        mode = 7;
        break;

   case 7: 
        screen9();
        mode = 8;
        break;
       
   case 8:
        screen10();
        mode = 9;
        break;

   case 9:
        screen11();
        mode = 10;
        break;

   case 10:
        screen1();
        mode = 0;
        break;
      
   case 11:
        screen1();
        mode = 0;
        break;

   case 12:
        screen4();
        mode = 3;
        break;
      
   case 14:
        screen4();
        mode = 3;
        break;
 }
        
  
     while(digitalRead(buttonPin_RHT) == LOW);   
  
  }
}

// left button
void leftBtn(){
  if(digitalRead(buttonPin_LFT) == LOW) {
    delay(250);
    Serial.println("Left Pin Is Pressed.");

    switch (mode){
    case 0: 
          screen12();
          mode = 11;
          break;
    
    case 1:
          screen1();
          mode = 0;     
          break;

    case 2:
          screen2();
          mode = 1;
          break;

   case 3:
          screen3();
          mode = 2;
          break;

   case 4:
          screen4();
          mode = 3;
          break;
 
   case 6:
          screen5();
          mode = 4;
          break;

   case 7: 
          screen7();
          mode = 6;
          break;
       
   case 8:
          screen8();
          mode = 7;
          break;

   case 9:
          screen9();
          mode = 8;
          break;

   case 10:
          screen10();
          mode = 9;
          break;
      
   case 11:
          screen11();
          mode = 10;
          break;

   case 12:
          screen2();
          mode = 1;
          break;
      
   case 14:
          screen2();
          mode = 1;
          break;
 }

 
  
      while(digitalRead(buttonPin_LFT) == LOW);    
  }
  
}

// down button
void downBtn(){
  if(digitalRead(buttonPin_DWN) == LOW) {
    delay(250);






    if (mode == 2){
    mode = 12;
    screen13();
    }

    else if (mode == 12 ){
    screen15();
    mode = 14;
    }

   

    else if (mode == 14 ){
    screen3();
    mode = 2;
    }
    
    
    //rpm
    if (mode == 7 && rpm >0){
    rpm = rpm-10;
    
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 35);
    tft.print(F("RPM \n  (min 80)"));
   
    tft.setCursor(40, 75);
    tft.print(rpm);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(rpm);
    }
    
    //clockwise
    else if (mode == 8 && acw >0){
    acw = acw-1;
    
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Anti\n  Clockwise"));
   
    tft.setCursor(50, 75);
    tft.print(acw);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(acw);
    }

    //delay
    else if (mode == 9 && dly >0){
    dly = dly-100;
    
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Delay"));
   
    tft.setCursor(50, 75);
    tft.print(dly);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(dly);
    }
   

    //anti clockwise
    else if (mode == 10 && cw >0){
    cw = cw-1;
    
   
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Clockwise"));
   
    tft.setCursor(50, 80);
    tft.print(cw);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(cw);
    }

    

    //cycle
    else if (mode == 11 && cyc >0){
    cyc = cyc-1;
    
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Cycle"));
   
    tft.setCursor(50, 75);
    tft.print(cyc);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(cyc);
    }
    
    Serial.println("Down Pin Is Pressed.");
    while(digitalRead(buttonPin_DWN) == LOW);
  }
  
}

// up button
void upBtn(){
  //original up button
  if(digitalRead(buttonPin_UP) == LOW) {
  delay(250);

 if (mode == 2){
    mode = 14;
    screen15();
    }

    else if (mode == 14 ){
    screen13();
    mode = 12;
    }

    

    else if (mode == 12 ){
    screen3();
    mode = 2;
    }
    

    //RPM
   if (mode == 7 ){
    rpm = rpm+10;
    
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 35);
    tft.print(F("RPN \n  (min 80)"));
   
    tft.setCursor(40, 75);
    tft.print(rpm);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(rpm);
    }
   //anti clockwise
    else if (mode == 8){
    acw = acw+1;
    
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Anti\n  Clockwise"));
   
    tft.setCursor(50, 75);
    tft.print(acw);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(acw);
    }

    //delay
    else if (mode == 9 ){
    dly = dly + 100;
    
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Delay"));
   
    tft.setCursor(50, 75);
    tft.print(dly);
     tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(dly);
    }
   

    //clockwise
    else if (mode == 10 ){
    cw = cw+1;
    
   
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Clockwise"));
   
    tft.setCursor(50, 80);
    tft.print(cw);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(cw);
    }

    

    //cycle
    else if (mode == 11 ){
    cyc = cyc+1;
    
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Cycle"));
   
    tft.setCursor(50, 75);
    tft.print(cyc);
    Serial.println(cyc);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
     }
    
   
 Serial.println("Up Pin Is Pressed.");
   while(digitalRead(buttonPin_UP) == LOW);
  }
 
}

// Mid button
void midBtn(){
  //button spoil on my set up 
  
  
  if(digitalRead(buttonPin_MID) == LOW) {
    delay(250);
    
    Serial.println("Middle Pin Is Pressed.");
    
    while(digitalRead(buttonPin_MID) == LOW);
  }
  
}
