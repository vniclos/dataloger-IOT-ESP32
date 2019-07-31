#ifndef GLOBAL_H
#define GLOBAL_H
#include "_defines.h"
//=============================================
//
//=============================================
char g_MsgLast[40] = "/0"; // last message
// variables wifi en uso se cargan al arrancar dependiendo
struct  strucCfgInUse
{
char software[128] = "/0";
char wifi_host[LEN_CFG_WIFIHOST] = "/0";
char wifi_Mode[LEN_CFG_WIFIMODE] = "/0"; // ap , ws
char wifi_Ssid[LEN_CFG_WIFISIID] = "/0";
char wifi_Pwd[LEN_CFG_WIFIPWD] = "/0";
char wifi_IP[LEN_CFG_WIFIIP] = "/0";
char web_UrlRoot[LEN_WEB_URLROOT] = "\0";
};
strucCfgInUse g_CfgInUse;
// for keep last read values and conversion to char
// for use in website...
struct strucDevices
{
float    v_TempSoil = 0;
float    v_TempSubsoil = 0;
float    v_TempAir = 0;
float    v_HumidityAir = 0;
uint32_t v_HumiditySoil = 0;
float    v_PreasureAirHpa = 0; //1 milibar = 1 hPa).
float    v_AltitudeByHpa = 0;
float    v_Lux = 0;
bool v_gpsIsConnected = false;
bool v_gpsIsReadAltitude = false;
bool v_gpsIsReadLocation = false;
bool v_gpsIsReadTime = false;
bool v_gpsIsReadDate = false;
bool v_gpsIsReadAll = false;
//  char values for web site
char s_RTCDateTime[LEN_DL_RTCDATETIME] = "\0";
char s_RTCDate[LEN_DL_RTCDATE] = "\0";
char s_RTCTime[LEN_DL_RTCTIME] = "\0";
char s_Lux[LEN_DL_LUX] = "/0";
char s_LuxMsg[LEN_DL_LUXMSG] = "\0";
char s_TempAir[LEN_DL_TempAir] = "\0";
char s_TempSubsoil[LEN_DL_TEMPSOIL] = "\0";
char s_TempSoil[LEN_DL_TEMPSUBSOIL] = "\0";
char s_HumidityAir[LEN_DL_HUMIDITYAIR] = "\0";
char s_HumiditySoil[LEN_DL_HUMIDITYSOIL] = "\0";
char s_PreasureAirHpa[LEN_DL_PREASUREAIRHPA] = "\0";
char s_AltitudeByHpa[LEN_DL_ALTITUDEBYHPA] = "\0"; //
char s_GpsAltitud[LEN_DL_GPSALTITUDE] = "\0";
char s_GpsLatiLong[LEN_DL_GPSLATILONG] = "\0";
char s_GpsDateTime[LEN_DL_GPSDATETIME] = "\0";
char s_GpsSatellites[LEN_DL_GPSSATELLITES] = "\0";
char s_UrlMap[60] = "/0";
char s_UrlMap_start[35] = "http://www.google.com/maps/place/";
// for control interval read sensors and other
bool          t_gps_gpsLookFor = true;
uint32_t      t_gps_gpsTryCount = 0;
uint32_t      t_gps_iCountFill = 0;
uint32_t      t_IntervalCounter = 0;
uint32_t      t_IntervalRead = SNS_INTERVALREAD; // read sensors
uint32_t      t_IntervalBefore = 0;
uint32_t      t_IntervalAct = millis();
bool          t_RtcError = false; // flag if rtd not run (Battery)?
int           t_Ds18B20_Count = 0;

}; 
strucDevices g_Dev;

struct struc_configuration
{
char IdName[LEN_CFG_IDNAME] = "\0";
char IdLocation[LEN_CFG_IDLOCATION] = "\0";
char IdLocationGps[LEN_CFG_IDLOCATIONGPS] = "\0"; // decimal format 1.2342342
char WifiMode[LEN_CFG_WIFIMODE] = "\0";     // wifimode
char WifiApSiid[LEN_CFG_WIFIAPSIID] = "\0"; // luego se añade 4 digitos de la targeta para nombre unico
char WifiApPwd[LEN_CFG_WIFIAPPWD] = "\0";   // luego se añade 4 digitos de la targeta para nombre unico
char WifiApSiidEnd[LEN_CFG_WIFIAPSIIDEND] = "\0";
char WifiWsSiid[LEN_CFG_WIFIWSSIID] = "\0";
char WifiWsPwd[LEN_CFG_WIFIWSPWD] = "\0";
char WifiWsIPDHCP[LEN_CFG_WIFIWSIPDHCP] = "\0";
char WifiWsIP[LEN_CFG_WIFIWSIP] = "\0";
char WifiWsIPMsk[LEN_CFG_WIFIWSIPMSK] = "\0";
char WifiWsIPGat[LEN_CFG_WIFIWSIPGAT] = "\0";
char WifiWsDns1[LEN_CFG_WIFIWSDNS1] = "\0";
char WifiWsDns2[LEN_CFG_WIFIWSDNS2] = "\0";
char ChgDate[11] = "\0";
char ChgTime[9] = "\0";
char Mac4[5]= "\0";
};
struc_configuration g_cfg;

struct struc_sta_acumulator
{
  uint32_t Counter;
  float TempSoil_Min=0;
  float TempSoil_Avg=0;
  float TempSoil_Max=0;
  float TempSubsoil_Min=0;
  float TempSubsoil_Avg=0;
  float TempSubsoil_Max=0;
  float TempAir_Min=0;
  float TempAir_Avg=0;
  float TempAir_Max=0;
  float HumidityAir_Min=9999999999.9;
  float HumidityAir_Avg=0;
  float HumidityAir_Max=0;
  uint32_t HumiditySoil_Min=0;
  uint32_t HumiditySoil_Avg;
  uint32_t HumiditySoil_Max;
  uint32_t PreasureAir_Min=0;
  uint32_t PreasureAir_Avg=0;
  uint32_t PreasureAir_Max=0;
  uint32_t Lux_Min=0;
  uint32_t Lux_Avg=0;
  uint32_t Lux_Max=0;
  uint32_t AltitudeByHpa_Min=0;
  uint32_t AltitudeByHpa_Avg=0;
  uint32_t AltitudeByHpa_Max=0;
  
};
char g_sta_HHMM[6] = "/0";  
struc_sta_acumulator g_sta_yy;
struc_sta_acumulator g_sta_mm;
struc_sta_acumulator g_sta_dd;
#define _STA_TEST
#ifdef _STA_TEST
__uint32_t g_sta_Interval_yy = 15;// 24 *60 ;  // 24h
__uint32_t g_sta_Interval_mm = 10;// 6  * 60;   //  6h
__uint32_t g_sta_Interval_dd = 5;//30;       //    1/2h

#elif
__uint32_t g_sta_Interval_yy =  24 *60 ;  // 24h
__uint32_t g_sta_Interval_mm =  6  * 60;   //  6h
__uint32_t g_sta_Interval_dd = 30;       //    1/2h
#endif
__uint32_t g_sta_Interval_yy_before = 0; // 24h
__uint32_t g_sta_Interval_mm_before = 0; //  6h
__uint32_t g_sta_Interval_dd_before = 0; //    1/2h
__uint32_t g_sta_Interval_now = 0;

bool g_sta_FileSaveStarted = true;
char g_SD_FileName[LEN_FILELINE] = "\0";
char g_SD_FileLineData[LEN_FILELINE] = "\0";
bool g_SD_Reader_enable = false;
bool g_SD_enable = false;
char g_SD_type[16] = "/0";
char g_SD_size[16] = "/0";
char g_SD_FileLineHead[] = "Id_Name;Id_Location;Id LocationGps;Date;Time;TempAir_min;TempAir_avg;TempAir_Max;TempSoil_Min;TempSoil_Avg;TempSoil_Max;TempSubsoil_Min;TempSubsoil_Avg;TempSubsoil_Max;HumidityAir_Min;HumidityAir_Avg;HumidityAir_Max;HumiditySoil_Min;HumiditySoil_Avg;HumiditySoil_Max;PreasureAirHpa_Min;PreasureAirHpa_Avg;PreasureAirHpa_Max;Lux_MinLux_Avg; Lux_Max;AltitudeByHpa;GpsAltitud;GpsLatiLong;_GpsDateTime;GpsSatellites";
bool g_SD_FileSaveStarted = true;             // control del salvado del datalog

Cls_Utils *g_Utils = Cls_Utils::Instance();
DNSServer g_DnsServer;
ClsMyWebServer g_server(80); 
HardwareSerial g_device_GpsSerial(1); // gps Serial Port
TinyGPSPlus g_device_Gps;             // decode gps fields
RtcDS3231<TwoWire> g_device_Rtc3231(Wire);
RtcTemperature g_device_Rtc3231Temp; // clock temperature
RtcDateTime g_device_Rtc3231Now;     // clock
Adafruit_BMP085 g_device_BMP180; //preasure
DHTesp g_device_DHT22;           // dht22 temp & air humi
OneWire g_device_oneWire(PIN_ONE_WIRE_BUS);
DallasTemperature g_device_Ds18B20(&g_device_oneWire); //temp soil, subsoil
BH1750 g_device_LuxMeter;                                   // default
CapacitiveMoisture g_device_CapMoisture = CapacitiveMoisture();
hw_timer_t *g_WDT_timer = NULL;
volatile SemaphoreHandle_t g_WDT_Semaphore;
portMUX_TYPE g_WDT_PortMux = portMUX_INITIALIZER_UNLOCKED;

#endif
