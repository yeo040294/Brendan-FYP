// pin wiring to Nano as follows
// GND ----- GND
// VCC ----- 3V3
// SCL ----- D13 yellow wire
// SDA ----- D11 green wire
// RES ----- D12
// DC ------ D2
// CS ------ D10
// BLK ----- 3V3 if you like
//


#include <Adafruit_GFX.h>                                                                           // Adafruit graphics library
#include <Adafruit_ST7735.h>                                                                        // Adafruit ST7735 display library
#include <SPI.h>                                                                                    // Arduino SPI library 
#include <Arduino.h>
#include "A4988.h"


#define TFT_RST  12                                                                                 // reset line (optional, pass -1 if not used)
#define TFT_CS   10                                                                                  // chip select line
#define TFT_DC   2                                                                                  // data/command line


#define MOTOR_STEPS 200
// configure the pins connected
#define DIR A4
#define STEP A3
A4988 stepper(MOTOR_STEPS, DIR, STEP);


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);                                     // constructor Adafruit ST7735 TFT library



const unsigned char right_arrow [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0x8f, 0xf0, 0xff, 0x87, 0xf0, 0xc0, 0x03, 0xf0, 0xc0, 0x00, 0xf0, 0xc0, 0x00, 0x70, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x70, 0xc0, 0x00, 0xf0, 0xc0, 0x03, 0xf0, 0xff, 0x87, 0xf0, 0xff, 0x8f, 0xf0, 0xff, 0xbf, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char rect_set_reset [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char down_arrow [] PROGMEM = {0xff, 0x9f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xfb, 0x0d, 0xf0, 0xf1, 0x08, 0xf0, 0xf0, 0x00, 0xf0, 0xf8, 0x01, 0xf0, 0xfc, 0x03, 0xf0, 0xfe, 0x07, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char up_arrow [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0x0f, 0xf0, 0xfe, 0x07, 0xf0, 0xfc, 0x03, 0xf0, 0xf8, 0x01, 0xf0, 0xf0, 0x00, 0xf0, 0xf0, 0x00, 0xf0, 0xf1, 0x08, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char left_arrow [] PROGMEM = {0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xfe, 0x7f, 0xf0, 0xfc, 0x7f, 0xf0, 0xf8, 0x7f, 0xf0, 0xf0, 0x00, 0x30, 0xe0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xe0, 0x00, 0x10, 0xf0, 0x00, 0x30, 0xf8, 0x7f, 0xf0, 0xfc, 0x7f, 0xf0, 0xfe, 0x7f, 0xf0, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0};
const unsigned char down_15 [] PROGMEM = {0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xe0, 0x0e, 0xe0, 0x0e, 0xf0, 0x1e, 0xf8, 0x3e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char up_15 [] PROGMEM = {0xfe, 0xfe, 0xfc, 0x7e, 0xf8, 0x3e, 0xf0, 0x1e, 0xe0, 0x0e, 0xe0, 0x0e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char left_15 [] PROGMEM = {0xff, 0xfe, 0xff, 0xfe, 0xf9, 0xfe, 0xf1, 0xfe, 0xe0, 0x06, 0xc0, 0x02, 0xc0, 0x02, 0xc0, 0x02, 0xe0, 0x02, 0xf1, 0xfe, 0xfb, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char right_15 [] PROGMEM = {0xff, 0xfe, 0xff, 0xfe, 0xfe, 0x7e, 0xfc, 0x3e, 0xc0, 0x1e, 0x80, 0x0e, 0x80, 0x06, 0x80, 0x0e, 0xc0, 0x1e, 0xfe, 0x7e, 0xff, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};

/*// some original color definitions
   #define BLACK   0x0000
   #define WHITE   0xffff
   #define BLUE    0x001F
   #define RED     0xF800
   #define GREEN   0x07E0
   #define CYAN    0x07FF
   #define MAGENTA 0xF81F
   #define YELLOW  0xFFE0
*/


// inverted color definitions - these used in this demo
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

#define ON   0
#define OFF  1

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

int mode = 0;
int rpm = 80;
int cw = 0;
int lin1 = 0;
int lin2 = 0;
int lin3 = 0;
int lin4 = 0;
int acw = 0;
int cyc = 1;


char buffer[50];

//Character Array
const char welcome[] PROGMEM = "Welcome to \n  Art Buddy";

const char pat1[] PROGMEM = "Pattern 1";
const char pat2[] PROGMEM = "Pattern 2";
const char pat3[] PROGMEM = "Pattern 3";
const char cus[] PROGMEM = "Customise";
const char cus1[] PROGMEM = "Customise 1";
const char cus2[] PROGMEM = "Customise 2";

const char string1[] PROGMEM = "RPM (min 80): ";
const char string2[] PROGMEM = "Clockwise: ";
const char string3[] PROGMEM = "Linear: ";
const char string4[] PROGMEM = "Anti-Clockwise: ";
const char string5[] PROGMEM = "Cycle: ";
const char string6[] PROGMEM = "RPM \n  (min 80)";
const char string7[] PROGMEM = "\nClockwise";
const char string8[] PROGMEM = "Anti\n Clockwise";
const char string9[] PROGMEM = "\nCycle";
const char string10[] PROGMEM = "Motor 1";
const char string11[] PROGMEM = "Motor 2";
const char string12[] PROGMEM = "Motor 3";
const char string13[] PROGMEM = "Motor 4";
const char string14[] PROGMEM = "\n Motor 1";
const char string15[] PROGMEM = "\n Motor 2";
const char string16[] PROGMEM = "\n Motor 3";
const char string17[] PROGMEM = "\n Motor 4";
const char string18[] PROGMEM = "Clockwise";
const char string19[] PROGMEM = "Linear";
const char string20[] PROGMEM = "Anti-Clockwise";
const char string21[] PROGMEM = "RPM";
const char string22[] PROGMEM = "Cycle";



const char *const mainmenu[] PROGMEM = {welcome};
const char *const pat_choice[] PROGMEM = {pat1, pat2, pat3, cus};
const char *const motor_choice[] PROGMEM = {string10, string11, string12, string13};
const char *const option_choice1[] PROGMEM = {string18, string19, string20};
const char *const option_choice2[] PROGMEM = {string21, string22};
const char *const pattern1[] PROGMEM = {pat1, string1, string2, string3, string4, string5};
const char *const pattern2[] PROGMEM = {pat2, string1, string2, string3, string4, string5};
const char *const pattern3[] PROGMEM = {pat3, string1, string2, string3, string4, string5};
const char *const customise1[] PROGMEM = {cus1, string1, string2, string3, string4, string5};
// anti clockwise first
const char *const customise2[] PROGMEM = {cus2, string1, string4, string3, string2, string5};
const char *const key[] PROGMEM = {string6, string7, string8, string9};
const char *const motorkey[] PROGMEM = {string14, string15, string16, string17};

void menu(int menu_opt ,  const char *const string_table[]) {
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  if (string_table == customise1 || string_table == customise2)
  {
    tft.setCursor(10, 30);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[0])));
  }
  else
  {
    tft.setCursor(30, 30);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[0])));
  }
  tft.println(buffer);
  for (int i = 1; i < menu_opt; i++)
  {
    tft.setTextSize(1);
    tft.setCursor(30, 50 + i * 10 - 10);
    strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
    tft.println(buffer);
  }
  tft.setTextSize(1);
  tft.setCursor(133, 92);
  tft.print(F("SET"));
  tft.drawRect(130, 90, 22, 15, WHITE);
  tft.drawBitmap (10, 70, left_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (135, 70, right_15, 15, 15, BLACK, WHITE);
}

void choice(int choice_opt ,  const char *const string_table[], int select) {

  tft.fillScreen(BLACK);
  if (choice_opt == 4)  {
    for (int i = 0; i < choice_opt; i++)
    {
      tft.setTextSize(1);
      tft.setCursor(30, 55 + i * 20 - 20);
      strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
      tft.println(buffer);
    }
    if (select == 0)
      tft.drawRect(28, 28, 60, 18, WHITE);
    else if (select == 1)
      tft.drawRect(28, 48, 60, 18, WHITE);
    else if (select == 2)
      tft.drawRect(28, 68, 60, 18, WHITE);
    else
      tft.drawRect(28, 88, 60, 18, WHITE);
  }
  else  {
    for (int i = 0; i < choice_opt; i++)
    {
      tft.setTextSize(1);
      tft.setCursor(30, 60 + i * 20 - 20);
      strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
      tft.println(buffer);
    }
    if (select == 0)
      tft.drawRect(28, 35, 60, 18, WHITE);
    else if (select == 1)
      tft.drawRect(28, 55, 60, 18, WHITE);
    else
      tft.drawRect(28, 75, 97, 18, WHITE);
  }
  tft.drawBitmap (90, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (90, 90, down_15, 15, 15, WHITE, BLACK);

}

void state (int menu_opt, const char *const string_table[]) {
  int i = menu_opt;
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 35);
  strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i])));
  tft.println(buffer);
  tft.drawBitmap (70, 30, up_15, 15, 15, WHITE, BLACK);
  tft.drawBitmap (70, 90, down_15, 15, 15, WHITE, BLACK);
}

//menu display
void mainscreenoption()
{
  option = getleftright(10, option);
  while (option != newoption  )
  {
    switch (option) {
      case 0:
        startpage();
        break;
      case 1: instructs();
        break;
      case 2: selection_pat1();                // pattern selection page
        break;
      case 3: pattern_1();
        break;
      case 4: pattern_2();
        break;
      case 5: pattern_3();
        break;
      case 6: clockoption_1();        
        break;
      case 7: rpmoption_2();         
        break;
      case 8:
        custom1();
        break;
      case 9:
        custom2();
        break;
      default : break;
    }
    newoption = option;
  }
}


void setup () {
  tft.setTextColor(WHITE);


  tft.initR (INITR_BLACKTAB);                                                                         // initialize ST7735S TFT display

  Serial.begin (9600);
  Serial.println ("starting ST 7735 TFT");
  Serial.println ("80x160 rotated 90 degrees");
  Serial.println ("Muybridge's galloping horse Sallie Gardner");
  Serial.println ("one frame - DEMO");
  Serial.println ("inverted color scheme");


  pinMode(buttonPin_RST, INPUT_PULLUP);
  pinMode(buttonPin_SET, INPUT_PULLUP);
  pinMode(buttonPin_MID, INPUT_PULLUP);
  pinMode(buttonPin_RHT, INPUT_PULLUP);
  pinMode(buttonPin_LFT, INPUT_PULLUP);
  pinMode(buttonPin_DWN, INPUT_PULLUP);
  pinMode(buttonPin_UP, INPUT_PULLUP);
  tft.setRotation (3);                                                                                // landscape upright text
  tft.fillScreen (BLUE);
  startpage();

  relay_init();//initialize the relay
}

void relay_init(void)//initialize the relay
{
  //set all the relays OUTPUT
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  relay_SetStatus(OFF, OFF, OFF, OFF); //turn off all the relay
}

//set the status of relays
void relay_SetStatus( unsigned char status_1,  unsigned char status_2, unsigned char status_3, unsigned char status_4)
{
  digitalWrite(IN1, status_1);
  digitalWrite(IN2, status_2);
  digitalWrite(IN3, status_3);
  digitalWrite(IN4, status_4);
}
//update of customise variable ( rpm / clockwise / anticlockwise / delay / cycle )
int dataupdates( int opt)
{
  suboption = opt;

  //RPM update
  if (digitalRead(buttonPin_UP) == LOW && suboption == 0)             
  {
    rpm = rpm  + 10;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && rpm  > 0 && suboption == 0)
  {
    rpm = rpm  - 10;
    delay(100);
  }

  // clockwise update
  if (digitalRead(buttonPin_UP) == LOW && suboption == 1)
  {
    cw = cw  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && cw  > 0 && suboption == 1)
  {
    cw = cw  - 1;
    delay(100);
  }

  // anticlockwise update
  if (digitalRead(buttonPin_UP) == LOW && suboption == 2)
  {
    acw = acw  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && acw  > 0 && suboption == 2)
  {
    acw = acw  - 1;
    delay(100);
  }

  // cycle update
  if (digitalRead(buttonPin_UP) == LOW && suboption == 3)
  {
    cyc = cyc  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && cyc  > 0 && suboption == 3)
  {
    cyc = cyc  - 1;
    delay(100);
  }

   // Lin 1
  if (digitalRead(buttonPin_UP) == LOW && suboption == 4)
  {
    lin1 = lin1  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && lin1  > 0 && suboption == 4)
  {
    lin1 = lin1  - 1;
    delay(100);
  }

     // Lin 2
  if (digitalRead(buttonPin_UP) == LOW && suboption == 5)
  {
    lin2 = lin2  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && lin2  > 0 && suboption == 5)
  {
    lin2 = lin2  - 1;
    delay(100);
  }
     // Lin 3
  if (digitalRead(buttonPin_UP) == LOW && suboption == 6)
  {
    lin3 = lin3  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && lin3  > 0 && suboption == 6)
  {
    lin3 = lin3  - 1;
    delay(100);
  }


 // Lin 4
  if (digitalRead(buttonPin_UP) == LOW && suboption == 7)
  {
    lin4 = lin4  + 1;
    delay(100);
  }
  else if ((digitalRead(buttonPin_DWN) == LOW) && lin4  > 0 && suboption == 7)
  {
    lin4 = lin4  - 1;
    delay(100);
  }

}


void loop () {

//  Serial.println(option);
Serial.print(selec);
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
      delay(100);
      option = 3;
      pattern_1();                             // required else code will auto execute
    }
    else if ((sel == 1) && (digitalRead(buttonPin_SET) == LOW))   //pattern 2
    {
      option = 4;
      pattern_2();                             // required else code will auto execute
    }
    else if ((sel == 2) && (digitalRead(buttonPin_SET) == LOW))   //pattern 2
    {
      option = 5;
      pattern_3();                             // required else code will auto execute
    }
    else if ((sel == 3) && (digitalRead(buttonPin_SET) == LOW))   //customise option
      option = 6;
    delay(100);
  }

  // selection rpm page
  if ((option == 6))
  {
    selec = getupdown (3, selec);
    if (selec != newselec) {
      choice(3, option_choice1, selec);         // clockwise / linear / anticlockwise
    }
    newselec = selec;
    if ((selec == 0) && (digitalRead(buttonPin_SET) == LOW))        //clockwise
    {
      delay (100);
      //suboption = 0;
      option = -1;
      do {
        //subscreenoption();
        clockwise_option();
        dataupdates(1);                     // increase / decrease clockwise
        if (digitalRead(buttonPin_SET) == LOW)
        {
          option = 6;
          selec = 1;                            // go to linear option
          break;
        }
      } while (option = -1);
    }

    else if ((selec == 1) && (digitalRead(buttonPin_SET) == LOW))     //linear
    {
      delay (100);
      //suboption = 1;
      option = -1;

      do {
        se = getupdown (4, se);
        if (se != newse) {
          choice(4, motor_choice, se);
        }
        newse = se;

        if ((se == 0) && (digitalRead(buttonPin_SET) == LOW))        //motor1
        {
          delay (100);
          suboption = -1;
          //option = -1;
          do {
            //subscreenoption();
            motor1_option();
            dataupdates(4);                     // increase / decrease motor1
            if (digitalRead(buttonPin_SET) == LOW)
            {
              delay(100);
              suboption = 1;                        // go to motor 2 option
              se = 1;
              break;
            }
          } while (suboption = -1);
        }

        else if ((se == 1) && (digitalRead(buttonPin_SET) == LOW))      // motor2
        {
        
                    delay (100);
                    suboption = -1;
                    option = -1;
                    do {
                      //subscreenoption();
                      motor2_option();
                      dataupdates(5);                          // increase / decrease motor 2
                      if (digitalRead(buttonPin_SET) == LOW)
                      {
                        delay(100);
                        suboption = 1;
                        se = 2;                             // go to motor 3 option
                        break;
                      }
                    } while (suboption = -1);
          
        }


        else if ((se == 2) && (digitalRead(buttonPin_SET) == LOW))      // motor 3
        {


          delay (100);
          suboption = -1;
          option = -1;
          do {
            //subscreenoption();
            motor3_option();
            dataupdates(6);                          // increase / decrease motor 3
            if (digitalRead(buttonPin_SET) == LOW)
            {
              delay(100);
              suboption = 1;
              se = 3;                            // go to motor 4
              break;
            }
          } while (suboption = -1);
        }

        else if ((se == 3) && (digitalRead(buttonPin_SET) == LOW))      //motor 4
        {


          delay (100);
          suboption = -1;
          option = -1;
          do {
            //subscreenoption();
            motor4_option();
            dataupdates(7);                          // increase / decrease motor 4
            if (digitalRead(buttonPin_SET) == LOW)                                      //ERROR unsure how to get out of the loop  to go :  option 6 selec 2 page (previous page) Linear page
            {
              delay(100);
             
                                                                                   
                                         // go to delay option

              option = 6;
              selec =2;
             // suboption = 1;
             // se = 0;
              break;
            }
          } while (suboption = -1);
         
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
        dataupdates(2);                          // increase / decrease anti clockwise
        if (digitalRead(buttonPin_SET) == LOW)
        {
          option = 6;
          selec = 0;                                // go to rpm option
          break;
        }
      } while (option = -1);
    }
  }

  if ((option == 7))
  {
    delay(200);
    sele = getupdown (2, sele);
    if (sele != newsele) {
      choice(2, option_choice2, sele);                                 // rpm
    }
    newsele = sele;

    //selectioncase2();
    if ((sele == 0) && (digitalRead(buttonPin_SET) == LOW))
    {
      delay (100);
      //suboption = 3;
      option = -1;
      do {
        rpm_option();
        //subscreenoption();
        dataupdates(0);                             // increase / decrease rpm
        if (digitalRead(buttonPin_SET) == LOW)
        {
          option = 7;                               // go to cycle option
          sele = 1;
          break;
        }
      } while (option = -1);
    }
    else if ((sele == 1) && (digitalRead(buttonPin_SET) == LOW))        //cycle
    {
      delay (100);
      //suboption = 4;
      option = -1;
      do {
        //subscreenoption();
        cycle_option();
        dataupdates(3);                             // increase / decrease cycle
        if (digitalRead(buttonPin_SET) == LOW)
        {
          option = 8;
          custom1();                                 // go to customise execution page
          break;
        }
      } while (option = -1);
    }
  }



}
