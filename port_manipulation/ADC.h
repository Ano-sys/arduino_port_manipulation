#ifndef ADC_H  
#define ADC_H  

#ifndef uint8_t
  #define uint8_t unsigned char
#endif

void initADC(uint8_t);
int readADC(uint8_t);

#endif