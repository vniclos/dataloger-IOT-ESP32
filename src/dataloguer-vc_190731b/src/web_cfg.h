 #ifndef _WEB_CFG_H
#define _WEB_CFG_H

const char g_HTML_Web_cfg[] PROGMEM = R"=====(


<button class="btnmini" onclick="fncCfggetConfig();return false;">Get values</button>
<button class="btnmini" onclick="fncReset();return false;">Reset</button></br>
<h3>Configuration</h3>
<p>Remenber: <br/>Default factory config is posible pressing reset button on start. Default=Mode access point,Password=123456789</p>
<fieldset>

<legend>Dataloger:</legend>
Id. name.<br/>
<input type="text" maxlength="30" size="30em" id="scnIdName"  maxlength="32"  value="" placeholder="Friendly id"><span id="scnIdNameMsg" style="color:#fff;">.</span>
<br/>Id Location geographic.<br/>
<input type="text" maxlength="30" size="30em" id="scnIdLoc"  maxlength="32"  value="" placeholder="City, country, riber..."><span id="scnIdLocMsg" style="color:#fff;">.</span>
<br/>GPS Location Lat, long, decimal format.<br/>
<input type="text" maxlength="30" size="30em" id="scnIdGps"  type="number" step="0.01" placeholder="-3.7339, 123.13" value=""><span id="scnIdGpsMsg" style="color:#fff;">.</span>

<span id="scnGPSMsg" style="color:#fff;">...</span><br/>
<button class="btnmini" onclick="fncGetAjaxValue("cfgsetlocgps", "scnLoc")">Update location from GPS</button>
<button class="btnmini" onclick="fncGpsNavigatorGet()">Open Google Map, need internet</button>
<br/><button onclick="fncCfgSetDataloger();return false;">Set Dataloger</button>
<br><span id="scnMsgDlBtn"></span>
</fieldset>

<fieldset>
<legend>Date time:</legend>
Date:<br/> <input type="date" id="scnDate" value="">
<span id="scnDateMsg">...</span><br/>
Time:<br/> <input type="time" id="scnTime" value="">
<span id="scnTimeMsg" >...</span><br/>
<button onclick="fncCfgSetDateTime();return false;">Set date time</button>
<br/><span id="scnMsgTimeBtn"></span>
</fieldset> <fieldset>
<legend>Wifi:</legenD>
Wifi mode <br/>
<label for="scnModeap">Acces point</label>
<input type="radio" id="scnModeap" name="scnMode" value="Work station" checked>
<label for="scnModews">Workstation</label>
<input type="radio" id="scnModews" name="scnMode" value="Access point"  >
<br/><b>Select access point</b> to work in the field, without internet connection. in this case the device itself is transformed into an access point that allows you to access it from a smarphone, laptop, tablet etc.
<br/><b>Select work station </b>to work connected to an access point, (router with connection to the Internet)
<fieldset>

<legend>Wifi Accesspoint:</legend>
Siid:<br/> <input type="text" id="scnWifiApSiid" value="">
<span id="scnWifiApSiidEnd">.</span>
<span id="scnWifiApSiidMsg" style="color:#fff;">.</span><br/>
Password:<br/> <input id="scnWifiApPwd" type="password" id="scnWifiApPwd" value=""><span id="scnWifiApPwdMsg" style="color:#fff;">.</span><br/>
<button class="btnmini" onclick="fncCfgTogglePwds('scnWifiApPwd',this);return false;">Show</button> 
</fieldset><fieldset>
<legend>Wifi workstation:</legend>
Siid:<br/> <input type="text" id="scnWifiWsSiid" value=""><span id="scnWifiWsSiidMsg" style="color:#fff;">.</span><br/>
Password:<br/> <input type="password" id="scnWifiWSPwd" value=""><span id="scnWifiWSPwdMsg" style="color:#fff;">.</span><br/>
<button class="btnmini" onclick="fncCfgTogglePwds('scnWifiWSPwd',this);return false;">Show</button> 
  <h3>Dinamic or static ip</h3>
<label for="scnDhcpOn">Use DHCP</label>
<input type="radio" id="scnDhcpOn" name="scnDhcp" value="1" checked>
<label for="scnDhcpOFF">StaticIp</label>
<input type="radio" id="scnDhcpOff" name="scnDhcp" value="0"  ><br/>


<br/>IP<br/><input id="sncIp" placeholder="192.168.1.10" type="text" minlength="7" maxlength="15" size="15" pattern="^((\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.){3}(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])$">
<span id="sncIpMsg" style="color:#fff;">.</span>
<br/>Mask<br/><input id="sncIpMask" placeholder="255.255.255.0" type="text" minlength="7" maxlength="15" size="15" pattern="^((\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.){3}(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])$">
<span id="sncIpMaskMsg" style="color:#fff;">.</span>
<br/>Gateway<br/><input id="sncIpGate" placeholder="192.168.1.1" type="text" minlength="7" maxlength="15" size="15" pattern="^((\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.){3}(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])$">
<span id="sncIpGateMsg" style="color:#fff;">.</span>


<br/>DNS 1<br/><input id="sncIpDns1" placeholder="8.8.8.8" type="text" minlength="7" maxlength="15" size="15" pattern="^((\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.){3}(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])$">
<span id="sncIpDns1Msg" style="color:#fff;">.</span>
<br/>DNS 2<br/><input id="sncIpDns2" placeholder="8.8.4.4" type="text" minlength="7" maxlength="15" size="15" pattern="^((\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.){3}(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])$">
<span id="sncIpDns2Msg" style="color:#fff;">.</span>


</fieldset>
<br/><button onclick="fncCfgSetWifi();return false;">Set wifi config</button>
<br/><span id="scnMsgWifiBtn"></span> 


</fieldset> <div id="scnDebug">debug</div>

)=====";
#endif
