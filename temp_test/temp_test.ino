#include "temp.h"

//Arduino setup
unsigned long  prev_millis = 0;
void setup() {
  // put your setup code here, to run once:
  main_setup();
  Wire.begin();

  sensor.init();

}

void loop()
{
//  nh.spinOnce();//run ros once
//old code from last year  process_temperature();//update the temperature data
  //process_imu();//handle all pid control for the vertical thrusters

  if (millis() - prev_millis >= 10)
  {
    temp_pin_on();
   // send_manipulator_data();
    //send_leveler_data();
    prev_millis = millis();
  }
}
