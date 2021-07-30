#include <Servo.h> 
 
int potPin = 0;  
int servoPin = 9;
Servo servo;
int i=0; 
 
void setup() 
{ 
  Serial.begin(9600);
  servo.attach(servoPin);  
} 
 
void loop() 
{ 
//Seurial.println(i);
  if(Serial.available()){
    i++;
    String servoAngle=Serial.readString();
    float rpm=servoAngle.toFloat();
    Serial.print("RPM=");
    Serial.println(rpm);
    float servoAngleInt=map(rpm,0,120,90,30);
    Serial.print("mapped=");
    Serial.println(servoAngleInt);
    if(servoAngleInt>30 && servoAngleInt<=68){
      servoAngleInt += 10;
    }
    else if(servoAngleInt>=69 && servoAngleInt<=78){
      servoAngleInt += 5;
    }
    else if(servoAngleInt>=79 && servoAngleInt<=84){
      servoAngleInt += 1;
    }


    Serial.print("Angle=");
    Serial.println(servoAngleInt);
    servo.write(servoAngleInt);
  }

  
  
//  int reading = ;     // 0 to 1023
//  int angle = reading / 6;              // 0 to 180-ish
//  servo.write(85);
}
