extern "C"{
  #include "port_manipulation.h"
}

#define LED_PIN 13
#define analogPin A1

void testAnalogStandard(int pin){
  Serial.print("Voltage: ");
  Serial.print(analogRead(pin) * 5 / 1.023);
  Serial.println("mV");
}

void testAnalog(int pin){
  Serial.print("Voltage: ");
  Serial.print(getAnalogPinValue(pin) * 5 / 1.023);
  Serial.println("mV");
}

void setup(){
  Serial.begin(115200);
  setPinOutput(LED_PIN);
  setPinOutput(12);
  setPinHigh(LED_PIN);
  setPinLow(12);
  setPinInput(analogPin);
  initADC(0);   // 0 -> do not use external voltage reference
}

void loop(){
  switchPinState(LED_PIN);
  //Serial.print("Current Pinstate: ");
  //Serial.println(getPinState(LED_PIN));
  //getPinState(LED_PIN);
  testAnalog(analogPin);
  //testAnalogStandard(analogPin);
  delay(100);
}