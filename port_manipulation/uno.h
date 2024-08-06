// #define UNO_H
#include <Arduino.h>
#define uint8_t unsigned char

#define A0  14
#define A1  15
#define A2  16
#define A3  17
#define A4  18
#define A5  19

volatile uint8_t *lookup_registers[][3] = {
  { &PORTB, &DDRB, &PINB },
  { &PORTC, &DDRC, &PINC },
  { &PORTD, &DDRD, &PIND },
};

typedef enum{
  B = 0,
  C,
  D,
}REGISTERS;

typedef enum{
  HL = 0,       // set pin High or Low
  IO,           // label pin as Input or Output
  GET           // get the state of the pin
}PIN_OPERATION;

int portB[] = { 8,  9, 10, 11, 12, 13, -1, -1};
int portC[] = {A0, A1, A2, A3, A4, A5, -1, -1};
int portD[] = { 0,  1,  2,  3,  4,  5,  6,  7};

int *registers[] = {portB, portC, portD};
