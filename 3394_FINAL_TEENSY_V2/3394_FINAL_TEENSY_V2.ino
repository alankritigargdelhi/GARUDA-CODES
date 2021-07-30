#include "pindef.h"


container_packet dataPacket(TEAM_ID);
payload_packet dataPacket_S1(TEAM_ID);
payload_packet dataPacket_S2(TEAM_ID);

void setup() {
  // put your setup code here, to run once:
    GCS_Xbee.begin(9600);
    xbee.begin(9600);
    //---------------------------------------------------------------

    //------------------------------------------------------------------
//    pinMode(BUILTIN_LED, OUTPUT);
    
    setSyncProvider(getTeensy3Time);
    pinMode(buzzer_pin,OUTPUT);
    pinMode(XBEE_INTERRUPT_PIN, INPUT);
    digitalWrite(buzzer_pin,LOW);
//    setRTC_UTC(12,12,12);
//    if(debug==1)
      //GCS_Xbee.print("SETUP HO GYA");
    setupBMP();
     Teensy3Clock.set(1622763312); // set the RTC
    setTime(1622763312);
//    xbee.print("HIII");
    initBatteryVoltage();
//    while(!SD.begin(chipSelect)){
//      if(debug==1)
//      GCS_Xbee.print(U"FAILED");
//    }
//    initSD();
    refBMP();
    dataPacket.altitude = getBMPCurr_ALt();
    dataPacket.software_state = BOOT;
    delay(1000);
    //attachInterrupt(digitalPinToInterrupt(XBEE_INTERRUPT_PIN), xbeeSendTelemetry, RISING);
    rtc.writeSqwPinMode(DS3231_SquareWave1Hz);
//    servo.write(50);
    Timer1.initialize(900000);
    Timer1.attachInterrupt(xbeeMessageReceived);
    dataPacket.software_state = BOOT;
    attachInterrupt(digitalPinToInterrupt(XBEE_INTERRUPT_PIN), xbeeSendTelemetry, RISING);
}

void loop() {
  if(debug==1)
    GCS_Xbee.print("LOOP MEIN AA GYA");
  if(SIMP_STATUS==0){
   dataPacket.altitude = getBMPAltitute();
  }
  dataPacket.temperature = bmp.readTemperature();
  dataPacket.voltage = getBatteryVoltage();


//  stabilizeCamera();
}

void xbeeSendTelemetry(){
//    stabilizeCamera();

    if(debug==1)
  GCS_Xbee.print("RTC INTRR CALLED");
  
  detachInterrupt(digitalPinToInterrupt(XBEE_INTERRUPT_PIN));
    while(xbee.available()>0)
    {
//      GCS_Xbee.print("HIII\n");
    char payload_data_char = xbee.read();
//    GCS_Xbee.write(payload_data_char);
    if(payload_data_char=='>'){
      received_complete_packet = true;
    }
    receivedPayloadPacket += payload_data_char; 
    }
    if(received_complete_packet){
      int firstCommaIndex = receivedPayloadPacket.indexOf(',');
      String firstValue = receivedPayloadPacket.substring(2, firstCommaIndex);
      int secondCommaIndex = receivedPayloadPacket.indexOf(',', firstCommaIndex + 1);
      String secondValue = receivedPayloadPacket.substring(firstCommaIndex + 1, secondCommaIndex);
      int thirdCommaIndex = receivedPayloadPacket.indexOf(',', secondCommaIndex + 1);
      String thirdValue = receivedPayloadPacket.substring(secondCommaIndex + 1, thirdCommaIndex); // To the end of the string
      //int fourthCommaIndex = receivedPayloadPacket.indexOf(',', thirdCommaIndex + 1);
      //String fourthValue = receivedPayloadPacket.substring(thirdCommaIndex + 1,fourthCommaIndex); // To the end of the string
      int closnigIndex = receivedPayloadPacket.indexOf('>', thirdCommaIndex + 1);
      String fourthValue = receivedPayloadPacket.substring(thirdCommaIndex + 1,closnigIndex); // To the end of the string
      
//      receivedPayloadPacket.charAt(0).toString();
      if(receivedPayloadPacket.startsWith("1")){
        payload_1_PacketCount++;
//        dataPacket_S1.mission_time = firstValue;
        dataPacket_S1.mission_time = dataPacket.mission_time;
        dataPacket_S1.packet_count = firstValue;
        dataPacket_S1.packet_type = "S1";
        dataPacket_S1.payload_altitude = secondValue;
        dataPacket_S1.payload_temperature = thirdValue;
        dataPacket_S1.rpm = fourthValue;
        
        dataPacket.SP1_packet_count = payload_1_PacketCount;
        
      }else if(receivedPayloadPacket.startsWith("2")) {
        payload_2_PacketCount++;
//        dataPacket_S2.mission_time = firstValue;
        dataPacket_S2.mission_time = dataPacket.mission_time;
        dataPacket_S2.packet_count = firstValue;
        dataPacket_S2.packet_type = "S2";
        dataPacket_S2.payload_altitude = secondValue;
        dataPacket_S2.payload_temperature = thirdValue;
        dataPacket_S2.rpm = fourthValue;
        
        dataPacket.SP2_packet_count = payload_2_PacketCount;
        
      }
      if(debug==1)
      {
      xbee.write("KUCH AAYAA");
      }
      received_complete_packet = false; 
      receivedPayloadPacket = "";
    }
//    float temp_alt = ;    
    UTC_time = String(hour())+":"+String(minute())+":"+String(second());
    dataPacket.packet_count = packetCount;
    dataPacket.mission_time = UTC_time;
    if(sendTeleToGCS){
      packetCount++;
      if(sendContainerTeleToGCS)
    transmitContainerPacketString(&dataPacket);
//    saveSD(",");
    transmitPayloadPacketString(&dataPacket_S1);
//    saveSD(",");
    transmitPayloadPacketString(&dataPacket_S2);
//   GCS_Xbee.print(dataPacket.software_state);
    GCS_Xbee.print("\n");
    }
    if(SD_Status==1)
//    saveSD(&dataPacket,&dataPacket_S1,&dataPacket_S2);
        
    delay(100); 
    attachInterrupt (digitalPinToInterrupt (XBEE_INTERRUPT_PIN), xbeeSendTelemetry, FALLING);

}


time_t getTeensy3Time()
{
  return Teensy3Clock.get();
}
