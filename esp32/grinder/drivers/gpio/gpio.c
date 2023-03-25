#include <stdint.h>
#include "log.h"
#include "gpio.h"

static const char *TAG = "GPIO";

void pin_mode(uint32_t pin, pin_mode_t mode)
{
    uint64_t pin_bit_mask;

    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    if(mode == INPUT || mode == INPUT_PULLUP || mode == INPUT_PULLDOWN)
    {
        io_conf.mode = GPIO_MODE_INPUT;
    }
    else
    {
        io_conf.mode = GPIO_MODE_OUTPUT;
    }
    pin_bit_mask = io_conf.pin_bit_mask;
    io_conf.pin_bit_mask = pin_bit_mask | (1ULL << pin);
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    if(mode == INPUT_PULLUP)
    {
        io_conf.pull_up_en = 1;
    }
    if(mode == INPUT_PULLDOWN)
    {
        io_conf.pull_down_en = 1;
    }
    gpio_config(&io_conf);
}

void attachInterrupt(uint32_t pin, isr_handler handler, isr_mode_t mode)
{
    esp_err_t err = gpio_set_intr_type(pin, mode);
    if(err != ESP_OK)
    {
        l(LOG_ERROR, TAG, "error enable interrupt on pin %d", pin);
    }
    else
    {
        err = gpio_isr_handler_add(pin, (gpio_isr_t)handler, (void *)pin);
        if(err != ESP_OK)
        {
            l(LOG_ERROR, TAG, "error enable interrupt on pin %d", pin);
        }
    }
}

int pin_read(uint32_t pin)
{
    return gpio_get_level(pin);
}

void pin_write(uint32_t pin, output_level_t level)
{
    gpio_set_level(pin, level);
}