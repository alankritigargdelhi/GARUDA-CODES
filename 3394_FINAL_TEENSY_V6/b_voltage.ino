void initBatteryVoltage() {
  // initialize battery voltage function
  pinMode(voltagePin,INPUT);
  #define R1 3300
  #define R2 4700
  #define ADC_MAX 1024 //12 bit ADC
  #define VCC 5.0 //Max voltage read by SAMD21
  #define VOLTAGE_DIV (R1+R2)/R2 //Factor for calculating battery voltage
//  analogReadResolution(12); // Set analog input resolution to max, 12-bits
}


float getBatteryVoltage() {
  int voltageDigital = analogRead(voltagePin);
  float voltageBattery = (voltageDigital)*(VCC/ADC_MAX)*VOLTAGE_DIV;
  return voltageBattery;
}
//
//float getBatteryVoltage(){
//  float cap = analogRead(voltagePin);                     //reads the analog value on A0 pin
//  float voltage = (cap/1024) * 9 ;
//  return voltage;
//}
