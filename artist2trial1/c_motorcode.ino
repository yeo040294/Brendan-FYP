//motorcode 1
void motorcode1() {
  stepper.setCurrentPosition(0);
  while (stepper.currentPosition() != 8 * 10 * 200 )
  {
    stepper.setSpeed(8*200);
    stepper.runSpeed();
  }
  stepper.setCurrentPosition(0);
  while (stepper.currentPosition() != 8* -10 * 200)
  {
    stepper.setSpeed(8*-200);
    stepper.runSpeed();
  }
Serial.print("code1");
  
}

//motor code 2
void motorcode2() {
  stepper.setCurrentPosition(0);
  while (stepper.currentPosition() !=8* 15 * 200 )
  {
    stepper.setSpeed(8*500);
    stepper.runSpeed();
  }
  stepper.setCurrentPosition(0);
  while (stepper.currentPosition() != 8*-15 * 200)
  {
    stepper.setSpeed(8*-500);
    stepper.runSpeed();
  }
  delay(1000);

  Serial.print("code2");
}

//adjustable code
int customcode (int spd, int aclw, int dlay, int clw, int rounds)
{
  while (rounds != 0 )
  {
    stepper.setCurrentPosition(0);
    while (stepper.currentPosition() != aclw *8* 200 )
    {
      stepper.setSpeed(8*spd);
      stepper.runSpeed();
    }
    delay(dlay);
    stepper.setCurrentPosition(0);
    while (stepper.currentPosition() != -clw *8* 200)
    {
      stepper.setSpeed(8*-spd);
      stepper.runSpeed();
    }
    delay(dlay);
    rounds--;

    Serial.print("rounds:");
    Serial.println(rounds);
    Serial.print("speed:");
    Serial.println(spd);
    Serial.print("cw:");
    Serial.println(acw);
    Serial.print("delay:");
    Serial.println(dlay);
    Serial.print("cw:");
    Serial.println(clw);
  }

}
