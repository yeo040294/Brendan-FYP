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
const char *const pattern1[] PROGMEM = {pat1, string1, string4, string3, string2, string5};
const char *const pattern2[] PROGMEM = {pat2, string1, string4, string3, string2, string5};
const char *const customise[] PROGMEM = {cus, string1, string4, string3, string2, string5};
const char *const key[] PROGMEM = {string6, string7, string8, string9, string10};
const char *const option_choice1[] PROGMEM = {string11, string12, string13};
const char *const option_choice2[] PROGMEM = {string14, string15};

int option = 0;
int sel = 0;
int sele = 0;
int selec = 0;
int suboption = -10;
int newoption = -2;
int newsel = -2;
int newsele = -2;
int newselec = -2;
int subnewoption = -2;

int mode = 0;
int rpm = 100;
int cw = 7;
int acw = 7;
int cyc = 1;
int dly  = 0;

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

void loop () {
  mainscreenoption();
  // selection pattern page
  if ((option == 2))
  {
    sel = getupdown (3, sel);
    if (sel != newsel) {
      choice(3, pat_choice, sel);               //pattern 1 / pattern2 / customise
    }
    newsel = sel;
    if ((sel == 0) && (digitalRead(buttonPin_SET) == LOW))        //paatern 1
    {
      delay(100);
      option = 3;
      pattern_1();                             // required else code will auto execute
    }
    else if ((sel == 1) && (digitalRead(buttonPin_SET) == LOW))   //pattern 2
    {
      option = 4;
      pattern_2();                             // required else code will auto execute
    }
    else if ((sel == 2) && (digitalRead(buttonPin_SET) == LOW))   //customise option
      option = 5;
    delay(100);
  }

  // selection rpm page
  if ((option == 5))
  {
    selec = getupdown (3, selec);
    if (selec != newselec) {
      choice(3, option_choice1, selec);         //rpm / clockwise / anticlockwise
    }
    newselec = selec;
    if ((selec == 0) && (digitalRead(buttonPin_SET) == LOW))        //rpm
    {
      delay (100);
      suboption = 0;
      option = -1;
      do {
        //subscreenoption();
        rpm_option();
        dataupdates(selec);                     // increase / decrease rpm
        if (digitalRead(buttonPin_SET) == LOW)
        {
          option = 5;
          selec = 1;                            // go to clockwise option
          break;
        }
      } while (option = -1);
    }
    else if ((selec == 1) && (digitalRead(buttonPin_SET) == LOW))     //clockwise
    {
      delay (100);
      suboption = 1;
      option = -1;
      do {
        clockwise_option();
        dataupdates(selec);                      // increase / decrease clockwise
        if (digitalRead(buttonPin_SET) == LOW)
        {
          option = 5;
          selec = 2;                              // go to anticlockwise option
          break;
        }
      } while (option = -1);
    }
    else if ((selec == 2) && (digitalRead(buttonPin_SET) == LOW))      // anti clockwise
    {
      delay (100);
      suboption = 2;
      option = -1;
      do {
        //subscreenoption();
        anticlockwise_option();
        dataupdates(selec);                          // increase / decrease anti clockwise
        if (digitalRead(buttonPin_SET) == LOW)
        {
          option = 6;
          selec = 0;                                // go to delay option
          break;
        }
      } while (option = -1);
    }
  }

  //selection delay page
  if ((option == 6))
  {
    delay(200);
    sele = getupdown (2, sele);
    if (sele != newsele) {
      choice(2, option_choice2, sele);                                 // delay
    }
    newsele = sele;

    //selectioncase2();
    if ((sele == 0) && (digitalRead(buttonPin_SET) == LOW))
    {
      delay (100);
      suboption = 3;
      option = -1;
      do {
        delay_option();
        //subscreenoption();
        dataupdates(3);                             // increase / decrease delay
        if (digitalRead(buttonPin_SET) == LOW)
        {
          option = 6;                               // go to cycle option
          sele = 1;
          break;
        }
      } while (option = -1);
    }
    else if ((sele == 1) && (digitalRead(buttonPin_SET) == LOW))        //cycle
    {
      delay (100);
      suboption = 4;
      option = -1;
      do {
        //subscreenoption();
        cycle_option();
        dataupdates(4);                             // increase / decrease cycle
        if (digitalRead(buttonPin_SET) == LOW)
        {
          option = 7;
          custom();                                 // go to customise execution page
          break;
        }
      } while (option = -1);
    }
  }
  
  // pattern 1 execution
  if ((option  == 3) && (digitalRead(buttonPin_SET) == LOW))
  {
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(30, 35);
    tft.print(F("Executing \n  Pattern 1"));
    motorcode1();
    pattern_1();
    Serial.print("code");
  }
  
  // pattern 2 execution
  if ((option  == 4) && (digitalRead(buttonPin_SET) == LOW))
  {
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(30, 35);
    tft.print(F("Executing \n  Pattern 2"));
    motorcode2();
    pattern_2();
  }
  
  // customise execution
  if ((option == 7) && (digitalRead(buttonPin_SET) == LOW))
  {
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(30, 35);
    tft.print(F("Executing \n  Customise"));
    customcode(rpm, acw, dly, cw, cyc);
    custom();
  }

}
