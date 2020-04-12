
//IF YOU ARE NOT ON THE FLIGHT COMPUTER TEAM, ONLY CHANGE THESE VALUES ON THE RIGHT
//DO NOT MESS WITH THE CODE, TALK TO CHIEF ELECTRICAL ENGINEER IF YOU NEED SOMETHING 
//THAT IS NOT SPECIFIED


//Overall Rocket Info
#define TWO_STAGE_ROCKET                true //"true" or "false"


//Two stage info
#define TILT_LOCK                       true //"true" or "false"
#define TILT_LOCK_ANGLE                 5.0f //degrees
#define SECOND_STAGE_IGNITION           true //"true" or "false"
#define SECOND_STAGE_FIRST_CONDITION    NONE//NONE, APOGEE, TIME_DELAY, VELOCITY_MIN, VELOCITY_MAX
#define SECOND_STAGE_FIRST_VALUE        100 //Use metric units
#define SECOND_STAGE_SECOND_CONDITION   NONE//NONE, APOGEE, TIME_DELAY, VELOCITY_MIN, VELOCITY_MAX
#define SECOND_STAGE_SECOND_VALUE       100//Use metric units
#define SECOND_STAGE_MOTOR_PRYO_CHANNEL 1


//Drogue info
//Both conditions must be true for drogue in order for the chute to deploy
#define DROGUE_FIRST_CONDITION  NONE //NONE, APOGEE, TIME_DELAY, VELOCITY_MIN, VELOCITY_MAX
#define DROGUE_FIRST_VALUE      100f //Use metric units
#define DROGUE_SECOND_CONDITION NONE //NONE, APOGEE, TIME_DELAY, VELOCITY_MIN, VELOCITY_MAX
#define DROGUE_SECOND_VALUE     100f //Use metric units
#define DROGUE_PYRO_CHANNEL     2


//Parachute info
#define MAIN_ALTITUDE       500f //altitude in meters
#define MAIN_PYRO_CHANNEL   3



//Logging info
#define LOGGING_FREQUENCY   1000 //Hz
#define APOGEE_DELAY_TIME   2    //s    if descent is detected, it will wait this time before confirming

//THRESHOLD
#define ROCKET_LAUNCH_THRESHOLD 1.5f //g Determine if rocket has launched
#define ROCKET_COAST_THRESHOLD  0.5f //g Determine if the motor has burnt out


//DO NOT EDIT PAST THIS POINT
enum FireConditions{
    NONE,
    APOGEE, 
    TIME_DELAY, 
    VELOCITY_MIN, 
    VELOCITY_MAX
};