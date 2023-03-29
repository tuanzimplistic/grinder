#include "driver/gpio.h"
#include "led.h"


#define UI_LED_RED      6
#define UI_LED_GREEN    7
#define UI_LED_BLUE     8

#define CONNECT_LED_RED      9
#define CONNECT_LED_GREEN    10
#define CONNECT_LED_BLUE     11

#define GPIO_OUTPUT_PIN_SEL  ( (1ULL<<UI_LED_RED) | (1ULL<<UI_LED_GREEN) | (1ULL<<UI_LED_BLUE) | (1ULL<<CONNECT_LED_RED) | (1ULL<<CONNECT_LED_GREEN) | (1ULL<<CONNECT_LED_BLUE) )

void init_led(void)
{
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);
}

void set_ui_led(led_color_t color)
{
    gpio_set_level(UI_LED_RED, 0);
    gpio_set_level(UI_LED_GREEN, 0);
    gpio_set_level(UI_LED_BLUE, 0);
    switch(color)
    {
        case LED_RED: 
        {
            gpio_set_level(UI_LED_RED, 1);
            break;
        }
        case LED_GREEN: 
        {
            gpio_set_level(UI_LED_GREEN, 1);
            break;
        }
        case LED_BLUE: 
        {
            gpio_set_level(UI_LED_BLUE, 1);
            break;
        }
        case LED_OFF:
        default: 
            break;
    }
}

void set_connect_led(led_color_t color)
{
    gpio_set_level(CONNECT_LED_RED, 0);
    gpio_set_level(CONNECT_LED_GREEN, 0);
    gpio_set_level(CONNECT_LED_BLUE, 0);
    switch(color)
    {
        case LED_RED: 
        {
            gpio_set_level(CONNECT_LED_RED, 1);
            break;
        }
        case LED_GREEN: 
        {
            gpio_set_level(CONNECT_LED_GREEN, 1);
            break;
        }
        case LED_BLUE: 
        {
            gpio_set_level(CONNECT_LED_BLUE, 1);
            break;
        }
        case LED_OFF:
        default: 
            break;
    }
}