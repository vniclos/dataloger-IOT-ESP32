//------------------------------------------
//dev_wdg.h
//management watchdog
//------------------------------------------
#ifndef DEVWDT_H
#define DEVWDT_H

void IRAM_ATTR fnc_WDT_OnFired() {
  ets_printf("reboot\n");
  esp_restart();
}
void fnc_WatchDog_Setup() {
  //Serial.println("Aqui: fnc_WatchDog_Setup");
  //watchdog
  
  int wdt_Timeout =  WTD_INTERVAL;
  g_WDT_timer = timerBegin(0, 80, true);                  //timer 0, div 80
  timerAttachInterrupt(g_WDT_timer, &fnc_WDT_OnFired, true);  //attach callback
  timerAlarmWrite(g_WDT_timer, wdt_Timeout * 100, false); //set time in us
  timerAlarmEnable(g_WDT_timer);
  Serial.println("fnc_WatchDog_Setup");
}

#endif
