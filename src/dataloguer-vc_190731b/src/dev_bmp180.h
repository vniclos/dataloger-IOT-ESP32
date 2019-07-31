// ==============================================================
// dev_bmp180.h 
// device atmospheric preasure sensor 
// device dev_bh1750 functions 
// function prefij:   fnc_dev_BMP180
// Global variables : g_Dev.s_PreasureAirHpa,
//                    g_Dev.v_AltitudeByHpa values.
//                    g_Dev.s_PreasureAirHpa,
//                    g_Dev.s_AltitudeByHpa char for web web
// ==============================================================

#ifndef DEV_BMP180_H
#define DEV_BMP180_H
#include "_extern.h"
void fnc_dev_BMP180_Setup() {
  unsigned int iCount=0;
  if (!g_device_BMP180.begin()) {
    
    Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
    while (1) {
    //  if ( iCount == 5000 ) break; 
      iCount++;}
  }
}

void fnc_dev_BMP180_Read() {
  // temperature read from dht22
  
  g_Dev.v_PreasureAirHpa = g_device_BMP180.readPressure()/100;
  g_Dev.v_AltitudeByHpa = g_device_BMP180.readAltitude();
  snprintf(g_Dev.s_PreasureAirHpa, sizeof(g_Dev.s_PreasureAirHpa) , "%0.0f", g_Dev.v_PreasureAirHpa);
  snprintf(g_Dev.s_AltitudeByHpa, sizeof(g_Dev.v_AltitudeByHpa) , "%0.0f", g_Dev.v_AltitudeByHpa);

}


#endif
