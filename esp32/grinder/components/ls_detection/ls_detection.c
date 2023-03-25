#include "ls_detection.h"
#include "gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void init_ls_detection(void)
{
    pin_mode(4, OUTPUT);
}

static void task_ls_detection(void* args)
{
    for(;;) 
    {
        pin_write(4, HIGH);
        vTaskDelay(pdMS_TO_TICKS(1000));
        pin_write(4, LOW);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void start_ls_detection(void)
{
    xTaskCreate(task_ls_detection, "task_ls_detection", 2048, NULL, uxTaskPriorityGet(NULL), NULL);
}