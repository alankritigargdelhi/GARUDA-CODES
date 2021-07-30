void xbeeMessageReceived(void){
  noInterrupts();
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


  
//  stabilizeCamera();
  
  interrupts();
}


void calibrateSensors(){
    refBMP();
//    dataPacket.altitude = 0.00;
    dataPacket.software_state = BOOT;
//    setSoftwareState();
//    received_calibrate_command = true;
//  packetCount = 0;
}
