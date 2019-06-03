/*
 * TODO:insert schpeil
 */

#include <Arduino.h>
#include "PowerMeter.h"
#include <SPI.h>
#include <NRFLite.h>
#include <LiquidCrystal.h>
#include "Packet.h"
#include <string.h>
//#define RX_RADIO_ID 1
//#define LCD_X 16
//#define LCD_Y 2

//Initialize power meter.
//lcdPins ~ {rs, enable, d0,...,d7} or { rs, enable, d4,...,d7}
PowerMeterRX::PowerMeterRX(LiquidCrystal& lcd, NRFLite& radio) : _lcd(lcd), _radio(radio) {
  //_lcd.noCursor(); //May be necessary
}

//Read data from radio and return pair of doubles, ints or strings
void PowerMeterRX::readData(){
  while (_radio.hasData()){
    _radio.readData(_data);
  }
}

//Receives data from readData(), processes it, and prints to lcd
void PowerMeterRX::writeData(){
  _lcd.setCursor(0,0);
  char buff[16];
  int precision;
  if(_data->torque >= 100)
    precision=0;
  else
    precision=1;
  sprintf(buff, precision, "T=%4.*f", getTorque());
  _lcd.setCursor(0,8);
  sprintf(buff, "f=%3.0fBPM", getFreq()/(2*PI*60));  
  _lcd.print(buff);
  _lcd.setCursor(1,0);
  _lcd.print("P=");
  sprintf(buff, "P=%4.1fWatts", getPower());
  _lcd.print(buff);
}

float PowerMeterRX::getTorque() {
  return _data->torque;
}

float PowerMeterRX::getFreq() {
  return _data->freq;
}

float PowerMeterRX::getPower() {
  return _data->freq * _data->torque;
}

void PowerMeterRX::testData(float t, float f){
  _data->torque = t;
  _data->freq = f;
}
