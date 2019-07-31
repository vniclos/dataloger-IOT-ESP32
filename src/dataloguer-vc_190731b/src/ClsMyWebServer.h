#ifndef CLSMYWEBSERVER_H
#define GLOBALCLSMYWEBSERVER_H_H
#include <arduino.h>
#include <WebServer.h>
// for improve send long javascript files
class ClsMyWebServer :public  WebServer
{
  //  protected:
  //    virtual size_t _currentClientWrite(const char* b, size_t l) { return _currentClient.write( b, l ); }
  //virtual size_t _currentClientWrite_P(PGM_P b, size_t l) { return _currentClient.write_P( b, l ); }
  void _addRequestHandler(RequestHandler* handler);
 public:
 ClsMyWebServer(int port=80) :WebServer( port=80){}
/*
 virtual size_t _currentClientWrite(const char* b, size_t l) {
   Serial.println("b1");
   Serial.println(b);
    size_t totalWritten = 0;
    size_t written;
    do {
      written = _currentClient.write( b + totalWritten, l - totalWritten );
      if (written > 0) {
        totalWritten += written;
      }
    } while (written != -1 && totalWritten < l);
    return totalWritten;
  }
  virtual size_t _currentClientWrite_P(PGM_P b, size_t l) {
    Serial.println("b2");
    Serial.println(b);
    size_t totalWritten = 0;
    size_t written;
    do {
      written = _currentClient.write_P( (PGM_P)(((char *)b) + totalWritten), l - totalWritten );
      if (written > 0) {
        totalWritten += written;
      }
    } while (written != -1 && totalWritten < l);
    return totalWritten;
  }
   */
};
#endif