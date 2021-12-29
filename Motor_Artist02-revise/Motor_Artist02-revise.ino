
// pin wiring to Nano as follows
// GND ----- GND
// VCC ----- 3V3
// SCL ----- D13 yellow wire
// SDA ----- D11 green wire
// RES ----- D12
// DC ------ D2
// CS ------ D10
// BLK ----- 3V3 if you like


#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <Arduino.h>
#include <AccelStepper.h>

#define TFT_RST  12
#define TFT_CS   10
#define TFT_DC   2
#define motorInterfaceType 1
#define DIR A4
#define STEP A3
#define BLACK   0xFFFF
#define WHITE   0x0000
#define BLUE    0x07FF
#define RED     0xFFE0
#define GREEN   0xF81F
#define CYAN    0xFFE0
#define MAGENTA 0x07E0
#define YELLOW  0xF800
#define ORANGE  0xFE00
#define POISON  0x68FF

AccelStepper stepper(AccelStepper::DRIVER, STEP, DIR);

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

//Button Pin to NANO
const int buttonPin_RST = 9;
const int buttonPin_SET = 8;
const int buttonPin_MID = 7;
const int buttonPin_RHT = 6;
const int buttonPin_LFT = 5;
const int buttonPin_DWN = 4;
const int buttonPin_UP = 3;

const unsigned char right_arrow [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0x8f, 0xf0, 0xff, 0x87, 0xf0, 0xc0, 0x03, 0xf0, 0xc0, 0x00, 0xf0, 0xc0, 0x00, 0x70, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x70, 0xc0, 0x00, 0xf0, 0xc0, 0x03, 0xf0, 0xff, 0x87, 0xf0, 0xff, 0x8f, 0xf0, 0xff, 0xbf, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char rect_set_reset [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char down_arrow [] PROGMEM = {0xff, 0x9f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xfb, 0x0d, 0xf0, 0xf1, 0x08, 0xf0, 0xf0, 0x00, 0xf0, 0xf8, 0x01, 0xf0, 0xfc, 0x03, 0xf0, 0xfe, 0x07, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char up_arrow [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0x0f, 0xf0, 0xfe, 0x07, 0xf0, 0xfc, 0x03, 0xf0, 0xf8, 0x01, 0xf0, 0xf0, 0x00, 0xf0, 0xf0, 0x00, 0xf0, 0xf1, 0x08, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char left_arrow [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xfe, 0x7f, 0xf0, 0xfc, 0x7f, 0xf0, 0xf8, 0x7f, 0xf0, 0xf0, 0x00, 0x30, 0xe0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xe0, 0x00, 0x10, 0xf0, 0x00, 0x30, 0xf8, 0x7f, 0xf0, 0xfc, 0x7f, 0xf0, 0xfe, 0x7f, 0xf0, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char down_15 [] PROGMEM = {0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xe0, 0x0e, 0xe0, 0x0e, 0xf0, 0x1e, 0xf8, 0x3e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char up_15 [] PROGMEM = {0xfe, 0xfe, 0xfc, 0x7e, 0xf8, 0x3e, 0xf0, 0x1e, 0xe0, 0x0e, 0xe0, 0x0e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char left_15 [] PROGMEM = {0xff, 0xfe, 0xff, 0xfe, 0xf9, 0xfe, 0xf1, 0xfe, 0xe0, 0x06, 0xc0, 0x02, 0xc0, 0x02, 0xc0, 0x02, 0xe0, 0x02, 0xf1, 0xfe, 0xfb, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char right_15 [] PROGMEM = {0xff, 0xfe, 0xff, 0xfe, 0xfe, 0x7e, 0xfc, 0x3e, 0xc0, 0x1e, 0x80, 0x0e, 0x80, 0x06, 0x80, 0x0e, 0xc0, 0x1e, 0xfe, 0x7e, 0xff, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};

char buffer[50];

//Character Array
const char welcome[] PROGMEM = "Welcome to \n  Art Buddy";

const char pat1[] PROGMEM = "Pattern 1";
const char pat2[] PROGMEM = "Pattern 2";
const char cus[] PROGMEM = "Customise";

const char string1[] PROGMEM = "RPM (min 80): ";
const char string2[] PROGMEM = "Anti-Clockwise: ";
const char string3[] PROGMEM = "Delay: ";
const char string4[] PROGMEM = "Clockwise: ";
const char string5[] PROGMEM = "Cycle: ";
const char string6[] PROGMEM = "RPM \n  (min 80)";
const char string7[] PROGMEM = "Anti\n Clockwise";
const char string8[] PROGMEM = "\nDelay: ";
const char string9[] PROGMEM = "\nClockwise ";
const char string10[] PROGMEM = "\nCycle";
const char string11[] PROGMEM = "RPM";
const char string12[] PROGMEM = "Clockwise";
const char string13[] PROGMEM = "Anti-Clockwise";
const char string14[] PROGMEM = "Delay";
const char string15[] PROGMEM = "Cycle";


const char *const mainmenu[] PROGMEM = {welcome};
const char *const pat_choice[] PROGMEM = {pat1, pat2, cus};
const char *const pattern1[] PROGMEM = {pat1, string1, string2, string3, string4, string5};
const char *const pattern2[] PROGMEM = {pat2, string1, string2, string3, string4, string5};
const char *const customise[] PROGMEM = {cus, string1, string2, string3, string4, string5};
const char *const key[] PROGMEM = {string6, string7, string8, string9, string10};
const char *const option_choice1[] PROGMEM = {string11, string12, string13};
const char *const option_choice2[] PROGMEM = {string14, string15};


bool updateMenu = true;
int option = 0;
int sel = 0;

int mode = 0;
int rpm = 100;
int cw = 7;
int lin1 = 0;
int acw = 7;
int cyc = 1;
int dly  = 0;


int getleftright(int option, int current_option) {
  if (!digitalRead(buttonPin_SET)) return current_option;
  if (!digitalRead(buttonPin_RHT)) {
    updateMenu = true;
    return (current_option == option - 1) ? 0 : ++current_option;
    Serial.println("Right Pin Is Pressed.");
  }

  if (!digitalRead(buttonPin_LFT)) {
    updateMenu = true;
    return (current_option == 0) ? option - 1 : --current_option;
    Serial.println("left Pin Is Pressed.");
  }

  return current_option;
}


int getupdown(int option, int current_option) {
  if (!digitalRead(buttonPin_SET)) return current_option;
  if (!digitalRead(buttonPin_DWN)) {
    Serial.println("down Pin Is Pressed.");
    updateMenu = true;
    return (current_option == option - 1) ? 0 : current_option = current_option + 1;

  }

  if (!digitalRead(buttonPin_UP)) {
    updateMenu = true;
    return (current_option == 0) ? option - 1 : current_option = current_option - 1;
    Serial.println("up Pin Is Pressed.");
  }

  return current_option;
}

void setup () {
  stepper.setMaxSpeed(1000);
  tft.setTextColor(WHITE);
  tft.initR (INITR_BLACKTAB);
  Serial.begin (9600);
  Serial.println ("starting ST 7735 TFT");
  Serial.println ("80x160 rotated 90 degrees");
  Serial.println ("inverted color scheme");
  pinMode(buttonPin_RST, INPUT_PULLUP);
  pinMode(buttonPin_SET, INPUT_PULLUP);
  pinMode(buttonPin_MID, INPUT_PULLUP);
  pinMode(buttonPin_RHT, INPUT_PULLUP);
  pinMode(buttonPin_LFT, INPUT_PULLUP);
  pinMode(buttonPin_DWN, INPUT_PULLUP);
  pinMode(buttonPin_UP, INPUT_PULLUP);
  tft.setRotation (3);
  tft.fillScreen (BLUE);
  startpage();




}

int newoption;
int newsel;

void loop () {
//  int buttonState;
//  buttonState = digitalRead(buttonPin_SET);
  option = getleftright(7, option);

  while (option != newoption  )
  {

    switch (option) {
      case 0:
        startpage();
        break;
      case 1: instructs();
        break;
      case 2:  selection_pat1();
      /* while (true) {
          sel = getupdown (3, sel);
          if (sel != newsel)
            switch (sel) {
              case 0: selection_pat1();
             //   if (digitalRead(buttonPin_SET) == LOW) {
             //     delay(250);
             //     Serial.println("Set Pin Is Pressed.");
             //     while (digitalRead(buttonPin_SET) == LOW);
            //    }
                do{
                  Serial.print("SET1");
                  option = 3;
                
                  //pattern_1();
                  }while ((digitalRead(buttonPin_RHT) == LOW));
                  //Serial.print( " set is press");
                  Serial.print(option);
                  
                break;
              case 1: selection_pat2();
                break;
              case 2: selection_custom();
                break;
            }
          newsel = sel;
          //Serial.print(sel);
        }
*/
        break;
      case 3: pattern_1();
      do{
       option = 1;
      }while (!digitalRead(buttonPin_UP));
   
  
        break;
      case 4: pattern_2();        
        break;
      case 5: rpmoption_1();
        /*while (true){
          sel = getupdown (3, sel);
          if (sel != newsel)
          switch (sel) {
           case 0: rpmoption_1();
           break;
           case 1: clockoption_1();
           break;
           case 2: antioption_1();
           break;
          }
          newsel = sel;
          } */
        break;
      case 6:

        delayoption_2();
        break;
      default : break;
    }
    Serial.print(option);
    newoption = option;
    Serial.print("newoption");
    Serial.println(newoption);
  }

}

/*switch(option) {
    case 0: //startpage
    case 1: //instructs
    case 2: //selection_part1
    case 3: //pattern_1
    case 4: //pattern_2
    case 5: //rpmoption_1
    case 6: //delayoption_2
  }
  option = leftright();
  }

  sub_page(sp_option) {
  switch(sp_option) {
    case 0: //rpm_option
    case 1: //anticlockwise_option
    case 2: //delay_option
    case 3: //clockwise_option
    case 4: //cycle_option
  }

*/
// Set Button

/* if (digitalRead(buttonPin_SET) == LOW) {
   delay(250);
   Serial.println("Set Pin Is Pressed.");
   switch (mode) {
     case 2:                               //Selection page
       Serial.println("selection_pat1");
       mode = 3;
       break;
     case 3:                               //Pattern1 page
       Serial.println("pattern_1");
       motorcode1();
       break;
     case 4:                               //Pattern2 page
       Serial.println("pattern_2");
       motorcode2();
       break;
     case 5:                               //customise page
       Serial.println("custom");
       motorcode5(rpm, acw, dly, cw, cyc);
       break;
     case 6:                               //RPM adjustment
       Serial.println("rpm_option");
       mode = 5;
       break;
     case 7:                               //Anticlockwise adjustment
       Serial.println("anticlockwise_option");
       mode = 5;
       break;
     case 8:                               //Delay adjustment
       Serial.println("delay_option");
       mode = 5;
       break;
     case 9:                               //Clockwise adjustment
       Serial.println("clockwise_option");
       mode = 5;
       break;
     case 10:                               //Cycle adjustment
       Serial.println("cycle_option");
       mode = 5;
       break;
     case 11:                               //Selection Page 2
       Serial.println("selection_pat2");
       mode = 4;
       break;
     case 12:                               //Selection Page 3
       Serial.println("selection_custom");
       mode = 5;
       break;
       ////////////////////////////////////////////////////////
       case 13:                               //rpmoption_1
       Serial.println("rpmoption_1");
       mode = 6;
       break;
       case 14:                               //clockoption_1
       Serial.println("clockoption_1");
       mode = 9;
       break;
       case 15:                               //antioption_1
       Serial.println("antioption_1");
       mode = 7;
       break;
       case 16:                               //delayoption_2
       Serial.println("delayoption_2");
       mode = 8;
       break;
       case 17:                               //delayoption_2
       Serial.println("cycleoption_2");
       mode = 10;
       break;
   }
   updatemenu();
   while (digitalRead(buttonPin_SET) == LOW);
  }
*/
//Left Button
/* if (digitalRead(buttonPin_LFT) == LOW) {
   delay(250);
   Serial.println("Left Pin Is Pressed.");
   if ( mode <  3)//3
   {
     mode = mode + 8;
     //mode = mode + 13;
   }
   else
     -- mode;
   updatemenu();

   while (digitalRead(buttonPin_LFT) == LOW);
  }
*/
//Right Button
/*  if (digitalRead(buttonPin_RHT) == LOW) {
    delay(250);
    Serial.println("Right Pin Is Pressed.");


    if (mode >  9)//9
      mode = mode - 8;
      //mode = mode - 13;

       else
      ++ mode ;
      //mode = mode ++;

    updatemenu();
    Serial.print(mode);

    while (digitalRead(buttonPin_RHT) == LOW);
  }*/


/*//Down Button
  if (digitalRead(buttonPin_DWN) == LOW) {
  delay(250);
  if (mode == 2) {                               //Selection Page 2
    mode = 11;
    selection_pat2();
  }
  else if (mode == 11 ) {                        //Selection Page 3
    mode = 12;
    selection_custom();
  }
  else if (mode == 12 ) {                        //Selection Page 1
    mode = 2;
    selection_pat1();
  }

  //decrease RPM
  if (mode == 6 && rpm > 0) {
    rpm = rpm - 50;
    state (0, key);
    tft.setCursor(40, 75);
    tft.print(rpm);;
  }

  //decrease clockwise
  else if (mode == 7 && acw > 0) {
    acw = acw - 1;
    state (1, key);
    tft.setCursor(50, 80);
    tft.print(acw);
  }

  //decrease delay
  else if (mode == 8 && dly > 0) {
    dly = dly - 100;
    state (2, key);
    tft.setCursor(50, 75);
    tft.print(dly);
  }

  //decrease anti clockwise
  else if (mode == 9 && cw > 0) {
    cw = cw - 1;
    state (3, key);
    tft.setCursor(50, 75);
    tft.print(cw);
  }

  //cycle
  else if (mode == 10 && cyc > 0) {
    cyc = cyc - 1;
    state (4, key);
    tft.setCursor(50, 75);
    tft.print(cyc);
  }

  Serial.println("Down Pin Is Pressed.");
  while (digitalRead(buttonPin_DWN) == LOW);
  }
*/
/* //Up Button
  if (digitalRead(buttonPin_UP) == LOW) {
   delay(250);

   if (mode == 2) {                               //Selection Page 3
     mode = 12;
     selection_custom();
   }
   else if (mode == 12 ) {                        //Selection Page 2
     mode = 11;
     selection_pat2();
   }
   else if (mode == 11 ) {                        //Selection Page 1
     mode = 2;
     selection_pat1();
   }

   //increase RPM
   if (mode == 6 ) {
     rpm = rpm + 50;
     state (0, key);
     tft.setCursor(40, 75);
     tft.print(rpm);;
   }

   //increase anti clockwise
   else if (mode == 7) {
     acw = acw + 1;
     state (1, key);
     tft.setCursor(50, 80);
     tft.print(acw);
   }

   //increase delay
   else if (mode == 8 ) {
     dly = dly + 100;
     state (2, key);
     tft.setCursor(50, 75);
     tft.print(dly);
   }

   //increase clockwise
   else if (mode == 9 ) {
     cw = cw + 1;
     state (3, key);
     tft.setCursor(50, 75);
     tft.print(cw);
   }

   //increase cycle
   else if (mode == 10 ) {
     cyc = cyc + 1;
     state (4, key);
     tft.setCursor(50, 75);
     tft.print(cyc);
   }

   Serial.println("Up Pin Is Pressed.");
   while (digitalRead(buttonPin_UP) == LOW);

  }
*/
//resetBtn();



//}
