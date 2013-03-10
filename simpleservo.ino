#include <Servo.h> 
 
Servo servo1;  // create servo object to control a servo 
int val;
int speed;
boolean up;

void setup() 
{ 
  servo1.attach(14);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(19200);
  Serial.println("Ready");
  up = true;
  
  //SET THIS
  int degrees_per_minute = 60;
  
  
  speed = (degrees_per_minute/60)*1000;
} 

void loop() {
 
  if(up == true){
       for (int i=0;i<180;i++) {
         servo1.write(i);
         delay(speed); //speed!
         Serial.println("going up");
         Servo::refresh();
       }
       up = false;
  } else {
       for (int i=180;i>0;i--) {
         servo1.write(i);
         delay(speed); //speed!
         Serial.println("going down");
         Servo::refresh();
       }
       up = true;
  }
  
  

} 
