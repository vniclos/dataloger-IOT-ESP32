// ====================================
// dev_bh1750.h 
// device Light sensor lux
// device dev_bh1750 functions 
// function prefij:         fnc_dev_bh1750
// Global variables prefij: g_Dev.v_Lux values
//                          g_Dev.s_Lux char for web web
//=====================================

#ifndef DEV_BH1750_H
#define DEV_BH1750_H
/*
  --------------------|--------|--------|-
  DEVICE              | BH1750 | ESP32  |
  --------------------|--------|--------|-
  I2C SDA             | SDA    | 21     |
  I2C SLC             | SLC    | 22     |
  GND                 | GND    | GND    |
  VCCC                | VCC    | 3.3V   |
  ADD notconnected or | ADD    |        |
  --------------------|--------|--------|-
*/
#define BH1750_ADDRESS_L       0x23
#define BH1750_ADDRESS_H       0x5C

const char g_dev_bh1750_MSG_00003[] = "3 Night, without artificial lighting";
const char g_dev_bh1750_MSG_00020[] = "20 night, very dark street";
const char g_dev_bh1750_MSG_00040[] = "40 sunset, dark street";
const char g_dev_bh1750_MSG_00100[] = "100 very dark ovecast,light streets";
const char g_dev_bh1750_MSG_00200[] = "200 Dark cloudy day";
const char g_dev_bh1750_MSG_00400[] = "400 Sunrise, sunset, offices";
const char g_dev_bh1750_MSG_01000[] = "1000 Overcast day";
const char g_dev_bh1750_MSG_10000[] = "10000 Sunny, great shading";
const char g_dev_bh1750_MSG_25000[] = "25000 Sunny not direct sun";
const char g_dev_bh1750_MSG_32000[] = "32000  Sunny, direct sun";
const char g_dev_bh1750_MSG_32001[] = ">32000  Sunny, bright half day";

void fnc_dev_bh1750_message()
{
  int iPrevious = 0;
  if (g_Dev.v_Lux <= 3)
  {
    iPrevious = 3;

    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_00003);
  }
  else if (g_Dev.v_Lux <= 20 &&  g_Dev.v_Lux > iPrevious)
  {
    iPrevious = 20;
    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_00020);
  }
  else if (g_Dev.v_Lux <= 40 &&  g_Dev.v_Lux > iPrevious)
  {
    iPrevious = 40;
    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_00040);
  }
  else if (g_Dev.v_Lux <= 100 && g_Dev.v_Lux > iPrevious)
  {
    iPrevious = 100;
    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_00100);
  }
  else if (g_Dev.v_Lux <= 200 && g_Dev.v_Lux > iPrevious)
  {
    iPrevious = 200;
    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_00200);
  }
  else if (g_Dev.v_Lux <= 400 && g_Dev.v_Lux > iPrevious)
  {
    iPrevious = 400;
    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_00400);
  }
  else if (g_Dev.v_Lux <= 1000 &&  g_Dev.v_Lux > iPrevious)
  {
    iPrevious = 1000;
    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_01000);
  }
  else if (g_Dev.v_Lux <= 10000 &&  g_Dev.v_Lux > iPrevious)
  {
    iPrevious = 10000;
    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_10000);
  }
  else if (g_Dev.v_Lux <= 25000 &&  g_Dev.v_Lux > iPrevious)
  {
    iPrevious = 25000;
    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_25000);
  }
  else if (g_Dev.v_Lux <= 32000 &&  g_Dev.v_Lux > iPrevious)
  {
    iPrevious = 32000;
    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_32000);
  }
  else if ( g_Dev.v_Lux > iPrevious)
  {

    snprintf(g_Dev.s_LuxMsg, sizeof(g_Dev.s_LuxMsg) , "%s", g_dev_bh1750_MSG_32001);
  }
}


void fnc_dev_bh1750_Setup()
{
  /*
    Initializacion modes this change the resolution an time
    DEFINE                             LUX RESOLUTION   TIME
    BH1750_CONTINUOUS_LOW_RES_MOD      4                16ms
    BH1750_CONTINUOUS_HIGH_RES_MODE    1                120ms (Default mode)
    BH1750_CONTINUOUS_HIGH_RES_MODE_2: 0.5              120ms
    BH1750_ONE_TIME_LOW_RES_MODE       4                16ms
    BH1750_ONE_TIME_HIGH_RES_MODE      1                120ms
    BH1750_ONE_TIME_HIGH_RES_MODE_2    0.5lux           120ms

    you can use 2 different address
    Device_Address_H "0x5C"
    Device_Address_L "0x23"
    LightSensor.SetAddress(Device_Address_H);//Address 0x5C
    lightMeter.SetAddress(Device_Address_L); //Address 0x23
  */


  Wire.begin(PIN_I2C_SDA, PIN_I2C_SLC );
  //g_Dev.v_LuxMeter.begin(BH1750::0);
  g_device_LuxMeter.begin(BH1750::ONE_TIME_HIGH_RES_MODE);


}



void fnc_dev_bh1750_Read() {
  {
    g_Dev.v_Lux = g_device_LuxMeter.readLightLevel();
    snprintf(g_Dev.s_Lux, sizeof(g_Dev.s_Lux) , "%0.1f", g_Dev.v_Lux);
    fnc_dev_bh1750_message();
  /*

    Serial.print("g_Dev.v_Lux: ");
    Serial.print(g_Dev.v_Lux);
    Serial.print(" lx, level: ");
    Serial.println(g_Dev.s_LuxMsg);
 */
  }
}
#endif
