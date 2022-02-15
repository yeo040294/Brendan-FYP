//motorcode 1
void motorcode1() {
  stepper.setAcceleration(50);
  stepper.setCurrentPosition(0);
  stepper.moveTo(motormovement(10));
  while (stepper.distanceToGo() != 0 )
  {
    stepper.run();
    if (stepper.distanceToGo() % (motormovement(10) / 3) == 0)
    {
      linear1(1);
    }
  }

  stepper.setCurrentPosition(0);
  stepper.moveTo(motormovement(-1 * 10));
  while (stepper.distanceToGo() != 0 )
  {
    stepper.run();
    if (stepper.distanceToGo() % (motormovement(-10) / 3) == 0)
    {
      linear3(1);
    }


  }


  // linear1(1);
  // linear2(1);
  // linear3(1);
  // linear4(1);
}

//motor code 2
void motorcode2() {
  stepper.setAcceleration(80);
  stepper.setCurrentPosition(0);
  stepper.moveTo(motormovement(7));
  while (stepper.distanceToGo() != 0 )
  {
    stepper.run();
  }

  stepper.setCurrentPosition(0);
  stepper.moveTo(motormovement(-1 * 10));
  while (stepper.distanceToGo() != 0 )
  {
    stepper.run();
    if (stepper.distanceToGo() % (motormovement(-10) / 3) == 0)
    {
      linear4(1);
    }

  }
}

//motor code 3

void motorcode3() {
  stepper.setAcceleration(100);
  stepper.setCurrentPosition(0);
  stepper.moveTo(motormovement(12));
  while (stepper.distanceToGo() != 0 )
  {
    stepper.run();
  }

  stepper.setCurrentPosition(0);
  stepper.moveTo(motormovement(-1 * 12));
  while (stepper.distanceToGo() != 0 )
  {
    stepper.run();
    if (stepper.distanceToGo() % (motormovement(-12) / 3) == 0)
    {
      linear1(1);
    }
  }
}

int motormovement(int val )
{
  return (val * 200);
}

int startLinear(bool L1, bool L2, bool L3, bool L4) {
  relay_SetStatus(!L1, !L2, !L3, !L4);
  delay(200);
  relay_SetStatus(OFF, OFF, OFF, OFF);
  delay(200);
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


}

void seqorder (char* data)
{
  // if character, declare true else false
  if (data[0] == 'w')
  {
    w1 = true;
    Serial.println("wt");
  }
  if (data[1] == 'x')
  {
    x1 = true;
    Serial.println("xt");
  }
  if (data[2] == 'y')
  {
    y1 = true;
    Serial.print("yt");
  }
  if (data[3] == 'z')
  {
    z1 = true;
    Serial.print("zt");
  }

  // check the value for clockwise / anti
  if (data[4] == 'c')
  {
    int steps = strtol(data + 5, NULL, 10);
    Serial.print("clock");

    rou = steps;
    Serial.println(rou);

  }
  if (data[4] == 'a')
  {
    int steps = strtol(data + 5, NULL, 10);
    Serial.print("clock");

    rou = -steps;
    Serial.println(rou);
  }

  // check value of rpm
  if (data[6] == 'r')
  {
    int steps = strtol(data + 7, NULL, 10);
    Serial.print("rpm");

    rp = steps;
    Serial.println(rp);
  }
  if (data[7] == 'r')
  {
    int steps = strtol(data + 8, NULL, 10);
    Serial.print("rpm");

    rp = steps;
    Serial.println(rp);
  }
  stepper.setAcceleration(rp);
  stepper.setCurrentPosition(0);
  stepper.moveTo(motormovement(1 * rou));
  while (stepper.distanceToGo() != 0 )
  {
    stepper.run();
    if (stepper.distanceToGo() == (motormovement(rou) / 2))
    {
      startLinear(w1, x1, y1, z1);
    }
  }

  w1 = false;
  x1 = false;
  y1 = false;
  z1 = false;
}



// adjustable code for linear motor1
int linear1(int L1) {
  int x = 0;
  while (x <  L1) {
    relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
    delay(200);
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(200);
    L1--;
    Serial.print(L1);
  }
}

// adjustable code for linear motor2
int linear2(int L2) {
  int x = 0;
  while (x <  L2) {
    relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_2
    delay(200);//delay 2s0
    //delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(200);
    L2--;
    Serial.print(L2);
  }
}

// adjustable code for linear motor3
int linear3(int L3) {
  int x = 0;
  while (x <  L3) {
    relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(200);
    L3--;
    Serial.print(L3);
  }
}

// adjustable code for linear motor4
int linear4(int L4) {
  int x = 0;
  while (x <  L4) {
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    delay(200);
    L4--;
    Serial.print(L4);
  }
}
