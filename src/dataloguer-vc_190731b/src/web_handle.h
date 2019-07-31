#ifndef _WEB_HANDLE_H
#define _WEB_HANDLE_H
#include "_defines.h"
#include "web_root.h"
#include "web_js.h"
#include "web_css.h"
#include "web_help.h"
#include "web_cfg.h"

#include "web_otaform.h"
#include "web_js_apexchart.h" // svg apexchart source

#include "web_JS_Apexchart2.h" // svg apexchart get data  and draw in page charts
#include "_extern.h"
#include "Cls_Utils.h"
#include "FS.h"
#include "SD_MMC.h"
#include "dev_sd.h"
//=================================================
// void handleROOT()
//=================================================
void handleROOT()
{
  // Serial.println("handleRoot");
  digitalWrite(PIN_LEDINT, 1);
  Serial.println(" --------------------Serial quita fncConfigLineUpdate()");
  fncConfigLineUpdate();
  g_server.send(200, "text/html", g_HTML_Web_root);
  digitalWrite(PIN_LEDINT, 0);
}
void handleReset()
{
  digitalWrite(PIN_LEDINT, 1);
  g_server.send(200, "text/html", "Rested, Please wait and reconnect");
  digitalWrite(PIN_LEDINT, 0);
}

void handleCharts()
{
  digitalWrite(PIN_LEDINT, 1);
  String szHtml = "\n<div class=\"divBoxCenter\">\n<div class=\"divBoxCentered\"> \n<div id=\"scnChart\"></div>\n<p>You can pic on label of categories to show hide it</d> <p id=\"scnDatg_aTable\"></p></div></div>\n";
  szHtml += "\n<fieldset><legend>Charts</legend><ol>\n";
  szHtml += fncSD_listChartList(SD_MMC, "/", 0);
  szHtml += "\n</ol></fieldset>";
  szHtml += "\n<script>fncChartAjaxGetFile('_20190718dd.csv');</script>";
  g_server.send(200, "text/html", szHtml);
  digitalWrite(PIN_LEDINT, 0);
}

void handleJSApexC()
{
  
  //g_server.sendHeader("Cache-Control", "public",  "max-age=31536000");
  //g_server.setContentLength(CONTENT_LENGTH_UNKNOWN); // *** BEGIN ***
  //g_server.send(200, "application/javascript", "");
 //g_server.sendContent_P(g_HTML_Web_JS_Apexchart, uiSize);
size_t uSize = sizeof(g_HTML_Web_JS_Apexchart)-1;
String sSize=String(uSize);
   g_server.sendHeader("Content-Length",sSize);
  g_server.sendHeader("Cache-Control", "max-age=31536000, public"); // cache for 30 days

  g_server.send_P(200, "application/javascript", g_HTML_Web_JS_Apexchart, uSize);
  //g_server.send(200, "application/javascript", g_HTML_Web_JS_Apexchart);
  //g_server.client().stop(); // *** END 2/2 ***
  //Serial.println(4);
}
/*
void handleJSApexC_old()
{ 
  Serial.print("handleJSApexC sSize=");
  digitalWrite(PIN_LEDINT, 1);
  __uint32_t uiSize = sizeof(g_HTML_Web_JS_Apexchart);
  String sSize = String(uiSize);
  Serial.println(sSize);
  //Serial.println(g_HTML_Web_JS_Apexchart);
  g_server.sendHeader("Content-Length", sSize);
  g_server.send(200, "application/javascript", g_HTML_Web_JS_Apexchart);
  digitalWrite(PIN_LEDINT, 0);
}
 */
void handleJSApexC2()
{
  digitalWrite(PIN_LEDINT, 1);
  g_server.send(200, "application/javascript", g_HTML_Web_JS_Apexchart2);
  digitalWrite(PIN_LEDINT, 0);
}

//=================================================
//=================================================
//=================================================
void handleHelp()
{
  // Serial.println("handleHelp");
  digitalWrite(PIN_LEDINT, 1);

  g_server.send(200, "text/html", g_HTML_Web_Help);
  digitalWrite(PIN_LEDINT, 0);
}
void handleOtaForm()
{
  // Serial.println("handleOtaForm");
  digitalWrite(PIN_LEDINT, 1);
  //char szActualFirmware[] = "\0";
  g_server.send(200, "text/html", String(g_HTML_OtaForm) + "Software Instaled=" + String(g_CfgInUse.software) + "<br/>");
  digitalWrite(PIN_LEDINT, 0);
}


//=================================================
//=================================================
//=================================================

void handleJS()
{
  // Serial.println("handleJS");
  digitalWrite(PIN_LEDINT, 1);
  g_server.send(200, "application/javascript", g_HTML_Web_JS);
  digitalWrite(PIN_LEDINT, 0);
}
//==============================================
void handleCSS()
{
  // Serial.println("handleCSS");
  digitalWrite(PIN_LEDINT, 1);
  g_server.send(200, "text/css", g_HTML_Web_CSS);
  digitalWrite(PIN_LEDINT, 0);
}
//=================================================
String fncHtmlFillGPS()
{
  String szHtml = "";
  szHtml += "<fieldset><legend>GPS last read</legend>";
  szHtml += "<br/><span class=\"fldtit\">latitude Longitude:</span><span id=\"scnIdGps2\" class=\"fldvalue\">" + String(g_Dev.s_GpsLatiLong) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">Altitude</span><span class=\"fldvalue\">" + String(g_Dev.s_GpsAltitud) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">Last Updated </span><span class=\"fldvalue\">" + String(g_Dev.s_GpsDateTime) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">Num. Satellites </span><span class=\"fldvalue\">" + String(g_Dev.s_GpsSatellites) + "</span>";
  //x ? "True" : "False" ;
  szHtml += "<br/><span class=\"fldtit\">Is Connected</span><span class=\"fldvalue\">" + String(g_Dev.v_gpsIsConnected) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">Is Read Location</span><span class=\"fldvalue\">" + String(g_Dev.v_gpsIsReadLocation) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">Is Read Altitude</span><span class=\"fldvalue\">" + String(g_Dev.v_gpsIsReadAltitude) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">Is Read Date</span><span class=\"fldvalue\">" + String(g_Dev.v_gpsIsReadDate) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">Is Read Time</span><span class=\"fldvalue\">" + String(g_Dev.v_gpsIsReadTime) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">s_UrlMap</span><span class=\"fldvalue\">" + String(g_Dev.s_UrlMap) + "</span>";
  szHtml += "<p/>Note: GPS datetime <> Geographic date time. </p>";
  szHtml += "<input type=\"button\" class=\"btn\" value=\"Refresh\" onclick=\"fncGetHtml('scndivgps','gpsread');return false;\"></button>";
  szHtml += "<button class=\"btnmini\" onclick=\"fncGpsNavigatorGetInner('scnIdGps2')\">Open in Google Map, need internet</button>";
  szHtml += "</fieldset>";
  return szHtml;
}

//=================================================

void handleReadSensors()
{
  Serial.println("handleReadSensors");
  digitalWrite(PIN_LEDINT, 1);
  fnc_devices_Read();
  String szHtml = "";
  szHtml += "<fieldset><legend>Dataloger</legend>";
  szHtml += "<br/><span class=\"fldtit\">Id. Name:</span><span class=\"fldvalue\">" + String(g_cfg.IdName) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">Id. Location:</span><span class=\"fldvalue\">" + String(g_cfg.IdLocation) + "</span>";
  szHtml += "<br/><span class=\"fldtit\">ID. GPS :</span><span id=\"scnIdGps\" class=\"fldvalue\">" + String(g_cfg.IdLocationGps) + "</span> [Lat. ,Long.]";

  String sz = "";
  if (g_SD_FileSaveStarted)
  {
    sz = "<span class=\"on\">ON</span>";
  }
  else
  {
    sz = "<span class=\"of\">OFF</span>";
  }
  szHtml += "<br/><span class=\"fldtit\">Started:</span><span class=\"fldvalue\">" + sz + "</span>";
  szHtml += "<br/><span class=\"fldtit\">Save interval day:</span><span class=\"fldvalue\">30 minutes</span>";
  szHtml += "<br/><span class=\"fldtit\">Save interval Month:</span><span class=\"fldvalue\">6 Hours</span>";
  szHtml += "<br/><span class=\"fldtit\">Save interval Year:</span><span class=\"fldvalue\">24 Hours</span>";
  szHtml += "<p id=\"msgSensors\" class=\"msg\"></p> ";
  szHtml += "<button class=\"btnmini\" onclick=\"fncGpsNavigatorGetInner('scnIdGps')\">Open in Google Map, need internet</button>";
  szHtml += "</fieldset>";

  szHtml += "<fieldset><legend>Sensors</legend>\n";
  szHtml += "<br/><span class=\"fldtit\">Last read at:</span><span class=\"fldvalue\">";
  szHtml += String(g_Dev.s_RTCTime);
  szHtml += " ";
  szHtml += String(g_Dev.s_RTCDate);

  szHtml += "?</span>";
  szHtml += "<br/><span class=\"fldtit\">Temp Air:</span><span class=\"fldvalue\">" + String(g_Dev.s_TempAir) + " ºC</span>";
  szHtml += "<br/><span class=\"fldtit\">Temp Soil:</span><span class=\"fldvalue\">" + String(g_Dev.s_TempSoil) + " ºC</span>";
  szHtml += "<br/><span class=\"fldtit\">Temp Subsoil:</span><span class=\"fldvalue\">" + String(g_Dev.s_TempSubsoil) + " ºC</span>";
  szHtml += "<br/><span class=\"fldtit\">Humidity Air:</span><span class=\"fldvalue\">" + String(g_Dev.s_HumidityAir) + " % (Inside)</span>";
  szHtml += "<br/><span class=\"fldtit\">Humidity Soil:</span><span class=\"fldvalue\">" + String(g_Dev.s_HumiditySoil) + " % (Inside)</span>";
  szHtml += "<br/><span class=\"fldtit\">Preasure:</span><span class=\"fldvalue\">" + String(g_Dev.s_PreasureAirHpa) + " mbar (=hPa) </span>";
  szHtml += "<br/><span class=\"fldtit\">Altitude</span><span class=\"fldvalue\">" + String(g_Dev.s_AltitudeByHpa) + " mts.(Calculate by hPa)</span>";
  szHtml += "<br/><span class=\"fldtit\">Light:</span><span class=\"fldvalue\">" + String(g_Dev.v_Lux) + " " + String(g_Dev.s_LuxMsg) + "</span></br>";
  szHtml += "<input type=\"button\" class=\"btn\" value=\"Refresh\" onclick=\"fncGetHtml('scnBody','fncReadSensors');return false;\"></button>";
  szHtml += "</fieldset>";

  szHtml += "<div id=\"scndivgps\" >";
  szHtml += fncHtmlFillGPS();
  szHtml += "</fieldset></div>";

  //if (!g_SD_FileSaveStarted)  {

  g_server.send(200, "text/html", szHtml);
  digitalWrite(PIN_LEDINT, 0);
}
//=================================================
//=================================================
//=================================================
void handleCfg()
{
  // Serial.println("handleCfg");
  digitalWrite(PIN_LEDINT, 1);
  g_server.send(200, "text/css", g_HTML_Web_cfg);
  digitalWrite(PIN_LEDINT, 0);
}
void handleCfgGetAll()
{

  digitalWrite(PIN_LEDINT, 1);

  fncConfigLineUpdate();
  String sz = String(g_SD_FileLineData);

  g_server.send(200, "text/plain", String(sz));
  digitalWrite(PIN_LEDINT, 0);
}

void handleGpsRead()
{
  digitalWrite(PIN_LEDINT, 1);
  fnc_dev_Gps_Read();

  g_server.send(200, "text/css", fncHtmlFillGPS());
  digitalWrite(PIN_LEDINT, 0);
}

//=================================================
//=================================================
//=================================================
void fncDebugArgs()
{
  String sz = "Args: ";
  ;
  sz += g_server.args() + "\n";
  for (int i = 0; i < g_server.args(); i++)
  {

    sz += "Arg nº" + (String)i + "–> ";
    sz += g_server.argName(i) + ": ";
    sz += g_server.arg(i) + "\n";
  }
  Serial.println(sz);
}


void handleCfgSetDL()
{
  // Serial.println("handleCfg");
  digitalWrite(PIN_LEDINT, 1);
  //Send: cfgsetdl?loc=244242424qweq&inteval=1
  fncDebugArgs();

  if (g_server.hasArg("name"))
  {
    //  strcpy(g_cfgIdName, g_server.arg("name").c_str());
    snprintf(g_cfg.IdName, sizeof(g_cfg.IdName), "%s", g_server.arg("name").c_str());
  }

  if (g_server.hasArg("loc"))
  {
    // strcpy(g_cfgIdLocation , g_server.arg("loc").c_str());
    snprintf(g_cfg.IdLocation, sizeof(g_cfg.IdLocation), "%s", g_server.arg("loc").c_str());
  }

  if (g_server.hasArg("gps"))
  {
    ///strcpy(g_cfgIdLocationGps , g_server.arg("gps").c_str());
    snprintf(g_cfg.IdLocationGps, sizeof(g_cfg.IdLocationGps), "%s", g_server.arg("gps").c_str());
  }
  strcpy(g_MsgLast, "Saved ID and Location");
  g_server.send(200, "text/html", g_MsgLast);
  digitalWrite(PIN_LEDINT, 0);
  fncSetupConfigSave();
}
void handlesetLocGPS()
{
  Serial.println("handlesetLocGPS");
  digitalWrite(PIN_LEDINT, 1);
  // Serial.println("handleLAPSESTART");
  strcpy(g_cfg.IdLocationGps, g_Dev.s_GpsLatiLong);
  g_server.send(200, "text/html", String(g_cfg.IdLocationGps));
  digitalWrite(PIN_LEDINT, 0);
}

void handleCfgSetDT()
{
  fncDebugArgs();
  uint16_t dyy = 0;
  uint8_t dmm = 0;
  uint8_t ddd = 0;
  uint8_t thh = 0;
  uint8_t tmm = 0;
  uint8_t tss = 0;
  String sz = "";

  if (g_server.hasArg("date"))
  {
    sz = g_server.arg("date");
    dyy = g_Utils->fncStringBySep(sz, '-', 0).toInt();
    dmm = g_Utils->fncStringBySep(sz, '-', 1).toInt();
    ddd = g_Utils->fncStringBySep(sz, '-', 2).toInt();
  }

  if (g_server.hasArg("time"))
  {
    sz = g_server.arg("time");
    thh = g_Utils->fncStringBySep(sz, ':', 0).toInt();
    tmm = g_Utils->fncStringBySep(sz, ':', 1).toInt();
    tss = 0;
  }
  fnc_dev_rtc3231_Set(dyy, dmm, ddd, thh, tmm, tss);
  strcpy(g_MsgLast, "Saved Date time");

  g_server.send(200, "text/html", g_MsgLast);
  digitalWrite(PIN_LEDINT, 0);
}

//=================================================
//=================================================
//=================================================
//=================================================
//=================================================
//=============   handleCfgSetWifi  ===============
//=================================================
//=================================================
//=================================================

void handleCfgSetWifi()
{
  fncDebugArgs();
  digitalWrite(PIN_LEDINT, 1);
  //Send: cfgsetdl?loc=244242424qweq&inteval=1
  // String fncStringBySep(String data, char separator, int index);
  if (g_server.hasArg("mode"))
  {
    strcpy(g_cfg.WifiMode, g_server.arg("mode").c_str());
  }
  if (g_server.hasArg("ApSiid"))
  {
    //strcpy(g_cfgWifiApSiid  , g_server.arg("ApSiid").c_str());
    snprintf(g_cfg.WifiApSiid, sizeof(g_cfg.WifiApSiid), "%s", g_server.arg("ApSiid").c_str());
  }
  if (g_server.hasArg("ApPwd"))
  {
    // strcpy(g_cfgWifiApPwd    , g_server.arg("ApPwd").c_str());
    snprintf(g_cfg.WifiApPwd, sizeof(g_cfg.WifiApPwd), "%s", g_server.arg("ApPwd").c_str());
  }
  if (g_server.hasArg("WsSiid"))
  {
    // strcpy(g_cfgWifiWsSiid   , g_server.arg("WsSiid").c_str());
    snprintf(g_cfg.WifiWsSiid, sizeof(g_cfg.WifiWsSiid), "%s", g_server.arg("WsSiid").c_str());
  }
  if (g_server.hasArg("WSPwd"))
  {
    // strcpy(g_cfgWifiWsPwd    , g_server.arg("WSPwd").c_str());
    snprintf(g_cfg.WifiWsPwd, sizeof(g_cfg.WifiWsPwd), "%s", g_server.arg("WSPwd").c_str());
  }
  if (g_server.hasArg("WsDhcp"))
  {
    //strcpy(g_cfgWifiWsIPDHCP , g_server.arg("WsDhcp").c_str());
    snprintf(g_cfg.WifiWsIPDHCP, sizeof(g_cfg.WifiWsIPDHCP), "%s", g_server.arg("WsDhcp").c_str());
  }
  if (g_server.hasArg("WSIp"))
  {

    // strcpy(g_cfgWifiWsIP     , g_server.arg("WSIp").c_str());
    snprintf(g_cfg.WifiWsIP, sizeof(g_cfg.WifiWsIP), "%s", g_server.arg("WSIp").c_str());
  }
  if (g_server.hasArg("WSGate"))
  {
    //strcpy(g_cfgWifiWsIPGat     , g_server.arg("WSGate").c_str());
    snprintf(g_cfg.WifiWsIPGat, sizeof(g_cfg.WifiWsIPGat), "%s", g_server.arg("WSGate").c_str());
  }
  if (g_server.hasArg("WSMask"))
  {
    //strcpy(g_cfgWifiWsIPMsk  , g_server.arg("WSMask").c_str());
    snprintf(g_cfg.WifiWsIPMsk, sizeof(g_cfg.WifiWsIPMsk), "%s", g_server.arg("WSMask").c_str());
  }
  if (g_server.hasArg("WSDns1"))
  {
    //strcpy(g_cfgWifiWsDns1   , g_server.arg("WSDns1").c_str());
    snprintf(g_cfg.WifiWsDns1, sizeof(g_cfg.WifiWsDns1), "%s", g_server.arg("WSDn").c_str());
  }
  if (g_server.hasArg("WSDns2"))
  {
    //strcpy(g_cfgWifiWsDns2   , g_server.arg("WSDns2").c_str());
    snprintf(g_cfg.WifiWsDns2, sizeof(g_cfg.WifiWsDns2), "%s", g_server.arg("WSDns2").c_str());
  }
  strcpy(g_MsgLast, "Saved Wifi configuration");
  g_server.send(200, "text/html", g_MsgLast);
  digitalWrite(PIN_LEDINT, 0);
  Serial.println("handleCfgSetWifi");
  //fncDebugConfig("handleCfgSetWifi");
  fncSetupConfigSave();
}

//=================================================
//=================================================
//=================================================

void handleStop()
{
  Serial.println("handleStop");
  digitalWrite(PIN_LEDINT, 1);
  // Serial.println("handleLAPSESTART");
  String msg = "Stoped datatoger";
  g_SD_FileSaveStarted = false;
  g_server.send(200, "text/html", msg);
  digitalWrite(PIN_LEDINT, 0);
}
void handleStart()
{
  Serial.println("handleStart");
  digitalWrite(PIN_LEDINT, 1);
  String msg = "Dataloged started";
  g_SD_FileSaveStarted = true;
  g_server.send(200, "text/html", msg);
  digitalWrite(PIN_LEDINT, 0);
}
//=================================================
//=================================================
//=================================================
void handleFileChartsList()
{
  String szCmd = "";
  String szfileName = "";
  String szReply = "<fieldset><legend>Daloger files</legend><table>\n";
  szReply += fncSD_listULLIDir(SD_MMC, "/", 0);
  szReply += "\n</table></fieldset>";
  g_server.send(200, "text/html", szReply);
}

//=================================================
//=================================================
//=================================================
void handleJSApexGetfile()
{

  Serial.println("handleFiledown");
  String szReply = "{\"bad recuest\":\"fail\"}";
  String szFileName = "";
  if (!g_server.hasArg("file"))
  {
    g_server.send(200, "text/plain;charset=utf-8", szReply);
  }
  else
  {

    szFileName = g_server.arg("file");
    Serial.printf("Reading file: %s\n", szFileName.c_str());
    //==================================================
    //==================================================
    //fncSD_readFile(SD_MMC,szFileName);
    File dataFile = SD_MMC.open(szFileName);
    int fsizeDisk = dataFile.size();
    Serial.print("fsizeDisk: ");
    Serial.println(fsizeDisk);
    size_t fsizeSent = g_server.streamFile(dataFile, "text/plain");
    Serial.print("fsizeSent: ");
    Serial.println(fsizeSent);

    //=============================================
    //==================================================

    szReply = "{\"File recuest\":\"" + szFileName + "\"}";
    g_server.sendHeader("Content-Type", "text/plain");
   // g_server.sendHeader("Content-Disposition", "attachment; filename=" + szFileName);
   // g_server.sendHeader("Connection", "close");
    g_server.streamFile(dataFile, "text/plain");
    dataFile.close();
  }
}

void handleFiledown()
{

  Serial.println("handleFiledown");
  String szReply = "{\"bad recuest\":\"fail\"}";
  String szFileName = "";
  if (!g_server.hasArg("file"))
  {
    g_server.send(200, "application/json;charset=utf-8", szReply);
  }
  else
  {

    szFileName = g_server.arg("file");
    Serial.printf("Reading file: %s\n", szFileName.c_str());
    //==================================================
    //==================================================
    //fncSD_readFile(SD_MMC,szFileName);
    File dataFile = SD_MMC.open(szFileName);
    int fsizeDisk = dataFile.size();
    Serial.print("fsizeDisk: ");
    Serial.println(fsizeDisk);
    size_t fsizeSent = g_server.streamFile(dataFile, "text/plain");
    Serial.print("fsizeSent: ");
    Serial.println(fsizeSent);

    //=============================================
    //==================================================

    szReply = "{\"File recuest\":\"" + szFileName + "\"}";
    g_server.sendHeader("Content-Type", "text/text");
    g_server.sendHeader("Content-Disposition", "attachment; filename=" + szFileName);
    g_server.sendHeader("Connection", "close");
    g_server.streamFile(dataFile, "application/octet-stream");
    dataFile.close();
  }
}
//=================================================
//=================================================
//=================================================

void handleDownloadList()
{
  //fncGetHtmlAjax(pDivTarget, pURLHtmlBody)

  String szCmd = "";
  String szfileName = "";
  String szReply = "<fieldset><legend>Daloger files</legend><table>\n";
  szReply += fncSD_listULLIDir(SD_MMC, "/", 0);
  szReply += "\n</table></fieldset>";
  g_server.send(200, "text/html", szReply);
}
//=================================================
//=================================================
//=================================================

void handleFileDelAll()
{
  // TODO ;
}
void handleFileDelete()
{
  Serial.println("fncWeb_handledelete");
  Serial.println(g_server.uri());
  String szArg = g_server.argName(0);
  String szFileName = g_server.arg(0);
  Serial.println(szArg);

  char cFilename[20];
  Serial.println(szFileName.length());
  szFileName.toCharArray(cFilename, 20);

  if (szArg == "file")
  {
    Serial.println(cFilename);
    Serial.println("remove");
    fncSD_deleteFile(SD_MMC, cFilename);
    //SD.remove(cFilename);
    yield();
    Serial.println("yield");
    //g_server.send(200, "text/text;charset=utf-8", "{\"Deleted\":\"" + szFileName + "\"}");
    //Serial.println("send");
  }
  String szReply = "<fieldset><legend>Daloger files</legend><table>\n";
  szReply += fncSD_listULLIDir(SD_MMC, "/", 0);
  szReply += "\n</table></fieldset>";
  g_server.send(200, "text/html", szReply);
}
//=================================================
//=================================================
void handleNotFound()
{
  digitalWrite(PIN_LEDINT, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += g_server.uri();
  message += "\nMethod: ";
  message += (g_server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += g_server.args();
  message += "\n";

  for (uint8_t i = 0; i < g_server.args(); i++)
  {
    message += " " + g_server.argName(i) + ": " + g_server.arg(i) + "\n";
  }

  g_server.send(404, "text/plain", message);
  digitalWrite(PIN_LEDINT, 0);
}

#endif
