
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
int sele=0;
int selec = 0;
int suboption = 0;
int newoption = -2;
int newsel = -2;
int newsele = -2;
int newselec= -2;
int subnewoption = -2;
 

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
    delay(100);
    Serial.println("Right Pin Is Pressed.");
    updateMenu = true;
    return (current_option == option - 1) ? 0 : current_option = current_option + 1;

  }

  if (!digitalRead(buttonPin_LFT)) {

    updateMenu = true;
    delay(100);
    Serial.println("left Pin Is Pressed.");
    return (current_option == 0) ? option - 1 : current_option = current_option - 1;


  }

  return current_option;
}


int getupdown(int option, int current_option) {
  if (!digitalRead(buttonPin_SET)) return current_option;
  if (!digitalRead(buttonPin_DWN)) {
    Serial.println("down Pin Is Pressed.");
    delay(100);
    updateMenu = true;
    return (current_option == option - 1) ? 0 : ++current_option;

  }

  if (!digitalRead(buttonPin_UP)) {
    delay(100);
    updateMenu = true;
    return (current_option == 0) ? option - 1 : --current_option;
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

void mainscreenoption()
{

  option = getleftright(8, option);

  while (option != newoption  )
  {

    switch (option) {
      case 0:
        startpage();
        break;
      case 1: instructs();
        break;
      case 2:  selection_pat1();
        break;
      case 3: pattern_1();
        break;
      case 4: pattern_2();
        break;
      case 5: rpmoption_1();
        break;
      case 6:
        delayoption_2();
        break;
      case 7:
        custom();
      default : break;
    }
    Serial.print(option);
    Serial.print("newoption");
    newoption = option;
  }

}

void selectionpat() {
  sel = getupdown (3, sel);
  if (sel != newsel)
    switch (sel) {
      case 0: selection_pat1();
        break;
      case 1: selection_pat2();
        break;
      case 2:
          selection_custom();
        break;
    }
  newsel = sel;

}


void selectioncase1() {
  selec = getupdown (3, selec);
  if (selec != newselec)
    switch (selec) {
      case 0: rpmoption_1();
        break;
      case 1: clockoption_1();
        break;
      case 2: antioption_1();
        break;
      case 3: delayoption_2();
      break;
      case 4: cycleoption_2();
      break;
    }
  newselec = selec;

}

void selectioncase2() {
  sele = getupdown (2, sele);
  if (sele != newsele)
    switch (sele) {
      case 0: delayoption_2();
        break;
      case 1: cycleoption_2();
        break;
     
    }
  newsele = sele;

}

// thinking if should add a bool to main and sub screen to call each option
// do until here
void subscreenoption()
{

  suboption = getleftright(5, suboption);

  while (suboption != subnewoption  )
  {

    switch (suboption) {
      case 0:
        rpm_option();
        break;
      case 1: clockwise_option();
        break;
      case 2:  anticlockwise_option();
        break;
      case 3: delay_option();
        break;
      case 4: cycle_option();
        break;
      
      default : break;
    }
    Serial.print(suboption);
    Serial.print("subnewoption");
    subnewoption = suboption;
  }

}

void loop () {
  mainscreenoption();
  
  // selection pattern page
  if ((option == 2))
  {
    selectionpat();
    if ((sel == 0) && (digitalRead(buttonPin_SET) == LOW))
    {
      option = 3;
    }
    else if ((sel == 1) && (digitalRead(buttonPin_SET) == LOW))
    {
      option = 4;
    }
    else if ((sel == 2) && (digitalRead(buttonPin_SET) == LOW))
      option = 5;
      delay(100);
    Serial.print(sel);
  }

// selection rpm page
if ((option == 5))
  {
    
    selectioncase1();
    if ((selec == 0) && (digitalRead(buttonPin_SET) == LOW))
    {
      suboption = 0;
    }
    else if ((selec == 1) && (digitalRead(buttonPin_SET) == LOW))
    {
      suboption = 1;
    }
    else if ((selec == 2) && (digitalRead(buttonPin_SET) == LOW))
    {
      suboption = 2;
    } 
    Serial.print(selec);
  }

//selection delay page
if ((option == 6))
  {
    
    selectioncase2();
    if ((sele == 0) && (digitalRead(buttonPin_SET) == LOW))
    {
      suboption = 3;
    }
    else if ((sele == 1) && (digitalRead(buttonPin_SET) == LOW))
    {
      suboption = 4;
    }
    
    Serial.print(sele);
  }

}
