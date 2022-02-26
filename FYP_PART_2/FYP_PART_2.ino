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

#define SENSOR 6
//#define SENSORRIGHT 5
#define MOTOR_STEPS 200
#define DIR A4
#define STEP A3
AccelStepper stepper(AccelStepper::DRIVER, STEP, DIR );

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

int Xpin = A0;
int Ypin = A1;
int Spin = 3;
int Xval;
int Yval;
int Sval;

//int sensorLeft;
//int sensorRight;
int buzzer = 7;
void setup()

{
  pinMode (Xpin, INPUT);
  pinMode (Ypin , INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);
  pinMode(SENSOR, INPUT_PULLUP);// define pin as Input  sensor
//  pinMode(SENSORRIGHT, INPUT_PULLUP);// define pin as Input  sensor
  Serial.begin(9600);
  stepper.setMaxSpeed(8000);
  stepper.setSpeed(3000);
}

void loop()
{
  int  sensorLeft = digitalRead(SENSOR); // read the sensorleft
  // int  sensorRight = digitalRead(SENSORRIGHT);
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);
  //stepper.runSpeed();
  if ( Xval > 712 ) {
    if ( sensorLeft == 1) {
      Serial.println(" Obstacle detected");
     tone ( buzzer , 450);
      delay(500);
      noTone(buzzer);
      delay(500);
    }
    else {
      stepper.setSpeed(-5000);
      stepper.runSpeed();
    }
  }

  if (Xval < 100 ) {
    /*if(sensorRight == 0){
    Serial.println(" Obstacle detected");
      tone ( buzzer , 450);
      delay(500);
      noTone(buzzer);
      delay(500);

      }
      else {
  */
    stepper.setSpeed(3000);
    stepper.runSpeed();
     
  }


}
