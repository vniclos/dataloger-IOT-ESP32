#ifndef _DEBUG
#define _DEBUG
#define RESTART_CONFIG
#include "_extern.h"
#include "_defines.h"
void fncDebugConfig( String szFrom) {

    Serial.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    Serial.print("--- fncDebugConfig start ---");
    Serial.println(szFrom);

    Serial.print("software=");
    Serial.println(g_CfgInUse.software);
    Serial.print("g_CfgInUse.wifi_host =");
    Serial.println(g_CfgInUse.wifi_host);
    Serial.print("g_CfgInUse.wifi_Mode =");
    Serial.println(g_CfgInUse.wifi_Mode);
    Serial.print("g_CfgInUse.wifi_Ssid =");
    Serial.println(g_CfgInUse.wifi_Ssid);
    Serial.print("web_UrlRoot =");
    Serial.println(g_CfgInUse.web_UrlRoot);


    Serial.print("g_wifi_IP =");
    Serial.println(g_CfgInUse.wifi_IP);

    Serial.print("g_cfgIdLocation =");
    Serial.println(g_cfg.IdLocation);
   Serial.print("g_cfgIdName =");
    Serial.println(g_cfg.IdName);
    Serial.print("g_cfgIdLocationGps =");
    Serial.println(g_cfg.IdLocationGps);



    Serial.print("g_cfgWifiMode =");
    Serial.println(g_cfg.WifiMode);
    Serial.print("g_cfg.WifiApSiid =");
    Serial.print(g_cfg.WifiApSiid);
    Serial.print("+");
    Serial.println(g_cfg.WifiApSiidEnd);
    Serial.print("g_cfgWifiApPwd =");
    Serial.println(g_cfg.WifiApPwd);
    Serial.print("g_cfgWifiWsSiid =");
    Serial.println(g_cfg.WifiWsSiid);
    Serial.print("g_cfgWifiWsPwd =");
    Serial.println(g_cfg.WifiWsPwd);
    Serial.print("g_cfgWifiWsIPDHCP =");
    Serial.println(g_cfg.WifiWsIPDHCP);
    Serial.print("g_cfgWifiWsIP =");
    Serial.println(g_cfg.WifiWsIP);
    Serial.print("g_cfgWifiWsIPMsk =");
    Serial.println(g_cfg.WifiWsIPMsk);
    Serial.print("g_cfgWifiWsIPGat =");
    Serial.println(g_cfg.WifiWsIPGat);
    Serial.print("g_cfgWifiWsDns1 =");
    Serial.println(g_cfg.WifiWsDns1);
    Serial.print("g_cfgWifiWsDns2 =");
    Serial.println(g_cfg.WifiWsDns2);

    fncConfigLineUpdate();  // for fill g_SD_FileLineData

    Serial.print("\ng_SD_FileName =");
    Serial.println(g_SD_FileName);
    Serial.print("g_SD_FileLineData = ");
    Serial.println(g_SD_FileLineData);
    sprintf(g_SD_FileName, "/%04d%02d%02d.csv", g_device_Rtc3231Now.Year(), g_device_Rtc3231Now.Month(), g_device_Rtc3231Now.Day()); // for fill full debug
    Serial.print("\ng_SD_FileName");
    Serial.println(g_SD_FileName);
    Serial.print("g_SD_FileLineHead=");
    Serial.println(g_SD_FileLineHead);
    Serial.print("g_SD_FileLineData");
    /**/
  Serial.println(g_SD_FileLineData);
  //Serial.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}
void fncDebug_temp() {


  Serial.print("g_cfgIdName" );
  Serial.println(g_cfg.IdName );
  Serial.print("g_cfgIdLocation=" );
  Serial.println(g_cfg.IdLocation );
  Serial.print("g_cfgIdLocationGps=" );
  Serial.println(g_cfg.IdLocationGps );

  Serial.print("g_Dev.s_RTCDate" );
  Serial.println(g_Dev.s_RTCDate );
  Serial.print("g_Dev.s_RTCTime" );
  Serial.println("g_Dev.v_Lux" );
  Serial.println(g_Dev.v_Lux );

  Serial.print("g_Dev.s_TempAir" );
  Serial.println(g_Dev.s_TempAir );
  Serial.print("g_Dev.s_TempSubsoil" );
  Serial.println(g_Dev.s_TempSubsoil );
  Serial.print("g_Dev.s_TempSoil" );
  Serial.println(g_Dev.s_TempSoil);
  Serial.print("g_Dev.s_HumidityAir" );
  Serial.println(g_Dev.s_HumidityAir );
  Serial.print("g_Dev.s_HumiditySoil" );
  Serial.println(g_Dev.s_HumiditySoil);
  Serial.print("g_Dev.s_PreasureAirHpa" );
  Serial.println(g_Dev.s_PreasureAirHpa);
  Serial.print("g_Dev.s_AltitudeByHpa" );
  Serial.println(g_Dev.s_AltitudeByHpa);
  Serial.print("g_Dev.s_GpsAltitud" );
  Serial.println(g_Dev.s_GpsAltitud );
  Serial.print("g_Dev.s_GpsLatiLong" );
  Serial.println(g_Dev.s_GpsLatiLong);
  Serial.print("g_Dev.s_GpsDateTime" );
  Serial.println(g_Dev.s_GpsDateTime );

  Serial.println(g_MsgLast);
  Serial.print(" " );
}


void fncDebugGps()
{
  Serial.print("g_Dev.t_gps_iCountFill=");
  Serial.println(g_Dev.t_gps_iCountFill);

  Serial.print(" g_Dev.s_GpsSatellites=");
  Serial.println( g_Dev.s_GpsSatellites);



  Serial.print("g_Dev.v_gpsIsConnected=");
  Serial.println(g_Dev.v_gpsIsConnected);
  if (!g_Dev.v_gpsIsConnected) {
    Serial.println("Gps NOT DETECTED, Where are the pins?");
  }
  Serial.print("g_Dev.v_gpsIsReadLocation=");
  Serial.println(g_Dev.v_gpsIsReadLocation);
  Serial.print("g_Dev.v_gpsIsReadAltitude=");
  Serial.println(g_Dev.v_gpsIsReadAltitude);

  Serial.print("g_Dev.v_gpsIsReadDate=");
  Serial.println(g_Dev.v_gpsIsReadDate);
  Serial.print("g_Dev.v_gpsIsReadTime=");
  Serial.println(g_Dev.v_gpsIsReadTime);


  Serial.print(" g_Dev.s_GpsLatiLong=");
  Serial.println( g_Dev.s_GpsLatiLong);
  Serial.print(" g_Dev.s_GpsAltitud=");
  Serial.println( g_Dev.s_GpsAltitud);
  Serial.print(" g_Dev.s_GpsDateTime=");
  Serial.println( g_Dev.s_GpsDateTime);
  Serial.print("URL for googlemap= ");


  Serial.println(g_Dev.s_UrlMap);
  Serial.println(".........\n");
}



void fncPrintDateTime(const RtcDateTime& dt)
{

  char datestring[20];

  snprintf_P(datestring,
             sizeof(datestring),
             PSTR("%04u/%02u/%02u %02u:%02u:%02u"),
             dt.Year(),
             dt.Month(),
             dt.Day(),

             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  Serial.print ("datestring = ");
  Serial.println(datestring);
}
#endif
