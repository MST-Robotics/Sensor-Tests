
#ifndef TEMP_H
#define TEMP_H

#include <ROV_main_setup.h>
#include <PID_v1.h>
#include <ros.h>
#include <Servo.h>
#include <SD.h>

#include <Wire.h>

#include "TSYS01.h"

TSYS01 sensor;
#include "pins.h"//this file should be in the same directory as .ino

/*ros message data types can be
 * found at: http://wiki.ros.org/std_msgs
*/
#include <std_msgs/Bool.h> //include required per type of message
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int16.h> 
#include <std_msgs/UInt8.h>
#include <geometry_msgs/Vector3.h>
#define CSV_FILE_LOCATION "theData.csv"
/*
 * turns on temp sensor, reads it, dumps it into csv
 */

void temp_pin_on() 
{
  char temp_val = 'a';
  bool on = true;
  sensor.read();
  File csvFile = SD.open(CSV_FILE_LOCATION, FILE_WRITE);
  if(on) 
  {
    // turn pin on
    Serial.print(sensor.temperature());
    int temp_val = sensor.temperature();
    delay(1000);
    
   // digitalWrite(temp_pin, HIGH);
   // int temp_val = analogRead(temp_sensor_pin); //read the temperature sensor
    // write to csv
    if (csvFile) 
    {
//      csvFile.print("temp, %d", temp_val);
    }
    
    digitalWrite(temp_pin, LOW);
  }
}



#endif
