/*#ifndef PowerMeterTX_h
#define PowerMeterTX_h
#include "Packet.h"
//interrupt on pins 2 or 3
class PowerMeterTX {
  public:
    PowerMeterTX(int analogPin, int hallPin, int CE, int CSN);
    update();
    sendData();
  private:
    NRFLite _radio;
    int _analogPin;
    Package _data;
    int _msLastUpdate; //time of last update in ms
};
#endif
*/
