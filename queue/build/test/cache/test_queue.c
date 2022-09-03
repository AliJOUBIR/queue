#include "src/queue.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"












    uint32_t data[(100)];

    queue_t test_q =

    {

        .data_p = data,

        .data_size = sizeof(uint32_t),

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



void test_queue_InitFrontRearNegativOne(void)

{



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((-1)), (UNITY_INT)(UNITY_INT32)((test_q.front)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((-1)), (UNITY_INT)(UNITY_INT32)((test_q.rear)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT32);

}



void test_queue_ArrayResetAfterInit(void)

{

    uint32_t data_buffer;

    for (uint32_t i = 0; i < (100) ; i++)

    {

        data_buffer = *((uint32_t*)test_q.data_p+i);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((0)), (UNITY_INT)(UNITY_INT32)((data_buffer)), (

       ((void *)0)

       ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX32);

    }

    UnityAssertEqualNumber((UNITY_INT)((test_q.data_size)), (UNITY_INT)((sizeof(uint32_t))), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_INT);

}



void test_queue_IsEmptyAfterInit(void)

{



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_EMPTY)), (UNITY_INT)((queue_get_state(&test_q))), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);



}



void test_queue_EnqueueReturnSuccessOperation(void)

{

    uint32_t d = 13;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&d))), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);



}



void test_queue_DequeueReturnEmpty(void)

{

    uint32_t d;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_EMPTY)), (UNITY_INT)((queue_dequeue(&test_q,&d))), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);



}



void test_queue_EnqueueOnce(void)

{

    uint32_t en = 0xdead;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((test_q.front)), (

   ((void *)0)

   ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((test_q.rear)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_get_state(&test_q))), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);

}



void test_queue_IsFullAfterDequeue(void)

{

    uint32_t en = 0xdead;

    for (uint32_t i = 0; i < (100) ; i++)

    {

        UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

       ((void *)0)

       ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

    }



    UnityAssertEqualNumber((UNITY_INT)(((100)-1)), (UNITY_INT)((test_q.rear)), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_FULL)), (UNITY_INT)((queue_get_state(&test_q))), (

   ((void *)0)

   ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);

}



void test_queue_DequeueReturnSuccess(void)

{

    uint32_t de ;

    uint32_t en = 0xdead;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_EMPTY)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT);

}



void test_queue_EnqueueDequeueValue(void)

{

    uint32_t de = 0;

    uint32_t en = 0;

    uint32_t databuff;



    en = 0x1234;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);



    en = 0xb00b;

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((0x1234)), (UNITY_INT)(UNITY_INT32)((de)), (

   ((void *)0)

   ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_HEX32);



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((0xb00b)), (UNITY_INT)(UNITY_INT32)((de)), (

   ((void *)0)

   ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_HEX32);



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

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((en_base)), (UNITY_INT)(UNITY_INT32)((de)), (

       ((void *)0)

       ), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_HEX32);

        en_base++;

    }



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_EMPTY)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_INT);

}





void test_queue_Circular(void)

{

    uint32_t de ;

    uint32_t en_base = 0xdeadbeef;

    uint32_t en = en_base;

    while (queue_enqueue(&test_q,&en) == QUEUE_SUCCESS);



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_dequeue(&test_q,&de))), (

   ((void *)0)

   ), (UNITY_UINT)(146), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(148), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_SUCCESS)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(149), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((QUEUE_FULL)), (UNITY_INT)((queue_enqueue(&test_q,&en))), (

   ((void *)0)

   ), (UNITY_UINT)(150), UNITY_DISPLAY_STYLE_INT);



}
