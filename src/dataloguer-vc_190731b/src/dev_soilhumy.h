#ifndef DEV_SOILHUMI_H
#define DEV_SOILHUMI_H
#include "_extern.h"
#define SNSCALLIBRATIONMIN  1400
#define SNSCALLIBRATIONMAX  3040
#define SNSLAPSEINTERVAL    0// 2000 0=not use intervall you must call read() 
const   unsigned int   g_SnsCallibrationMin = SNSCALLIBRATIONMIN;
const   unsigned int   g_SnsCallibrationMax = SNSCALLIBRATIONMAX;
const   unsigned int   g_snsLapseInterval   = SNSLAPSEINTERVAL;
void fnc_dev_SoilHumy_Setup(unsigned int calibrateMin , unsigned int calibrateMax)
{
  g_device_CapMoisture.setup(PIN_CAPTATIVESOIL,  CAPACITIVE_CALIBRATE_MIN,  CAPACITIVE_CALIBRATE_MAX);

}
void fnc_dev_SoilHumi_Read() {

  g_device_CapMoisture.read();
  
  g_Dev.v_HumiditySoil = g_device_CapMoisture.valuePct();
  snprintf(g_Dev.s_HumiditySoil, sizeof(LEN_DL_HUMIDITYSOIL) , "%u", g_Dev.v_HumiditySoil);
 
  
  


}
#endif
