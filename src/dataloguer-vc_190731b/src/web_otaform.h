#ifndef _WEB_OTAFORM_H
#define _WEB_OTAFORM_H
const char g_HTML_OtaForm[] PROGMEM = R"=====(
<form id="file-form" action="" onsubmit="fncOtaUpload();return false;" enctype="multipart/form-data"  method="POST">
<fieldset>
<legend>Upload firmware with OTA:</legend>
  <div id="upup">

    <h4>Attention, Be carefull</h2>
    <p>Instaled sofware version: <span id="scnSoftware"></span></p>
    <ul><li>Sure do you want to do this?</li>
    <li>Sure do know firmaware version?</li>
    <li>Sure do where do you are connected?</li></ul>
    <p id="progressdiv"><progress max="100" value="0" id="progress" style="display: none;"></progress></p>
    
    <input type="file" name="scnOtaFileSelect"  id="scnOtaFileSelect">
    <button type="submit" id="scnOtaUploadBtn" >Upload</button>
    <span id=scnMsgUpload>.</span>
  </div>
<fieldset>  

</form>
)=====";
#endif
