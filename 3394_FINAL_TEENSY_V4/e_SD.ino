void initSD(){
  myFile = SD.open("test9June2021_V1.csv" , FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    //GCS_Xbee.print("Writing to test15.csv...");
    myFile.print("Team ID,Mission Time,Packet count,Packet Type,Mode, SP1 Released, SP2 Released,Altitude,Temperature,Voltage, GPS Time,GPS Latitude, GPS Longitude, GPS Altitude, GPS Sats, Software state, SP1 Packet Count, SP2 Packet Count, CMD Echo,");//CONTAINER
    myFile.print("Team ID, Mission Time, Packet Count, Packet Type, SP Altitude, SP Temperature, SP Roation Rate,");//SP1
     myFile.println("Team ID, Mission Time, Packet Count, Packet Type, SP Altitude, SP Temperature, SP Roation Rate");//SP2 
  // close the file:
    myFile.close();
    SD_Status = 1;
    //GCS_Xbee.println("Written fields in CSV file.DONE."); 
  } 
  

}


void saveSD(container_packet* dataPacket , payload_packet* dataPacketS1 , payload_packet* dataPacketS2){
   myFile = SD.open("test9June2021_V1.csv" , FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile){
    myFile.print(dataPacket->toString());
    myFile.print(",");
    myFile.print(dataPacketS1->toString());
    myFile.print(",");
    myFile.print(dataPacketS2->toString());
    myFile.print("\n");
   myFile.close();
   GCS_Xbee.println("WRITTEN");
  }
 else {
    // if the file didn't open, print an error:
    GCS_Xbee.println("error opening file");
  } 
}
