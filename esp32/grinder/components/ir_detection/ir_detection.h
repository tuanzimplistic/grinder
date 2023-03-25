#ifndef __IR_DETECT_H__
#define __IR_DETECT_H__ 

#include "base_message.h"
#include "observer.h" 

typedef enum {
    IR_DETECTION_LEVEL_OK,                     
    IR_DETECTION_LEVEL_CRITICAL,
    IR_DETECTION_LEVEL_EMPTY
} ir_detection_level_t;

typedef struct {
    int ir_detection_range;
    base_message_t base;
    ir_detection_level_t level;
    uint8_t ir_detection_id;
} ir_detection_message_t;

void init_ir_detection(void);
void register_observer_ir_detection(observer_t *observer);
void start_ir_detection(void);

#endif