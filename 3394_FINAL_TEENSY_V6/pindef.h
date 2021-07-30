#include "container_packet.h"
#include "payload_packet.h"

#include <RTClib.h>    //RTC Library

#include <Adafruit_BMP280.h>      //BMP280
#include <TimeLib.h>
#include<TimerOne.h>
#include<SPI.h>
#include<SD.h>
#include <Wire.h>
#include <MPU6050_tockn.h>
//#include <PWMServo.h>

File myFile;
RTC_DS3231 rtc;         //2. RTC object: I2C interface //Used "Wire"

#define debug 0
#define XBEEBaud 9600
#define XBEE_INTERRUPT_PIN 2
#define TEAM_ID 3394    //TEAM GARUDA
#define TEAM_ID_PAYLOAD 3399    //TEAM GARUDA
#define BMP_ADDR 0x76
#define MPU_ADDR 0x69
#define MPU_ADDR_HEX 0b1101001
#define voltagePin A1
#define year 2021
#define month 6
#define date 07
#define RESET_PIN 9
#define xbee Serial1
#define GCS_Xbee Serial3
#define BUILTIN_LED 13
#define chipSelect 4
#define buzzer_pin 6
#define file_name "test6June2021.csv"

Adafruit_BMP280 bmp; 

String UTC_time = "";
String receivedPayloadPacket = "";
String receivedSIMPCommand = "";
bool received_complete_packet = false;
bool received_complete_SIMP_command = false;
bool received_set_time_command = false;
bool has_the_time_been_set = true;
bool received_complete_ST_command = false;
bool received_calibrate_command = false;
String ST_string = "";
int SIMP_STATUS = 0;
int bmp_available = 0;
volatile float ground_altitude = 0;
//int prev_alt=0, curr_alt=0;
//float ref_mpu_gyroz = 0.00;
//volatile float rotZ = 0.00,rpmZ = 0.00;                          //MPU9250
//volatile float gyroZ = 0.00;                               //MPU9250
int packetCount = 0;
int payload_1_PacketCount = 0;
int payload_2_PacketCount = 0;
int SD_Status = 0;
boolean sendTeleToGCS = false;
boolean sendContainerTeleToGCS = false;



//int servoPin = 10;
//PWMServo servo; 
//float rotZ = 0,raw_rpmZ = 0, filt_rpmZ=0;                          //MPU9250
//long gyroZ = 0;                               //MPU9250
//String rpmZ_string = "0";  
//float ref_rotZ=0;
//float ref_rpmZ=0;//MPU9250 - STRING VARIABLE FOR rpmZ 
//float servoAngleInt;
