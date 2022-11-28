#include "src/queue.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
















uint16_t data[(100)];

queue_t test_q =

{

    .data_p = data,

    .data_size = sizeof(uint16_t),

    .queue_size = (100)

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

        .data_p = 

                 ((void *)0)

                     ,

        .data_size = sizeof(uint16_t),

        .queue_size = (100)

    };

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_ERROR)), (UNITY_INT)((queue_init(&test_q_null))), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);



    test_q_null.data_size = 0;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_ERROR)), (UNITY_INT)((queue_init(&test_q_null))), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);



    test_q_null.data_size = -213;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_ERROR)), (UNITY_INT)((queue_init(&test_q_null))), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);



    test_q_null.queue_size = 0;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_ERROR)), (UNITY_INT)((queue_init(&test_q_null))), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);



    test_q_null.queue_size = -487;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_ERROR)), (UNITY_INT)((queue_init(&test_q_null))), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

}



void test_queue_InitFrontRearNegativOne(void)

{

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((-1)), (UNITY_INT)(UNITY_INT32)((test_q.front)), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((-1)), (UNITY_INT)(UNITY_INT32)((test_q.rear)), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT32);

}



void test_queue_ArrayResetAfterInit(void)

{

    uint16_t data_buffer;

    for (uint32_t i = 0; i < (100) ; i++)

    {

        data_buffer = *((uint16_t*)test_q.data_p+i);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((0)), (UNITY_INT)(UNITY_INT32)((data_buffer)), (

       ((void *)0)

       ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX32);

    }

    UnityAssertEqualNumber((UNITY_INT)((test_q.data_size)), (UNITY_INT)((sizeof(uint16_t))), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

}



void test_queue_IsEmptyAfterInit(void)

{



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_EMPTY)), (UNITY_INT)((queue_get_state(&test_q))), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);



}



void test_queue_EnqueueReturnSuccessOperation(void)

{

    uint16_t d = 13;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&d))), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);



}



void test_queue_DequeueReturnEmpty(void)

{

    uint16_t d;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_EMPTY)), (UNITY_INT)((queue_dequeue(&test_q,&d))), (

   ((void *)0)

   ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);



}



void test_queue_EnqueueOnce(void)

{

    uint16_t en = 0xdead;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((test_q.front)), (

   ((void *)0)

   ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((test_q.rear)), (

   ((void *)0)

   ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_get_state(&test_q))), (

   ((void *)0)

   ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);

}



void test_queue_IsFullAfterDequeue(void)

{

    uint16_t en = 0xdead;

    for (uint32_t i = 0; i < (100) ; i++)

    {

        UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

       ((void *)0)

       ), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

    }



    UnityAssertEqualNumber((UNITY_INT)(((100)-1)), (UNITY_INT)((test_q.rear)), (

   ((void *)0)

   ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_FULL)), (UNITY_INT)((queue_get_state(&test_q))), (

   ((void *)0)

   ), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT);

}



void test_queue_DequeueReturnSuccess(void)

{

    uint16_t de ;

    uint16_t en = 0xdead;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_EMPTY)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

}



void test_queue_EnqueueDequeueValue(void)

{

    uint16_t de = 0;

    uint16_t en = 0;

    uint16_t databuff;



    en = 0x1234;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_INT);



    en = 0xb00b;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)(((uint16_t)0x1234)), (UNITY_INT)(UNITY_INT32)((de)), (

   ((void *)0)

   ), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_HEX32);



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(135), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)(((uint16_t)0xb00b)), (UNITY_INT)(UNITY_INT32)((de)), (

   ((void *)0)

   ), (UNITY_UINT)(136), UNITY_DISPLAY_STYLE_HEX32);



}







void test_queue_EnqueueUntilFullDequeueAllValue(void)

{

    uint16_t de ;

    uint16_t en_base = (uint16_t)0xdeadbeef;

    uint16_t en = en_base;

    while (queue_enqueue(&test_q,&en) == QUEUE_SUCCESS)

    {

        en++;

    }



    while (queue_dequeue(&test_q,&de) == QUEUE_SUCCESS)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((en_base)), (UNITY_INT)(UNITY_INT32)((de)), (

       ((void *)0)

       ), (UNITY_UINT)(154), UNITY_DISPLAY_STYLE_HEX32);

        en_base++;

    }



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_EMPTY)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_INT);

}





void test_queue_Circular(void)

{

    uint16_t de ;

    uint16_t en_base = (uint16_t)0xdeadbeef;

    uint16_t en = en_base;

    while (queue_enqueue(&test_q,&en) == QUEUE_SUCCESS);



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(170), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(172), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(173), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_FULL)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(174), UNITY_DISPLAY_STYLE_INT);



}
