//--------------------------------------------------
// ESP32 and Captative Soil Moisture

//..........................................
// Aut. V. Niclos
// this class is a part of dataloger project
// of testudines.org for study tortoise in wild
//-------------------------------------------

#ifndef CAPACITIVE_MOISURE_H
#define CAPACITIVE_MOISURE_H
#define CAPACITIVE_MOISURE_DEBUG
#include <arduino.h>
#include <driver/adc.h>
#include <esp_adc_cal.h>

#define CAPACITIVE_MOISURE_DEBUG // add code for callibration and ouput Serial

class CapacitiveMoisture {

  public:
    CapacitiveMoisture();
    ~CapacitiveMoisture(void);
    unsigned int valuePct();   //return humidity as pct
    unsigned int valueRead();  //return voltage read
    unsigned int valueMin();   //return voltage min read
    unsigned int valueMax();   //return voltage  max read

    unsigned int            calibrateMin() ;         //  change for our min value readed
    unsigned int             calibrateMax()  ;

    unsigned int read() ;
    void         setup(unsigned short Pin, unsigned int calibrateMin , unsigned int calibrateMax);
    void         callibrateTo(unsigned int calibrateMin , unsigned int calibrateMax);

    void         resetCounters();
    //void     fncReadADC1_CHANNEL_();
#ifdef CAPACITIVE_MOISURE_DEBUG
    void debugCalibration(unsigned int Repeats, unsigned int lapseMillis);
    void debugSerial();
#endif
  private:
    unsigned short  m_pin = 0;                     // pin were sensor is connected
    // in ESP32 is recomended use adc1 pins
    // adc2 pins is used for wifi

    unsigned int    m_calibrateMin = 0 ;         //  change for our min value readed
    unsigned int    m_calibrateMax = 0 ;         // change for max value readed
    unsigned int    m_valueVRead = 0;              // is last read
    unsigned int    m_valueVMin = 9999999 ;        // is min read since start or reset counter
    unsigned int    m_valueVMax = 0 ;              // is max read  since start or reset counter
    unsigned int    m_valuePct = 0;                // % read humidity in funcion of read value,  range m_calibrateMin and m_calibrateMax
    unsigned int    m_count = 0;                   // in number of read sensor from start or reset conuter.
};
#endif
