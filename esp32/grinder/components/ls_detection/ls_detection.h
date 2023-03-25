#ifndef __LIMIT_SWITCH_H__
#define __LIMIT_SWITCH_H__

#include <stdint.h>
#include "base_message.h"

typedef enum {
    LS_DETECTION_ON,
    LS_DETECTION_OFF
} ls_detection_level_t;

typedef struct {
	base_message_t base;
    ls_detection_level_t level; 
    uint8_t ls_detection_id;
} ls_detection_message_t;

void init_ls_detection(void);

void start_ls_detection(void);

#endif