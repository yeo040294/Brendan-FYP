#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <Arduino.h>
#include <AccelStepper.h>

#define TFT_RST  12
#define TFT_CS   10
#define TFT_DC   9

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

#define SENSOR 5
#define SENSORRIGHT 6
#define MOTOR_STEPS 200
#define DIR A4
#define STEP A3

const unsigned char down_15 [] PROGMEM = {0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xe0, 0x0e, 0xe0, 0x0e, 0xf0, 0x1e, 0xf8, 0x3e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char up_15 [] PROGMEM = {0xfe, 0xfe, 0xfc, 0x7e, 0xf8, 0x3e, 0xf0, 0x1e, 0xe0, 0x0e, 0xe0, 0x0e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xfc, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char left_15 [] PROGMEM = {0xff, 0xfe, 0xff, 0xfe, 0xf9, 0xfe, 0xf1, 0xfe, 0xe0, 0x06, 0xc0, 0x02, 0xc0, 0x02, 0xc0, 0x02, 0xe0, 0x02, 0xf1, 0xfe, 0xfb, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};
const unsigned char right_15 [] PROGMEM = {0xff, 0xfe, 0xff, 0xfe, 0xfe, 0x7e, 0xfc, 0x3e, 0xc0, 0x1e, 0x80, 0x0e, 0x80, 0x06, 0x80, 0x0e, 0xc0, 0x1e, 0xfe, 0x7e, 0xff, 0x7e, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe, 0xff, 0xfe};

AccelStepper stepper(AccelStepper::DRIVER, STEP, DIR );

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

int Xpin = A0;
int Ypin = A1;
int Spin = 3;
int Xval;
int Yval;
int Sval;
int motorspeed = 5000;
//int sensorLeft;
//int sensorRight;
int buzzer = 7;
bool updateMenu = true;
bool stepmotion = false;
int mode = 0;
int newstate;
int state = 0;

void setup()
{
  pinMode (Xpin, INPUT);
  pinMode (Ypin , INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);
  pinMode(SENSOR, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(SENSORRIGHT, INPUT_PULLUP);// define pin as Input  sensor
  Serial.begin(9600);
  stepper.setMaxSpeed(8000);
  stepper.setSpeed(3000);
  tft.setTextColor(WHITE);
  tft.initR (INITR_BLACKTAB);
  tft.setRotation (0);
  tft.fillScreen (BLACK);
  tft.setTextSize(1);
  tft.setCursor(40, 20);
  tft.print("Auto");
  tft.setTextSize(1);
  tft.setCursor(40, 100);
  tft.print("Manual");
  tft.drawBitmap (70, 100, right_15, 15, 15, BLACK, WHITE);
  tft.drawBitmap (70, 20, left_15, 15, 15, BLACK, WHITE);


}

void loop()
{

  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  // Serial.println(state);
  if (state  < 1) {
    if (Xval > 712 ) {
      delay(500);
      if (Xval = 512) {
        state = 2;
        mode = 1;
        Serial.println("mode = 1");
        updateMenu = true;
        tft.fillScreen (BLACK);
        tft.setTextSize(1);
        tft.setCursor(40, 20);
        tft.print("Speed is: ");
        tft.drawBitmap (50, 40, up_15, 15, 15, BLACK, WHITE);
        tft.drawBitmap (50, 80, down_15, 15, 15, BLACK, WHITE);
        tft.setCursor(50, 110);
        tft.print("motion");
        tft.drawBitmap (100, 110, right_15, 15, 15, BLACK, WHITE);
        tft.setCursor(50, 130);
        tft.print("stop");
        tft.drawBitmap (20, 130, left_15, 15, 15, BLACK, WHITE);
        tft.setCursor(50, 150);
        tft.print("Automatic");
        Serial.println(state);
      }
    }
    else if ( Xval < 100)
    {
      delay(500);
      if ( Xval = 512)
      {
        state = 1;
        mode = 1;
        updateMenu = true;
        Serial.println("mode = 10");
        tft.fillScreen (BLACK);
        tft.setTextSize(1);
        tft.setCursor(40, 20);
        tft.print("Speed is: ");
        tft.drawBitmap (50, 40, up_15, 15, 15, BLACK, WHITE);
        tft.drawBitmap (50, 80, down_15, 15, 15, BLACK, WHITE);
        tft.setCursor(50, 120);
        tft.print("motion");
        tft.drawBitmap (100, 120, right_15, 15, 15, BLACK, WHITE);
        tft.drawBitmap (20, 120, left_15, 15, 15, BLACK, WHITE);
      }
    }
  }

  if (state < 2  ) { // manual option
    int  sensorLeft = digitalRead(SENSOR); // read the sensorleft
    int  sensorRight = digitalRead(SENSORRIGHT);
    Xval = analogRead(Xpin);
    Yval = analogRead(Ypin);
    Sval = digitalRead(Spin);

    if (updateMenu) {
      updateMenu = false;
      tft.fillRect(50, 60, 60, 20, BLACK);
      tft.setTextSize(2);
      tft.setCursor(50, 60);
      tft.print(motorspeed / 8);
    }

    //stepper.runSpeed();
    if ( Xval > 712 ) {
      if ( sensorLeft == 0) {
        Serial.println(" left Obstacle detected");
        tone ( buzzer , 450);
        delay(500);
        noTone(buzzer);
        delay(500);
      }
      else {
        stepper.setSpeed(-1 * motorspeed);
        stepper.runSpeed();
      }
    }

    if (Xval < 100 ) {
      if (sensorRight == 0) {
        Serial.println(" Right Obstacle detected");
        tone ( buzzer , 450);
        delay(500);
        noTone(buzzer);
        delay(500);
      }
      else {

        stepper.setSpeed(motorspeed);
        stepper.runSpeed();
      }
    }
    if (Yval < 100) {
      motorspeed = motorspeed + 100;
      delay(200);
      Serial.println(motorspeed);
      updateMenu = true;
    }
    if (Yval > 712 && motorspeed > 0)
    {
      motorspeed = motorspeed - 100;
      delay(200);
      Serial.println(motorspeed);
      updateMenu = true;
    }
  }

  else if (state < 3) {  // automatic motion
    int  sensorLeft = digitalRead(SENSOR); // read the sensorleft
    int  sensorRight = digitalRead(SENSORRIGHT);
    Xval = analogRead(Xpin);
    Yval = analogRead(Ypin);
    Sval = digitalRead(Spin);

    if (updateMenu) {
      updateMenu = false;
      tft.fillRect(50, 60, 60, 20, BLACK);
      tft.setTextSize(2);
      tft.setCursor(50, 60);
      tft.print(motorspeed / 8);
    }



    if (Xval < 100 ) {
      stepmotion = true;
      while ( stepmotion != false)
      {
        Xval = analogRead(Xpin);
        int  sensorLeft = digitalRead(SENSOR); // read the sensorleft
        int  sensorRight = digitalRead(SENSORRIGHT);
        stepper.setSpeed(motorspeed);
        stepper.runSpeed();
        if (sensorRight == 0 ) {
          if (motorspeed > 0)
          {
            motorspeed = motorspeed * -1;
          }
        }
        if ( sensorLeft == 0) {
          if ( motorspeed < 0)
          {
            motorspeed = motorspeed * -1;
          }
        }

        if ( Xval > 712 ) {
          stepmotion = false;
          //motorspeed = 0;
          break;
          Serial.print("left button");
        }
      }


    }
    if (Yval < 100) {
      motorspeed = motorspeed + 100;
      delay(200);
      Serial.println(motorspeed);
      updateMenu = true;
    }
    if (Yval > 712 && motorspeed > 0)
    {
      motorspeed = motorspeed - 100;
      delay(200);
      Serial.println(motorspeed);
      updateMenu = true;
    }
  }
}
