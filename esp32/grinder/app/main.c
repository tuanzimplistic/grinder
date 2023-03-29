#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "led.h"
#include "loadcell.h"
#include "ir_detection.h"
#include "ls_detection.h"
#include "observer.h"
#include "log.h"
#include "micropy.h"

static const char *TAG =  "application";

static observer_t ir_detection_observer;
static ir_detection_message_t ir_detection_notify;
static SemaphoreHandle_t ir_detection_level_mutex;

static void ir_detection_sensors_update(void *message)
{
    xSemaphoreTake( ir_detection_level_mutex, portMAX_DELAY );
    ir_detection_notify = *((ir_detection_message_t *)message);
    xSemaphoreGive( ir_detection_level_mutex );
}

static void app_init_for_ir_detection()
{
    init_ir_detection();
    ir_detection_level_mutex = xSemaphoreCreateMutex();
    ir_detection_observer.update = ir_detection_sensors_update;
    ir_detection_observer.id = 11;
    register_observer_ir_detection(&ir_detection_observer);
    start_ir_detection();
}

static void application_task(void* args)
{
    while(1) 
    {
        xSemaphoreTake( ir_detection_level_mutex, portMAX_DELAY );
        l(LOG_INFO, TAG, "app task received message %d from sensor id %d", \
                            ir_detection_notify.ir_detection_range, ir_detection_notify.ir_detection_id);
        xSemaphoreGive( ir_detection_level_mutex );
        vTaskDelay(10);
    }
}

void app_main(void)
{
    app_init_for_ir_detection();
    init_ls_detection();
    start_ls_detection();
    xTaskCreate(application_task, "application_task", 3072, NULL, uxTaskPriorityGet(NULL), NULL); 
    start_micropy();
}
