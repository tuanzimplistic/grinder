#ifndef __LOG_H__
#define __LOG_H__

#include "esp_log.h"

typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
} log_level_t;

void l(log_level_t level, const char *tag, const char * format, ...);

#endif