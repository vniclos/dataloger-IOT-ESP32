
#ifndef _DEFINES_H
#define _DEFINES_H
#include <string.h>
// if DEBUG is defines send data to serial
#define DEBUG
//-------------------------------------------------
// CONFIG_RESET_ONSTART on start force on start
// reset config.txt with default values.
// comment this define  in explotation or
// the user will lost his config preferences
//#define CONFIG_RESET_ONSTART
//----------------------------------------------------
/*
  ---------------------------------------------
  DEVICE              PIN  | ESP32  | NOTES
  ------------------|------|--------|------
  SD_               | D0   |  2     | SD CARD READER
  SD_               | D1   |  4     |
  SD_               | D2   | 12     |
  SD_               | D3   | 13     |
  SD_               | CLK  | 14     |
  SD_               | CMD  | 15     |
  GPS               | TX   | 16     | RX2
  GPS               | RX   | 17     | TX2
  I2C SDA           |      | 21     | DS3231 ,BMP180, BH1750
  I2C SLC           |      | 22     | DS3231 ,  , BH1750
  PIN_DHT           |      | 23     | SHT22
  PIN_RESET_FACTORY |      | 34     | If presed on start
  PIN_ONE_WIRE_BUS  |      | 32     | DS18B20 DallasTemperature
  PIN_CAPTATIVESOIL |      | 35     | Soil humidity
  PIN_LDR           |      | 36     | LDR RESISTENCE (Light)
  // --------------------------------------

*/
#define PIN_LEDINT         2
#define PIN_RX_GPS        16
#define PIN_TX_GPS        17
#define PIN_I2C_SDA       21
#define PIN_I2C_SLC       22
#define PIN_DHT           23
#define PIN_RESET_FACTORY 25
#define PIN_ONE_WIRE_BUS  32
#define PIN_CAPTATIVESOIL 35
#define PIN_LDR           36



#define CAPACITIVE_CALIBRATE_MIN 2250 // water
#define CAPACITIVE_CALIBRATE_MAX 3900 // dray

// GPS_READ_TRIES for read gps, if not all data is
// recived, may be gps is not in good locaction or
// not satellital coberture
#define GPS_BAUDS 9600
#define GPS_PARITY SERIAL_8N1
#define GPS_READ_TRIES 500
#define GPS_INTERVALREAD  1000

#define SNS_INTERVALREAD   10000     //100000;
#define WTD_INTERVAL     4000000    // 80mhz 1.000.000 = 1 segundo
#define DL_INTERVALSAVE        5     //minutes

#define LEN_FILELINE            256
#define LEN_FILENAME             17
#define LEN_CFG_WIFIHOST         32
#define LEN_CFG_WIFIIP           17
#define LEN_CFG_WIFISIID         32
#define LEN_CFG_WIFIPWD          32
#define LEN_CFG_IDNAME           32  // used too in DL
#define LEN_CFG_IDLOCATION       32  // used too in DL
#define LEN_CFG_IDLOCATIONGPS    32  // used too in DL
#define LEN_CFG_WIFIMODE          3
#define LEN_CFG_WIFIAPSIID        LEN_CFG_WIFISIID
#define LEN_CFG_WIFIAPSIIDEND     5
#define LEN_CFG_WIFIAPPWD         LEN_CFG_WIFIPWD
#define LEN_CFG_WIFIWSSIID        LEN_CFG_WIFISIID
#define LEN_CFG_WIFIWSPWD         LEN_CFG_WIFIPWD
#define LEN_CFG_WIFIWSIPDHCP      2
#define LEN_CFG_WIFIWSIP          LEN_CFG_WIFIIP
#define LEN_CFG_WIFIWSIPMSK       LEN_CFG_WIFIIP
#define LEN_CFG_WIFIWSIPGAT       LEN_CFG_WIFIIP
#define LEN_CFG_WIFIWSDNS1        LEN_CFG_WIFIIP
#define LEN_CFG_WIFIWSDNS2        LEN_CFG_WIFIIP

const byte DNS_PORT = 53;

#define    WIFIMODE_WS "ws" //  workstation
#define    WIFIMODE_AP "ap" //  accesspoint
#define    WIFIWSIPDHCP_ONOF  "0"

// The Values in use
// depend of config, of config,
// values saved, and if  config fail.

// Default values for first start and
// reset factory

#define CFG_WIFIHOST      "dataloguer"     // no lo confitura el usuario
#define CFG_WIFIAPIP      "192.168.1.1"   // no lo configura el usuario
#define CFG_WIFIAPMASK    "255.255.255.0" // no lo configura usuario
#define CFG_FILENAME      "/config.txt"
#define CFG_IDNAME   "No Name"
#define CFG_IDLOCATION  "No Location"
#define CFG_IDLOCATIONGPS           "0.0,0.0"
#define CFG_WIFIMODE      "ws"            //ap=accespoint  ws=workstation
#define CFG_WIFIAPSIID    "dataloguer"
#define CFG_WIFIAPPWD     "123456789"
// #define CFG_WIFIAPSIIDEND read of chip
#define CFG_WIFIWSSIID    "testudines"
#define CFG_WIFIWSPWD     "915265ABCD"
#define CFG_WIFIWSIPDHCP  "0"
#define CFG_WIFIWSIP      "192.168.1.10"
#define CFG_WIFIWSIPMSK   "255.255.255.0"
#define CFGWIFIWSIPGAT   "192.168.1.1"
#define CFG_WIFIWSDNS1    "8.8.8.8"
#define CFG_WIFIWSDNS2    "8.8.4.4"

// remember 1+ for end '/0'

#define LEN_WEB_URLROOT          32 
#define LEN_DL_RTCDATE           12
#define LEN_DL_RTCTIME           10
#define LEN_DL_RTCDATETIME       23
#define LEN_DL_TempAir           10
#define LEN_DL_TEMPSOIL          10
#define LEN_DL_TEMPSUBSOIL       10
#define LEN_DL_HUMIDITYAIR       10
#define LEN_DL_HUMIDITYSOIL      10
#define LEN_DL_PREASUREAIRHPA    10
#define LEN_DL_LUX               10
#define LEN_DL_LUXMSG            32
#define LEN_DL_ALTITUDEBYHPA     10
#define LEN_DL_GPSALTITUDE       10
#define LEN_DL_GPSLATILONG       21
#define LEN_DL_GPSDATETIME       22
#define LEN_DL_GPSSATELLITES      4


#define FILENAME ({ \
    const char* filename_start = __FILE__; \
    const char* filename = filename_start; \
    while(*filename != '\0') \
      filename++; \
    while((filename != filename_start) && (*(filename - 1) != '\\')) \
      filename--; \
    filename; })
#endif
