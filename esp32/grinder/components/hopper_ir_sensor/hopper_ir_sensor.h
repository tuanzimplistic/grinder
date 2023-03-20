#ifndef __HOPPER_IR_SENSOR_H__
#define __HOPPER_IR_SENSOR_H__ 

#include "observer.h" 

typedef enum {
    HOPPER_LEVEL_OK,                     
    HOPPER_LEVEL_CRITICAL,
    HOPPER_LEVEL_EMPTY
} hopper_level_t;

typedef struct {
    hopper_level_t level;
    uint8_t sensor_id;
} hopper_message_t;

void init_hopper_ir_sensors(void);
void register_observer_hopper_ir_sensors(observer_t *observer);
void start_hopper_ir_sensors(void);

#endif