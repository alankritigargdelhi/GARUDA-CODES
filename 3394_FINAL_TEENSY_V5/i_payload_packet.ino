boolean transmitPayloadPacketString(payload_packet* dataPacket){
  /*
  Transmits packet as a csv string over xbee
  */
//#ifdef SER_DEBUG
//    Serial1.println("Sending via xbee : "+ dataPacket->toString());
//#endif
  GCS_Xbee.print(dataPacket->toString());
//  saveSD(dataPacket->toString());
  return true;
}
