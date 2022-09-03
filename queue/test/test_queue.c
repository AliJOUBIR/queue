#define TEST
#ifdef TEST

#include "unity.h"

#include "queue.h"

#define DATA_SIZE (100)
    uint32_t data[DATA_SIZE];
    queue_t test_q =
    {
        .data_p = data,
        .data_size = sizeof(uint32_t),
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

void test_queue_InitFrontRearNegativOne(void)
{
    
    TEST_ASSERT_EQUAL_INT32(-1,test_q.front);
    TEST_ASSERT_EQUAL_INT32(-1,test_q.rear); 
}

void test_queue_ArrayResetAfterInit(void)
{
    uint32_t data_buffer;
    for (uint32_t i = 0; i < DATA_SIZE ; i++)
    {
        data_buffer = *((uint32_t*)test_q.data_p+i);
        TEST_ASSERT_EQUAL_HEX32(0, data_buffer);
    }
    TEST_ASSERT_EQUAL(test_q.data_size, sizeof(uint32_t));
}

void test_queue_IsEmptyAfterInit(void)
{
    
    TEST_ASSERT_EQUAL(QUEUE_EMPTY,queue_get_state(&test_q));
    
}

void test_queue_EnqueueReturnSuccessOperation(void) 
{
    uint32_t d = 13;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&d));
    
}

void test_queue_DequeueReturnEmpty(void) 
{
    uint32_t d;
    TEST_ASSERT_EQUAL(QUEUE_EMPTY,queue_dequeue(&test_q,&d));
    
}

void test_queue_EnqueueOnce(void) 
{
    uint32_t en = 0xdead;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    TEST_ASSERT_EQUAL(0,test_q.front);
    TEST_ASSERT_EQUAL(0,test_q.rear);
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_get_state(&test_q));
}

void test_queue_IsFullAfterDequeue(void) 
{
    uint32_t en = 0xdead;
    for (uint32_t i = 0; i < DATA_SIZE ; i++)
    {
        TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    }
    
    TEST_ASSERT_EQUAL(DATA_SIZE-1,test_q.rear);
    TEST_ASSERT_EQUAL(QUEUE_FULL,queue_get_state(&test_q));
}

void test_queue_DequeueReturnSuccess(void)
{
    uint32_t de ;
    uint32_t en = 0xdead;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de));
    TEST_ASSERT_EQUAL(QUEUE_EMPTY,queue_dequeue(&test_q,&de));
}

void test_queue_EnqueueDequeueValue(void)
{
    uint32_t de = 0;
    uint32_t en = 0;
    uint32_t databuff;

    en = 0x1234;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));

    en = 0xb00b;
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));

    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de)); 
    TEST_ASSERT_EQUAL_HEX(0x1234,de);
    
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de));
    TEST_ASSERT_EQUAL_HEX(0xb00b,de);
    
}



void test_queue_EnqueueUntilFullDequeueAllValue(void)
{
    uint32_t de ;
    uint32_t en_base = 0xdeadbeef;
    uint32_t en = en_base;
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
    uint32_t de ;
    uint32_t en_base = 0xdeadbeef;
    uint32_t en = en_base;
    while (queue_enqueue(&test_q,&en) == QUEUE_SUCCESS);

    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de));
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_dequeue(&test_q,&de));
    
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    TEST_ASSERT_EQUAL(QUEUE_SUCCESS,queue_enqueue(&test_q,&en));
    TEST_ASSERT_EQUAL(QUEUE_FULL,queue_enqueue(&test_q,&en));

}




#endif // TEST
