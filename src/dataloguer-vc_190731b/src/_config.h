//--------------------------------
// _config.h
// management config file
//---------------------------------
#ifndef _CONFIG_H
#define _CONFIG_H

void fncSetupFactoryValues()
{
  Serial.println("fncSetupFactoryValues ");
  sprintf(g_CfgInUse.software, "%s %s %s", FILENAME, __TIME__, __DATE__);
  uint64_t chipid = ESP.getEfuseMac();      //The chip ID is essentially its MAC address(length: 6 bytes).
  uint16_t chip = (uint16_t)(chipid >> 32); //print High 2 bytes

  //uint64_t chipid=ESP.getEfuseMac();//The chip ID is essentially its MAC address(length: 6 bytes).
  //Serial.printf("ESP32 Chip ID = %04X",(uint16_t)(chipid>>32));//print High 2 bytes

  snprintf(g_SD_FileName, LEN_FILENAME, "%s", CFG_FILENAME);
  snprintf(g_cfg.IdName, LEN_CFG_IDNAME, "%s", CFG_IDNAME);
  snprintf(g_cfg.IdLocation, LEN_CFG_IDLOCATION, "%s", CFG_IDLOCATION);
  snprintf(g_cfg.IdLocationGps, LEN_CFG_IDLOCATIONGPS, "%s", CFG_IDLOCATIONGPS);
  snprintf(g_cfg.WifiMode, LEN_CFG_WIFIMODE, "%s", CFG_WIFIMODE);
  snprintf(g_cfg.WifiApSiid, LEN_CFG_WIFIAPSIID, "%s", CFG_WIFIAPSIID);
  snprintf(g_cfg.WifiApPwd, LEN_CFG_WIFIAPPWD, "%s", CFG_WIFIAPPWD);
  //  snprintf(g_cfgWifiApSiidEnd, 5, "%04X", chip);
  snprintf(g_cfg.WifiApSiidEnd, LEN_CFG_WIFIAPSIIDEND, "%04X", chip);

  snprintf(g_cfg.WifiWsSiid, LEN_CFG_WIFIWSSIID, "%s", CFG_WIFIWSSIID);
  snprintf(g_cfg.WifiWsPwd, LEN_CFG_WIFIWSPWD, "%s", CFG_WIFIWSPWD);
  snprintf(g_cfg.WifiWsIPDHCP, LEN_CFG_WIFIWSIPDHCP, "%s", CFG_WIFIWSIPDHCP);
  snprintf(g_cfg.WifiWsIP, LEN_CFG_WIFIWSIP, "%s", CFG_WIFIWSIP);
  snprintf(g_cfg.WifiWsIPMsk, LEN_CFG_WIFIWSIPMSK, "%s", CFG_WIFIWSIPMSK);
  snprintf(g_cfg.WifiWsIPGat, LEN_CFG_WIFIWSIPGAT, "%s", CFGWIFIWSIPGAT);
  snprintf(g_cfg.WifiWsDns1, LEN_CFG_WIFIWSDNS1, "%s", CFG_WIFIWSDNS1);
  snprintf(g_cfg.WifiWsDns2, LEN_CFG_WIFIWSDNS2, "%s", CFG_WIFIWSDNS2);

  snprintf(g_CfgInUse.wifi_host, LEN_CFG_WIFIHOST, "%s", CFG_WIFIHOST);
  snprintf(g_CfgInUse.wifi_Mode, LEN_CFG_WIFIMODE, "%s", CFG_WIFIMODE);
  snprintf(g_CfgInUse.wifi_Ssid, LEN_CFG_WIFIAPSIID, "%s", CFG_WIFIAPSIID);
  snprintf(g_CfgInUse.wifi_Pwd, LEN_CFG_WIFIAPPWD, "%s", CFG_WIFIAPPWD);
  snprintf(g_CfgInUse.wifi_IP, LEN_CFG_WIFIIP, "%s", CFG_WIFIAPIP);
  //fncDebugConfig("Read from fncSetupFactoryValues");
  Serial.println("at end of fncSetupFactoryValues");
  fncConfigLineUpdate();
}
void fncConfigLineUpdate()
{
  Serial.println("Aqui: fncConfigLineUpdate");
  g_device_Rtc3231Now = g_device_Rtc3231.GetDateTime();
  snprintf(g_SD_FileLineData, sizeof(g_SD_FileLineData),
  "%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%s#%04d-%02d-%02d#%02d:%02d:00#%s",
          g_cfg.IdName,
          g_cfg.IdLocation,
          g_cfg.IdLocationGps,
          g_cfg.WifiMode,
          g_cfg.WifiApSiid,
          g_cfg.WifiApPwd,
          g_cfg.WifiWsSiid,
          g_cfg.WifiWsPwd,
          g_cfg.WifiWsIPDHCP,
          g_cfg.WifiWsIP,
          g_cfg.WifiWsIPMsk,
          g_cfg.WifiWsIPGat,
          g_cfg.WifiWsDns1,
          g_cfg.WifiWsDns2,
          g_device_Rtc3231Now.Year(),
          g_device_Rtc3231Now.Month(),
          g_device_Rtc3231Now.Day(),
          g_device_Rtc3231Now.Hour(),
          g_device_Rtc3231Now.Minute(),
          g_cfg.WifiApSiidEnd
                     );
  Serial.println(g_SD_FileLineData);
}

void fncSetupConfigSave()
{
  //Serial.println("fncSetupConfigSave");
  Serial.println("-----------fncSetupConfigSave");

  snprintf(g_SD_FileName, LEN_FILENAME, "%s", CFG_FILENAME);
  fncConfigLineUpdate();
  if (fncSD_FileExist(SD_MMC, g_SD_FileName))
  {
    Serial.println("Cfg  exist Delete for overwrite");
    fncSD_deleteFile(SD_MMC, g_SD_FileName);

    delay(100);
  }
  fncSD_writeFile(SD_MMC, g_SD_FileName, g_SD_FileLineData);
  Serial.println("write toconfig");
  Serial.println("at end of fncSetupConfigSave");
  fncConfigLineUpdate();
  ;
}

void fncSetupConfigRead()
{

  Serial.println("----------------- fncSetupConfigRead");
  fncSetupFactoryValues();
  snprintf(g_SD_FileName, LEN_FILENAME, "%s", CFG_FILENAME);
  if (!fncSD_FileExist(SD_MMC, g_SD_FileName))
  {
    Serial.println("Cfg no exist create and save default values");
    fncSetupConfigSave(); //crea el fichero de configuracion con default
    return;
  }
  // leer fichero
  Serial.print("Cfg " + String(g_SD_FileName) + " exist read  values");
  fncSD_readFile(SD_MMC, g_SD_FileName);
  String szLine = "";
  File myFile = SD_MMC.open(g_SD_FileName, FILE_READ);
  while (myFile.available() != 0)
  {
    szLine = myFile.readStringUntil('\n');
  }
  myFile.close();
  Serial.println();
  Serial.println("Done readed");
  Serial.println(szLine);

  char cSep = '#';
  snprintf(g_cfg.IdName, LEN_CFG_IDNAME, "%s", g_Utils->fncStringBySep(szLine, cSep, 0).c_str());
  snprintf(g_cfg.IdLocation, LEN_CFG_IDLOCATION, "%s", g_Utils->fncStringBySep(szLine, cSep, 1).c_str());
  snprintf(g_cfg.IdLocationGps, LEN_CFG_IDLOCATIONGPS, "%s", g_Utils->fncStringBySep(szLine, cSep, 2).c_str());
  //snprintf(g_cfgDlLapseFile, LEN_CFg_Dev.s_LAPSEFILE, "%s", g_Utils->fncStringBySep(szLine, cSep, 3).c_str());
  snprintf(g_cfg.WifiMode, LEN_CFG_WIFIMODE, "%s", g_Utils->fncStringBySep(szLine, cSep, 3).c_str());
  snprintf(g_cfg.WifiApSiid, LEN_CFG_WIFIAPSIID, "%s", g_Utils->fncStringBySep(szLine, cSep, 4).c_str());
  snprintf(g_cfg.WifiApPwd, LEN_CFG_WIFIAPPWD, "%s", g_Utils->fncStringBySep(szLine, cSep, 5).c_str());
  snprintf(g_cfg.WifiWsSiid, LEN_CFG_WIFIWSSIID, "%s", g_Utils->fncStringBySep(szLine, cSep, 6).c_str());
  snprintf(g_cfg.WifiWsPwd, LEN_CFG_WIFIWSPWD, "%s", g_Utils->fncStringBySep(szLine, cSep, 7).c_str());
  snprintf(g_cfg.WifiWsIPDHCP, LEN_CFG_WIFIWSIPDHCP, "%s", g_Utils->fncStringBySep(szLine, cSep, 8).c_str());
  snprintf(g_cfg.WifiWsIP, LEN_CFG_WIFIWSIP, "%s", g_Utils->fncStringBySep(szLine, cSep, 9).c_str());
  snprintf(g_cfg.WifiWsIPMsk, LEN_CFG_WIFIWSIPMSK, "%s", g_Utils->fncStringBySep(szLine, cSep, 10).c_str());
  snprintf(g_cfg.WifiWsIPGat, LEN_CFG_WIFIWSIPGAT, "%s", g_Utils->fncStringBySep(szLine, cSep, 11).c_str());
  snprintf(g_cfg.WifiWsDns1, LEN_CFG_WIFIWSDNS1, "%s", g_Utils->fncStringBySep(szLine, cSep, 12).c_str());
  snprintf(g_cfg.WifiWsDns2, LEN_CFG_WIFIWSDNS2, "%s", g_Utils->fncStringBySep(szLine, cSep, 13).c_str());
  //fncDebugConfig("fncSetupConfigRead");
  Serial.println("at end of fncSetupConfigRead");
  fncConfigLineUpdate();
  ;
}

void fnc_Config_IfResetFactory()
{
  Serial.println("fnc_Config_IfResetFactory");

#ifdef CONFIG_RESET_ONSTART // developing time:force reset config by soft
  fncSetupFactoryValues();
  fncSetupConfigSave(); // borra el fichero si lo hay y guarda por defecto.
  return;
#endif
  int resetCounter = 50;
  Serial.println("fnc_Config_IfResetFactory read button");

  while (digitalRead(PIN_RESET_FACTORY) && resetCounter > 0)
  {
    resetCounter--;
    Serial.print(resetCounter);
    Serial.print(", ");
    delay(100);
  }
  if (resetCounter < 1)
  {
    Serial.println("RESET FACTORY and save config with default values");
    fncSetupFactoryValues();
    fncSetupConfigSave(); // borra el fichero si lo hay y guarda por defecto.
  }
  return;
}
void fnc_Config_SetupRead()
{

  Serial.println("1 fnc_Config_SetupRead");
  fnc_Config_IfResetFactory();
  fncSetupConfigRead();
}

#endif
