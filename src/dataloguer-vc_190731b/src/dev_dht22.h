// ==============================================================
// dev_dht22.h 
// device atmospheric preasure sensor 
// device g_device_DHT22 functions 
// function prefij:   fnc_dev_DHT22
// Global variables : g_Dev.v_HumidityAir,
//                    g_Dev.v_TempAir values. (Degree)
//                    g_Dev.s_HumidityAir,
//                    g_Dev.s_TempAir char for web web
// ==============================================================

#ifndef DEV_DHT22_H
#define DEV_DHT22_H
#include "_extern.h"
void fnc_dev_DHT22_Setup() {
  g_device_DHT22.setup(PIN_DHT, DHTesp::DHT22); //for DHT22 Connect DHT sensor to GPIO 17
}
void fnc_dev_DHT22_Read() {

  delay(g_device_DHT22.getMinimumSamplingPeriod());
  g_Dev.v_HumidityAir   = g_device_DHT22.getHumidity();
  g_Dev.v_TempAir = g_device_DHT22.getTemperature();
  snprintf(g_Dev.s_TempAir, sizeof(g_Dev.s_TempAir) , "%0.2f", g_Dev.v_TempAir);
  snprintf(g_Dev.s_HumidityAir, sizeof(g_Dev.s_HumidityAir) , "%0.2f", g_Dev.v_HumidityAir);
 
}
#endif
