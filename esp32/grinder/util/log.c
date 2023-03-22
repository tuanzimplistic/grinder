#include "log.h"
#include <stdarg.h>
#include <stdio.h>

#define LOG_BUFFER_SIZE 300

void l(log_level_t level, const char *tag, const char * format, ...)
{
    char buffer[LOG_BUFFER_SIZE];

    va_list args;
    va_start(args, format);
    vsnprintf(buffer, LOG_BUFFER_SIZE, format, args);
    va_end(args);

    switch(level)
    {
        case LOG_ERROR:
            ESP_LOGE(tag, "%s", buffer);
            break;
        case LOG_WARN:
            ESP_LOGW(tag, "%s", buffer);
            break;
        case LOG_INFO:
        default:
            ESP_LOGI(tag, "%s", buffer);
            break;
    }
    fflush(stdout);
}