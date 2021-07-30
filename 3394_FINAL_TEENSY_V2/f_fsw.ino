void setSoftwareState(){
  int oldSoftState = dataPacket.software_state;
//  if(received_calibrate_command) {
//    oldSoftState = BOOT;
//    dataPacket.altitude = 0;
//    received_calibrate_command = false;
//  }
  switch(oldSoftState){
    case BOOT:  
          if(dataPacket.altitude > 5) dataPacket.software_state = ACCENT;
          break;
    case ACCENT:
          if(dataPacket.altitude > 675) dataPacket.software_state = DEPLOYMENT;
//          else dataPacket.software_state = BOOT;
          break;
    case DEPLOYMENT:
          if(dataPacket.altitude < 600) dataPacket.software_state = DESCENT;
          break;
    case DESCENT:
          if(dataPacket.altitude < 505) {dataPacket.software_state = SP1DEPLOYMENT;
          xbee.write("D");
          dataPacket.SP1_released= "R";}
          break;
    case SP1DEPLOYMENT:
          if(dataPacket.altitude < 405) {dataPacket.software_state = SP2DEPLOYMENT;
          xbee.write("E");
          dataPacket.SP2_released= "R";}
          break;
    case SP2DEPLOYMENT:
          if(dataPacket.altitude < 50) {
            dataPacket.software_state = LANDING;
            transmitContainerPacketString(&dataPacket);
        //    saveSD(",");
            transmitPayloadPacketString(&dataPacket_S1);        //    saveSD(",");
            transmitPayloadPacketString(&dataPacket_S2);
        //   GCS_Xbee.print(dataPacket.software_state);
            GCS_Xbee.print("\n");

            sendContainerTeleToGCS= false;
            buzzerON();
//            sendCommandtoCamera(SWITCHONCAMERASERVO);
          }
          //Sending command to camera subsystem
                //2 is switch on camera and servo command
          break;
    default: break;
  }

//  if(oldSoftState != dataPacket.software_state){
//    backupUpdatedSoftwareState(dataPacket.software_state);
//  }
//  prevAlt = dataPacket.altitude;
}
