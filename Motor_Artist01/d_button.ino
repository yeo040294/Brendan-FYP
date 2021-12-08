void resetBtn(){

if (digitalRead(buttonPin_RST) == LOW) {
    delay(250);
    Serial.println("Reset Pin Is Pressed.");
    // mode = 0;
    // screen1();


    mode = 0;
    screen1();
    int rpm = 80;
    int cw = 0;
    int lin1 = 0;
    int lin2 = 0;
    int lin3 = 0;
    int lin4 = 0;
    int acw = 0;
    int cyc = 1;
    while (digitalRead(buttonPin_SET) == LOW);
    while (digitalRead(buttonPin_RST) == LOW);
  }
}

void setBtn(){
  if (digitalRead(buttonPin_SET) == LOW) {
    delay(250);
    Serial.println("Set Pin Is Pressed.");
    // stepper.stop();
    // stepper.speed(0);


    while (true) {
      if (mode == 0) {
        Serial.println("Screen1");
        return;
      }
      else if (mode == 1) {
        Serial.println("Screen2");
        return;
      }
      else if (mode == 2) {
        Serial.println("Screen3");
        mode = 3;
        screen4();
        return;
      }
      else if (mode == 3) {
        Serial.println("Screen4");
        motorcode1();
        return;
      }
      else if (mode == 4) {
        Serial.println("Screen5");
        motorcode2();
        return;
      }
      else if (mode == 5) {
        Serial.println("Screen6");
        //motorcode4(lin1);
        motorcode3();
        return;
      }
      else if (mode == 6) {

        Serial.println("Screen7");
        motorcode5(rpm, cw, lin1 ,lin2, lin3, lin4, acw, cyc);
        return;
      }
      else if (mode == 7) {
        Serial.println("Screen8");
        screen24();
        mode = 23;
        return;
      }
      else if (mode == 8) {
        Serial.println("Screen9");
        screen21();
        mode = 20;
        return;
      }
      else if (mode == 9) {
        Serial.println("Screen10");
        screen20();
        mode = 19;
        return;
      }
      else if (mode == 10) {
        Serial.println("Screen11");
        screen22();
        mode = 21;
        return;
      }
      else if (mode == 11) {
        Serial.println("Screen12");
        screen7();
        mode = 6;
        return;
      }
      else if (mode == 12) {
        Serial.println("Screen13");
        mode = 4;
        screen5();
        return;
      }
      else if (mode == 13) {
        Serial.println("Screen14");
        mode = 5;
        screen6();
        return;
      }
      else if (mode == 14) {
        Serial.println("Screen15");
        screen20();
        mode = 19;
        return;
      }
      else if (mode == 15) {
        screen10();
        mode = 9;
        Serial.println("Screen16");
      
        return;
      }
      
      else if (mode == 16) {
        Serial.println("Screen17");
        screen25();
        mode = 24;
        return;
      }
      else if (mode == 17) {
        Serial.println("Screen18");
        screen26();
        mode = 25;
        return;
      }
      else if (mode == 18) {
        Serial.println("Screen19");
        screen27();
        mode = 26;
        return;
      }
      else if (mode == 19) {
        Serial.println("Screen20");
        screen9();
        mode = 8;
        return;
      }
      else if (mode == 20) {
        Serial.println("Screen21");
        screen11();
        mode = 10;
        return;
      }
      else if (mode == 21) {
        Serial.println("Screen22");
        screen16();
        mode = 15;
        return;
      }
      else if (mode == 22) {
        Serial.println("Screen23");
        screen8();
        mode = 7;
        return;
      }
      else if (mode == 23) {
        Serial.println("Screen24");
        screen12();
        mode = 11;
        return;
      }
      else if (mode == 24) {
        Serial.println("Screen25");
        screen20();
        mode = 19; 
        return;
      }

       else if (mode == 25) {
        Serial.println("Screen26");
        screen20();
        mode = 19; 
        return;
      }

       else if (mode == 26) {
        Serial.println("Screen27");
        screen20();
        mode = 19; 
        return;
      }
      else if (mode == 27) {
        Serial.println("Screen28");
         motorcode6(rpm, cw, lin1 ,lin2, lin3, lin4, acw, cyc);
        return;
      }
    }
  }
}

void midBtn(){
  if (digitalRead(buttonPin_MID) == LOW) {
    delay(250);


     
    
    Serial.println("Middle Pin Is Pressed.");
    while (digitalRead(buttonPin_MID) == LOW);
  }

}

void rightBtn(){

  if (digitalRead(buttonPin_RHT) == LOW) {
    delay(250);
    Serial.println("Right Pin Is Pressed.");
    while (true) {
      if (mode == 0) {
        screen2();
        mode = 1 ;
        return;
      }
      else if (mode == 1) {
        screen3();
        mode = 2;
        return;
      }
      else if (mode == 2) {
        screen4();
        mode = 3;
        return;
      }
      else if (mode == 3) {
        screen5();
        mode = 4;
        return;
      }
      else if (mode == 4) {
        screen6();
        mode = 5;
        return;
      }
      else if (mode == 5) {
        screen20();
        mode = 19;
        return;

      }
      else if (mode == 19) {
        screen23();
        mode = 22;
        return;

      }
      else if (mode == 22) {
        screen28();
        mode = 6;
        return;

      }
       else if (mode == 6) {
        screen28();
        mode = 27;
        return;

      }
      else if (mode == 27) {
        screen1();
        mode = 0;
        return;
      
      }
      else if (mode == 12) {
        screen4();
        mode = 3;
        return;
      
      }
      else if (mode == 13) {
        screen4();
        mode = 3;
        return;
      
      }
      else if (mode == 14) {
        screen4();
        mode = 3;
        return;
      
      }
      else if (mode == 20) {
        screen23();
        mode = 22;
        return;
      
      }
      else if (mode == 21) {
        screen23();
        mode = 22;
        return;
      
      }

        else if (mode == 23) {
        screen7();
        mode = 6;
        return;
      
      }

      
      
      //end of main selection

      //start of selection cw, anti, linear 
      else if (mode == 8) {
        screen11();
        mode = 10;
        return;

      }
      else if (mode == 10) {
        screen16();
        mode = 15;
        return;

      }
      else if (mode == 15) {
        screen9();
        mode = 8;
        return;

      }
       else if (mode == 16) {
        screen9();
        mode = 8;
        return;

      }
      else if (mode == 17) {
        screen9();
        mode = 8;
        return;

      }
      else if (mode == 18) {
        screen9();
        mode = 8;
        return;

      }
// end of selection cw, anti linear
      //start of linear selection 
      else if (mode == 9) {
        screen25();
        mode = 24;
        return;

      }
      else if (mode == 24) {
        screen26();
        mode = 25;
        return;

      }

      else if (mode == 25) {
        screen27();
        mode = 26;
        return;

      }
      else if (mode == 26) {
        screen10();
        mode = 9;
        return;
// end of linear selection
//start of rpm, cycle selection
      }
      else if (mode == 7) {
        screen12();
        mode = 11;
        return;

      }else if (mode == 11) {
        screen8();
        mode = 7;
        return;

      }
      // end of rpm cycle selection
      
     
      while (digitalRead(buttonPin_RHT) == LOW);
    }
  }

}

void leftBtn(){
  

  if (digitalRead(buttonPin_LFT) == LOW) {
    delay(250);
    Serial.println("Left Pin Is Pressed.");
    while (true) {

      //start of main 
      if (mode == 0) {
        screen28();
        mode = 27;
        return;
      }
       else if (mode == 27) {
        screen7();
        mode = 6;
        return;
      }
        else if (mode == 6) {
        screen23();
        mode = 22;
        return;
      }
      else if (mode == 22) {
        screen20();
        mode = 19;
        return;
      }
      else if (mode == 19) {
        screen6();
        mode = 5;
        return;
      }
      else if (mode == 5) {
        screen5();
        mode = 4;
        return;
      }
      else if (mode == 4) {
        screen4();
        mode = 3;
        return;
      }
      else if (mode == 3) {
        screen3();
        mode = 2;
        return;
      }
      else if (mode == 2) {
        screen2();
        mode = 1;
        return;
      }
      else if (mode == 1) {
        screen1();
        mode = 0;
        return;
      }

        else if (mode == 12) {
        screen2();
        mode = 1;
        return;
      }
      else if (mode == 13) {
        screen2();
        mode = 1;
        return;
      }
      else if (mode == 14) {
        screen2();
        mode = 1;
        return;
      }
      else if (mode == 20) {
        screen6();
        mode = 5;
        return;
      }
      else if (mode == 21) {
        screen6();
        mode = 5;
        return;
      }

        else if (mode == 23) {
        screen20();
        mode = 19;
        return;
      }
     
//end of main
//start of selection linear
      
      else if (mode == 9) {
        screen27();
        mode = 26;
        return;
      }
      else if (mode == 26) {
        screen26();
        mode = 25;
        return;
      }
      else if (mode == 25) {
        screen25();
        mode = 24;
        return;
      }
      else if (mode == 24) {
        screen10();
        mode = 9;
        return;
      }

      //end of linear
      // start of cw, anti , linear
      else if (mode == 8) {
        screen16();
        mode = 15;
        return;
      }
      else if (mode == 15) {
        screen11();
        mode = 10;
        return;
      }
      else if (mode == 10) {
        screen9();
        mode = 8;
        return;
      }
       else if (mode == 16) {
        screen11();
        mode = 10;
        return;
      }
      else if (mode == 17) {
        screen11();
        mode = 10;
        return;
      }
      else if (mode == 18) {
        screen11();
        mode = 10;
        return;
      }
      // end of cw anti linear
      // start of rpm , cycle

       else if (mode == 7) {
        screen12();
        mode = 11;
        return;
      }
      else if (mode == 11) {
        screen8();
        mode = 7;
        return;
      }

      
     // end of rpm , cycle
    }
    while (digitalRead(buttonPin_LFT) == LOW);
  }

}


void downBtn(){
  

  if (digitalRead(buttonPin_DWN) == LOW) {
    delay(250);
// start of P1,P2,P3, Custom
    if (mode == 2) {
      mode = 12;
      screen13();
    }

    else if (mode == 12 ) {
      screen14();
      mode = 13;
    }

    else if (mode == 13 ) {
      screen15();
      mode = 14;
    }

    else if (mode == 14 ) {
      screen3();
      mode = 2;
    }
// end of P1,P2,P3, Custom
// start of linear
   if (mode == 15) {
      mode = 16;
      screen17();
    }

    else if (mode == 16 ) {
      screen18();
      mode = 17;
    }

    else if (mode == 17 ) {
      screen19();
      mode = 18;
    }

    else if (mode == 18 ) {
      screen16();
      mode = 15;
    }
//end of linear
// start of cw, anti , linear
     if (mode == 19) {
      mode = 20;
      screen21();
    }

    else if (mode == 20 ) {
      screen22();
      mode = 21;
    }

    else if (mode == 21 ) {
      screen20();
      mode = 19;
    }
//end of cw, anti , linear
// start of rpm, linear
    else if (mode == 22 ) {
      screen24();
      mode = 23;
    }

    else if (mode == 23 ) {
      screen23();
      mode = 22;
    }

    //end of rpm,linear
   
    //rpm
    else if (mode == 7 && rpm > 0) {
      rpm = rpm - 10;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 45);
      tft.print(F("RPM \n  (min 80)"));

      tft.setCursor(40, 75);
      tft.print(rpm);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(rpm);
    }

    //clockwise
    else if (mode == 8 && cw > 0) {
      cw = cw - 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 50);
      tft.print(F("Clockwise"));

      tft.setCursor(50, 75);
      tft.print(cw);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(cw);
    }

    //linear 1
    else if (mode == 9 && lin1 > 0) {
      lin1 = lin1 - 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 50);
      tft.print(F("Linear 1"));

      tft.setCursor(50, 75);
      tft.print(lin1);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(lin1);
    }

    //linear 2
    else if (mode == 24 && lin2 > 0) {
      lin2 = lin2 - 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 50);
      tft.print(F("Linear 2"));

      tft.setCursor(50, 75);
      tft.print(lin2);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(lin2);
    }


    //linear 3
    else if (mode == 25 && lin3 > 0) {
      lin3 = lin3 - 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 50);
      tft.print(F("Linear 3"));

      tft.setCursor(50, 75);
      tft.print(lin3);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(lin3);
    }


   //linear 4
    else if (mode == 26 && lin4 > 0) {
      lin4 = lin4 - 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 50);
      tft.print(F("Linear 4"));

      tft.setCursor(50, 75);
      tft.print(lin4);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(lin4);
    }


    //anti clockwise
    else if (mode == 10 && acw > 0) {
      acw = acw - 1;


      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 45);
      tft.print(F("Anti\n  Clockwise"));

      tft.setCursor(50, 80);
      tft.print(acw);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(acw);
    }



    //cycle
    else if (mode == 11 && cyc > 0) {
      cyc = cyc - 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 50);
      tft.print(F("Cycle"));

      tft.setCursor(50, 75);
      tft.print(cyc);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(cyc);
    }

    Serial.println("Down Pin Is Pressed.");
    while (digitalRead(buttonPin_DWN) == LOW);
  }

}

void upBtn(){

  //original up button
  if (digitalRead(buttonPin_UP) == LOW) {
    delay(250);
// start of P1,P2,P3, cus
    if (mode == 2) {
      mode = 14;
      screen15();
    }

    else if (mode == 14 ) {
      screen14();
      mode = 13;
    }

    else if (mode == 13 ) {
      screen13();
      mode = 12;
    }

    else if (mode == 12 ) {
      screen3();
      mode = 2;
    }
//end of P1,P2,P3, cus
//start of linear  

 if (mode == 15) {
      mode = 18;
      screen19();
    }

    else if (mode == 18 ) {
      screen18();
      mode = 17;
    }

    else if (mode == 17 ) {
      screen17();
      mode = 16;
    }

    else if (mode == 16 ) {
      screen16();
      mode = 15;
    }
// end of linear
//start of cw, anti , linear

     if (mode == 19) {
      mode = 21;
      screen22();
    }

    else if (mode == 21 ) {
      screen21();
      mode = 20;
    }

    else if (mode == 20 ) {
      screen20();
      mode = 19;
    }

    //end of cw, anti, linear
//start of rpm, cycle
    else if (mode == 22 ) {
      screen24();
      mode = 23;
    }
     if (mode == 23) {
      mode = 22;
      screen23();
    }
//end of rpm cycle
   

    //RPM
    else if (mode == 7 ) {
      rpm = rpm + 10;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 45);
      tft.print(F("RPN \n  (min 80)"));

      tft.setCursor(40, 75);
      tft.print(rpm);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(rpm);
    }
    //clockwise
    else if (mode == 8) {
      cw = cw + 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 45);
      tft.print(F("Clockwise"));

      tft.setCursor(50, 75);
      tft.print(cw);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(cw);
    }

    //linear 1
    else if (mode == 9 ) {
      lin1 = lin1 + 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 45);
      tft.print(F("Linear 1"));

      tft.setCursor(50, 75);
      tft.print(lin1);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(lin1);
    }

//linear 2
    else if (mode == 24 ) {
      lin2 = lin2 + 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 45);
      tft.print(F("Linear 2"));

      tft.setCursor(50, 75);
      tft.print(lin2);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(lin2);
    }

//linear 3
    else if (mode == 25 ) {
      lin3 = lin3 + 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 45);
      tft.print(F("Linear 3"));

      tft.setCursor(50, 75);
      tft.print(lin3);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(lin3);
    }

    //linear 4
    else if (mode == 26 ) {
      lin4 = lin4 + 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 45);
      tft.print(F("Linear 4"));

      tft.setCursor(50, 75);
      tft.print(lin4);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(lin4);
    }

    //anti clockwise
    else if (mode == 10 ) {
      acw = acw + 1;


      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 45);
      tft.print(F("Anti\n  Clockwise"));

      tft.setCursor(50, 80);
      tft.print(acw);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
      Serial.println(acw);
    }



    //cycle
    else if (mode == 11 ) {
      cyc = cyc + 1;

      tft.fillScreen(BLACK);
      tft.setTextSize(2);
      tft.setCursor(20, 50);
      tft.print(F("Cycle"));

      tft.setCursor(50, 75);
      tft.print(cyc);
      Serial.println(cyc);
      tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
      tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
    }


    Serial.println("Up Pin Is Pressed.");
    while (digitalRead(buttonPin_UP) == LOW);
  }
}
