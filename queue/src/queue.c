#include "queue.h"
#include <string.h>


queue_error_t queue_init(queue_t * const q)
{
    queue_error_t q_state;

    if ((q->data_p == NULL) || (q->data_size == 0) || (q->queue_size == 0))
    {
        q_state = QUEUE_ERROR;
    }
    else
    {
        q->front = -1;
        q->rear = -1;
        memset(q->data_p,0, (q->data_size)*(q->queue_size));
        q_state = QUEUE_SUCCESS;
    }
    return q_state;
}

queue_error_t queue_get_state(queue_t * const q)
{
    queue_error_t q_state;

    if ((q->front == -1) && (q->rear == -1))
    {
        q_state = QUEUE_EMPTY;
    }
    else if ((q->rear + 1)% q->queue_size == q->front)
    {
        q_state = QUEUE_FULL;
    }
    else
    {
        q_state = QUEUE_SUCCESS;
    }
    return q_state;
}

queue_error_t queue_enqueue(queue_t * const q, const void * const data)
{
    queue_error_t q_state;

 
    switch (queue_get_state(q))
    {
        case QUEUE_EMPTY:
            q->front = 0;
            q->rear = 0;
            q_state = QUEUE_SUCCESS;
            break;
        
        case QUEUE_FULL:
            q_state = QUEUE_FULL;
            break;

        case QUEUE_SUCCESS:
            q->rear = (q->rear + 1) % q->queue_size;
            q_state = QUEUE_SUCCESS;
            break;

        default:
            break;
    }


    if (q_state == QUEUE_SUCCESS)
    {
        memcpy( q->data_p+ (q->rear * q->data_size),data,q->data_size);
    }

    return q_state;
    
}



queue_error_t queue_dequeue(queue_t * const q, void * const data)
{
    queue_error_t q_state;

    switch (queue_get_state(q))
    {
        case QUEUE_EMPTY:
            q_state =  QUEUE_EMPTY;
            break;
        
        case QUEUE_FULL:
            memcpy(data, q->data_p+ (q->front * q->data_size),q->data_size);
            
            q->front = (q->front + 1) % q->queue_size;
            q_state = QUEUE_SUCCESS;
            break;

        case QUEUE_SUCCESS:
            memcpy(data, q->data_p+ (q->front * q->data_size),q->data_size);
         
            if (q->front == q->rear)
            {
                q->front = -1;
                q->rear  = -1;
            }
            else
            {
                q->front = (q->front + 1) % q->queue_size;
            }
            q_state = QUEUE_SUCCESS;
            break;

        default: 
            break;
    }


    return q_state;
}








