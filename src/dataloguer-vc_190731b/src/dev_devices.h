// ==============================================================
// dev_devices.h 
// all devices manager 
// function prefij:   fnc_devices
// Global variables : g_Dev.g_dev_
// ==============================================================
#ifndef DEVICES_H
#define DEVICES_H
#include "_extern.h"

void fnc_devices_Read()
{
  fnc_dev_rtc3231_Read();
  fnc_dev_DS18B20_Read();
  fnc_dev_bh1750_Read();
  fnc_dev_BMP180_Read();
  fnc_dev_DHT22_Read();
  fnc_dev_SoilHumi_Read();
  fnc_dev_Gps_Read_IsInteval(24,59) ;
  //Note: Read gps  may be spent too much time if not find satellites  
  //it read one time each hour
   fnc_sta_Add();
}

bool fnc_devices_Loop_IsInterval()
{

  g_Dev.t_IntervalAct = millis();
  // desvordamiento
  if (g_Dev.t_IntervalBefore > g_Dev.t_IntervalAct)
  {
    g_Dev.t_IntervalBefore = 0;
    return false;
  }
  uint32_t interval = g_Dev.t_IntervalAct - g_Dev.t_IntervalBefore;
  if (interval >= g_Dev.t_IntervalRead)
  {
    g_Dev.t_IntervalBefore = g_Dev.t_IntervalAct;
    fnc_devices_Read();
    //Serial.println("Aqui: fncLoop_DL_ReadSensorsIsInterval");
  }
  else
  {
    return false;
  }
  return true;
}
void fnc_devices_Setup()
{

  fnc_dev_Gps_setup();
  fnc_dev_Gps_Read(); // fist read. Exception Gps is slow on start.

  //g_SD_enable = fnc_dev_SD_Setup();
  fnc_dev_bh1750_Setup();  //ldr light sensor
  fnc_dev_rtc3231_Setup(); //clock
  fnc_dev_Ds18B20_Setup(); //sensor temp soil subsoil

  fnc_dev_BMP180_Setup();                                                     // preasure
  fnc_dev_DHT22_Setup();                                                      // humidity and temp
  fnc_dev_SoilHumy_Setup(CAPACITIVE_CALIBRATE_MIN, CAPACITIVE_CALIBRATE_MAX); // soil humidity
  fnc_dev_Gps_Read();                                                          // exception for seach satellites on beguin
  Serial.println("-----------------------");
}
#endif
