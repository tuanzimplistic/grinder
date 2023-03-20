#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "led.h"
#include "loadcell.h"
#include "hopper_ir_sensor.h"
#include "observer.h"
#include "log.h"

static const char *TAG =  "application";

static observer_t hopper_observer;
static hopper_message_t hopper_notify;
static SemaphoreHandle_t hopper_level_mutex;

static void hopper_sensors_update(void *message)
{
    xSemaphoreTake( hopper_level_mutex, portMAX_DELAY );
    hopper_notify = *((hopper_message_t *)message);
    l(LOG_INFO, TAG, "updated message %d from sensor id %d", hopper_notify.level, hopper_notify.sensor_id);
    xSemaphoreGive( hopper_level_mutex );
}

static void app_init_for_hopper()
{
    init_hopper_ir_sensors();
    hopper_level_mutex = xSemaphoreCreateMutex();
    hopper_observer.update = hopper_sensors_update;
    hopper_observer.id = 11;
    register_observer_hopper_ir_sensors(&hopper_observer);
    start_hopper_ir_sensors();
}

static void application_task(void* args)
{
    while(1) 
    {
        xSemaphoreTake( hopper_level_mutex, portMAX_DELAY );
        l(LOG_INFO, TAG, "app task received message %d from sensor id %d", hopper_notify.level, hopper_notify.sensor_id);
        xSemaphoreGive( hopper_level_mutex );
        vTaskDelay(10);
    }
}

void app_main(void)
{
    app_init_for_hopper();
    xTaskCreate(application_task, "application_task", 3072, NULL, uxTaskPriorityGet(NULL), NULL); 
}
