#include "observer.h"
#include "log.h"

static const char * TAG = "observer";

void init(subject_t *subject, uint8_t no_observers, observer_t *observers[])
{
    subject->no_observers = no_observers;
    if(observers != NULL)
    {
        subject->observers = observers;
        for(uint8_t i = 0; i < subject->no_observers; i++)
        {
            subject->observers[i] = NULL;
        }
    }
    else
    {
        l(LOG_ERROR, TAG, "%s", "observers is null");
    }
}

void attach(subject_t *subject, observer_t *observer)
{
    uint8_t i;
    if(subject->observers != NULL)
    {
        for(i = 0; i < subject->no_observers; i++)
        {
            if(subject->observers[i] == NULL && observer != NULL)
            {
            subject->observers[i] = observer; 
            break;
            }
        }
        if(i == subject->no_observers)
        {
            l(LOG_ERROR, TAG, "%s", "add more observers elements");
        }
    }
    else
    {
        l(LOG_ERROR, TAG, "%s", "subject->observers is null");
    }
}

void deattach(subject_t *subject, observer_t *observer)
{
    uint8_t i;
    if(subject->observers != NULL)
    {
        for(i = 0; i < subject->no_observers; i++)
        {
            if(subject->observers[i] == observer)
            {
                subject->observers[i] = NULL;
                break;
            }
        }
        if(i == subject->no_observers)
        {
            l(LOG_ERROR, TAG, "%s", "can not find observer");
        }
    }
    else
    {
        l(LOG_ERROR, TAG, "%s", "subject->observers is null");
    }
}

void notify(subject_t *subject, void *message)
{
    if(subject->observers != NULL)
    {
        for(uint8_t i = 0; i < subject->no_observers; i++)
        {
            if(subject->observers[i] != NULL)
            {
                l(LOG_INFO, TAG, "notify observer %d", subject->observers[i]->id);
                if(subject->observers[i]->update != NULL)
                {
                    subject->observers[i]->update(message);
                }
                else
                {
                    l(LOG_ERROR, TAG, "observers[%d]->update is null", i);
                }
            }
        }
    }
    else
    {
        l(LOG_ERROR, TAG, "%s", "subject->observers is null");
    }
}
