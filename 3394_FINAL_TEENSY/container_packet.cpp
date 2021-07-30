#include <Arduino.h>
#include "container_packet.h"

#define SER_DEBUG

//constructor
container_packet::container_packet(const uint16_t team_id){
  this->team_id = team_id;
  this->mission_time = "0";
  this->packet_count = 0;
  this->altitude = 0;
//  this->pressure = 0;
  this->temperature = 0;
  this->voltage = 0;
  this->gps_time_utc = "0";
  this->gps_lattitude = "27.204658";
  this->gps_longitude = "77.497737";
  this->gps_altitude = "185.40";
  this->gps_sats = "5";
//  this->pitch = 0;
//  this->roll = 0;
//  this->blade_spin_rate = 0;
  this->software_state = BOOT;
  this->packet_type = "C";
  this->mode = "F";
  this->SP1_released = "N";
  this->SP2_released = "N";
  this->CMD_ECHO = "G";
  this->SP1_packet_count = 0;
  this->SP2_packet_count = 0;
  this->rpm = "0";
//  this->bonus_direction = "0";
    //this->
}

String container_packet::toString(){
  String csv = String( 
    "<" +
    String(this->team_id) + "," +
    this->mission_time + "," +
    String(this->packet_count) + ",C," +
    this->mode + "," +
    this->SP1_released + "," +
    this->SP2_released + "," +
    String(this->altitude) + "," +
//    String(this->pressure) + "," +
    String(this->temperature) + "," +
    String(this->voltage) + "," +
    this->gps_time_utc + "," +
    this->gps_lattitude + "," +
    this->gps_longitude + "," +
    this->gps_altitude + "," +
    this->gps_sats + "," +
//    String(this->pitch) + "," +
//    String(this->roll) + "," +
//    String(this->blade_spin_rate) + "," +
    String(this->software_state) + "," +
//    this->bonus_direction
    String(this->SP1_packet_count) + "," +
    String(this->SP2_packet_count) + "," +
    
    this->CMD_ECHO + ">" 
  );
  //this->_csv_string = csv;
  return csv;
}

void container_packet::display(){
  #ifdef SER_DEBUG
    Serial.println("======================= PACKET =======================");
    Serial.println("Packet Size\t\t:\t\t" + String(sizeof(*this)) + "\tBytes");
    Serial.println("------------------------------------------------------");
    Serial.println("Team ID\t\t\t:\t\t" + String(this->team_id));
    Serial.println("Mission Time\t\t:\t\t" + String(this->mission_time) + "\ts");
//    Serial.println("Packet Count\t\t:\t\t" + String(this->packet_count) + "\tunits");
//    Serial.println("Altitude\t\t:\t\t" + String(this->altitude) + "\tm");
//    Serial.println("Pressure\t\t:\t\t" + String(this->pressure) + "\tPa");
//    Serial.println("Temperature\t\t:\t\t" + String(this->temperature) + "\tC");
//    Serial.println("Battery Voltage\t\t:\t\t" + String(this->voltage) + "\tV");
//    Serial.println("GPS Time\t\t:\t\t" + this->gps_time_utc);
//    Serial.println("GPS Lattitude\t\t:\t\t" + this->gps_lattitude + "\tE");
//    Serial.println("GPS Longitude\t\t:\t\t" + this->gps_longitude + "\tN");
//    Serial.println("GPS Altitude\t\t:\t\t" + this->gps_altitude + "\tm");
//    Serial.println("GPS Sats\t\t:\t\t" + this->gps_sats + "\tunits");
//    Serial.println("Pitch\t\t\t:\t\t" + String(this->pitch) + "\tdeg");
//    Serial.println("Roll\t\t\t:\t\t" + String(this->roll) + "\tdeg");
//    Serial.println("Blade Spin Rate\t\t:\t\t" + String(this->blade_spin_rate) + "\tRPM");
//    Serial.println("Op state\t\t:\t\t" + String(this->software_state) + "");
//    Serial.println("Direction\t\t:\t\t" + this->bonus_direction + "\tdeg");
//    Serial.println("======================================================\n\n");
  #endif
}
