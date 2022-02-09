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

#define MOTOR_STEPS 200
#define DIR A4
#define STEP A3

#define BLACK   0x0000
#define WHITE   0xffff
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0

#define ON   0
#define OFF  1

AccelStepper stepper(AccelStepper::DRIVER, STEP, DIR );
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

const unsigned char right_arrow [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0x8f, 0xf0, 0xff, 0x87, 0xf0, 0xc0, 0x03, 0xf0, 0xc0, 0x00, 0xf0, 0xc0, 0x00, 0x70, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x70, 0xc0, 0x00, 0xf0, 0xc0, 0x03, 0xf0, 0xff, 0x87, 0xf0, 0xff, 0x8f, 0xf0, 0xff, 0xbf, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char rect_set_reset [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char down_arrow [] PROGMEM = {0xff, 0x9f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xfb, 0x0d, 0xf0, 0xf1, 0x08, 0xf0, 0xf0, 0x00, 0xf0, 0xf8, 0x01, 0xf0, 0xfc, 0x03, 0xf0, 0xfe, 0x07, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char up_arrow [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0x0f, 0xf0, 0xfe, 0x07, 0xf0, 0xfc, 0x03, 0xf0, 0xf8, 0x01, 0xf0, 0xf0, 0x00, 0xf0, 0xf0, 0x00, 0xf0, 0xf1, 0x08, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char left_arrow [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xfe, 0x7f, 0xf0, 0xfc, 0x7f, 0xf0, 0xf8, 0x7f, 0xf0, 0xf0, 0x00, 0x30, 0xe0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xe0, 0x00, 0x10, 0xf0, 0x00, 0x30, 0xf8, 0x7f, 0xf0, 0xfc, 0x7f, 0xf0, 0xfe, 0x7f, 0xf0, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char down_15 [] PROGMEM = {0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xe0, 0x0e, 0xe0, 0x0e, 0xf0, 0x1e, 0xf8, 0x3e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char up_15 [] PROGMEM = {0xfe, 0xfe, 0xfc, 0x7e, 0xf8, 0x3e, 0xf0, 0x1e, 0xe0, 0x0e, 0xe0, 0x0e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char left_15 [] PROGMEM = {0xff, 0xfe, 0xff, 0xfe, 0xf9, 0xfe, 0xf1, 0xfe, 0xe0, 0x06, 0xc0, 0x02, 0xc0, 0x02, 0xc0, 0x02, 0xe0, 0x02, 0xf1, 0xfe, 0xfb, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char right_15 [] PROGMEM = {0xff, 0xfe, 0xff, 0xfe, 0xfe, 0x7e, 0xfc, 0x3e, 0xc0, 0x1e, 0x80, 0x0e, 0x80, 0x06, 0x80, 0x0e, 0xc0, 0x1e, 0xfe, 0x7e, 0xff, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};

const int buttonPin_RST = 9;     // the number of the reset button pin
const int buttonPin_SET = 8;     // the number of the set button pin
const int buttonPin_MID = 7;     // the number of the middle button pin
const int buttonPin_RHT = 6;     // the number of the right button pin
const int buttonPin_LFT = 5;     // the number of the left button pin
const int buttonPin_DWN = 4;     // the number of the down button pin
const int buttonPin_UP = 3;      // the number of the up button pin

//the relays connect to
int IN1 = A0;
int IN2 = A1;
int IN3 = A5;
int IN4 = A2;

int option = 0;
int sel = 0;
int se = 0;
int sele = 0;
int selec = 0;
int suboption = -10;
int newoption = -2;
int newse = -2;
int newsel = -2;
int newsele = -2;
int newselec = -2;
int subnewoption = -2;

int rpm = 50;
int cw = 0;
int lin1 = 0;
int lin2 = 0;
int lin3 = 0;
int lin4 = 0;
int acw = 0;
int cyc = 1;
bool updateMenu = true;
int motorsum = 0;

int roun = 0;
bool caw = true;
bool p1 = false;
bool p2 = false;
bool p3 = false;
bool p4 = false;
int su = 0;
int rou = 0;
int rp = 0;
bool w1 = false;
bool x1 = false;
bool y1 = false;
bool z1 = false;

char testing[100];
char testing1[100];
char buffer1[20];
char buffer2[20];
char buffer3[20];


char buffer[50];
//Character Array
const char welcome[] PROGMEM = "Welcome \n    to \n    Art\n   Buddy";

const char pat1[] PROGMEM = "Pattern 1";
const char pat2[] PROGMEM = "Pattern 2";
const char pat3[] PROGMEM = "Pattern 3";
const char cus[] PROGMEM = "Customise";
const char cus1[] PROGMEM = "Custom 1";
const char cus2[] PROGMEM = "Custom 2";

const char string1[] PROGMEM = "RPM (min 80): ";
const char string2[] PROGMEM = "Clockwise: ";
const char string3[] PROGMEM = "Linear: ";
const char string4[] PROGMEM = "Anti-Clockwise: ";
const char string5[] PROGMEM = "Cycle: ";
const char string6[] PROGMEM = "RPM \n  (min 80)";
const char string7[] PROGMEM = "\nClockwise";
const char string8[] PROGMEM = "Anti\n Clockwise";
const char string9[] PROGMEM = "\nCycle";
const char string10[] PROGMEM = "Piston 1";
const char string11[] PROGMEM = "Piston 2";
const char string12[] PROGMEM = "Piston 3";
const char string13[] PROGMEM = "Piston 4";
const char string14[] PROGMEM = "\n Piston 1";
const char string15[] PROGMEM = "\n Piston 2";
const char string16[] PROGMEM = "\n Piston 3";
const char string17[] PROGMEM = "\n Piston 4";
const char string18[] PROGMEM = "Clockwise";
const char string19[] PROGMEM = "Linear";
const char string20[] PROGMEM = "Anti-Clockwise";
const char string21[] PROGMEM = "RPM";
const char string22[] PROGMEM = "Cycle";
const char string23[] PROGMEM = "Rounds";
const char string24[] PROGMEM = "Clock/Anti";

const char string25[] PROGMEM = "NEXT";
const char string26[] PROGMEM = "EXECUTE";

const char *const mainmenu[] PROGMEM = {welcome};
const char *const pat_choice[] PROGMEM = {pat1, pat2, pat3, cus};
const char *const motor_choice[] PROGMEM = {string10, string11, string12, string13};
//const char *const option_choice1[] PROGMEM = {string18, string20, string21, string22};
const char *const option_choice1[] PROGMEM = {string18, string20, string10, string11, string12, string13, string21, string22};
const char *const option_choice[] PROGMEM = {string23, string24, string10, string11, string12, string13, string21, string25, string26};
//const char *const option_choice2[] PROGMEM = {};
const char *const pattern1[] PROGMEM = {pat1, string1, string2, string3, string4, string5};
const char *const pattern2[] PROGMEM = {pat2, string1, string2, string3, string4, string5};
const char *const pattern3[] PROGMEM = {pat3, string1, string2, string3, string4, string5};
const char *const customise1[] PROGMEM = {cus1, string1, string2, string3, string4, string5};
// anti clockwise first
//const char *const customise2[] PROGMEM = {cus2, string1, string4, string3, string2, string5};
const char *const key[] PROGMEM = {string6, string7, string8, string9};
const char *const motorkey[] PROGMEM = {string14, string15, string16, string17};


void setup () {
  stepper.setMaxSpeed(8000);
  tft.setTextColor(WHITE);
  tft.initR (INITR_BLACKTAB);
  Serial.begin (9600);
  pinMode(buttonPin_RST, INPUT_PULLUP);
  pinMode(buttonPin_SET, INPUT_PULLUP);
  pinMode(buttonPin_MID, INPUT_PULLUP);
  pinMode(buttonPin_RHT, INPUT_PULLUP);
  pinMode(buttonPin_LFT, INPUT_PULLUP);
  pinMode(buttonPin_DWN, INPUT_PULLUP);
  pinMode(buttonPin_UP, INPUT_PULLUP);
  tft.setRotation (0);
  tft.fillScreen (BLUE);
  startpage();
  relay_init();//initialize the relay
}

void loop () {
  
  mainscreenoption();
  // selection pattern page
  if ((option == 2))
  {
    sel = getupdown (4, sel);
    if (sel != newsel) {
      choice(4, pat_choice, sel);               //pattern 1 / pattern2 /pattern 3 / customise
    }
    newsel = sel;
    if ((sel == 0) && (digitalRead(buttonPin_SET) == LOW))        //paatern 1
    {
       pattern_1();
       option = 30;
       sel = 0;
       
       newsel = 10;
    /* if ( digitalRead(buttonPin_UP)==LOW)
              {
                newsel = 3;    
                option = 2;
                sel=0;   
              }
     */         
      Serial.print("RIGHT PRESS");
      delay(100);
      
     
    }
    else if ((sel == 1) && (digitalRead(buttonPin_SET) == LOW))   //pattern 2
    {
      pattern_2();
      option = 40;
      sel =1;
      newsel = 10;
      delay(100);
      /*if ( digitalRead(buttonPin_LFT)==LOW)
              {
                option = 2;
                choice(4, pat_choice, sel);
                //sel = 1;
              }
      */
    }
    
    else if ((sel == 2) && (digitalRead(buttonPin_SET) == LOW))   //pattern 2
    {
      pattern_3();
      option = 50;
       sel=2;
      newsel = 10;
      delay(100);
         /*   if ( digitalRead(buttonPin_LFT)==LOW)
              {
                option = 2;
                choice(4, pat_choice, sel);
                //sel = 2;
              }
              */
    }
    
    else if ((sel == 3) && (digitalRead(buttonPin_SET) == LOW))   //customise option
    {
       delay(100);
      option = 60;
      sel=3;
      newsel = 10;
      
    }
  }



  if ((option == 60))                        //customise page
  {
    delay(200);
    se = getupdown (9, se);
    if (se != newse) { // change this if statement
      custom();
    }
    /*
     * custom();
     * se = getupdown(9,se);
     */
    newse = se;

    if ((se == 0) && (digitalRead(buttonPin_SET) == LOW))        //rounds
    {
      delay (200);
      option = -1;
      do {
        if (updateMenu) {
          updateMenu = false;
          tft.drawBitmap (80, 36, right_15, 15, 15, BLACK, WHITE);
          tft.fillRect(100, 40, 20, 10, BLACK);
          tft.setCursor(100, 40);
          tft.print(roun);
        }
        dataupdates(0);                     // increase / decrease rounds
        if (digitalRead(buttonPin_SET) == LOW)
        {
          newse=10;
          delay(100);
          option = 60;
          se = 0;                            // go to clockwise/anticlockwise option
          // put newse here (to fulfill condition)
          /*
           * updateMenu = true;
           */
          break;
        }
      } while (option = -1);
    }

    else if ((se == 1) && (digitalRead(buttonPin_SET) == LOW))      // clockwise anticlockwise
    {
      option = -1;
      do {                       
        if (digitalRead(buttonPin_SET) == LOW)
        {
          newse=10;
          dataupdates(1);                       // T/F
          delay(100);
          option = 60;
          se = 1;                             // go to piston 1
          break;
        }
      } while (option = -1);

    }


    else if ((se == 2) && (digitalRead(buttonPin_SET) == LOW))      // Piston1
    {
      option = -1;
      do {
        // T/F
        if (digitalRead(buttonPin_SET) == LOW)
        {
          newse=10;
          dataupdates(2);                     // T/F
          option = 60;
          se = 2;                            // go to piston 2
          break;
        }
      } while (option = -1);
    }

    else if ((se == 3) && (digitalRead(buttonPin_SET) == LOW))      // Piston2
    {
      option = -1;
      do {
        // increase / decrease motor 4
        if (digitalRead(buttonPin_SET) == LOW)
        {
          newse=10;
          dataupdates(3);                     // T/F
          option = 60;
          se = 3;                            // go to piston 3
          break;
        }
      } while (option = -1);

    }

    else if ((se == 4) && (digitalRead(buttonPin_SET) == LOW))      // Piston3
    {
      option = -1;
      do {
        // increase / decrease motor 4
        if (digitalRead(buttonPin_SET) == LOW)
        {
          newse=10;
          dataupdates(4);                     // T/F
          option = 60;
          se = 4;                            // go to piston 4
          break;
        }
      } while (option = -1);

    }

    else if ((se == 5) && (digitalRead(buttonPin_SET) == LOW))      //Piston4
    {
      option = -1;
      do {
        // increase / decrease motor 4
        if (digitalRead(buttonPin_SET) == LOW)
        {
          newse=10;
          dataupdates(5);                     // T/F
          option = 60;
          se = 5;                            // go to rpm
          break;
        }
      } while (option = -1);

    }


    else if ((se == 6) && (digitalRead(buttonPin_SET) == LOW))      //rpm
    {
      delay (200);
      option = -1;
      do {
        if (updateMenu) {
          updateMenu = false;   
          tft.drawBitmap (80, 108, right_15, 15, 15, BLACK, WHITE);
          tft.fillRect(100, 110, 20, 10, BLACK);
          tft.setCursor(100, 110);
          tft.print(rpm);
        }


        dataupdates(6);                       // increase / decrease rpm 
        if (digitalRead(buttonPin_SET) == LOW)
        {
          newse=10;
          delay(100);
          option = 60;         
          se = 6;                            // go to NEXT
          break;
        }
      } while (option = -1);

    }

    else if ((se == 7) && (digitalRead(buttonPin_SET) == LOW))      //NEXT
    {
      delay (100);
      option = -1;
      do {
        if (digitalRead(buttonPin_SET) == LOW)
        {
          newse=10;
          if (p1 == true)
          {
            strcat(testing, "w");
           // motorsum = motorsum + 1;
          }
          else
            strcat(testing, "f");
          if (p2 == true)
          {
            strcat(testing, "x");
          //  motorsum = motorsum + 1;
          }
          else
            strcat(testing, "f");
          if (p3 == true)
          {
            strcat(testing, "y");
         //   motorsum = motorsum + 1;
          }
          else
            strcat(testing, "f");
          if (p4 == true)
          {
            strcat(testing, "z");
         //   motorsum = motorsum + 1;
          }
          else
            strcat(testing, "f");

         /* strcat(testing, "m");
          itoa(motorsum, buffer1, 10);
          strcat(testing, buffer1);
          */
          if (caw == true )
            strcat(testing, "c");
          else
            strcat(testing, "a");
          itoa(roun, buffer2, 10);
          strcat(testing, buffer2);
          strcat(testing, "r");
          itoa(rpm, buffer3, 10);
          strcat(testing, buffer3);
          strcat(testing, "_");
          strcpy(testing1, testing);
          strcpy(testing, testing1);

          Serial.println(testing);
          //Serial.print("motorsum");
          //Serial.println(motorsum);
          roun = 0;                                   //reset data to default
          caw = true;
          p1 = false;
          p2 = false;
          p3 = false;
          p4 = false;
          rpm = 50;
          //motorsum = 0;
          option = 60;                           //go to rounds
          se = 0;
          break;
        }

      } while (option = -1);

    }

    else if ((se == 8) && (digitalRead(buttonPin_SET) == LOW))      //execute
    {
      delay (100);
      option = -1;
      do {

        if (digitalRead(buttonPin_SET) == LOW)
        {
          newse=10;
          tft.fillScreen(BLACK);
          tft.setTextSize(2);
          tft.setCursor(10, 35);
          tft.print(F("Executing\n  Custom\n     1"));
          split(testing);
          delay(100);
          option = 60;
          se = 8;                            // go to rounds
          break;
        }
      } while (option = -1);

    }
  }


  // pattern 1 execution
  if ((option  == 30) && (digitalRead(buttonPin_SET) == LOW))
  {
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 35);
    tft.print(F("Executing \n  Pattern     1"));
    motorcode1();
    pattern_1();
    Serial.print("code");
  }



  // pattern 2 execution
  if ((option  == 40) && (digitalRead(buttonPin_SET) == LOW))
  {
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 35);
    tft.print(F("Executing\n  Pattern\n     2"));
    motorcode2();
    pattern_2();
  }

  // pattern 3 execution
  if ((option  == 50) && (digitalRead(buttonPin_SET) == LOW))
  {
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 35);
    tft.print(F("Executing\n  Pattern\n    3"));
    motorcode3();
    pattern_3();
  }

}
