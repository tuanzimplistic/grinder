#ifndef __ADC_H__
#define __ADC_H__

#include <stdint.h>
#include "driver/gpio.h"

typedef enum {
    INPUT,
    OUTPUT,
    INPUT_PULLUP,
    INPUT_PULLDOWN
} pin_mode_t;

typedef enum {
    LOW,
    HIGH
} output_level_t;

typedef enum {
    ISR_LOW = GPIO_INTR_LOW_LEVEL,
    ISR_HIGH = GPIO_INTR_HIGH_LEVEL,
    ISR_CHANGE = GPIO_INTR_ANYEDGE,
    ISR_RISING = GPIO_INTR_POSEDGE,
    ISR_FALLING = GPIO_INTR_NEGEDGE
} isr_mode_t;

typedef void (*isr_handler) (void);
void pin_mode(uint32_t pin, pin_mode_t mode);
void attachInterrupt(uint32_t pin, isr_handler handler, isr_mode_t mode);
int pin_read(uint32_t pin);
void pin_write(uint32_t pin, output_level_t level);

#endif