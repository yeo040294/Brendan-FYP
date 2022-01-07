//motorcode 1
void motorcode1() {
  /*int trial = 0;
  while (trial < 5) {
    clockw(4,80);
    relay_SetStatus(ON, OFF, OFF, OFF);//turn on RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    anticlockw(3,100);
    relay_SetStatus(OFF, OFF , ON, OFF); //turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    clockw(3,110);
    anticlockw(3,110);
   
    relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    
    trial++;
 
  }
  */
}
//motor code 2
void motorcode2() {
/*
  int trial = 0;
  while (trial < 5) {
    stepper.begin(100, 1);
    stepper.rotate(720);//3 rounds clockwise
    stepper.begin(100, 1);
    stepper.rotate(-720);
    relay_SetStatus(OFF, OFF , ON, OFF); //turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1


    stepper.begin(110, 1);
    stepper.rotate(1080);
    stepper.begin(110, 1);
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
  */
}

//motor code 3
// void motorcode3(int round){
void motorcode3() {
 /* int trial = 0;
  while (trial < 5) {
    stepper.begin(100, 1);
    stepper.rotate(720);//3 rounds clockwise
    relay_SetStatus(ON, OFF, OFF, OFF);//turn on RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(ON,OFF , OFF, OFF);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
  

   stepper.begin(110, 1);
    stepper.rotate(1080);
    stepper.begin(110, 1);
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
  */
}
// adjustable code for linear motor1
/*int linear1(int L1) {
  int x = 0;
  while (x <  L1) {
    relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
    delay(500);//delay 2s0
    relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    L1--;
    Serial.print(L1);
  }
}
*/
int linear1(int L1, int L2, int L3, int L4) {
  if (L1 != 0)
  {
  int x = 0;
  while (x <  L1) {
    relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
    delay(500);//delay 2s0
    //relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    //delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    L1--;
    Serial.print(L1);
  }
  }
  if (L2 != 0)
  {
    int x = 0;
  while (x <  L2) {
    relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
    delay(500);//delay 2s0
    //relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    //delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    L2--;
    Serial.print(L2);
  }
  }
  if (L3 != 0)
  {
    int x = 0;
  while (x <  L3) {
    relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    delay(500);//delay 2s0
   // relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
   // delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    L3--;
    Serial.print(L3);
  }
  
  }

  if (L4 != 0)
  {
    int x = 0;
  while (x <  L4) {
    relay_SetStatus(OFF, OFF, OFF, ON);//turn off RELAY_1
    delay(500);//delay 2s0
    //relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    //delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    L4--;
    Serial.print(L4);
  }
  }
}

// adjustable code for linear motor2
/*int linear2(int L2) {
  int x = 0;
  while (x <  L2) {
    relay_SetStatus(OFF, ON, OFF, OFF);//turn off RELAY_1
    delay(500);//delay 2s0
    //relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    //delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
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
   // relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
   // delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
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
    //relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
    //delay(200);//delay 2s0
    relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
    L4--;
    Serial.print(L4);
  }
}
*/
//clockwise 
int clockw(int clw, int spd)
{
  stepper.begin(spd, 1);
  stepper.rotate(clw * 360);
}

//anti clockwise 
int anticlockw(int aclw, int spd)
{
  stepper.begin(spd, 1);
  stepper.rotate(aclw * 360);
}


//adjustable code
int motorcode5 (int spd, int clw, int L1,int L2, int L3, int L4, int aclw, int rounds)
{

 
  int newL1 = L1;
  int newL2 = L2;
  int newL3 = L3;
  int newL4 = L4;
  while (rounds != 0 )
  {
    
    clockw( clw, spd);
    /*
    stepper.begin(spd, 1);
    stepper.rotate(clw * 360); //3 rounds clockwise
    */

   
    linear1(L1, L2, L3, L4);
   
    /*while (y != 0) {
      relay_SetStatus(ON, OFF, OFF, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
      relay_SetStatus(OFF, OFF, ON, OFF);//turn off RELAY_1
      delay(200);//delay 2s0
      relay_SetStatus(OFF, OFF, OFF, OFF);//turn off RELAY_1
      y--;
      Serial.println("LINEAR");
      Serial.println(y);
    }
    */
    anticlockw(aclw , spd);
    /*
    stepper.begin(spd, 1);
    stepper.rotate(aclw * 360 * -1 ); //3 rounds clockwise
    */
    L1 = newL1;
    L2 = newL2;
    L3 = newL3;
    L4 = newL4;
    rounds--;
    Serial.print("rounds:");
    Serial.println(rounds);
    Serial.print("speed:");
    Serial.println(spd);
    Serial.print("cw:");
    Serial.println(clw);
    Serial.print("cw:");
    Serial.println(aclw);
    Serial.println(L1);
    Serial.println(L2);
    Serial.println(L3);
    Serial.println(L4);
  }
}

int motorcode6 (int spd, int clw, int L1,int L2, int L3, int L4, int aclw, int rounds)
{

 
  int newL1 = L1;
  int newL2 = L2;
  int newL3 = L3;
  int newL4 = L4;
  while (rounds != 0 )
  {
    anticlockw(aclw , spd);
    linear1(L1,L2,L3,L4);
    
    clockw( clw, spd);
  
    L1 = newL1;
    L2 = newL2;
    L3 = newL3;
    L4 = newL4;
    rounds--;
    Serial.print("rounds:");
    Serial.println(rounds);
    Serial.print("speed:");
    Serial.println(spd);
    Serial.print("cw:");
    Serial.println(clw);
    Serial.print("cw:");
    Serial.println(aclw);
  }
}
