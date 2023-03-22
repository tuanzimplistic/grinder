#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdinit.h>

typedef enum {

} gpio_isr_detect_t;

typedef enum {
    GPIO_IN;
    GPIO_OUT;
} gpio_mode_t;

typedef void (*gpio_interrupt_handler)(void);
void gpio_set_mode(gpio_mode_t mode);
void gpio_read_pin(uint8_t pin);
void gpio_write_pin(uint8_t pin);
void gpio_attach_interrupt(uint8_t pin, gpio_interrupt_handler func, gpio_isr_detect_t detect_type);

#endif