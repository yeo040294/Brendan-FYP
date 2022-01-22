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
int motorsum=0;

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

const char *const mainmenu[] PROGMEM = {welcome};
const char *const pat_choice[] PROGMEM = {pat1, pat2, pat3, cus};
const char *const motor_choice[] PROGMEM = {string10, string11, string12, string13};
//const char *const option_choice1[] PROGMEM = {string18, string20, string21, string22};
const char *const option_choice1[] PROGMEM = {string18, string20, string10, string11, string12, string13, string21, string22};
//const char *const option_choice2[] PROGMEM = {};
const char *const pattern1[] PROGMEM = {pat1, string1, string2, string3, string4, string5};
const char *const pattern2[] PROGMEM = {pat2, string1, string2, string3, string4, string5};
const char *const pattern3[] PROGMEM = {pat3, string1, string2, string3, string4, string5};
const char *const customise1[] PROGMEM = {cus1, string1, string2, string3, string4, string5};
// anti clockwise first
//const char *const customise2[] PROGMEM = {cus2, string1, string4, string3, string2, string5};
const char *const key[] PROGMEM = {string6, string7, string8, string9};
const char *const motorkey[] PROGMEM = {string14, string15, string16, string17};

char testing[100];
char testing1[100];
 char buffer1[20];

void setup () {
  stepper.setMaxSpeed(8000);

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
  tft.setRotation (0);                                                                                // landscape upright text
  tft.fillScreen (BLUE);
  startpage();

  relay_init();//initialize the relay
}

void split(char* data)
{
  char splitdata[25];
  strcpy(splitdata, data);
  char* param;
  param = strtok(splitdata, "_");
  while (param != NULL)
  {
    Serial.print(param);
    seqorder(param);
    param = strtok(NULL, "_");
  }
  Serial.print("motorsum: ");
  Serial.println(motorsum);

}

void seqorder (char* data)
{
  stepper.setAcceleration(rpm);
  if (data[0] == 'c')
  {
    int steps = strtol(data+1, NULL, 10);
    Serial.println(steps); 
    stepper.setCurrentPosition(0);
    stepper.moveTo(motormovement(1 * steps));
     while (stepper.distanceToGo() != 0 )
  {
    stepper.run();
  }
    
  }

  if (data[0] == 'a')
  {
    int steps = strtol(data+1, NULL, 10);
    Serial.println(steps); 
    stepper.setCurrentPosition(0);
    stepper.moveTo(motormovement(-1 * steps));
     while (stepper.distanceToGo() != 0 )
  {
    stepper.run();
  }
  }

  if (data[0] == 'w')
  {
    int steps = strtol(data+1, NULL, 10);
    Serial.println(steps);
    motorsum = motorsum + steps;
    linear1(steps);
  }
  
  if (data[0] == 'x')
  {
    int steps = strtol(data+1, NULL, 10);
    Serial.println(steps); 
    motorsum = motorsum + steps;
    linear2(steps);
  }
  
   if (data[0] == 'y')
  {
    int steps = strtol(data+1, NULL, 10);
    Serial.println(steps); 
    motorsum = motorsum + steps;
     linear3(steps);
  }
  
  if (data[0] == 'z')
  {
    int steps = strtol(data+1, NULL, 10);
    Serial.println(steps); 
    motorsum = motorsum + steps;
     linear4(steps);
  }

  if (data[0] == 'r')
  {
    int steps = strtol(data+1, NULL, 10);
    Serial.println(steps); 
  }

  if (data[0] == 'e')
  {
    int steps = strtol(data+1, NULL, 10);
    Serial.println(steps); 
  }
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
    selec = getupdown (8, selec);
    if (selec != newselec) {
      choice(8, option_choice1, selec);         // clockwise / anticlockwise / rpm / cycle
    }
    newselec = selec;
    if ((selec == 0) && (digitalRead(buttonPin_SET) == LOW))        //clockwise
    {
     
      delay(200);
      
      //suboption = 0;
      option = -1;
      do {
        updateMenu = false;
        //subscreenoption();
        clockwise_option();
        dataupdates(1);                     // increase / decrease clockwise
        if (digitalRead(buttonPin_SET) == LOW)
        {
      strcat(testing, "c");
      itoa(cw, buffer1, 10);
      strcat(testing, buffer1);
      strcat(testing, "_");
      strcpy(testing1, testing);
      strcpy(testing, testing1);
      Serial.println(testing);
      delay (100);
          option = 6;
          selec = 1;                            // go to linear option
          break;
        }
      } while (option = -1);

    }

    else if ((selec == 1) && (digitalRead(buttonPin_SET) == LOW))     //anticlockwise
    {
      delay(200);
      option = -1;
      do {
        
        anticlockwise_option();
        dataupdates(2);                          // increase / decrease anti clockwise
        if (digitalRead(buttonPin_SET) == LOW)
        {
          strcat(testing, "a");
      itoa(acw, buffer1, 10);
      strcat(testing, buffer1);
      strcat(testing, "_");
      strcpy(testing1, testing);
      strcpy(testing, testing1);
      Serial.println(testing);
      delay (100);
          option = 6;
          selec = 2;                                // go to rpm option
          break;
        }
      } while (option = -1);
    }



    else if ((selec == 2) && (digitalRead(buttonPin_SET) == LOW))        //motor1
    {

      delay(200);
      
      option = -1;
      do {
        //subscreenoption();
        motor1_option();
        dataupdates(4);                     // increase / decrease motor1
        if (digitalRead(buttonPin_SET) == LOW)
        {
          strcat(testing, "w");
      itoa(lin1, buffer1, 10);
      strcat(testing, buffer1);
      strcat(testing, "_");
      strcpy(testing1, testing);
      strcpy(testing, testing1);
      Serial.println(testing);
      delay (100);
          option = 6;                        // go to motor 2 option
          selec = 3;
          break;
        }
      } while (option = -1);

    }

    else if ((selec == 3) && (digitalRead(buttonPin_SET) == LOW))        //motor2
    {
      delay(200);
      
      option = -1;
      do {
        motor2_option();
        dataupdates(5);                          // increase / decrease motor 2
        if (digitalRead(buttonPin_SET) == LOW)
        {
          strcat(testing, "x");
      itoa(lin2, buffer1, 10);
      strcat(testing, buffer1);
      strcat(testing, "_");
      strcpy(testing1, testing);
      strcpy(testing, testing1);
      Serial.println(testing);
      delay (100);
          delay(100);
          option = 6;
          selec = 4;                             // go to motor 3 option
          break;
        }
      } while (option = -1);

    }
    else if ((selec == 4) && (digitalRead(buttonPin_SET) == LOW))        //motor3
    {
      delay(200);
     
      option = -1;
      do {
        motor3_option();
        dataupdates(6);                          // increase / decrease motor 3
        if (digitalRead(buttonPin_SET) == LOW)
        {
          strcat(testing, "y");
      itoa(lin3, buffer1, 10);
      strcat(testing, buffer1);
      strcat(testing, "_");
      strcpy(testing1, testing);
      strcpy(testing, testing1);
      Serial.println(testing);
      
          delay(100);
          option = 6;
          selec = 5;                            // go to motor 4
          break;
        }
      } while (option = -1);

    }

    else if ((selec == 5) && (digitalRead(buttonPin_SET) == LOW))        //motor4
    {
      delay(200);
      option = -1;
      do {
        motor4_option();
        dataupdates(7);                          // increase / decrease motor 4
        if (digitalRead(buttonPin_SET) == LOW)
        {
          strcat(testing, "z");
      itoa(lin4, buffer1, 10);
      strcat(testing, buffer1);
      strcat(testing, "_");
      strcpy(testing1, testing);
      strcpy(testing, testing1);
      Serial.println(testing);
      delay (100);
          
          option = 6;
          selec = 6;                            //go to rpm
          break;
        }
      } while (option = -1);

    }
    else if ((selec == 6) && (digitalRead(buttonPin_SET) == LOW))
    {
      delay(200);
      option = -1;
      do {
        rpm_option();
        dataupdates(0);                             // increase / decrease rpm
        if (digitalRead(buttonPin_SET) == LOW)
        {
           strcat(testing, "r");
      itoa(rpm, buffer1, 10);
      strcat(testing, buffer1);
      strcat(testing, "_");
      strcpy(testing1, testing);
      strcpy(testing, testing1);
      Serial.println(testing);
      delay (100);
          option = 6;                               // go to cycle option
          selec = 7;
          break;
        }
      } while (option = -1);

    }
    else if ((selec == 7) && (digitalRead(buttonPin_SET) == LOW))        //cycle
    {
      delay(200);
      option = -1;
      do {
        cycle_option();
        dataupdates(3);                             // increase / decrease cycle
        if (digitalRead(buttonPin_SET) == LOW)
        {
           strcat(testing, "e");
      itoa(cyc, buffer1, 10);
      strcat(testing, buffer1);
      strcat(testing, "_");
      strcpy(testing1, testing);
      strcpy(testing, testing1);
      Serial.println(testing);
      delay (100);
          option = 8;
          custom1();                                // go to customise page
          break;

        }
      } while (option = -1);
    }
  }

  /*  if ((option == 7))
    {

      delay(200);
      se = getupdown (4, se);
      if (se != newse) {
        choice(4, motor_choice, se);
      }
      newse = se;

      if ((se == 0) && (digitalRead(buttonPin_SET) == LOW))        //motor1
      {
        delay (100);
        option = -1;
        //option = -1;
        do {
          //subscreenoption();
          motor1_option();
          dataupdates(4);                     // increase / decrease motor1
          if (digitalRead(buttonPin_SET) == LOW)
          {
            delay(100);
            option = 7;                        // go to motor 2 option
            se = 1;
            break;
          }
        } while (option = -1);
      }

      else if ((se == 1) && (digitalRead(buttonPin_SET) == LOW))      // motor2
      {

        delay (100);
        //suboption = -1;
        option = -1;
        do {
          //subscreenoption();
          motor2_option();
          dataupdates(5);                          // increase / decrease motor 2
          if (digitalRead(buttonPin_SET) == LOW)
          {
            delay(100);
            option = 7;
            se = 2;                             // go to motor 3 option
            break;
          }
        } while (option = -1);

      }


      else if ((se == 2) && (digitalRead(buttonPin_SET) == LOW))      // motor 3
      {


        delay (100);
        //suboption = -1;
        option = -1;
        do {
          //subscreenoption();
          motor3_option();
          dataupdates(6);                          // increase / decrease motor 3
          if (digitalRead(buttonPin_SET) == LOW)
          {
            delay(100);
            option = 7;
            se = 3;                            // go to motor 4
            break;
          }
        } while (option = -1);
      }

      else if ((se == 3) && (digitalRead(buttonPin_SET) == LOW))      //motor 4
      {


        delay (100);
        //suboption = -1;
        option = -1;
        do {
          //subscreenoption();
          motor4_option();
          dataupdates(7);                          // increase / decrease motor 4
          if (digitalRead(buttonPin_SET) == LOW)                                      //ERROR unsure how to get out of the loop  to go :  option 6 selec 2 page (previous page) Linear page
          {
            delay(300);
            option = 8;

            break;
          }
        } while (option = -1);

      }
    }
  */

  // pattern 1 execution
  if ((option  == 3) && (digitalRead(buttonPin_SET) == LOW))
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
  if ((option  == 4) && (digitalRead(buttonPin_SET) == LOW))
  {
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 35);
    tft.print(F("Executing\n  Pattern\n     2"));
    motorcode2();
    pattern_2();
  }

  // pattern 3 execution
  if ((option  == 5) && (digitalRead(buttonPin_SET) == LOW))
  {
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 35);
    tft.print(F("Executing\n  Pattern\n    3"));
    motorcode3();
    pattern_3();
  }
  // customise execution
  if ((option == 8) && (digitalRead(buttonPin_SET) == LOW))
  {
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 35);
    tft.print(F("Executing\n  Custom\n     1"));
    //motorcode7(rpm, cw, lin1, lin2, lin3, lin4, acw, cyc);
    split(testing);
    Serial.print(motorsum); 
    custom1();
  }

if  (digitalRead(buttonPin_MID) == LOW)
{
strcpy (testing, ""); 
int rpm = 200;
int cw = 0;
int lin1 = 0;
int lin2 = 0;
int lin3 = 0;
int lin4 = 0;
int acw = 0;
int cyc = 1;

}

}
