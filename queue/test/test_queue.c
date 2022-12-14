#ifdef TEST

#include "unity.h"

#include "queue.h"

#define DATA_SIZE (100)

#define DATA_TYPE uint16_t
#define DATA_TYPE_SIZE sizeof(DATA_TYPE)
DATA_TYPE data[DATA_SIZE];
queue_t test_q =
{
    .data_p = data,
    .data_size = DATA_TYPE_SIZE,
    .queue_size = DATA_SIZE
};

void setUp(void)
{
    queue_init(&test_q);
}

void tearDown(void)
{
    queue_init(&test_q);
}

void test_queue_InitWithWrongData(void)
{
    queue_t test_q_null =
    {
        .data_p = NULL,
        .data_size = DATA_TYPE_SIZE,
        .queue_size = DATA_SIZE
    };
    TEST_ASSERT_EQUAL(QUEUE_ERROR,queue_init(&test_q_null));

    test_q_null.data_size = 0;
    TEST_ASSERT_EQUAL(QUEUE_ERROR,queue_init(&test_q_null));

    test_q_null.data_size = -213;
    TEST_ASSERT_EQUAL(QUEUE_ERROR,queue_init(&test_q_null));

    test_q_null.queue_size = 0;
    TEST_ASSERT_EQUAL(QUEUE_ERROR,queue_init(&test_q_null));

    test_q_null.queue_size = -487;
    TEST_ASSERT_EQUAL(QUEUE_ERROR,queue_init(&test_q_null));
}

void test_queue_InitFrontRearNegativOne(void)
{
    TEST_ASSERT_EQUAL_INT32(-1,test_q.front);
    TEST_ASSERT_EQUAL_INT32(-1,test_q.rear); 
}

void test_queue_ArrayResetAfterInit(void)
{
    DATA_TYPE data_buffer;
    for (uint32_t i = 0; i < DATA_SIZE ; i++)
    {
        data_buffer = *((DATA_TYPE*)test_q.data_p+i);
        TEST_ASSERT_EQUAL_HEX32(0, data_buffer);
    }
    TEST_ASSERT_EQUAL(test_q.data_size, DATA_TYPE_SIZE);
}

void test_queue_IsEmptyAfterInit(void)
{
    
    TEST_ASSERT_EQUAL(QUEUE_EMPTY,queue_get_state(&test_q));
    
}

void test_queue_EnqueueReturnSuccessOperation(void) 
{
    DATA_TYPE d = 13;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&d));
    
}

void test_queue_DequeueReturnEmpty(void) 
{
    DATA_TYPE d;
    TEST_ASSERT_EQUAL(QUEUE_EMPTY,queue_dequeue(&test_q,&d));
    
}

void test_queue_EnqueueOnce(void) 
{
    DATA_TYPE en = 0xdead;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    TEST_ASSERT_EQUAL(0,test_q.front);
    TEST_ASSERT_EQUAL(0,test_q.rear);
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_get_state(&test_q));
}

void test_queue_IsFullAfterDequeue(void) 
{
    DATA_TYPE en = 0xdead;
    for (uint32_t i = 0; i < DATA_SIZE ; i++)
    {
        TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    }
    
    TEST_ASSERT_EQUAL(DATA_SIZE-1,test_q.rear);
    TEST_ASSERT_EQUAL(QUEUE_FULL,queue_get_state(&test_q));
}

void test_queue_DequeueReturnSuccess(void)
{
    DATA_TYPE de ;
    DATA_TYPE en = 0xdead;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de));
    TEST_ASSERT_EQUAL(QUEUE_EMPTY,queue_dequeue(&test_q,&de));
}

void test_queue_EnqueueDequeueValue(void)
{
    DATA_TYPE de = 0;
    DATA_TYPE en = 0;
    DATA_TYPE databuff;

    en = 0x1234;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));

    en = 0xb00b;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));

    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de)); 
    TEST_ASSERT_EQUAL_HEX((DATA_TYPE)0x1234,de);
    
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de));
    TEST_ASSERT_EQUAL_HEX((DATA_TYPE)0xb00b,de);
    
}



void test_queue_EnqueueUntilFullDequeueAllValue(void)
{
    DATA_TYPE de ;
    DATA_TYPE en_base = (DATA_TYPE)0xdeadbeef;
    DATA_TYPE en = en_base;
    while (queue_enqueue(&test_q,&en) == QUEUE_SUCCESS)
    {
        en++;
    }

    while (queue_dequeue(&test_q,&de) == QUEUE_SUCCESS)
    {
        TEST_ASSERT_EQUAL_HEX(en_base,de);
        en_base++;
    }
 
    TEST_ASSERT_EQUAL(QUEUE_EMPTY,queue_dequeue(&test_q,&de));
}


void test_queue_Circular(void)
{
    DATA_TYPE de ;
    DATA_TYPE en_base = (DATA_TYPE)0xdeadbeef;
    DATA_TYPE en = en_base;
    while (queue_enqueue(&test_q,&en) == QUEUE_SUCCESS);

    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de));
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de));
    
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    TEST_ASSERT_EQUAL(QUEUE_FULL,queue_enqueue(&test_q,&en));

}




#endif // TEST
