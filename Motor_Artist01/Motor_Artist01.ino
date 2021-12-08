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
int lin1 = 0;
int lin2 = 0;
int lin3 = 0;
int lin4 = 0;
int acw = 0;
int cyc = 1;



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





void loop () {

  //screen1();                                                               // color bar 07
  //delay(2000);

  //  screen2();
  //  delay(2000);
  //   screen3();                                                                 // color bar 07
  //  delay(2000);
  resetBtn();
  setBtn();
  midBtn();
  rightBtn();
  leftBtn();
  downBtn();
  upBtn();
}
