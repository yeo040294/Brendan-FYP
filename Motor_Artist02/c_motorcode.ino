//motorcode 1
void motorcode1(){
  int trial =0;
  while (trial<1){
  stepper.begin(150,1); // rpm 150
  stepper.rotate(10*360*-1 );//10 rounds clockwise
  stepper.begin(150,1);
  stepper.rotate(10*360);//10 rounds clockwise
  trial++;
  }
}
//motor code 2
   void motorcode2(){
    
   int trial =0;
  while (trial<1){
   stepper.begin(120,1); // rpm 120
   stepper.rotate(15*360*-1 );//15 rounds clockwise
   stepper.begin(120,1);
   stepper.rotate(15*360);//15 rounds clockwise
  trial++;
  }
   }



//adjustable code
//int motorcode5 (int spd, int clw, int y, int aclw, int rounds)
int motorcode5 (int spd, int aclw, int dlay, int clw, int rounds)
 {
  
   
 
  while (rounds != 0 )
  {

    stepper.begin(spd,1);
     stepper.rotate(aclw*360*-1 );//3 rounds clockwise
     delay(dlay);
    stepper.begin(spd,1);
     stepper.rotate(clw*360);//3 rounds clockwise  
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
