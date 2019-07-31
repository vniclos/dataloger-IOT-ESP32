/*! * ApexCharts v3.7.0 * (c) 2018-2019 Juned Chhipa * Released under the MIT License. */
 #ifndef _WEB_JS_APEXCHART2_H
#define _WEB_JS_APEXCHART2_H
const char g_HTML_Web_JS_Apexchart2[] PROGMEM = R"=====(

var  g_chart ;
var  g_ChartDocumentById='#scnChart';
var  g_ChartId='ChartId';
var  g_ChartTitle="IOT Weather testudines.org";
var  g_ChartSubtitle="12/11/31";
var  g_ChartFileUrl="data/data.txt"; 
var  g_ChartOptions=[];
var g_aAxir='';
var g_aTAir='';
var g_aTSoil='';
var g_aTSSoil='';
var g_aHAir='';
var g_aHSoil='';
var g_aPAir='';
var g_aLight='';
var g_aTable="";
var g_ChartData=[];
	g_ChartData= [
   { name: 'T Air', data: [ ]},
   { name: 'T Soil', data: [ ]},
   { name: 'T Subsoil', data: [ ]},
   { name: 'H Air', data: [ ]},
   { name: 'H Soil', data: [ ]},
   { name: 'Preaure', data: [ ]},
   { name: 'Light', data: [ ]},

        ];

// readme https://apexcharts.com/javascript-chart-demos/area-charts/irregular-timeseries/

function fnc_ChartSetup(sTitle,sSubtitle){
	

	
  g_ChartOptions = {
  	  chart: {	id: g_ChartId,  height: 400, type: 'line',  zoom: { enabled: false} },
 	    title: {text: sTitle, align: 'center', },
      subtitle: {text: sSubtitle, 	align: 'center',},
   
      dataLabels: { enabled: false},
      stroke: {curve: 'smooth'},
      //--------------------------------
      series: g_ChartData,
    
    //--------------------------------
     xaxis: {  
 
      // categories: ['00:01', '01:00', '02:00', '03:00', '04:00', '05:00', '06:00', '07:00', '08:00'],
         lines: {    show: true,  },
        
         labels: { show: false, style: {color: "#00ff00",},   
        
        
          formatter: function (value) { 
          	
          	var hhmm="NaN";
          	var s=""+value;
          	s=s.replace(' ','#');
          	
          	var dt=s.split('#');
            
            var ymd=dt[0].split('-');
            var hms=dt[1].split(':');
          	var hhmm=hms[0]+':'+hms[1];
          	

          	  return hhmm; }
         	 },
     },
    //--------------------------------
    yaxis: [
    {		seriesName: 'yTemp',
    	title: { text: "Temp,. Celsious" },
      axisTicks: { show: true },
      axisBorder: { show: true, color: "#FF1654"},
      labels: { show: true,style: {color: "#FF1654"},  },
      min: -20,
      max: 50,
    },
    {seriesName: 'yTemp',show: false, min: -20,   max: 50,},
    {seriesName: 'yTemp',show: false, min: -20,    max: 50,},
    
    { seriesName: 'yHumi',
    	title: { text: "Humidity %"},
      axisTicks: {show: true },
      axisBorder: { show: true, color: "#FF1654"},
      labels: {style: {  color: "#FF1654" }},
      min: 0,
      max: 100,
    },
     {seriesName: 'yPress',show: false,min: 0,  max: 100, },
    {seriesName: 'yPress',
     
    title: { text: "Preasure Hpa" } ,
      opposite: true,
      axisTicks: { show: true },
      axisBorder: { show: true, color: "#247BA0"},
      labels: { style: { color: "#247BA0"}
      },
      
      	min: 500,
      max: 2000,
    },
   
    { seriesName: 'yLux',
    	title: {text: "light Lux"},
      opposite: true,
      axisTicks: { show: true},
      axisBorder: { show: true, color: "#247BA0"},
      labels: {style: { color: "#247BA0"} },
      min: 0,
      max: 65000,
    }
  ],
  //--------------------------------
    }
     g_chart = new ApexCharts( document.querySelector(g_ChartDocumentById), g_ChartOptions );

    g_chart.render();
}
  





function fncChartAjaxGetFile(file) {
  file="/jsapexgetfile?file="+file;
alert(file);
 var rawFile = new XMLHttpRequest();
 //rawFile.responseType = 'application/json;charset=utf-8'; 
rawFile.responseType = ' text/plain'; 

 rawFile.open("GET", file, true);
 rawFile.onreadystatechange = function (){
    if(rawFile.readyState === 4) {
      if(rawFile.status === 200 || rawFile.status == 0) {
         var allText = rawFile.responseText;
         fncChartPlot(allText); 
  }}}
  rawFile.send(null);
}
//.............	 	
function fncChartParseAddPoint(aSerie, xDateTime,yVal,sep){
	if(xDateTime==undefined){ return;}
	if(xDateTime==''){ return;}
	if(yVal==undefined){yVal=null;}
	var aPoint="" ;
	aPoint = sep+'{"x":"'+xDateTime+'", ';
	aPoint += '"y":'+ yVal+'}';
  if(aSerie=='g_aAxir') {g_aAxir+=aPoint;}        
  else if(aSerie=='g_aTAir') {g_aTAir+=aPoint;  }   
  else if(aSerie=='g_aTSoil') {g_aTSoil+=aPoint;} 
  else if(aSerie=='g_aTSSoil') {g_aTSSoil+=aPoint;}
  else if(aSerie=='g_aHAir') {g_aHAir+=aPoint;}   
  else if(aSerie=='g_aHSoil') {g_aHSoil+=aPoint;} 
  else if(aSerie=='g_aPAir') {g_aPAir+=aPoint;}  
  else if(aSerie=='g_aLight') {g_aLight+=aPoint;}
}

function fncChartPlot(allText) {
  alert(allText);
   g_aAxir='[';
   g_aTAir='[';
   g_aTSoil='[';
   g_aTSSoil='[';
   g_aHAir='[';
   g_aHSoil='[';
   g_aPAir='[';
   g_aLight='[';
   var aLines=allText.split(/\r?\n/);
	 var aVal=[];
	 var sep='';
	 // titles
 	 aVal=aLines[1].split(';');
 	 g_ChartTitle=aVal[0];
   g_ChartSubtitle=aVal[1]+" "+ aVal[3];
 	 fncChangetitle(g_ChartTitle, g_ChartSubtitle);
 	 
   var szHeadHtml="<h4>Station</h4>";
   szHeadHtml+="<br/>Name:&nbsp"+ aVal[0];
   szHeadHtml+="<br/>Location:&nbsp"+ aVal[1];
   szHeadHtml+="<br/>Location Gps:&nbsp"+ aVal[2];
   szHeadHtml+="<br/>Date:&nbsp"+ aVal[3];
   g_aTable=szHeadHtml+"<table class='tablegray'><thead>";
   g_aTable+="<tr><th>Date Time</th><th colspan='3'>temperature</th><th  colspan='2'>humidity</th><th>Preasure</th><th>light</th><tr>\n";
   g_aTable+="<tr><th>yyymmdd hhmmss</th><th>Air</th><th>Soil</th><th>Subsoil</th><th>Air</th><th>Soil</th><th>%</th><th>lux</th><tr>\n"; 
   g_aTable+="</thead><tbody>";
   
   for (i=1;i<aLines.length;i++){
	 	 aVal=aLines[i].split(';');
 	   if(aVal[0] ==undefined)  { return;}
 	   sDateTime = aVal[3]+" "+aVal[4]+":00";
 	   fncChartParseAddPoint('g_aTAir',   sDateTime,aVal[6],sep);
 	   fncChartParseAddPoint('g_aTSoil',  sDateTime,aVal[9],sep);
 	   fncChartParseAddPoint('g_aTSSoil', sDateTime,aVal[12],sep);
 	   fncChartParseAddPoint('g_aHAir',   sDateTime,aVal[15],sep);
 	   fncChartParseAddPoint('g_aHSoil',  sDateTime,aVal[18],sep);
 	   fncChartParseAddPoint('g_aPAir',   sDateTime,aVal[21],sep);
 	   fncChartParseAddPoint('g_aLight',  sDateTime,aVal[24],sep);
 	   sep=', ';
 	   g_aTable+="<tr><th>"+ aVal[4]+"</th>";
 	   g_aTable+="<th>"+ aVal[6]+"</th>";
 	   g_aTable+="<th>"+ aVal[9]+"</th>";
 	   g_aTable+="<th>"+ aVal[12]+"</th>";
 	   g_aTable+="<th>"+ aVal[15]+"</th>";
 	   g_aTable+="<th>"+ aVal[18]+"</th>";
 	   g_aTable+="<th>"+ aVal[21]+"</th>";
 	   g_aTable+="<th>"+ aVal[24]+"</th></tr>\n";
    }
 	  g_aTable+="</table>";
 	  
 	  htm="<table>";
htm+="<tr><td>Lux</td><td>Light level</td><td>Nivel de luz ambiantal</td></tr>";
htm+="<tr><td>120000</td><td>Sun brighter daylight</td><td>Luz diurna más brillante</td></tr>";
htm+="<tr><td>110000</td><td>Bright daylight</td><td>lux	Luz diurna brillante</td></tr>";
htm+="<tr><td>20000</td><td>Shadow illuminated by a completely blue sky, at noon.</td><td>Sombra iluminada por un cielo completamente azul, al mediodía.</td></tr>";
htm+="<tr><td>10000 - 25000 </td><td>ypical cloudy or midday day.</td><td>Típico día nublado o al mediodía.</td></tr>";
htm+="<tr><td>400</td><td>lux Ortho or sunset on a clear day (ambient lighting)</td><td>Orto u ocaso en un día claro (iluminación ambiental)</td></tr>";
htm+="<tr><td><200</td><td>lux End of the darkest tempestuous clouds and at noon.</td><td>Extremo de las más oscuras nubes tempestuosas y al mediodía</td></tr>";
htm+="<tr><td>40</td><td>Completely cloudy, at sunrise / sunset.</td><td>Completamente nublado, en el orto/ocaso.</td></tr>  ";
htm+="<tr><td>>10</td><td>End of the darkest tempestuous clouds, in the ortho / sunset.</td><td>Extremo de las más oscuras nubes tempestuosas, en el orto/ocaso.</td></tr>";
htm+="</table>";
 g_aTable+=htm;
 	  document.getElementById("scnDatg_aTable").innerHTML=g_aTable;
    g_aAxir+=']';
    g_aTAir+=']';
    g_aTSoil+=']';
    g_aTSSoil+=']';
    g_aHAir+=']';
    g_aHSoil+=']';
    g_aPAir+=']';
    g_aLight+=']';
   
 	  g_ChartData[0].data=JSON.parse(g_aTAir); // temp air
    g_ChartData[1].data=JSON.parse(g_aTSoil); // temp soil
    g_ChartData[2].data=JSON.parse(g_aTSSoil); //temp subsoil
    g_ChartData[3].data=JSON.parse(g_aHAir);  // humidity air
    g_ChartData[4].data=JSON.parse(g_aHSoil); //humidity soil
    g_ChartData[5].data=JSON.parse(g_aPAir); //pression air
    g_ChartData[6].data=JSON.parse(g_aLight); //light
   	ApexCharts.exec(g_ChartId, 'updateSeries', g_ChartData, true);
   
}
function fncChangetitle(Title, Subtitle)
{
	g_ChartOptions.title.text=Title;
  g_ChartOptions.subtitle.text=Subtitle;
	ApexCharts.exec(g_ChartId, 'updateOptions', g_ChartOptions, true);
	
	}
    
fnc_ChartSetup(g_ChartTitle,g_ChartSubtitle);
//window.onload = function() {
//	fncChartAjaxGetFile('20190715ddb.csv')                 // add object 
//};


)=====";
#endif