/*
  PowerMeter.h - Library for operating bicycle power meter
  Created by Lauren Brotherson, September 28, 2018
*/

#ifndef PowerMeterRX_h
#define PowerMeterRX_h

#include <Arduino.h>
#include "Packet.h"
#include <LiquidCrystal.h>
#include <NRFLite.h>
class PowerMeterRX {
  public:
    PowerMeterRX(LiquidCrystal&, NRFLite&);
    void readData();
    void writeData();
    float getTorque();
    float getFreq();
    float getPower();
    void testData(float, float);
  private:
    Packet* _data;
    LiquidCrystal _lcd;
    NRFLite _radio;
    };

#endif
