#include "CapacitiveMoisture.h"
#include <driver/adc.h>
#include <esp_adc_cal.h>

CapacitiveMoisture::CapacitiveMoisture() {}
CapacitiveMoisture::~CapacitiveMoisture() {}
unsigned int CapacitiveMoisture::valuePct() {
  return m_valuePct;
}
unsigned int CapacitiveMoisture::valueRead() {
  return m_valueVRead;
}
unsigned int CapacitiveMoisture::valueMin() {
  return m_valueVMin;
}
unsigned int CapacitiveMoisture::valueMax() {
  return m_valueVMax;
}
void CapacitiveMoisture::callibrateTo(unsigned int calibrateMin , unsigned int calibrateMax) {
  m_calibrateMin = calibrateMin;
  m_calibrateMax = calibrateMax;
}

unsigned int CapacitiveMoisture::CapacitiveMoisture::read() {

  m_count++;
  m_valueVRead = analogRead(m_pin);
  if (m_valueVRead < m_valueVMin) {
    m_valueVMin = m_valueVRead;
  }
  else if (m_valueVRead > m_valueVMax) {
    m_valueVMax = m_valueVRead;
  }
  unsigned int valRead = m_valueVRead - m_calibrateMin;
  unsigned int valMax = m_calibrateMax - m_calibrateMin;
  int valPct = 100 - (valRead * 100 / valMax);
  // m_valuePct = 100 - map(m_valueVRead, m_calibrateMin, m_calibrateMax, 0, 100);
  if (valPct < 0) {
    valPct = 0;
  }
  if (valPct > 100) {
    valPct = 100;
  }
  m_valuePct = valPct;
  return m_valuePct;
}

void CapacitiveMoisture::setup(unsigned short Pin, unsigned int calibrateMin , unsigned int calibrateMax )   {
  m_calibrateMin = calibrateMin;
  m_calibrateMax = calibrateMax;
  m_pin = Pin;
  pinMode(m_pin, INPUT);
}

void     CapacitiveMoisture::resetCounters() {
  m_count = 0;
  m_valueVMax = 9999999 ;
  m_valueVMax = 0 ;

}
unsigned int CapacitiveMoisture::calibrateMin() {
  return m_calibrateMin;
}

unsigned int CapacitiveMoisture::calibrateMax() {
  return m_calibrateMax;
}
/*
  void     CapacitiveMoisture::fncReadADC1_CHANNEL_0() {
  //Reading voltage on ADC1 channel 0 (GPIO 36):
  adc1_config_width(ADC_WIDTH_BIT_10);   //Range 0-1023
  adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11); //ADC_ATTEN_DB_11 = 0-3,6V
  int value = adc1_get_raw( ADC1_CHANNEL_0 );
  #ifdef DEBUG_CAPACITATIVE
  {
    Serial.println(value);

  }
  #endif
  return value ;//Read analog
  }
*/
#ifdef CAPACITIVE_MOISURE_DEBUG
void CapacitiveMoisture::debugCalibration(unsigned int iRepeats, unsigned int LapseDelayMillis) {

  Serial.println("................");
  Serial.println("CALLIBRATION STEEPS.");
  Serial.println("1 Totally dry sensor,");
  Serial.println("2 touch the sensor with a slightly damp cloth ");
  Serial.println("3 Put the sensor in water.");
  Serial.println("4 at the end of the test observe the minimum and maximum values, ");
  Serial.println("5 Modify the program variables");
  Serial.println("  g_SNSCALLIBRATIONMAX; ");
  Serial.println("  g_SnsCallibrationMin; ");
  Serial.println("NOTE:");
  Serial.println("Is more reliable if you lower the variable g_SnsCallibrationMin a bit and increase the g_SNSCALLIBRATIONMAX a little");
  Serial.println("................");
  delay(10000);
  resetCounters();
  for (unsigned int i = 0; i < iRepeats; i++)
  {
    read();
    debugSerial();
    delay(LapseDelayMillis);
  }
}
void CapacitiveMoisture::debugSerial() {

  Serial.print("Count= ");
  Serial.print(m_count);

  Serial.print(" Min= ");
  Serial.print(m_valueVMin);

  Serial.print(" Read= ");
  Serial.print(m_valueVRead);


  Serial.print(" Max= ");
  Serial.print(m_valueVMax);

  Serial.print(" valuePct= ");
  Serial.print( m_valuePct);
  Serial.println("%");




}



#endif
