//float Kalman(float raw_rpmZ){
//  static float R=100;//covariance
//  static float H=1.00;
//  static float Q=10;
//  static float P=0;
////  static float filt_rpmZ=0;//filtered alt
//  static float Kg=0;//Kalaman gain
//
//  Kg= P*H/(H*P*H+ R);
//  //Serial.print("Kg=");
//  //Serial.println(Kg);
//  //Serial.print("filter_value=");
//  filt_rpmZ= filt_rpmZ + Kg*(raw_rpmZ-H*filt_rpmZ);
//  P=(1-Kg*H)*P+Q;
//  return filt_rpmZ;
//  }
//
//
//void setupMPU(){
//  Wire.beginTransmission(0b1101001); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
//  Wire.write(0x6B); //Accessing the register 6B - Power Management (Sec. 4.28)
//  Wire.write(0b00000000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
//  Wire.endTransmission();  
//  Wire.beginTransmission(0b1101001); //I2C address of the MPU
//  Wire.write(0x1B); //Accessing the register 1B - Gyroscope Configuration (Sec. 4.4)
//  Wire.write(0x00011000); //Setting the gyro to full scale +/- 250deg./s
//  Wire.endTransmission();
//  Wire.beginTransmission(0b1101001); //I2C address of the MPU
//  Wire.write(0x1C); //Accessing the register 1C - Acccelerometer Configuration (Sec. 4.5)
//  Wire.write(0b00011001); //Setting the accel to +/- 2g
//  Wire.endTransmission();
////  Serial.println("MPU Setup");
//}
//
//void recordGyroRegisters(){
////    Serial.println("MPu");
//  Wire.beginTransmission(0b1101001); //I2C address of the MPU
//  Wire.write(0x43); //Starting register for Gyro Readings
//  Wire.endTransmission();
//  Wire.requestFrom(0b1101001,6); //Request Gyro Registers (43 - 48)
//  while(Wire.available() < 6);
//  gyroZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ
////  processGyroData();
//  } 
//
//  void processRefGyroData() {
//    for (int i=0;i<1000;i++){
//       ref_rotZ = gyroZ / 16.4;
//  ref_rpmZ=ref_rpmZ+ref_rotZ/6;
//    }
//    ref_rpmZ=ref_rpmZ/1000;
// 
////  rpmZ_string=rpmZ;
////  Serial.print("rpmZ = ");
////  Serial.println(raw_rpmZ);
////  return rpmZ;
////  Kalman (raw_rpmZ);
////   Serial.print("rpmZ = ");
////  Serial.println(filt_rpmZ);
//}
//
//
//volatile float processGyroData() {
//  rotZ = gyroZ / 16.4;
//  raw_rpmZ=(rotZ/6)-ref_rpmZ;
////  rpmZ_string=rpmZ;
////  Serial.print("rpmZ = ");
////  Serial.println(raw_rpmZ);
////  return rpmZ;
//  Kalman (raw_rpmZ);
////   Serial.print("rpmZ = ");
////  Serial.println(filt_rpmZ);
//  return filt_rpmZ;
////  delay(1000);
//}
//
//void printMPU(){
////  Serial.print("Angular Velocity about z-axis = ");
////  Serial.print(processGyroData());
////  Serial.println("RPM");
//}
