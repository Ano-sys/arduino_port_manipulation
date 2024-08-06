#define PORT_MANIPULATION_H

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
int getAnalogPinState(int);
