// #define MEGA2560_H
#include <Arduino.h>
#define uint8_t unsigned char

#define A0  54
#define A1  55
#define A2  56
#define A3  57
#define A4  58
#define A5  59
#define A6  60
#define A7  61

#define A8  62
#define A9  63
#define A10 64
#define A11 65
#define A12 66
#define A13 67
#define A14 68
#define A15 69

volatile uint8_t *lookup_registers[][3] = {
  { &PORTA, &DDRA, &PINA },
  { &PORTB, &DDRB, &PINB },
  { &PORTC, &DDRC, &PINC },
  { &PORTD, &DDRD, &PIND },
  { &PORTE, &DDRE, &PINE },
  { &PORTF, &DDRF, &PINF },
  { &PORTG, &DDRG, &PING },
  { &PORTH, &DDRH, &PINH },
  { &PORTJ, &DDRJ, &PINJ },
  { &PORTK, &DDRK, &PINK },
  { &PORTL, &DDRL, &PINL },
};

typedef enum{
  A = 0,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  J,
  K,
  L,
}REGISTERS;

typedef enum{
  HL = 0,       // set pin High or Low
  IO,           // label pin as Input or Output
  GET           // get the state of the pin
}PIN_OPERATION;

int portA[] = {22, 23, 24, 25, 26, 27, 28, 29};
int portB[] = {53, 52, 51, 50, 10, 11, 12, 13};
int portC[] = {37, 36, 35, 34, 33, 32, 31, 30};
int portD[] = {21, 20, 19, 18, -1, -1, -1, 38};
int portE[] = { 0,  1,  5,  2,  3, -1, -1, -1};
int portF[] = {A7, A6, A5, A4, A3, A2, A1, A0};
int portG[] = {41, 40, 39, -1, -1,  4, -1, -1};
int portH[] = {17, 16, -1,  6,  7,  8,  9, -1};
int portJ[] = {15, 14, -1, -1, -1, -1, -1, -1};
int portK[] = {A8, A9,A10,A11,A12,A13,A14,A15};
int portL[] = {49, 48, 47, 46, 45, 44, 43, 42};

int *registers[] = {portA, portB, portC, portD, portE, portF, portG, portH, portJ, portK, portL};
