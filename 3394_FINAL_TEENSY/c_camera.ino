//void stabilizeCamera() {
//  recordGyroRegisters();
//  float valuee = processGyroData();
////  delay(1000);
//if (valuee<0){
//  if(valuee<-110)
//    valuee=-110;
//// Serial.println("<0 mein aa gyaaaa");
//   servoAngleInt=map(valuee,-120,0,150,91);
//  if (servoAngleInt<=140 && servoAngleInt>=111){
//      servoAngleInt -= 8;    }
//else if(servoAngleInt>=104 && servoAngleInt<=110){
//      servoAngleInt -= 5;
//}
//    else if(servoAngleInt<=103 && servoAngleInt>=98){
//      servoAngleInt -= 1;
//    }
//}
//
//  if (valuee>0){
//    if(valuee>110)
//    valuee=110;
////    Serial.println("GREATER 0 mein aa gyaaaa");
//     servoAngleInt=map(valuee,0,120,90,30);
//    if(servoAngleInt>30 && servoAngleInt<=68){
//      servoAngleInt += 10;
//
//      
//    }
//    else if(servoAngleInt>=69 && servoAngleInt<=78){
//      servoAngleInt += 5;
//    }
//    else if(servoAngleInt>=79 && servoAngleInt<=84){
//      servoAngleInt += 1;
//    }
//  }
//
//  
//
//  
////    GCS_Xbee.println(servoAngleInt);
////    servo.write(servoAngleInt);
//
//  
////  delay(1000);
//}
