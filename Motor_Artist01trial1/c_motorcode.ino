//motorcode 1
void motorcode1() {
  int trial = 0;
  while (trial < 3) {
    stepper.setAcceleration(200);
    stepper.moveTo(8 * 200 * 10);
    stepper.runToPosition();
    relay_SetStatus(OFF, OFF , ON, OFF); //turn off RELAY_1
    delay(400);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    delay(400);//delay 2s0
    relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
    delay(400);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(400);//delay 2s0

    stepper.moveTo(0);
    stepper.runToPosition();
    trial++;

  }
}
//motor code 2
void motorcode2() {    
  int trial = 0;
  while (trial < 2) {
    stepper.setAcceleration(300);
    stepper.moveTo(8 * 200 * 10* -1);
    stepper.runToPosition();
    relay_SetStatus(ON, OFF , OFF , OFF); //turn off RELAY_1
    delay(400);
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    delay(400);
    relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
    delay(400);
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(400);
    stepper.moveTo(0);
    stepper.runToPosition();
    trial++;
  }
}

//motor code 3
// void motorcode3(int round){
void motorcode3() {
   stepper.setAcceleration(500);
     int trial = 0;
    while (trial < 2) {
    stepper.moveTo(8 * 200 * 10* -1);
    stepper.runToPosition();
    relay_SetStatus(ON, OFF , OFF , OFF); //turn off RELAY_1
    delay(400);
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    delay(400);
    relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
    delay(400);
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(400);
    stepper.moveTo(0);
    stepper.runToPosition();
    trial++;
    }
}

// adjustable code for linear motor1
int linear1(int L1) {
  int x = 0;
  while (x <  L1) {
    relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
    delay(500);
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(500);
    L1--;
    Serial.print(L1);
  }
}

// adjustable code for linear motor2
int linear2(int L2) {
  int x = 0;
  while (x <  L2) {
    relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_2
    delay(500);//delay 2s0
    //delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(500);
    L2--;
    Serial.print(L2);
  }
}

// adjustable code for linear motor3
int linear3(int L3) {
  int x = 0;
  while (x <  L3) {
    relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    delay(500);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(500);
    L3--;
    Serial.print(L3);
  }
}

// adjustable code for linear motor4
int linear4(int L4) {
  int x = 0;
  while (x <  L4) {
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    delay(500);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(500);
    L4--;
    Serial.print(L4);
  }
}

//clockwise
int clockw(int clw)
{
 stepper.moveTo(8 * 200 *clw);
 stepper.runToPosition();
}

//anti clockwise
int anticlockw(int aclw)
{
  stepper.moveTo(8 * 200 *aclw*-1);
  stepper.runToPosition();
  
}

//adjustable code
int motorcode7 (int spd, int clw, int L1, int L2, int L3, int L4, int aclw, int rounds)
{
  stepper.setAcceleration(spd);
  while (rounds != 0 )
  {
    for (int x = 0; x < strlen(testing); x++)
    {
      delay(100);
      if (testing[x] == 'c')
      {
        Serial.println("clockwise");
        clockw(clw);
      }
      else if (testing[x] == 'a')
      {
        Serial.println("anticlockwise");
        anticlockw(aclw);
      }
      else if (testing[x] == 'w')
      {
        Serial.println("motor1");
        linear1(L1);
      }
      else if (testing[x] == 'x')
      {
        Serial.println("motor2");
        linear2(L2);
      }
      else if (testing[x] == 'y')
      {
        Serial.println("motor3");
        linear3(L3);
      }
      else if (testing[x] == 'z')
      {
        Serial.println("motor4");
        linear4(L4);
      }
    }
    rounds--;
  }
}
