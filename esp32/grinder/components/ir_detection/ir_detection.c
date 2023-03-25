#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ir_detection.h"
#include "log.h"
#include "adc.h"          

#define MAX_OBSERVERS   3

#define TASK_PERIOD     500

static subject_t ir_detection_subject;
static observer_t *observers[MAX_OBSERVERS];

static void task_ir_detection(void* args)
{
    uint8_t ir_detection_id = 0;
    for(;;) 
    {
        ir_detection_message_t message;
        message.ir_detection_id = ir_detection_id;
        message.ir_detection_range = analog_read(34);
        message.level = IR_DETECTION_LEVEL_CRITICAL;
        ir_detection_id ++;
        notify(&ir_detection_subject, (void *)&message);
        vTaskDelay(pdMS_TO_TICKS(TASK_PERIOD));
    }

    vTaskDelay(pdMS_TO_TICKS(TASK_PERIOD));
    vTaskDelete(NULL);
}

void init_ir_detection(void)
{
    analog_init();
    init(&ir_detection_subject, MAX_OBSERVERS, observers);
}

void register_observer_ir_detection(observer_t *observer)
{
    attach(&ir_detection_subject, observer);
}

void start_ir_detection(void)
{
    xTaskCreate(task_ir_detection, "task_ir_detection", 3072, NULL, uxTaskPriorityGet(NULL), NULL);
}

