// ==============================================================
// dev_rtcds32331.h 
// Management device RTC3231(clock)      
// Device object      g_device_Rtc3231 
// Functions prefij:  fnc_dev_rtc3231
// Global variables : g_device_Rtc3231Now,
//                    g_device_Rtc3231Temp 
//                    g_Dev.s_RTCDateTime
//                    g_Dev.s_RTCDate
//                    g_Dev.s_RTCTime<>clock time
//                   
// ==============================================================
//----------------------------

//---------------------------
#ifndef RTCDS3231_H
#define RTCDS3231_H
#include "_extern.h"
void fnc_dev_rtc3231_Read() {
  
  if (!g_device_Rtc3231.IsDateTimeValid())
  {
    g_Dev.t_RtcError = true;
  } else  {
    g_Dev.t_RtcError = false;
  }
  g_device_Rtc3231Now = g_device_Rtc3231.GetDateTime();    //get the time from the RTC
  g_device_Rtc3231Temp = g_device_Rtc3231.GetTemperature();
  //g_Dev.s_SaveMinuteAct = g_device_Rtc3231Now.Hour() * 60 + g_device_Rtc3231Now.Minute();
  snprintf_P(g_Dev.s_RTCDateTime,
             sizeof(g_Dev.s_RTCDateTime),
             PSTR("%04u/%02u/%02u %02u:%02u:%02u"),
             g_device_Rtc3231Now.Year(),
             g_device_Rtc3231Now.Month(),
             g_device_Rtc3231Now.Day(),

             g_device_Rtc3231Now.Hour(),
             g_device_Rtc3231Now.Minute(),
             g_device_Rtc3231Now.Second() );
 snprintf_P(g_Dev.s_RTCDate,
             sizeof(g_Dev.s_RTCDate),
             PSTR("%04u/%02u/%02u"),
             g_device_Rtc3231Now.Year(),
             g_device_Rtc3231Now.Month(),
             g_device_Rtc3231Now.Day());
 snprintf_P(g_Dev.s_RTCTime,
             sizeof(g_Dev.s_RTCTime),
             PSTR("%02u:%02u:%02u"),
             g_device_Rtc3231Now.Hour(),
             g_device_Rtc3231Now.Minute(),
             g_device_Rtc3231Now.Second());
}
void fnc_dev_rtc3231_Set(int8_t yyyy, int8_t mm, int8_t dd, int8_t hh, int8_t mi, int8_t ss) {
  RtcDateTime newDateTime(yyyy, mm, dd, hh, mi, 00);
  g_device_Rtc3231.SetDateTime(newDateTime);
  g_device_Rtc3231Now = g_device_Rtc3231.GetDateTime();
}
void fnc_dev_rtc3231_Setup() {
  //Serial.println("Aqui: fnc_dev_rtc3231_Setup");
  g_device_Rtc3231.Begin();
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  fncPrintDateTime(compiled);

  Serial.println();
  if (!g_device_Rtc3231.IsDateTimeValid())
  {
    if (g_device_Rtc3231.LastError() != 0)
    {
      // we have a communications error
      // see https://www.arduino.cc/en/Reference/WireEndTransmission for
      // what the number means
      Serial.print("RTC communications error = ");
      Serial.println(g_device_Rtc3231.LastError());
    }
    else
    {
      // Common Cuases:
      //    1) first time you ran and the device wasn't running yet
      //    2) the battery on the device is low or even missing

      Serial.println("RTC lost confidence in the DateTime!");

      // following line sets the RTC to the date & time this sketch was compiled
      // it will also reset the valid flag internally unless the Rtc device is
      // having an issue

      g_device_Rtc3231.SetDateTime(compiled);
    }
  }

  if (!g_device_Rtc3231.GetIsRunning())
  {
    Serial.println("RTC was not actively running, starting now");
    g_device_Rtc3231.SetIsRunning(true);
  }

  RtcDateTime now = g_device_Rtc3231.GetDateTime();
  if (now < compiled)
  {
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    g_device_Rtc3231.SetDateTime(compiled);
  }
  else if (now > compiled)
  {
    Serial.println("RTC is newer than compile time. (this is expected)");
  }
  else if (now == compiled)
  {
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }

  // never assume the Rtc was last configured by you, so
  // just clear them to your needed state
  
  g_device_Rtc3231.Enable32kHzPin(false);
  
  g_device_Rtc3231.SetSquareWavePin(DS3231SquareWavePin_ModeNone);
  
}

#endif
