//------------------------------------------
//dev_wifi.h
//management wifi connection
//------------------------------------------
#ifndef DEVWIFI_H
#define DEVWIFI_H
//#include "_defines.h"
void fnc_Wifi_Setup_mDNS() {
  //const char* host = "esp32";
  if (!MDNS.begin(g_CfgInUse.wifi_host)) {
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  else
  {
    Serial.print("mDNS responder at http://" + String(g_CfgInUse.wifi_host) + ".local");
  }
}

void fnc_Wifi_SetupAP() {
  Serial.print("Aqui: fnc_Wifi_SetupAP() g_wifi_Ssid=");
  strcpy(g_CfgInUse.wifi_Ssid, g_cfg.WifiApSiid);
  strcat(g_CfgInUse.wifi_Ssid, g_cfg.WifiApSiidEnd);
  Serial.println(g_CfgInUse.wifi_Ssid);

  WiFi.mode(WIFI_AP);
  WiFi.softAP(g_CfgInUse.wifi_Ssid, g_CfgInUse.wifi_Pwd);
  delay(2000);
  IPAddress ip = g_Utils->fncWifi_String2IP4(CFG_WIFIAPIP);; // where xx is the desired IP Address
  IPAddress ipMask = g_Utils->fncWifi_String2IP4(CFG_WIFIAPMASK);
  IPAddress ipGateway = ip; // set gateway to match your network
  WiFi.softAPConfig(ip, ipGateway, ipMask);
  delay(100);
  IPAddress myIP = WiFi.softAPIP();
  strcpy( g_CfgInUse.wifi_IP, (g_Utils->fncWifi_IP42String(myIP)).c_str());
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  delay(1000);
  fnc_Wifi_Setup_mDNS();

  g_DnsServer.start(DNS_PORT, "*", myIP);

}
void fcSetupWifiAPDefault() {
  strcpy(g_CfgInUse.wifi_Mode , WIFIMODE_AP); // WIFIMODE_AP   WIFIMODE_WS // ABIERTO ;
  strcpy(g_CfgInUse.wifi_Pwd, CFG_WIFIAPPWD);
  strcpy(g_CfgInUse.web_UrlRoot, CFG_WIFIAPSIID);
  fnc_Wifi_SetupAP();

}
void fnc_Wifi_SetupWS() {

  Serial.println("fnc_Wifi_SetupWS");
  snprintf(g_CfgInUse.wifi_Ssid, LEN_CFG_WIFISIID , "%s", g_cfg.WifiWsSiid);
  snprintf(g_CfgInUse.wifi_Pwd, LEN_CFG_WIFIPWD , "%s", g_cfg.WifiWsPwd);
  unsigned int uLen = 0;
  unsigned int uSize = 0;

  WiFi.mode(WIFI_STA);
  // config static IP
  Serial.print("g_cfgWifiWsIPDHCP=");
  Serial.println(g_cfg.WifiWsIPDHCP);


  if (strcmp(g_cfg.WifiWsIPDHCP, WIFIWSIPDHCP_ONOF) == 0) {

  
    uLen = strlen ( g_cfg.WifiWsIP );
    uSize = sizeof ( g_cfg.WifiWsIP );
    Serial.print("g_cfgWifiWsIP= ");
    Serial.print(g_cfg.WifiWsIP);
    Serial.print(" strlen = ");
    Serial.print(uLen);
    Serial.print(" sizeof = ");
    Serial.println(uSize);
    snprintf(g_cfg.WifiWsIP, LEN_CFG_WIFIWSIP , "%s", CFG_WIFIWSIP);
    uLen = strlen (g_cfg.WifiWsIP );
    uSize = sizeof ( CFG_WIFIWSIP );
    Serial.print("g_cfgWifiWsIP= ");
    Serial.print(g_cfg.WifiWsIP);
    Serial.print(" strlen = ");
    Serial.print(uLen);
    Serial.print(" sizeof = ");
    Serial.println(uSize);
    
    IPAddress ip      = g_Utils->fncWifi_String2IP4(g_cfg.WifiWsIP);
    IPAddress ipMask  = g_Utils->fncWifi_String2IP4(g_cfg.WifiWsIPMsk);
    IPAddress ipGateway = g_Utils->fncWifi_String2IP4(g_cfg.WifiWsIPGat);
    IPAddress ipDNS1 = g_Utils->fncWifi_String2IP4(g_cfg.WifiWsDns1);
    IPAddress ipDNS2 = g_Utils->fncWifi_String2IP4(g_cfg.WifiWsDns2);

    Serial.println("Wifi.config(");
    Serial.println("No. DHCP. Tray set ip to " + String (g_cfg.WifiWsIP));
    Serial.println ("IP=" + g_Utils->fncWifi_IP42String (ip));
    Serial.println ("ipMask=" + g_Utils->fncWifi_IP42String (ipMask));
    Serial.println ("ipGateway=" + g_Utils->fncWifi_IP42String (ipGateway));
    Serial.println ("ipDNS1=" + g_Utils->fncWifi_IP42String (ipDNS1));
    Serial.println ("ipDNS2=" + g_Utils->fncWifi_IP42String (ipDNS2));
    Serial.println (")");
    if (!WiFi.config(ip, ipGateway, ipMask, ipDNS1, ipDNS2)) {
      //
      Serial.println("STA Failed to configure");
    }
    else {
      Serial.println("DHCP active ip dinamic");
    }
    delay(1000);
    Serial.println("WiFi.begin(" + String(g_CfgInUse.wifi_Ssid) + "," + String(g_CfgInUse.wifi_Pwd) + ")");
    WiFi.begin(g_CfgInUse.wifi_Ssid , g_CfgInUse.wifi_Pwd);
    //WiFi.begin(CFG_WIFIWSSIID , CFG_WIFIWSPWD);

    // Wait for connection if cant connet go to default factory mode
    unsigned int iCount = 50;
    while (WiFi.status() != WL_CONNECTED && iCount > 0) {
      iCount--;
      delay(500);
      Serial.print(".");
    }
    if (iCount == 0)  {
      Serial.println("Fail to connect Wifi mode workstation ");
      Serial.println("Start as access point defaul factory");
      fcSetupWifiAPDefault();
      return;
    }
    delay(1100);
    Serial.println("Wifi mode workstation ");
    Serial.print("Connected to ");
    Serial.println(g_CfgInUse.wifi_Ssid);
    IPAddress myIP = WiFi.localIP();
    Serial.print("IP address: ");
    Serial.println(myIP);
    strcpy( g_CfgInUse.wifi_IP, (g_Utils->fncWifi_IP42String(myIP)).c_str());
    fnc_Wifi_Setup_mDNS();


  }

}

void fnc_Wifi_Setup() {
  // Serial.print("Aqui: fnc_Wifi_Setup g_wifi_Mode = ");
  Serial.println(g_CfgInUse.wifi_Mode);
  if (strcmp(g_CfgInUse.wifi_Mode, WIFIMODE_AP) == 0)
  {
    strcpy(g_CfgInUse.web_UrlRoot, g_cfg.WifiApSiid);
    fnc_Wifi_SetupAP();
  }
  else
  {
    fnc_Wifi_SetupWS();
  }
}
#endif
