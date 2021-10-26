// nano_80x160_TFT_ST7735_muybridge_demo
// display 80*160 TFT 7-pins SPI interface
// NOTE this is a 3.3V device. Use resistors in control lines
//
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
// december 26, 2020
// Floris Wouterlood 
// public domain
 
   #include <Adafruit_GFX.h>                                                                           // Adafruit graphics library
   #include <Adafruit_ST7735.h>                                                                        // Adafruit ST7735 display library
   #include <SPI.h>                                                                                    // Arduino SPI library 
   #include <Arduino.h> 
   #include "A4988.h"
  

   #define TFT_RST  12                                                                                 // reset line (optional, pass -1 if not used)
   #define TFT_CS   10                                                                                  // chip select line
   #define TFT_DC   2                                                                                  // data/command line

   //Stepper motor
   // using a 200-step motor (most common) 
    #define MOTOR_STEPS 200 
    // configure the pins connected 
    #define DIR A4
    #define STEP A3 
    A4988 stepper(MOTOR_STEPS, DIR, STEP); 

    
   Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);                                     // constructor Adafruit ST7735 TFT library


const unsigned char right_arrow [] PROGMEM = {
 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0x8f, 0xf0, 0xff, 0x87, 0xf0, 0xc0, 
 0x03, 0xf0, 0xc0, 0x00, 0xf0, 0xc0, 0x00, 0x70, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x70, 0xc0, 0x00, 
  0xf0, 0xc0, 0x03, 0xf0, 0xff, 0x87, 0xf0, 0xff, 0x8f, 0xf0, 0xff, 0xbf, 0xf0, 0xff, 0xff, 0xf0, 
  0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0
};

const unsigned char rect_set_reset [] PROGMEM = {
  0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xc0, 0x00, 0x30, 0xc0, 
  0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 
  0x30, 0xc0, 0x00, 0x30, 0xc0, 0x00, 0x30, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 
  0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0
};

const unsigned char down_arrow [] PROGMEM = {
  0xff, 0x9f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 
  0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xfb, 0x0d, 0xf0, 0xf1, 0x08, 0xf0, 0xf0, 0x00, 
  0xf0, 0xf8, 0x01, 0xf0, 0xfc, 0x03, 0xf0, 0xfe, 0x07, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x9f, 0xf0, 
  0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0
};

const unsigned char up_arrow [] PROGMEM = {
  0xff, 0xff, 0xf0, 0xff, 0x0f, 0xf0, 0xfe, 0x07, 0xf0, 0xfc, 0x03, 0xf0, 0xf8, 0x01, 0xf0, 0xf0, 
  0x00, 0xf0, 0xf0, 0x00, 0xf0, 0xf1, 0x08, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 
  0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x0f, 0xf0, 0xff, 0x9f, 0xf0, 
  0xff, 0x9f, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0
};

const unsigned char left_arrow [] PROGMEM = {
  0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xfe, 0x7f, 0xf0, 0xfc, 0x7f, 0xf0, 0xf8, 0x7f, 0xf0, 0xf0, 
  0x00, 0x30, 0xe0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xc0, 0x00, 0x10, 0xe0, 0x00, 
  0x10, 0xf0, 0x00, 0x30, 0xf8, 0x7f, 0xf0, 0xfc, 0x7f, 0xf0, 0xfe, 0x7f, 0xf0, 0xff, 0x7f, 0xf0, 
  0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0
};

// 'down_15', 15x15px
const unsigned char down_15 [] PROGMEM = {
  0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xe0, 0x0e, 
  0xe0, 0x0e, 0xf0, 0x1e, 0xf8, 0x3e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe
};
// 'up_15', 15x15px
const unsigned char up_15 [] PROGMEM = {
  0xfe, 0xfe, 0xfc, 0x7e, 0xf8, 0x3e, 0xf0, 0x1e, 0xe0, 0x0e, 0xe0, 0x0e, 0xfc, 0x7e, 0xfc, 0x7e, 
  0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe
};
// 'left_15', 15x15px
const unsigned char left_15 [] PROGMEM = {
  0xff, 0xfe, 0xff, 0xfe, 0xf9, 0xfe, 0xf1, 0xfe, 0xe0, 0x06, 0xc0, 0x02, 0xc0, 0x02, 0xc0, 0x02, 
  0xe0, 0x02, 0xf1, 0xfe, 0xfb, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe
};
// 'right_15', 15x15px
const unsigned char right_15 [] PROGMEM = {
  0xff, 0xfe, 0xff, 0xfe, 0xfe, 0x7e, 0xfc, 0x3e, 0xc0, 0x1e, 0x80, 0x0e, 0x80, 0x06, 0x80, 0x0e, 
  0xc0, 0x1e, 0xfe, 0x7e, 0xff, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe
};

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


int mode = 0;
int rpm = 80;   
int cw = 0;
int lin1 =0;
int acw =0;
int cyc = 1;


void setup () {

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
  //pinMode(buttonPin_UP, INPUT);
  pinMode(buttonPin_UP, INPUT_PULLUP);
   tft.setRotation (3);                                                                                // landscape upright text
   tft.fillScreen (BLUE); 
   screen1();

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

 
void screen1(){

tft.fillScreen(WHITE);
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
  tft.fillScreen(WHITE);
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
void print_text(byte x_pos, byte y_pos, char *text, byte text_size, uint16_t color) {

}
void screen3(){
 /*tft.fillScreen(WHITE);
//tft.fillRect (18,80,50,20,GREEN);
    tft.setTextSize(2);
    tft.setCursor(20, 35);
 tft.print(F("Trial 1/3"));
    tft.setTextSize(1);
    tft.setCursor(20, 70);
     tft.print(F("Press SET to start"));   
      tft.setTextSize(1);
    tft.setCursor(20, 80);
     tft.print(F("RIGHT to continue"));// 
*/
     tft.fillScreen(WHITE);

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
    
    tft.drawBitmap (10,70, left_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (70,90, rect_set_reset, 20, 20, WHITE, BLACK);
}

void screen4(){
/*  tft.fillScreen(WHITE);
//tft.fillRect (18,80,50,20,GREEN);
    tft.setTextSize(2);
    tft.setCursor(20, 35);
 tft.print(F("Trial 2/3"));
    tft.setTextSize(1);
    tft.setCursor(20, 70);
     tft.print(F("Press SET to start"));   
      tft.setTextSize(1);
    tft.setCursor(20, 80);
     tft.print(F("RIGHT to continue"));// 
*/
     tft.fillScreen(WHITE);

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

    tft.drawBitmap (10,70, left_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (70,90, rect_set_reset, 20, 20, WHITE, BLACK);
}

void screen5(){
  /* tft.fillScreen(WHITE);
//tft.fillRect (18,80,50,20,GREEN);
    tft.setTextSize(2);
    tft.setCursor(20, 35);
 tft.print(F("Trial 3/3"));
    tft.setTextSize(1);
    tft.setCursor(20, 70);
     tft.print(F("Press SET to start"));   
      tft.setTextSize(1);
    tft.setCursor(20, 80);
     tft.print(F("RIGHT to continue"));// 
*/
   tft.fillScreen(WHITE);

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

    tft.drawBitmap (10,70, left_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (70,90, rect_set_reset, 20, 20, WHITE, BLACK);
}

/*void screen5(){
   tft.fillScreen(WHITE);
//tft.fillRect (18,80,50,20,GREEN);
    tft.setTextSize(2);
    tft.setCursor(20, 35);
 tft.print(F("Trial 3/3"));
    tft.setTextSize(1);
    tft.setCursor(20, 70);
     tft.print(F("Press SET to start"));   
      tft.setTextSize(1);
    tft.setCursor(20, 80);
     tft.print(F("RIGHT to continue"));// 
}
*/
void screen6(){
   tft.fillScreen(WHITE);

    tft.setTextSize(2);
    tft.setCursor(30, 30);
    tft.print(F("Customise"));



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
    tft.setCursor(120, 70);
    tft.print(lin1);
    
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

    tft.drawBitmap (10,70, left_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (135,70, right_15, 15, 15, BLACK, WHITE);
    tft.drawBitmap (70,90, rect_set_reset, 20, 20, WHITE, BLACK);
}


void screen7(){

    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 35);
    tft.print(F("RPM \n  (min 80)"));
   
    tft.setCursor(40, 75);
    tft.print(rpm);;

   tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
   tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
}

void screen8(){

    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Clockwise"));
   
    tft.setCursor(50, 75);
    tft.print(cw);

    

    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
}


void screen9(){

    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Linear"));
   
    tft.setCursor(50, 75);
    tft.print(lin1);
 
    
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
   
}

void screen10(){
 
    
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Anti\n  Clockwise"));
   
    tft.setCursor(50, 80);
    tft.print(acw);

    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
}


void screen11(){
  
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Cycle"));
   
    tft.setCursor(50, 75);
    tft.print(cyc);

    
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
}


//motorcode 1
void motorcode1(){
  int trial =0;
  while (trial<5){
  stepper.begin(80,1);
     stepper.rotate(540);//3 rounds clockwise
     relay_SetStatus(ON, OFF, OFF, OFF);//turn on RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    stepper.begin(100,1);
    stepper.rotate(-720);
    relay_SetStatus(OFF,OFF , ON, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    stepper.begin(110,1);
    stepper.rotate(720);
     relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
     delay(200);//delay 2s0
      relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     stepper.begin(110,1);
    stepper.rotate(-720);
     relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     
     stepper.begin(110,1);
    stepper.rotate(1080);
     stepper.begin(110,1);
    stepper.rotate(-1080);
    relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     
  trial++;
  }
}
//motor code 2
   void motorcode2(){
    
   int trial =0;
  while (trial<5){
    stepper.begin(100,1);
    stepper.rotate(720);//3 rounds clockwise
    stepper.begin(100,1);
    stepper.rotate(-720);
    relay_SetStatus(OFF,OFF , ON, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
      delay(200);//delay 2s0
       relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    stepper.begin(110,1);
    stepper.rotate(720);
     stepper.begin(110,1);
    stepper.rotate(-720);
     relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     
     stepper.begin(110,1);
    stepper.rotate(1080);
     stepper.begin(110,1);
    stepper.rotate(-1080);
    relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     
  trial++;
  }
   }

 //motor code 3
 // void motorcode3(int round){
 void motorcode3(){
    int trial =0;
  while (trial<5){
 stepper.begin(100,1);
     stepper.rotate(720);//3 rounds clockwise
     relay_SetStatus(ON, OFF, OFF, OFF);//turn on RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    stepper.begin(100,1);
    stepper.rotate(-720);
    relay_SetStatus(OFF,OFF , ON, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    stepper.begin(130,1);
    stepper.rotate(900);
     relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
     delay(200);//delay 2s0
      relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     stepper.begin(130,1);
    stepper.rotate(-900);
     relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     
     stepper.begin(110,1);
    stepper.rotate(1080);
     stepper.begin(110,1);
    stepper.rotate(-1080);
    relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     delay(200);//delay 2s0
     relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
     
  trial++;
  }
}
// adjustable code for linear motor2
int motorcode4(int y){
  int x =0;
  while (x <  y) {
  relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
       relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
   relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
   y--;
   Serial.print(y);
  }
}

//adjustable code
int motorcode5 (int spd, int clw, int y, int aclw, int rounds)
 {
  
   
   int newy = y;
  while (rounds != 0 )
  {
    stepper.begin(spd,1);
     stepper.rotate(clw*360);//3 rounds clockwise

    
  while (y!= 0) {
  relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
       relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
   relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
   y--;
   Serial.println("LINEAR");
   Serial.println(y);
  }

  stepper.begin(spd,1);
     stepper.rotate(aclw*360*-1 );//3 rounds clockwise
     y= newy;
     rounds--;
     Serial.println("rounds:");
     Serial.print(rounds);
     Serial.println("speed:");
     Serial.print(spd);
      Serial.println("cw:");
     Serial.print(clw);
       Serial.println("cw:");
      Serial.print(clw);
  }
 }

void loop (){

   //screen1();                                                               // color bar 07
   //delay(2000);
   
 //  screen2();
 //  delay(2000);
 //   screen3();                                                                 // color bar 07
 //  delay(2000);
 
 if(digitalRead(buttonPin_RST) == LOW) {
    delay(250);
    Serial.println("Reset Pin Is Pressed.");
   // mode = 0;
   // screen1();
    while(digitalRead(buttonPin_RST) == LOW);
  }
  
  if(digitalRead(buttonPin_SET) == LOW) {
    delay(250);
   Serial.println("Set Pin Is Pressed.");
   while(true){
    if (mode == 0){
      Serial.println("Screen1");
      return;
    }
    else if (mode == 1){
      Serial.println("Screen2"); 
      return;
    }
    else if (mode == 2){
      Serial.println("Screen3");
      motorcode1();
      return;
    }
    else if (mode == 3){
      Serial.println("Screen4");
      motorcode2();
      return;
    }
    else if (mode == 4){
      Serial.println("Screen5");
      motorcode3();
      return;
    }
    else if (mode == 5){
      Serial.println("Screen6");
      //motorcode4(lin1);
      motorcode5(rpm, cw, lin1, acw, cyc);
      return;
   }
    else if (mode == 6){
      screen6();
      mode=5;
      Serial.println("Screen7");
      
      return;
   }
    else if (mode == 7){
      Serial.println("Screen8");
      screen6();
      mode=5;
      return;
   }
    else if (mode == 8){
      Serial.println("Screen9");
     screen6();
     mode=5;
      return;
   }
    else if (mode == 9){
      Serial.println("Screen10");
      screen6();
      mode=5;
      return;
   }
    else if (mode == 10){
      Serial.println("Screen11");
      screen6();
      mode=5;
      return;
   }
   }
    while(digitalRead(buttonPin_SET) == LOW);
  }
  
  if(digitalRead(buttonPin_MID) == LOW) {
    delay(250);
   // stepper.stop();
  // stepper.speed(0);
    mode = 0;
    screen1();
    int rpm = 80;   
    int cw = 0;
    int lin1 =0;
    int acw =0;
    int cyc = 1;
    Serial.println("Middle Pin Is Pressed.");
    while(digitalRead(buttonPin_MID) == LOW);
  }
  
  if(digitalRead(buttonPin_RHT) == LOW) {
    delay(250);
    Serial.println("Right Pin Is Pressed.");
    while(true){
    if (mode == 0){
      screen2();
      mode =1 ;
      return;
    }
    else if (mode == 1){
      screen3();
      mode = 2;
      return;
    }
    else if (mode == 2){
      screen4();
      mode = 3;
      return;
    }
    else if (mode == 3){
      screen5();
      mode = 4;
      return;
    }
     else if (mode == 4){
      screen6();
      mode = 5;
      return;
    }
     else if (mode == 5){
      screen7();
      mode = 6;
      return;
    
    }
    else if (mode == 6){
      screen8();
      mode = 7;
      return;
    
    }
    else if (mode == 7){
      screen9();
      mode = 8;
      return;
    
    }
    else if (mode == 8){
      screen10();
      mode = 9;
      return;
    
    }
    else if (mode == 9){
      screen11();
      mode = 10;
      return;
    
    }
    else if (mode == 10){
      screen1();
      mode = 0;
      return;
    
    }
     while(digitalRead(buttonPin_RHT) == LOW);   
  }
  }
  if(digitalRead(buttonPin_LFT) == LOW) {
    delay(250);
    Serial.println("Left Pin Is Pressed.");
     while(true){
    if (mode == 0){
      screen11();
      mode = 10;
      return;
    }
    else if (mode == 1){
      screen1();
      mode = 0;
      return;
    }
    else if (mode == 2){
      screen2();
      mode = 1;
      return;
    }
    else if (mode == 3){
      screen3();
      mode = 2;
      return; 
    }
     else if (mode == 4){
      screen4();
      mode = 3;
      return; 
    }
    else if (mode == 5){
      screen5();
      mode = 4;
      return; 
    }
    else if (mode == 6){
      screen6();
      mode = 5;
      return; 
    }
    else if (mode == 7){
      screen7();
      mode = 6;
      return; 
    }
    else if (mode == 8){
      screen8();
      mode = 7;
      return; 
    }
    else if (mode == 9){
      screen9();
      mode = 8;
      return; 
    }
    else if (mode == 10){
      screen10();
      mode = 9;
      return; 
    }
      }
      while(digitalRead(buttonPin_LFT) == LOW);    
  }
  
  if(digitalRead(buttonPin_DWN) == LOW) {
    delay(250);


    //rpm
    if (mode == 6 && rpm >0){
    rpm = rpm-10;
    
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("RPM \n  (min 80)"));
   
    tft.setCursor(40, 75);
    tft.print(rpm);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(rpm);
    }
    
    //clockwise
    else if (mode == 7 && cw >0){
    cw = cw-1;
    
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Clockwise"));
   
    tft.setCursor(50, 75);
    tft.print(cw);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(cw);
    }

    //linear 1
    else if (mode == 8 && lin1 >0){
    lin1 = lin1-1;
    
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.print(F("Linear"));
   
    tft.setCursor(50, 75);
    tft.print(lin1);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(lin1);
    }
   

    //anti clockwise
    else if (mode == 9 && acw >0){
    acw = acw-1;
    
   
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Anti\n  Clockwise"));
   
    tft.setCursor(50, 80);
    tft.print(acw);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(acw);
    }

    

    //cycle
    else if (mode == 10 && cyc >0){
    cyc = cyc-1;
    
    tft.fillScreen(WHITE);
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
  
  //original up button
  if(digitalRead(buttonPin_UP) == LOW) {
  delay(250);

    //RPM
    if (mode == 6 ){
    rpm = rpm+10;
    
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("RPN \n  (min 80)"));
   
    tft.setCursor(40, 75);
    tft.print(rpm);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(rpm);
    }
   //clockwise
    else if (mode == 7){
    cw = cw+1;
    
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Clockwise"));
   
    tft.setCursor(50, 75);
    tft.print(cw);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(cw);
    }

    //linear 1
    else if (mode == 8 ){
    lin1 = lin1+1;
    
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Linear"));
   
    tft.setCursor(50, 75);
    tft.print(lin1);
     tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(lin1);
    }
   

    //anti clockwise
    else if (mode == 9 ){
    acw = acw+1;
    
   
    tft.fillScreen(WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 45);
    tft.print(F("Anti\n  Clockwise"));
   
    tft.setCursor(50, 80);
    tft.print(acw);
    tft.drawBitmap (70,30, up_15, 15, 15, WHITE, BLACK);
    tft.drawBitmap (70,90, down_15, 15, 15, WHITE, BLACK);
    Serial.println(acw);
    }

    

    //cycle
    else if (mode == 10 ){
    cyc = cyc+1;
    
    tft.fillScreen(WHITE);
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

/*void screen1(){
    tft.fillScreen(BLACK);
   tft.drawBitmap (10,35, horse_rider, 96, 64, BLACK, MAGENTA);                                        // horse_rider frame
   tft.fillRect (120,35,30,5,GREEN);                                                                   // color bar 01
   tft.fillRect (120,45,30,5,RED);                                                                     // color bar 02
   tft.fillRect (120,55,30,5,YELLOW);                                                                  // bcolor ar 03
   tft.fillRect (120,65,30,5,POISON);                                                                  // color bar 04
   tft.fillRect (120,75,30,5,MAGENTA);                                                                 // color bar 05
   tft.fillRect (120,85,30,5,YELLOW);                                                                  // color bar 06
   tft.fillRect (120,95,30,5,ORANGE);  
}



void screen2(){
      tft.fillScreen(ORANGE);
      tft.drawBitmap (10,35, epd_bitmap_testing, 140, 70, BLACK, MAGENTA);
}
*/

//void screen1(){
//  tft.fillScreen(BLACK);
//  tft.drawBitmap (10,35, epd_bitmap_Art_Buddy, 140, 70, BLACK, MAGENTA);
//}

//void screen2(){
//  tft.fillScreen(BLACK);
//  tft.drawBitmap (10,35, epd_bitmap_PAGE1, 140, 70, BLACK, BLUE);
//}

//void screen3(){
//  tft.fillScreen(BLACK);
//  tft.drawBitmap (10,35, epd_bitmap_PAGE2, 140, 70, BLACK, MAGENTA);
//}

//void screen4(){
//  tft.fillScreen(BLACK);
//  tft.drawBitmap (10,35, epd_bitmap_PAGE3, 140, 70, BLACK, CYAN);
//}



/*
void relay1(){
relay_SetStatus(ON, OFF, OFF, OFF);//turn on RELAY_1
  delay(1000);//delay 2s0
  relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
  delay(2000);
  relay_SetStatus(OFF, ON, OFF, OFF);//turn on RELAY_2
  delay(1000);//delay 2s
  relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
  delay(2000);   
  
  relay_SetStatus(OFF, OFF, ON, OFF);//turn on RELAY_1
  delay(1000);//delay 2s
  relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
  delay(2000);
  relay_SetStatus(OFF, OFF, OFF, ON);//turn on RELAY_2
  delay(1000);//delay 2s
  relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
  delay(2000);
} 
*/
