void xbeeMessageReceived(void){
  noInterrupts();
//  stabilizeCamera();
  if(SIMP_STATUS==1) setSoftwareState();
  
  if(debug==1)
  GCS_Xbee.print("INIT XBEE");
  
  if(SIMP_STATUS==0 && !received_set_time_command){
  while(GCS_Xbee.available()>0){
 
  char x = GCS_Xbee.read();
  switch(x){
    //----------------------------------0-----------------------------------------------
    case 48:GCS_Xbee.write("<OK>\n"); 
           break;
    //----------------------------------A-----------------------------------------------
    case 65:if(debug==1)
            GCS_Xbee.write("Recieved 1: <CX ON>\n");
            
            dataPacket.CMD_ECHO = "CXON";
            sendTeleToGCS = true;
//           calibrateSensors1(); 
           break;
    //----------------------------------B-----------------------------------------------
    case 66: calibrateSensors();
          //GCS_Xbee.write("Recieved 2: <CAL ON>\n");
           
//           dataPacket.CMD_ECHO = "CALON";
           break;
    //----------------------------------C-----------------------------------------------
    case 67: received_set_time_command = true;
             //has_the_time_been_set = false;
             
            if(debug==1)
            GCS_Xbee.write("ST");
            
    break;
    //----------------------------------D-------------------------SP1X ON----------------------
    case 68:xbee.write("D");            //SP1X ON
            dataPacket.CMD_ECHO = "SP1XON";
            if(debug==1)
            GCS_Xbee.write("Recieved 3: <SP1X ON>\n");
            
//           recieve3();
           break;
    //----------------------------------E-------------------------SP2X ON----------------------
    case 69:xbee.write("E");            //SP2X ON
            dataPacket.CMD_ECHO = "SP2XON";
            if(debug==1)
            GCS_Xbee.write("Recieved 4: <SP2X ON>\n");
            
            break;
    //----------------------------------F-----------------------------------------------
    case 70: dataPacket.CMD_ECHO = "SIMENABLE";
             if(debug==1)
              GCS_Xbee.write("SIM enable");
             break;
    //----------------------------------G-----------------------------------------------
     case 71: dataPacket.CMD_ECHO = "SIMACTIVATE";
              dataPacket.mode = "S";
              SIMP_STATUS = 1;
              dataPacket.software_state = BOOT;
              if(debug==1)
                GCS_Xbee.write("SIM activate");
              break;
    //----------------------------------H-----------------------------------------------            
     case 72:sendTeleToGCS = false;
            dataPacket.CMD_ECHO = "CXOFF";
            if(debug==1)
              GCS_Xbee.write("cx off");
            break;
    //----------------------------------I------------------------SP1X OFF-----------------------
     case 73: xbee.write("I");
             dataPacket.CMD_ECHO = "SP1XOFF";
             if(debug==1)
              GCS_Xbee.write("sp1x off");
              break;
    //----------------------------------J-------------------------SP2X OFF----------------------
     case 74:xbee.write("J");
             if(debug==1)
              GCS_Xbee.write("sp2x off");
             dataPacket.CMD_ECHO = "SP2XOFF";
              break;
     //----------------------------------K-----------------------------------------------
     case 75: GCS_Xbee.write("RESET");
              digitalWrite(RESET_PIN,LOW);
              delay(50);
              digitalWrite(RESET_PIN,HIGH);
              break;
    //-----------------------------------L-------------------------SP1 RELEASE----------------------          
     case 76: GCS_Xbee.write("EXTRA");
              
              break;
     default: GCS_Xbee.write("<INCORRECT>");
  }
}
}
   if(received_set_time_command){
    while(GCS_Xbee.available()>0){
      char ST_char = GCS_Xbee.read();
      ST_string += ST_char;
      if(ST_char=='>'){
        received_complete_ST_command = true;
      }
    }
    if(received_complete_ST_command){
      int commaIndex = ST_string.indexOf(',');
      int closnigIndex = ST_string.indexOf('>', commaIndex + 1);
      int received_time = ST_string.substring(commaIndex + 1,closnigIndex).toInt();
      Teensy3Clock.set(received_time); // set the RTC
       setTime(received_time);
//      GCS_Xbee.println(received_time);
      received_set_time_command = false;
    }
   }

  if(SIMP_STATUS==1){
    while(GCS_Xbee.available()>0)
    {
    char SIMP_char = GCS_Xbee.read();
//    GCS_Xbee.write(payload_data_char);
    if(SIMP_char=='>'){
      received_complete_SIMP_command = true;
    }
    receivedSIMPCommand += SIMP_char; 
    }
    if(received_complete_SIMP_command){
      if(receivedSIMPCommand.startsWith("<SIMP")){
//        GCS_Xbee.println("HIII");
      int commaIndex = receivedSIMPCommand.indexOf(',');
      int closnigIndex = receivedSIMPCommand.indexOf('>', commaIndex + 1);
      int  received_simulated_pressure = receivedSIMPCommand.substring(commaIndex + 1,closnigIndex).toInt();
       //GCS_Xbee.println(received_simulated_pressure);
       float simp_altitude=44330.00*(1-pow((received_simulated_pressure/101325.00),0.19));
       if(dataPacket.software_state == ACCENT || dataPacket.software_state == BOOT){
        if(dataPacket.altitude < simp_altitude){
          dataPacket.altitude = simp_altitude;
        }
       }

       else if(dataPacket.altitude > simp_altitude){
          dataPacket.altitude = simp_altitude;
        }
       
       
       dataPacket.CMD_ECHO = "SIMP"+String(received_simulated_pressure);
       receivedSIMPCommand = "";
       received_complete_SIMP_command = false;
      }
      else if(receivedSIMPCommand.startsWith("<SIMDISABLE")){
        SIMP_STATUS=0;
        dataPacket.software_state = BOOT;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  BOOT;
        dataPacket.CMD_ECHO = "SIMDISABLE";
        dataPacket.mode = "F";
        receivedSIMPCommand = "";
       received_complete_SIMP_command = false;
      }
    }
  }
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
