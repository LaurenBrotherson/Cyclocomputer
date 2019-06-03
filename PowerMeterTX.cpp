/*#include <Arduino.h>
#include <PowerMeterTX.h>
#include <Packet.h>
#include <NRFLite.h>
#define TX_RADIO_ID 0
#define DESTINATION_ID 1
const float RADIUS = 0.1; //radius in meters
const float CALIBRATION_CONST = 1; //calibration constant

PowerMeterTX::PowerMeterTX(int analogPin, int hallPin, int CE, int CSN){
  _analogPin = analogPin;
  _radio.init(TX_RADIO_ID, CE, CSN);
  pinMode(hallPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(hallPin), update, RISING);
}

void PowerMeterTX::update(){
  float time = millis();
  float t = analogRead(_analogPin) * RADIUS * CALIBRATION_CONST; //TODO: set constants
  float f = 1000/(time - _msLastUpdate);//frequency in Hz
  _msLastUpdate = time;
  _data.torque = t;
  _data.freq = f;
}

void PowerMeterTX::sendData(){
  _radio.send(DESTINATION_ID, &_data, sizeof(_data));
}
*/
