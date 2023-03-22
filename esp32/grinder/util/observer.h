#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <stdint.h>

typedef struct {
    uint8_t id;
    void (*update)(void *message);
} observer_t;

typedef struct {
    uint8_t no_observers;
    observer_t **observers;
} subject_t;

void init(subject_t *subject, uint8_t no_observers, observer_t *observers[]);
void attach(subject_t *subject, observer_t *observer);
void detach(subject_t *subject, observer_t *observer);
void notify(subject_t *subject, void *message);

#endif