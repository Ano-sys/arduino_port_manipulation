#include <Arduino.h>      // needs to be included ADC, ADCSRA, ...
#include "ADC.h"

void initADC(uint8_t external){
  // set Prescaler to 128 (16MHz / 128 = 125KHz)
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  // Arduino Uno has a Boardvoltage of 5v so the reference is set to 5v
  
  if(external){
    // Arduino Uno has a Boardvoltage of 5v so the reference is set to external set reference via AREF Pin
    ADMUX = (1 << REFS1) | (0 << REFS0);
    return;
  }
  ADMUX = (1 << REFS0);
}

// returns the Value of the given channel (analogPin)
int readADC(uint8_t channel){
  ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
  ADCSRA |= (1 << ADSC);
  while(ADCSRA & (1 << ADSC));
  return ADC;
}