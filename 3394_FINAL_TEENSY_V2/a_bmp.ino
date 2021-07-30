          
void setupBMP(){
//  digitalWrite(BUILTIN_LED, HIGH);
  /* Default settings from datasheet. */
  if(bmp.begin(BMP_ADDR)){
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_OFF,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */ 

  }
               
}

void refBMP(){
 // Serial.println("BMP reference set");
  if(!bmp.begin(BMP_ADDR)) {
    ground_altitude = 0;  
    dataPacket.altitude = 0;
    dataPacket.temperature =0;
  } else
  ground_altitude= bmp.readAltitude(); 
//  delay(50);
}

float getBMPAltitute(){
  double sum = 0;
  for(int i=0; i<100; i++){
    sum += bmp.readAltitude(1013.25);
  }
//  ground_altitude = ;
  return (sum/100 - ground_altitude);
 
}

float getBMPCurr_ALt(){
  return bmp.readAltitude(1013.25);
}


//void BMPmeasurement(){
//  //float temp_alt = bmp.readAltitude();
//  if(!bmp.begin(BMP_ADDR)) { 
//   // Serial.println("BMP NOT FOUND"); 
//   dataPacket.altitude = 0;
//   dataPacket.temperature =0;
//  } else{
//   // Serial.println("BMP FOUND"); 
//  float avg=0;
//  avg=avg+bmp.readAltitude()-ref_alt;
//  
//  for (int i=2;i<10;i++){
//    avg=(avg+bmp.readAltitude()-ref_alt)/2;
//  } 
//    prev_alt=curr_alt;
//    dataPacket.altitude = avg;
//    curr_alt=avg;
//    float temp = bmp.readTemperature();
//    dataPacket.temperature = temp;
////    alt_string=String(alt);
////    temperature_string=String(temp);
//    
//}
//}
