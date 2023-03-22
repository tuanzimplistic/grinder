#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "hopper_ir_sensor.h"
#include "log.h"           

#define MAX_OBSERVERS   3

#define TASK_PERIOD     500

static subject_t hopper_ir_sensor_subject;
static observer_t *observers[MAX_OBSERVERS];

static void task_hopper_ir_sensors(void* args)
{
    uint8_t sensor_id = 0;
    for(;;) 
    {
        hopper_message_t sensor_message;
        sensor_message.sensor_id = sensor_id;
        sensor_message.level = HOPPER_LEVEL_CRITICAL;
        sensor_id ++;
        notify(&hopper_ir_sensor_subject, (void *)&sensor_message);
        vTaskDelay(pdMS_TO_TICKS(TASK_PERIOD));
    }

    vTaskDelay(pdMS_TO_TICKS(TASK_PERIOD));
    vTaskDelete(NULL);
}

void init_hopper_ir_sensors(void)
{
    init(&hopper_ir_sensor_subject, MAX_OBSERVERS, observers);
}

void register_observer_hopper_ir_sensors(observer_t *observer)
{
    attach(&hopper_ir_sensor_subject, observer);
}

void start_hopper_ir_sensors(void)
{
    xTaskCreate(task_hopper_ir_sensors, "task_hopper_ir_sensors", 3072, NULL, uxTaskPriorityGet(NULL), NULL);
}

