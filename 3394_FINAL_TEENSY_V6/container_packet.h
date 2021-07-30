/*
 * packet.h
 */

//#ifndef packet_h
//#define packet_h

//enum op_state {
//  boot, idle, launch_detect, deploy
//};
//const String op_state_string_lut[] = {
//  "Boot", "Idle", "Launch detect", "Deploy"
//};

//========== DEFINING SOFTWARE STATES===============
#define BOOT 1
#define ACCENT 2
#define DEPLOYMENT 3
#define DESCENT 4
#define SP1DEPLOYMENT 5
#define SP2DEPLOYMENT 6
#define LANDING 7
//===================================================

class container_packet {
  public:
    container_packet(const uint16_t team_id = 3394);  //assigned to GAGAN
    
    /*
    Variables to be transmitted
    Minimum Total Size = 50 bytes
    */
    
    uint16_t team_id;     // the assigned team identification
    String mission_time;  //the time since initial power up in seconds
    volatile int packet_count;  // the count of transmitted packets, which is to be maintained through processor reset.
    float altitude;  // the altitude in units of meters and must be relative to ground level. The resolution must be 0.1 meters.
//    volatile float pressure;  //the measurement of atmospheric pressure in units of pascals. The resolution must be 0.1 pascals.
    volatile float temperature; // the sensed temperature in degrees C with one tenth of a degree resolution.
    volatile float voltage;   //the voltage of the CanSat power bus. The resolution must be 0.01 volts.
    String gps_time_utc;    // the time generated by the GPS receiver. The time must be reported in UTC and have a resolution of a second. UTC Format: 2013-10-22T01:37:56+05:30
    String gps_lattitude; //the latitude generated by the GPS receiver in decimal degrees with a resolution of 0.0001 degrees.
    String gps_longitude; //the longitude generated by the GPS receiver in decimal degrees with a resolution of 0.0001 degrees.
    String gps_altitude;  //the altitude generated by the GPS receiver in meters above mean sea level with a resolution of 0.1 meters.
    String gps_sats;    // the number of GPS satellites being tracked by the GPS receiver. This must be an integer number.
//    volatile int pitch;     // the tilt angle in the pitch axis in degrees. The resolution must be 1 degree.
//    volatile int roll;      // the tilt angle of the roll axis in degrees. The resolution must be 1 degree.
//    volatile uint16_t blade_spin_rate;  // the rate the auto-gyro blades spin relative to the science payload. The units must be in revolutions per minute (rpm). The resolution must be 1 rpm.
    volatile int software_state;      // the operating state of the software. (boot, idle, launch detect, deploy, etc.)
//    String bonus_direction; // the direction the camera is pointed relative to earth’s magnetic north specified in degrees.
    String packet_type;
    String mode;
    String SP1_released;
    String SP2_released;
    String CMD_ECHO;
    //Other variables
    volatile int SP1_packet_count;
    volatile int SP2_packet_count;
    String _csv_string;     //locally stores output of toString()
    String gps_time;
    String rpm;
    
    String toString();      //returns a csv string of all the data fields.
    void display();         //prints the packet to the terminal
  
};

//#endif // packet_h