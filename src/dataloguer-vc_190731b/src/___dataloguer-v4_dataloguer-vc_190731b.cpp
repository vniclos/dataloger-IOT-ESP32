   /*
-------------------------------------------
   TODO 
-------------------------------------------
1    LEER SENSORES
1.1  OK RTC
1.1  OK fnc_dev_rtc3231_Read();
1.2  OK fnc_dev_DS18B20_Read();
1.3  OK fnc_dev_Ldr_Read ();
1.4  OK fnc_dev_BMP180_Read(); // change unit /100
1.5  OK fnc_dev_DHT22_Read (); // Change in read 
1.6  OK fnc_dev_SoilHumi_Read (); 
1.7  OK GPS----------------------aqui
1.9  XX BOTON RESET FACTORY
1.10 OK Solar power
2.1  OK Web show sensor values in main
2.2  OK Web start dataloguer
2.3  OK Web stop dataloguer
2.4  OK Web config
2.5  OK Web download dataloguer files
2.6  OK Web delete dataloguer file
2.7  xx Web help
2.8  OL Web charts vectorial day
2.9  xx WEB chart vectorial month
2.10 OK Web chart vectorial year
3.-  xx hitgub upload software
3.1  xx Squematic pcb
3.1  xx squematic Software
3.2  xx Guide 

//-------------------------------------------
*/
#include <Arduino.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "ClsMyWebServer.h"

#include <DNSServer.h>

#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "FS.h"
#include "SD_MMC.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <RtcDS3231.h>
#include <TinyGPS++.h>
#include  <HardwareSerial.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <BH1750.h>
#include "DHTesp.h"
//#include <driver/adc.h>
#include "_defines.h"
#include "Cls_Utils.h"
#include "CapacitiveMoisture.h"
#include "_global.h"
#include "_debug.h"
#include "dev_sd.h"           // management sdcard 
#include "dl_sta.h"           // dataloguer  stadistic
#include "_config.h"
#include "dev_wifi.h"         // management wifi connections
#include "dev_wdt.h"          // management watch dog
#include "dev_rtcds32331.h"   // management rtc clock
#include "dev_DS18B20.h"      // nanagement i2c ds12820(soil&subsoil celsius)
#include "dev_bh1750.h"       // management Light sensor BH1750
#include "dev_gps.h"          // management gps neo-m6 v2 module
#include "dev_bmp180.h"       // management bmp180 air preasure.it has too Temp, but it is not used
#include "dev_dht22.h"        // management dht22 temp and humi of air.
#include "dev_soilhumy.h"     // management captacitive soil moisture
#include "dev_devices.h"          // management join devices
#include "web_handle.h"       // management web events
#include "web_root.h"         // page root
#include "web_js.h"           // javascript
#include "web_css.h"          // stylesheet   
#include "web_cfg.h"          // page config
#include "web_otaform.h"      // page ota upload
#include "web_help.h"         // page HELP TODO 
#include "web_setup.h"        // config web service
#include "web_js_apexchart.h" // svg apexchart source

#include "web_JS_Apexchart2.h"// svg apexchart get data  and draw in page charts
#include "CapacitiveMoisture.h"

void setup() {
  Serial.begin(115200);
  Serial.println("\n=====================================");
  Serial.print(FILENAME);
  Serial.print(" compiled: ");
  Serial.print(__DATE__);
  Serial.print(" ");
  Serial.println(__TIME__);
  Serial.println("\n=====================================\n");
  pinMode(PIN_LEDINT, OUTPUT);
  pinMode(PIN_RESET_FACTORY, INPUT);
  digitalWrite(PIN_RESET_FACTORY, LOW);

  g_SD_enable = fnc_dev_SD_Setup();
  fnc_Config_SetupRead();
  fnc_Wifi_Setup();
  fnc_Web_Setup();
  fnc_devices_Setup();
  fnc_devices_Read();
  fnc_sta_Start();
  fnc_WatchDog_Setup();
  
}

void loop() {
   timerWrite(g_WDT_timer, 0);      // watchdog reset lapse counter
   fnc_devices_Loop_IsInterval();   // read sensof if lapse
   fnc_sta_Loop_SaveIsInterval();   // SAVE datalog if is interval 
   g_server.handleClient();         // handle web browser clients
   ArduinoOTA.handle();             // handle upload firmware by web

}
