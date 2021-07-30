
#include <Servo.h>

MPU6050 mpu6050(Wire);

long timer = 0;

int servoPin = 10;
Servo servo; 

float servoAngleInt;

float ref_rotz=0.00,prev_rotz=0.00,curr_rotz=0.00,rotz=0.00;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  servo.attach(servoPin);
servo.write(90);
//  ref_rotz=mpu6050.getGyroAngleZ()/98.4;
}

void loop() {
  mpu6050.update();
//
////  if(millis() - timer > 1000){
//    
////    Serial.println("=======================================================");
////    Serial.print("temp : ");Serial.println(mpu6050.getTemp());
////    Serial.print("accX : ");Serial.print(mpu6050.getAccX());
////    Serial.print("\taccY : ");Serial.print(mpu6050.getAccY());
////    Serial.print("\taccZ : ");Serial.println(mpu6050.getAccZ());
////  
////    Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
////    Serial.print("\tgyroY : ");Serial.print(mpu6050.getGyroY());
////    Serial.print("\tgyroZ : ");Serial.println(mpu6050.getGyroZ());
////  
////    Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
////    Serial.print("\taccAngleY : ");Serial.println(mpu6050.getAccAngleY());
////  
////    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
////    Serial.print("\tgyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
////    Serial.print("\tgyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
////    
////    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
////    Serial.print("\tangleY : ");Serial.print(mpu6050.getAngleY());
////    Serial.print("\tangleZ : ");Serial.println(mpu6050.getAngleZ());
////    Serial.println("=======================================================\n");
////    timer = millis();
//
//
    rotz= (mpu6050.getGyroZ()/6);  
    Serial.println(rotz);


//  delay(1000);
if (rotz<0){
  if(rotz<-110)
    rotz=-110;
 Serial.println("<0 mein aa gyaaaa");
   servoAngleInt=map((0-rotz),-120,0,150,91);
  if (servoAngleInt<=140 && servoAngleInt>=131){
      servoAngleInt -= 8;    }
else if(servoAngleInt>=103 && servoAngleInt<=130){
      servoAngleInt -=15;
}
    else if(servoAngleInt<=103 && servoAngleInt>=98){
      servoAngleInt -= 2;
    }
}

 else if (rotz>0){
    if(rotz>110)
    rotz=110;
    Serial.println("GREATER 0 mein aa gyaaaa");
     servoAngleInt=map((0-rotz),0,120,90,30);
    if(servoAngleInt>30 && servoAngleInt<=58){
      servoAngleInt += 10;

      
    }
    else if(servoAngleInt>=59 && servoAngleInt<=78){
      servoAngleInt += 15;
    }
    else if(servoAngleInt>=79 && servoAngleInt<=84){
      servoAngleInt += 1;
    }
  }

 
    Serial.println(servoAngleInt);
    servo.write(servoAngleInt);

//delay(1000);
}
