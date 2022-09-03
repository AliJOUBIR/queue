#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    QUEUE_SUCCESS,
    QUEUE_EMPTY,
    QUEUE_FULL
}queue_error_t;

typedef struct
{
    void *data_p;
    uint32_t data_size;
    uint32_t queue_size;
    int32_t front;
    int32_t rear;
}queue_t;

void queue_init(queue_t * const q);

queue_error_t queue_get_state(queue_t * const q);

queue_error_t queue_enqueue(queue_t * const q, const void * const data);

queue_error_t queue_dequeue(queue_t * const q, void * const data);
#endif // QUEUE_H
