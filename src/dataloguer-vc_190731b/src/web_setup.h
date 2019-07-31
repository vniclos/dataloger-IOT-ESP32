//------------------------------------------
//web_setup.h
//configure web url with events handlers
//and start web service
//------------------------------------------
#ifndef WEBSETUP_H
#define WEBSETUP_H
void fnc_Web_Setup()
{
  Serial.println("fnc_Web_Setup in");


  g_server.on("/", handleROOT);
  g_server.on("/js.js", handleJS);
  g_server.on("/jsapexchart2.js", handleJSApexC2);
  g_server.on("/jsapexchart.js",  handleJSApexC);
  g_server.on("/jsapexgetfile",handleJSApexGetfile);
  g_server.on("/css.css", handleCSS);
  //g_server.on("/fncDebug", handleDEBUG);
  g_server.on("/fncReadSensors", handleReadSensors);
  g_server.on("/fncOff", handleStop);
  g_server.on("/fncOn", handleStart);
  g_server.on("/download", handleDownloadList);
  g_server.on("/charts", handleCharts);
  g_server.on("/filedown", handleFiledown);
  g_server.on("/filedel", handleFileDelete);

  g_server.on("/filedelall", handleFileDelAll);
  g_server.on("/fncHelp", handleHelp);
  //g_server.on("/fncsoftware", handleSoftware);
  g_server.on("/config", handleCfg);
  g_server.on("/cfgsetlocgps", handlesetLocGPS);
  g_server.on("/cfggetall", handleCfgGetAll);
  g_server.on("/cfgsetdl", handleCfgSetDL);
  g_server.on("/cfgsetdt", handleCfgSetDT);
  g_server.on("/cfgsetwifi", handleCfgSetWifi);
  g_server.on("/reset", handleReset);
  g_server.on("/gpsread", handleGpsRead);

  g_server.onNotFound(handleNotFound);

  //------------- OTA  START

  g_server.on("/otaform", handleOtaForm); /*handling uploading firmware file */
  //g_server.on("/otaupdate", handleOtaUpdate);
  g_server.on("/otaupdate", HTTP_POST, []() {
    g_server.sendHeader("Connection", "close");
    g_server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
    ESP.restart(); }, []() {
    HTTPUpload& upload = g_server.upload();
    if (upload.status == UPLOAD_FILE_START) {
      Serial.printf("Update: %s\n", upload.filename.c_str());
      if (!Update.begin(UPDATE_SIZE_UNKNOWN)) { //start with max available size
        Update.printError(Serial);
      }
    } else if (upload.status == UPLOAD_FILE_WRITE) {
      /* flashing firmware to ESP*/
      if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
        Update.printError(Serial);
      }
    } else if (upload.status == UPLOAD_FILE_END) {
      if (Update.end(true)) { //true to set the size to the current progress
        Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
      } else {
        Update.printError(Serial);
      }
    } });
  //-------------- OTA END
  g_server.begin();
  Serial.println("fnc_Web_Setup out");
}
#endif
