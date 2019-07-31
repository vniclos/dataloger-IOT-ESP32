// ==============================================================
// dev_gps.h
// GPS sensor        (Connected by serial)
// device object      g_device_Gps
// functions prefij:  fnc_Dev_Gps
// Global variables : g_Dev.v_gps,
//                    g_Dev.s_GpsSatellites Satellits found
//                    g_Dev.s_GpsAltitud
//                    g_Dev.s_GpsLatiLong
//                    g_Dev.s_GpsDateTime<>clock time
//                    IsReadLocation (Need more than 2 satellites)
//                    IsReadDate (Only need 1 satellite)
//                    IsReadAltitude(Need more than 3 )
//                    g_Dev.v_gpsIsConnected (test sensor)
//                    g_Dev.t_gps_iCountFill (Number of read tries,
//                    used like flag for not spend too much time)
// ==============================================================
#ifndef DEV_GPS_H
#define DEV_GPS_H
void fnc_dev_Gps_setup()
{
  g_device_GpsSerial.begin(9600, SERIAL_8N1, 16, 17);
}
#ifdef DEBUG
void fnc_Dev_Gps_PrintSerial()
{
  if (!g_Dev.v_gpsIsConnected)
  {
    Serial.print(" GPS NOT DETECTED, Where are the pins?");
  }
  else
  {
    Serial.print("GPS g_Dev.t_gps_iCountFill=");
    Serial.print(g_Dev.t_gps_iCountFill);

    Serial.print(" g_Dev.s_GpsSatellites=");
    Serial.print(g_Dev.s_GpsSatellites);
    Serial.print(" g_Dev.s_GpsLatiLong=");
    Serial.print(g_Dev.s_GpsLatiLong);
    Serial.print(" g_Dev.s_GpsDateTime=");
    Serial.print(g_Dev.s_GpsDateTime);
    Serial.print(" g_Dev.s_GpsAltitud=");
    Serial.print(g_Dev.s_GpsAltitud);

    Serial.print(" IsConnected=");
    Serial.print(g_Dev.v_gpsIsConnected);
    Serial.print(" IsReadLocation=");
    Serial.print(g_Dev.v_gpsIsReadLocation);
    Serial.print(" IsReadDate=");
    Serial.print(g_Dev.v_gpsIsReadDate);
    Serial.print(" IsReadTime=");
    Serial.print(g_Dev.v_gpsIsReadTime);
    Serial.print(" IsReadAltitude=");

    Serial.println(g_Dev.v_gpsIsReadAltitude);
    Serial.print(" g_Dev.v_gpsIsReadAll=");
    Serial.println(g_Dev.v_gpsIsReadAll);
  }
}
#endif // DEBUG
void fnc_Dev_Gps_FillFlds()
{

  g_Dev.t_gps_iCountFill++;

  unsigned int uiSat = g_device_Gps.satellites.value();
  if (uiSat > 3)
  {
    g_Dev.v_gpsIsReadAltitude = true;
  }
  snprintf(g_Dev.s_GpsSatellites, sizeof(g_Dev.s_GpsSatellites), "%zu", g_device_Gps.satellites.value());

  sprintf(g_Dev.s_GpsAltitud, "%0.0f", g_device_Gps.altitude.meters());
  if (g_device_Gps.location.isValid())
  {
    //sprintf(g_Dev.s_GpsLatiLong, "%0.6f,%0.6f",  g_device_Gps.location.lat(), g_device_Gps.location.lng());
    snprintf(g_Dev.s_GpsLatiLong, sizeof(g_Dev.s_GpsLatiLong), "%0.6f,%0.6f", g_device_Gps.location.lat(), g_device_Gps.location.lng());
    g_Dev.v_gpsIsReadLocation = true;
    strcpy(g_Dev.s_UrlMap, g_Dev.s_UrlMap_start);
    strcat(g_Dev.s_UrlMap, g_Dev.s_GpsLatiLong);
  }

  if (g_device_Gps.time.isValid() && g_device_Gps.date.isValid() && g_device_Gps.date.year() > 2018)
  {

    //  sprintf(g_Dev.s_GpsDateTime, "%04u/%02u/%02u %02u:%02u:%02u:%02u", g_device_Gps.date.year(), g_device_Gps.date.month(), g_device_Gps.date.day(),
    //          g_device_Gps.time.hour(), g_device_Gps.time.minute(), g_device_Gps.time.second(), g_device_Gps.time.second(), g_device_Gps.time.centisecond());

    snprintf(g_Dev.s_GpsDateTime, sizeof(g_Dev.s_GpsDateTime), "%04u/%02u/%02u %02u:%02u:%02u:%02u",
             g_device_Gps.date.year(),
             g_device_Gps.date.month(),
             g_device_Gps.date.day(),
             g_device_Gps.time.hour(),
             g_device_Gps.time.minute(),
             g_device_Gps.time.second(),
             g_device_Gps.time.centisecond());

    if (g_device_Gps.time.isValid())
    {
      g_Dev.v_gpsIsReadTime = true;
    }
    if (g_device_Gps.date.isValid())
    {
      g_Dev.v_gpsIsReadDate = true;
    }
  }
}
//-------------------------------------------

void fnc_dev_Gps_Read()
{
  g_Dev.v_gpsIsConnected = false;
  g_Dev.v_gpsIsReadLocation = false;
  g_Dev.v_gpsIsReadDate = false;
  g_Dev.v_gpsIsReadTime = false;
  g_Dev.v_gpsIsReadAltitude = false;
  g_Dev.v_gpsIsReadAll = false;
  g_Dev.t_gps_iCountFill = 0;
  g_Dev.t_gps_gpsLookFor = true;
  g_Dev.t_gps_gpsTryCount = 0; // flag for end seach if not find data
  while (g_Dev.t_gps_gpsLookFor)
  {
    g_Dev.t_gps_gpsTryCount++;
    //Serial.println(g_Dev.t_gps_gpsTryCount);
    while (g_device_GpsSerial.available() > 0)
    {
      if (g_device_Gps.encode(g_device_GpsSerial.read()))
      {
        g_Dev.v_gpsIsConnected = true;
        fnc_Dev_Gps_FillFlds();
#ifdef DEBUG
        fnc_Dev_Gps_PrintSerial();
#endif
      }
    } // end while 2
    if (millis() > 5000 && g_device_Gps.charsProcessed() < 10)
    {
      g_Dev.v_gpsIsConnected = false;
#ifdef DEBUG
      Serial.println(F("No GPS detected: check wiring."));
#endif
      while (true)
        ;
    }

    // if all data filled force exit
    if (g_Dev.v_gpsIsReadAltitude && g_Dev.v_gpsIsReadLocation && g_Dev.v_gpsIsReadTime && g_Dev.v_gpsIsReadDate && g_Dev.v_gpsIsReadAltitude)
    {
#ifdef DEBUG
      Serial.println("GPS All data filled, stop search");
#endif                                // DEBUG
      g_Dev.t_gps_gpsLookFor = false; // if fill all data not continue search
      g_Dev.v_gpsIsReadAll = true;
    }
    // if too many time for get data force exit
    if (GPS_READ_TRIES < g_Dev.t_gps_gpsTryCount)
    {
#ifdef DEBUG
      Serial.println("Gps end for max tries");
#endif
      g_Dev.t_gps_gpsLookFor = false;
    }
  } // end while 1
}
void fnc_dev_Gps_Read_IsInteval(u32_t uiHH, u32_t uiMM)
{
  if (uiMM == g_device_Rtc3231Now.Minute() && uiHH == g_device_Rtc3231Now.Hour())
  {
    fnc_dev_Gps_Read();
  }
}
#endif
