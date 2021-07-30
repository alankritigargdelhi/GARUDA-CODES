#include <Arduino.h>
#include "payload_packet.h"

#define SER_DEBUG

//constructor
payload_packet::payload_packet(const uint16_t team_id){
  this->team_id = team_id;
  this->mission_time = "-";
  this->packet_count = "-";
  this->packet_type = "-";
  this->payload_altitude = "-";
//  this->pressure = 0;
  this->payload_temperature = "-";
  this->rpm = "-";
//  this->voltage = 0;
//  this->gps_time_utc = "2013-10-22T01:37:56+05:30";
//  this->gps_lattitude = "0";
//  this->gps_longitude = "0";
//  this->gps_altitude = "0";
//  this->gps_sats = "0";
//  this->software_state = BOOT;
//  this->packet_type = "C";
//  this->mode = "F";
//  this->SP1_released = "N";
//  this->SP2_released = "N";
//  this->CMD_ECHO = "G";
//  this->SP1_packet_count = "0";
//  this->SP2_packet_count = "0";
//  this->rpm = "0";
//  this->bonus_direction = "0";
    //this->
}

String payload_packet::toString(){
  String csv = String( 
    "<" +
    String(this->team_id) + "," +
    this->mission_time + "," +
    this->packet_count + "," +
    this->packet_type + "," +
    this->payload_altitude + "," +
    this->payload_temperature + "," +
    this->rpm + ">" 
    
     
  );
  //this->_csv_string = csv;
  return csv;
}

void payload_packet::display(){
  #ifdef SER_DEBUG
    Serial1.println("======================= PACKET =======================");
    Serial1.println("Packet Size\t\t:\t\t" + String(sizeof(*this)) + "\tBytes");
    Serial1.println("------------------------------------------------------");
    Serial1.println("Team ID\t\t\t:\t\t" + String(this->team_id));
    Serial1.println("Mission Time\t\t:\t\t" + String(this->mission_time) + "\ts");
//    Serial1.println("Packet Count\t\t:\t\t" + String(this->packet_count) + "\tunits");
//    Serial1.println("Altitude\t\t:\t\t" + String(this->altitude) + "\tm");
//    Serial1.println("Pressure\t\t:\t\t" + String(this->pressure) + "\tPa");
//    Serial1.println("Temperature\t\t:\t\t" + String(this->temperature) + "\tC");
//    Serial1.println("Battery Voltage\t\t:\t\t" + String(this->voltage) + "\tV");
//    Serial1.println("GPS Time\t\t:\t\t" + this->gps_time_utc);
//    Serial1.println("GPS Lattitude\t\t:\t\t" + this->gps_lattitude + "\tE");
//    Serial1.println("GPS Longitude\t\t:\t\t" + this->gps_longitude + "\tN");
//    Serial1.println("GPS Altitude\t\t:\t\t" + this->gps_altitude + "\tm");
//    Serial1.println("GPS Sats\t\t:\t\t" + this->gps_sats + "\tunits");
//    Serial1.println("Pitch\t\t\t:\t\t" + String(this->pitch) + "\tdeg");
//    Serial1.println("Roll\t\t\t:\t\t" + String(this->roll) + "\tdeg");
//    Serial1.println("Blade Spin Rate\t\t:\t\t" + String(this->blade_spin_rate) + "\tRPM");
//    Serial1.println("Op state\t\t:\t\t" + String(this->software_state) + "");
//    Serial1.println("Direction\t\t:\t\t" + this->bonus_direction + "\tdeg");
//    Serial1.println("======================================================\n\n");
  #endif
}
