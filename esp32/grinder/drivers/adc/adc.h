#ifndef __ADC_H__
#define __ADC_H__

#include <stdint.h>

void analog_init(void);

uint16_t analog_read(uint8_t pin);

#endif