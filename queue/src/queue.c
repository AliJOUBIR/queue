#include "queue.h"
#include <string.h>


void queue_init(queue_t * const q)
{
    q->front = -1;
    q->rear = -1;
    memset(q->data_p,0, (q->data_size)*(q->queue_size));
    return;
}

queue_error_t queue_get_state(queue_t * const q)
{
    if ((q->front == -1) && (q->rear == -1))
    {
        return QUEUE_EMPTY;
    }
    else if ((q->rear + 1)% q->queue_size == q->front)
    {
        return QUEUE_FULL;
    }
    else
    {
        return QUEUE_SUCCESS;
    }
}

queue_error_t queue_enqueue(queue_t * const q, const void * const data)
{
    queue_error_t queue_state;

 
    switch (queue_get_state(q))
    {
        case QUEUE_EMPTY:
            q->front = 0;
            q->rear = 0;
            queue_state = QUEUE_SUCCESS;
            break;
        
        case QUEUE_FULL:
            queue_state = QUEUE_FULL;
            break;

        case QUEUE_SUCCESS:
            q->rear = (q->rear + 1) % q->queue_size;
            queue_state = QUEUE_SUCCESS;
            break;

        default:
            break;
    }


    if (queue_state == QUEUE_SUCCESS)
    {
        memcpy( q->data_p+ (q->rear * q->data_size),data,sizeof(uint32_t));
    }

    return queue_state;
    
}



queue_error_t queue_dequeue(queue_t * const q, void * const data)
{
    queue_error_t queue_state;

    switch (queue_get_state(q))
    {
        case QUEUE_EMPTY:
            queue_state =  QUEUE_EMPTY;
            break;
        
        case QUEUE_FULL:
            memcpy(data, q->data_p+ (q->front * q->data_size),sizeof(uint32_t));
            
            q->front = (q->front + 1) % q->queue_size;
            queue_state = QUEUE_SUCCESS;
            break;

        case QUEUE_SUCCESS:
            memcpy(data, q->data_p+ (q->front * q->data_size),sizeof(uint32_t));
            
            if (q->front == q->rear)
            {
                q->front = -1;
                q->rear  = -1;
            }
            else
            {
                q->front = (q->front + 1) % q->queue_size;
            }
            queue_state = QUEUE_SUCCESS;
            break;

        default: 
            break;
    }


    return queue_state;
}








