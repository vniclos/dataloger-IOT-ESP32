// ====================================
// dl_sta.h
// DATALOGUER STATISTIC FUNCTIONS
// function prefij:         fnc_sta
// Global variables prefij: g_sta
//=====================================
#ifndef DL_STA_H
#define DL_STA_H
#include "_global.h"

float fnc_sta_fmin(uint32_t uiCounter, float vAnt, float vNew)
{
  if (uiCounter == 0)
  {
    return vNew;
  }
  if (vNew<-126) {return vAnt;}
  if (vAnt <= vNew)
  {
    return vAnt;
  }
  else
  {
    return vNew;
  }
}
float fnc_sta_fmax(uint32_t uiCounter, float vAnt, float vNew)
{
  if (uiCounter == 0)
  {
    return vNew;
  }
  if (vAnt >= vNew)
  {
    return vAnt;
  }
  else
  {
    return vNew;
  }
}
float fnc_sta_fAvg(uint32_t uiCounter, float vAnt, float vNew)
{
  if (uiCounter == 0)
  {
    return vNew;
  }
   if (vNew<-126) {return vAnt;}
  return ((uiCounter * vAnt + vNew) / (uiCounter + 1));
}

uint32_t fnc_sta_umin(uint32_t uiCounter, uint32_t vAnt, uint32_t vNew)
{
  if (uiCounter == 0)
  {
    return vNew;
  }
  if (vAnt <= vNew)
  {
    return vAnt;
  }
  else
  {
    return vNew;
  }
}
uint32_t fnc_sta_umax(uint32_t uiCounter, uint32_t vAnt, uint32_t vNew)
{
  if (uiCounter == 0)
  {
    return vNew;
  }
  if (vAnt >= vNew)
  {
    return vAnt;
  }
  else
  {
    return vNew;
  }
}
uint32_t fnc_sta_uAvg(uint32_t uiCounter, uint32_t vAnt, uint32_t vNew)
{
  if (uiCounter == 0)
  {
    return vNew;
  }
  return ((uiCounter * vAnt + vNew) / (uiCounter + 1));
}

void fnc_sta_Add()
{

  g_sta_yy.TempSoil_Max = fnc_sta_fmax(g_sta_yy.Counter, g_sta_yy.TempSoil_Max, g_Dev.v_TempSoil);
  g_sta_mm.TempSoil_Max = fnc_sta_fmax(g_sta_mm.Counter, g_sta_mm.TempSoil_Max, g_Dev.v_TempSoil);
  g_sta_dd.TempSoil_Max = fnc_sta_fmax(g_sta_dd.Counter, g_sta_dd.TempSoil_Max, g_Dev.v_TempSoil);

  g_sta_yy.TempSoil_Min = fnc_sta_fmin(g_sta_yy.Counter, g_sta_yy.TempSoil_Min, g_Dev.v_TempSoil);
  g_sta_mm.TempSoil_Min = fnc_sta_fmin(g_sta_mm.Counter, g_sta_mm.TempSoil_Min, g_Dev.v_TempSoil);
  g_sta_dd.TempSoil_Min = fnc_sta_fmin(g_sta_dd.Counter, g_sta_dd.TempSoil_Min, g_Dev.v_TempSoil);

  g_sta_yy.TempSoil_Avg = fnc_sta_fAvg(g_sta_yy.Counter, g_sta_yy.TempSoil_Avg, g_Dev.v_TempSoil);
  g_sta_mm.TempSoil_Avg = fnc_sta_fAvg(g_sta_mm.Counter, g_sta_mm.TempSoil_Avg, g_Dev.v_TempSoil);
  g_sta_dd.TempSoil_Avg = fnc_sta_fAvg(g_sta_dd.Counter, g_sta_dd.TempSoil_Avg, g_Dev.v_TempSoil);

  g_sta_yy.TempSubsoil_Max = fnc_sta_fmax(g_sta_yy.Counter, g_sta_yy.TempSubsoil_Max, g_Dev.v_TempSubsoil);
  g_sta_mm.TempSubsoil_Max = fnc_sta_fmax(g_sta_mm.Counter, g_sta_mm.TempSubsoil_Max, g_Dev.v_TempSubsoil);
  g_sta_dd.TempSubsoil_Max = fnc_sta_fmax(g_sta_dd.Counter, g_sta_dd.TempSubsoil_Max, g_Dev.v_TempSubsoil);

  g_sta_yy.TempSubsoil_Min = fnc_sta_fmin(g_sta_yy.Counter, g_sta_yy.TempSubsoil_Min, g_Dev.v_TempSubsoil);
  g_sta_mm.TempSubsoil_Min = fnc_sta_fmin(g_sta_mm.Counter, g_sta_mm.TempSubsoil_Min, g_Dev.v_TempSubsoil);
  g_sta_dd.TempSubsoil_Min = fnc_sta_fmin(g_sta_dd.Counter, g_sta_dd.TempSubsoil_Min, g_Dev.v_TempSubsoil);

  g_sta_yy.TempSubsoil_Avg = fnc_sta_fAvg(g_sta_yy.Counter, g_sta_yy.TempSubsoil_Avg, g_Dev.v_TempSubsoil);
  g_sta_mm.TempSubsoil_Avg = fnc_sta_fAvg(g_sta_mm.Counter, g_sta_mm.TempSubsoil_Avg, g_Dev.v_TempSubsoil);
  g_sta_dd.TempSubsoil_Avg = fnc_sta_fAvg(g_sta_dd.Counter, g_sta_dd.TempSubsoil_Avg, g_Dev.v_TempSubsoil);

  g_sta_yy.TempAir_Max = fnc_sta_fmax(g_sta_yy.Counter, g_sta_yy.TempAir_Max, g_Dev.v_TempAir);
  g_sta_mm.TempAir_Max = fnc_sta_fmax(g_sta_mm.Counter, g_sta_mm.TempAir_Max, g_Dev.v_TempAir);
  g_sta_dd.TempAir_Max = fnc_sta_fmax(g_sta_dd.Counter, g_sta_dd.TempAir_Max, g_Dev.v_TempAir);

  g_sta_yy.TempAir_Min = fnc_sta_fmin(g_sta_yy.Counter, g_sta_yy.TempAir_Min, g_Dev.v_TempAir);
  g_sta_mm.TempAir_Min = fnc_sta_fmin(g_sta_mm.Counter, g_sta_mm.TempAir_Min, g_Dev.v_TempAir);
  g_sta_dd.TempAir_Min = fnc_sta_fmin(g_sta_dd.Counter, g_sta_dd.TempAir_Min, g_Dev.v_TempAir);

  g_sta_yy.TempAir_Avg = fnc_sta_fAvg(g_sta_yy.Counter, g_sta_yy.TempAir_Avg, g_Dev.v_TempAir);
  g_sta_mm.TempAir_Avg = fnc_sta_fAvg(g_sta_mm.Counter, g_sta_mm.TempAir_Avg, g_Dev.v_TempAir);
  g_sta_dd.TempAir_Avg = fnc_sta_fAvg(g_sta_dd.Counter, g_sta_dd.TempAir_Avg, g_Dev.v_TempAir);

  g_sta_yy.HumidityAir_Max = fnc_sta_umax(g_sta_yy.Counter, g_sta_yy.HumidityAir_Max, g_Dev.v_HumidityAir);
  g_sta_mm.HumidityAir_Max = fnc_sta_umax(g_sta_mm.Counter, g_sta_mm.HumidityAir_Max, g_Dev.v_HumidityAir);
  g_sta_dd.HumidityAir_Max = fnc_sta_umax(g_sta_dd.Counter, g_sta_dd.HumidityAir_Max, g_Dev.v_HumidityAir);

  g_sta_yy.HumidityAir_Min = fnc_sta_umin(g_sta_yy.Counter, g_sta_yy.HumidityAir_Min, g_Dev.v_HumidityAir);
  g_sta_mm.HumidityAir_Min = fnc_sta_umin(g_sta_mm.Counter, g_sta_mm.HumidityAir_Min, g_Dev.v_HumidityAir);
  g_sta_dd.HumidityAir_Min = fnc_sta_umin(g_sta_dd.Counter, g_sta_dd.HumidityAir_Min, g_Dev.v_HumidityAir);

  g_sta_yy.HumidityAir_Avg = fnc_sta_uAvg(g_sta_yy.Counter, g_sta_yy.HumidityAir_Max, g_Dev.v_HumidityAir);
  g_sta_mm.HumidityAir_Avg = fnc_sta_uAvg(g_sta_mm.Counter, g_sta_mm.HumidityAir_Max, g_Dev.v_HumidityAir);
  g_sta_dd.HumidityAir_Avg = fnc_sta_uAvg(g_sta_dd.Counter, g_sta_dd.HumidityAir_Max, g_Dev.v_HumidityAir);

  g_sta_yy.HumiditySoil_Max = fnc_sta_umax(g_sta_yy.Counter, g_sta_yy.HumiditySoil_Max, g_Dev.v_HumiditySoil);
  g_sta_mm.HumiditySoil_Max = fnc_sta_umax(g_sta_mm.Counter, g_sta_mm.HumiditySoil_Max, g_Dev.v_HumiditySoil);
  g_sta_dd.HumiditySoil_Max = fnc_sta_umax(g_sta_dd.Counter, g_sta_dd.HumiditySoil_Max, g_Dev.v_HumiditySoil);

  g_sta_yy.HumiditySoil_Min = fnc_sta_umin(g_sta_yy.Counter, g_sta_yy.HumiditySoil_Min, g_Dev.v_HumiditySoil);
  g_sta_mm.HumiditySoil_Min = fnc_sta_umin(g_sta_mm.Counter, g_sta_mm.HumiditySoil_Min, g_Dev.v_HumiditySoil);
  g_sta_dd.HumiditySoil_Min = fnc_sta_umin(g_sta_dd.Counter, g_sta_dd.HumiditySoil_Min, g_Dev.v_HumiditySoil);

  g_sta_yy.HumiditySoil_Avg = fnc_sta_uAvg(g_sta_yy.Counter, g_sta_yy.HumiditySoil_Avg, g_Dev.v_HumiditySoil);
  g_sta_mm.HumiditySoil_Avg = fnc_sta_uAvg(g_sta_mm.Counter, g_sta_mm.HumiditySoil_Avg, g_Dev.v_HumiditySoil);
  g_sta_dd.HumiditySoil_Avg = fnc_sta_uAvg(g_sta_dd.Counter, g_sta_dd.HumiditySoil_Avg, g_Dev.v_HumiditySoil);

  g_sta_yy.PreasureAir_Max = fnc_sta_umax(g_sta_yy.Counter, g_sta_yy.PreasureAir_Max, g_Dev.v_PreasureAirHpa);
  g_sta_mm.PreasureAir_Max = fnc_sta_umax(g_sta_mm.Counter, g_sta_mm.PreasureAir_Max, g_Dev.v_PreasureAirHpa);
  g_sta_dd.PreasureAir_Max = fnc_sta_umax(g_sta_dd.Counter, g_sta_dd.PreasureAir_Max, g_Dev.v_PreasureAirHpa);

  g_sta_yy.PreasureAir_Min = fnc_sta_umin(g_sta_yy.Counter, g_sta_yy.PreasureAir_Min, g_Dev.v_PreasureAirHpa);
  g_sta_mm.PreasureAir_Min = fnc_sta_umin(g_sta_mm.Counter, g_sta_mm.PreasureAir_Min, g_Dev.v_PreasureAirHpa);
  g_sta_dd.PreasureAir_Min = fnc_sta_umin(g_sta_dd.Counter, g_sta_dd.PreasureAir_Min, g_Dev.v_PreasureAirHpa);

  g_sta_yy.PreasureAir_Avg = fnc_sta_uAvg(g_sta_yy.Counter, g_sta_yy.PreasureAir_Avg, g_Dev.v_PreasureAirHpa);
  g_sta_mm.PreasureAir_Avg = fnc_sta_uAvg(g_sta_mm.Counter, g_sta_mm.PreasureAir_Avg, g_Dev.v_PreasureAirHpa);
  g_sta_dd.PreasureAir_Avg = fnc_sta_uAvg(g_sta_dd.Counter, g_sta_dd.PreasureAir_Avg, g_Dev.v_PreasureAirHpa);

  g_sta_yy.Lux_Max = fnc_sta_umax(g_sta_yy.Counter, g_sta_yy.Lux_Max, g_Dev.v_Lux);
  g_sta_mm.Lux_Max = fnc_sta_umax(g_sta_mm.Counter, g_sta_mm.Lux_Max, g_Dev.v_Lux);
  g_sta_dd.Lux_Max = fnc_sta_umax(g_sta_dd.Counter, g_sta_dd.Lux_Max, g_Dev.v_Lux);

  g_sta_yy.Lux_Min = fnc_sta_umin(g_sta_yy.Counter, g_sta_yy.Lux_Min, g_Dev.v_Lux);
  g_sta_mm.Lux_Min = fnc_sta_umin(g_sta_mm.Counter, g_sta_mm.Lux_Min, g_Dev.v_Lux);
  g_sta_dd.Lux_Min = fnc_sta_umin(g_sta_dd.Counter, g_sta_dd.Lux_Min, g_Dev.v_Lux);

  g_sta_yy.Lux_Avg = fnc_sta_uAvg(g_sta_yy.Counter, g_sta_yy.Lux_Avg, g_Dev.v_Lux);
  g_sta_mm.Lux_Avg = fnc_sta_uAvg(g_sta_mm.Counter, g_sta_mm.Lux_Avg, g_Dev.v_Lux);
  g_sta_dd.Lux_Avg = fnc_sta_uAvg(g_sta_dd.Counter, g_sta_dd.Lux_Avg, g_Dev.v_Lux);

  g_sta_yy.AltitudeByHpa_Max = fnc_sta_umax(g_sta_yy.Counter, g_sta_yy.AltitudeByHpa_Max, g_Dev.v_AltitudeByHpa);
  g_sta_mm.AltitudeByHpa_Max = fnc_sta_umax(g_sta_mm.Counter, g_sta_mm.AltitudeByHpa_Max, g_Dev.v_AltitudeByHpa);
  g_sta_dd.AltitudeByHpa_Max = fnc_sta_umax(g_sta_dd.Counter, g_sta_dd.AltitudeByHpa_Max, g_Dev.v_AltitudeByHpa);

  g_sta_yy.AltitudeByHpa_Min = fnc_sta_umin(g_sta_yy.Counter, g_sta_yy.AltitudeByHpa_Min, g_Dev.v_HumiditySoil);
  g_sta_mm.AltitudeByHpa_Min = fnc_sta_umin(g_sta_mm.Counter, g_sta_mm.AltitudeByHpa_Min, g_Dev.v_HumiditySoil);
  g_sta_dd.AltitudeByHpa_Min = fnc_sta_umin(g_sta_dd.Counter, g_sta_dd.AltitudeByHpa_Min, g_Dev.v_HumiditySoil);

  g_sta_yy.AltitudeByHpa_Avg = fnc_sta_uAvg(g_sta_yy.Counter, g_sta_yy.AltitudeByHpa_Avg, g_Dev.v_HumiditySoil);
  g_sta_mm.AltitudeByHpa_Avg = fnc_sta_uAvg(g_sta_mm.Counter, g_sta_mm.AltitudeByHpa_Avg, g_Dev.v_HumiditySoil);
  g_sta_dd.AltitudeByHpa_Avg = fnc_sta_uAvg(g_sta_dd.Counter, g_sta_dd.AltitudeByHpa_Avg, g_Dev.v_HumiditySoil);
  g_sta_dd.Counter++;
  g_sta_mm.Counter++;
  g_sta_yy.Counter++;
}
void fnc_sta_Stop()
{

  g_sta_FileSaveStarted = false;
}
void fnc_sta_Start()
{

  g_sta_FileSaveStarted = true;
}
void fnc_sta_Save()
{

  if (fncSD_FileExist(SD_MMC, g_SD_FileName))
  {
    // Serial.println("fncSD_appendFile ");
    fncSD_appendFile(SD_MMC, g_SD_FileName, g_SD_FileLineData);
  }
  else
  {
    // Serial.println("fncSD_writeFile new");
    fncSD_writeFile(SD_MMC, g_SD_FileName, g_SD_FileLineHead);
    delay(100);
    fncSD_appendFile(SD_MMC, g_SD_FileName, g_SD_FileLineData);
  }
}

void fnc_sta_FillData( struct struc_sta_acumulator *sta)
{



  snprintf(g_SD_FileLineData, sizeof(g_SD_FileLineData),
           "\n%s;%s;%s;%s;%s;%0.1f;%0.1f;%0.1f;%0.1f;%0.1f;%0.1f;%0.1f;%0.1f;%0.1f;%0.0f;%0.0f;%0.0f;%u;%u;%u;%u;%u;%u;%u;%u;%u;%s;%s;%s;%s",
           g_cfg.IdName,
           g_cfg.IdLocation,
           g_cfg.IdLocationGps,
           g_Dev.s_RTCDate,
           g_sta_HHMM,
           (*sta).TempAir_Min,
           (*sta).TempAir_Avg,
           (*sta).TempAir_Max,
           (*sta).TempSoil_Min,
           (*sta).TempSoil_Avg,
           (*sta).TempSoil_Max,
           (*sta).TempSubsoil_Min,
           (*sta).TempSubsoil_Avg,
           (*sta).TempSubsoil_Max,
           (*sta).HumidityAir_Min,
           (*sta).HumidityAir_Avg,
           (*sta).HumidityAir_Max,
           (*sta).HumiditySoil_Min,
           (*sta).HumiditySoil_Avg,
           (*sta).HumiditySoil_Max,
           (*sta).PreasureAir_Min,
           (*sta).PreasureAir_Avg,
           (*sta).PreasureAir_Max,
           (*sta).Lux_Min,
           (*sta).Lux_Avg,
           (*sta).Lux_Max,
           g_Dev.s_GpsAltitud,
           g_Dev.s_GpsLatiLong,
           g_Dev.s_GpsDateTime,
           g_Dev.s_GpsSatellites);
           
}


/*
void fnc_debug_interval(String TypeInterval, __uint32_t before, __uint32_t interval)
{

  if (g_sta_Interval_now - before >= interval)
  {
    Serial.print(TypeInterval);
    Serial.print(" ");

    Serial.print(g_sta_Interval_now);
    Serial.print("-");
    Serial.print(before);
    Serial.print("=");
    Serial.print(g_sta_Interval_now - before);
    Serial.print(" >= ");
    Serial.print(interval);
    Serial.print("=> ");
    Serial.println("true");
  }
}
*/
void fnc_sta_Loop_SaveIsInterval()
{
  //comprobar se hay que salvar
  if (!g_sta_FileSaveStarted)
  {
    return;
  }
  u32_t uiHH= g_device_Rtc3231Now.Hour();
  u32_t uiMM= g_device_Rtc3231Now.Minute();
  if(uiHH+uiMM==0) return; 
  if (uiMM==59 && uiHH==23) 
  { 
    uiMM=0;
    uiHH=24;
     }
  snprintf_P(g_sta_HHMM, sizeof(g_sta_HHMM), PSTR("%02u:%02u"), uiHH,uiMM);
  g_sta_Interval_now = uiHH * 60 + uiMM;
  uint32_t uiModule_yy = g_sta_Interval_now % g_sta_Interval_yy;
  uint32_t uiModule_mm = g_sta_Interval_now % g_sta_Interval_mm;
  uint32_t uiModule_dd = g_sta_Interval_now % g_sta_Interval_dd;

  // overflow counter -> reset

  if (uiModule_dd == 0 && g_sta_Interval_now != g_sta_Interval_dd_before)
  {
    //fnc_debug_interval("dd", g_sta_Interval_dd_before, g_sta_Interval_dd);
    fnc_sta_FillData( &g_sta_dd );
    sprintf(g_SD_FileName, "/%04d%02d%02ddd.csv", g_device_Rtc3231Now.Year(), g_device_Rtc3231Now.Month(), g_device_Rtc3231Now.Day());
    fnc_sta_Save();
    g_sta_dd.Counter = 0;
    g_sta_Interval_dd_before = g_sta_Interval_now;
  }
  if (uiModule_mm == 0 && g_sta_Interval_now != g_sta_Interval_mm_before)
  {
    //fnc_debug_interval("mm", g_sta_Interval_mm_before, g_sta_Interval_mm);
    fnc_sta_FillData( &g_sta_mm );
    sprintf(g_SD_FileName, "/%04d%02dmm.csv", g_device_Rtc3231Now.Year(), g_device_Rtc3231Now.Month());
    fnc_sta_Save();
    g_sta_mm.Counter = 0;
    g_sta_Interval_mm_before = g_sta_Interval_now;
  }
  if (uiModule_yy == 0 && g_sta_Interval_now != g_sta_Interval_yy_before)
  {
    //fnc_debug_interval("yy", g_sta_Interval_yy_before, g_sta_Interval_yy);
     fnc_sta_FillData( &g_sta_yy );
    sprintf(g_SD_FileName, "/%04dyy.csv", g_device_Rtc3231Now.Year());
    fnc_sta_Save();
    g_sta_yy.Counter = 0;
    g_sta_Interval_yy_before = g_sta_Interval_now;
  }
}

#endif
