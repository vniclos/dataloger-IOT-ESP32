// ==============================================================
// dev_DS18B20.h 
// temperature sensor soil subsoil
// device g_device_Ds18B20 
// function prefij:   fnc_dev_Ds18B20
// Global variables : g_Dev.v_TempSoil,
//                    g_Dev.v_TempSubsoil values. (Degree)
//                    g_Dev.s_TempSoil,
//                    g_Dev.s_TempSubsoil char for web web
// ==============================================================
//----------------------------------
// Management DS18B20 (DallasTemperature)
// two OneWire temperature sensors
// for get soil and subsoil temperature
// connected to
// OneWire g_oneWire(PIN_ONE_WIRE_BUS);
// DallasTemperature g_Dev.g_dev_Ds18B20_2(&g_oneWire);
//----------------------------------
#ifndef  DEV_DS18B20_H
#define DEV_DS18B20_H
#include "_extern.h"

void fnc_dev_Ds18B20_Setup()
{
  g_Dev.t_Ds18B20_Count = g_device_Ds18B20.getDeviceCount();
}
void fnc_dev_DS18B20_Read() {
  
  g_device_Ds18B20.requestTemperatures();
  g_Dev.v_TempSoil = g_device_Ds18B20.getTempCByIndex(0);
  g_Dev.v_TempSubsoil = g_device_Ds18B20.getTempCByIndex(1);
  snprintf(g_Dev.s_TempSubsoil, sizeof(g_Dev.s_TempSubsoil) , "%0.0f", g_Dev.v_TempSoil);
  snprintf(g_Dev.s_TempSoil, sizeof(g_Dev.s_TempSoil) , "%0.0f", g_Dev.v_TempSubsoil);
 
}

#endif
