extern "C"{
  #include "port_manipulation.h"
}

#define LED_PIN 13

void setup(){
  Serial.begin(115200);
  setPinOutput(LED_PIN);
  setPinOutput(12);
  setPinHigh(LED_PIN);
  setPinLow(12);
}

void loop(){
  switchPinState(LED_PIN);
  //Serial.print("Current Pinstate: ");
  //Serial.println(getPinState(LED_PIN));
  getPinState(LED_PIN);
}