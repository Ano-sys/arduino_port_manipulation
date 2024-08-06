#include "lib_select.h"

#ifdef UNO_H
  #include "uno.h"
#elif defined MEGA2560_H
  #include "mega2560.h"
#endif

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
// gets the Index of the given element in the given array, returns -1 if not found
#define ARRAY_INDEXOF(array, element) ({ int* a = array; int index = -1; while(*a){ if(*a == element) { index = a - array; } a++; } index; })

static volatile uint8_t *pin_def_register;      // pin defination registers, PORT*, PIN*, DDR*
static uint8_t bitmask;                    // mask to select bit in registers
static int last_pin = 0;
static PIN_OPERATION last_op = -1;

void setBitmask(int bit){
  bitmask = 0x01;         // general 1 in the first place
  bitmask <<= bit;        // shift the 1 in the bitmask bit steps to the left
}

// sets the global variables pin_def_reg to the desired DDR*, PORT* or PIN* register and bitmask to the desired bit for the right pin
uint8_t distinguishManipulationRegister(int pin, PIN_OPERATION op){
  static int i = -1;                                    // remember the last index, if pin is equal but operation not, the loop does not need to be run again
  if(last_pin == pin && last_op == op) return 0;
  if(last_pin == pin) goto takeAction;                  // if the pin is the same but the operation has changed just get the new register for this operation
  for(i = 0; i < ARRAY_SIZE(registers); i++){           // move through all registered defined in the included header
    int index;
    if((index = ARRAY_INDEXOF(registers[i], pin)) != -1){   // find the register which is responsible for the pin
      last_pin = pin;
      setBitmask(index);                                    // set a bitmask to determine the right pin in the register
      goto takeAction;
    }
  }
  return -1;

  // didn not want to write an extra function for that and jumps to the bottom are legit
  takeAction:
  pin_def_register = lookup_registers[i][op];           // get the register which is responsible for the operation
  last_op = op;
  return 0;
}

// xor's the bit for the corresponding pin in the PORT* register
int switchPinState(int pin){
  if(distinguishManipulationRegister(pin, HL) == -1) return -1;
  *pin_def_register ^= bitmask;
  return 0;
}

// sets the bit for the corresponding pin to 1 in the PORT* register
int setPinHigh(int pin){
  if(distinguishManipulationRegister(pin, HL) == -1) return -1;
  *pin_def_register |= bitmask;
  return 0;
}

// sets the bit for the corresponding pin to 0 in the PORT* register
int setPinLow(int pin){
  if(distinguishManipulationRegister(pin, HL) == -1) return -1; //     |             |            |             |             |             |
  // invert the bitmask and & it with the register ->                0x00110010 &= 0x11111111 ^ 0x00010000 => 0x00110010 &= 0x11101111 => 0x00100010
  *pin_def_register &= 0xFF ^ bitmask;
  return 0;
}

// sets the bit for the corresponding pin to 1 in the DDR* register
int setPinOutput(int pin){
  if(distinguishManipulationRegister(pin, IO) == -1) return -1;
  *pin_def_register |= bitmask;
  return 0;
}

// sets the bit for the corresponding pin to 0 in the DDR* register
int setPinInput(int pin){
  if(distinguishManipulationRegister(pin, IO) == -1) return -1;
  *pin_def_register &= 0xFF ^ bitmask;
  return 0;
}

// sets the bit for corresponding pin to 1 in the PORT* register
int setPinPullUp(int pin){
  if(distinguishManipulationRegister(pin, HL) == -1) return -1;
  *pin_def_register |= bitmask;
  return 0;
}

// sets the bit for corresponding pin to 0 in the PORT* register
int setPinPullDown(int pin){
  if(distinguishManipulationRegister(pin, HL) == -1) return -1;
  *pin_def_register &= 0xFF ^ bitmask;
  return 0;
}

// gets the state HIGH or LOW from bit for corresponding pin in the PIN* register
int getPinState(int pin){
  if(distinguishManipulationRegister(pin, GET) == -1) return -1;
  return (*pin_def_register & bitmask) == 0 ? LOW : HIGH; // actually this would return 0, 1, 2, 4, 8, 16, 32, 64, 128 -> 0x10000000 = 128
}

int getAnalogPinState(int pin){
  return -1;
}
