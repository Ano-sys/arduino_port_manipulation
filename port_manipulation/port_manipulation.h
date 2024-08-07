#ifndef PORT_MANIPULATION_H
#define PORT_MANIPULATION_H

#include <stdint.h>

#ifndef ADC_H
  #include "ADC.h"
#endif

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
// gets the Index of the given element in the given array, returns -1 if not found
#define ARRAY_INDEXOF(array, element) ({ int* a = array; int index = -1; while(*a){ if(*a == element) { index = a - array; } a++; } index; })

int switchPinState(int);
// sets the bit for the corresponding pin to 1 in the PORT* register
int setPinHigh(int);
// sets the bit for the corresponding pin to 0 in the PORT* register
int setPinLow(int);
// sets the bit for the corresponding pin to 1 in the DDR* register
int setPinOutput(int);
// sets the bit for the corresponding pin to 0 in the DDR* register
int setPinInput(int);
// sets the bit for corresponding pin to 1 in the PORT* register
int setPinPullUp(int);
// sets the bit for corresponding pin to 0 in the PORT* register
int setPinPullDown(int);
// gets the state HIGH or LOW from bit for corresponding pin in the PIN* register
int getPinState(int);
int getAnalogPinValue(int);

#endif
