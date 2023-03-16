#ifndef __LED_H__
#define __lED_H__

typedef enum {
    LED_RED,
    LED_GREEN,
    LED_BLUE,
    LED_OFF
} led_color_t;

void init_led(void);

void set_ui_led(led_color_t color);

void set_connect_led(led_color_t color);

#endif