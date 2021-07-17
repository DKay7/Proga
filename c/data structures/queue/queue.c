#include <assert.h>
#include <stdio.h>
#include "queue.h"

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
const hummingbird_type HUMMINGBIRD = (hummingbird_type) 0xBADDED;

int queue_exit_code = 0;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

Queue* QueueCtor()
{   
    
    Queue* queue = (Queue*) calloc(1, sizeof(Queue));

    if(queue == NULL)
    {
        queue_exit_code = QUEUE_MEMORY_ALLOC_ERROR + QUEUE_CTOR_CODE;
        return NULL;
    }

    queue->start_bird = HUMMINGBIRD;
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    queue->hash = HashSum(queue);
    queue->end_bird = HUMMINGBIRD;

    return queue;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void QueuePush(Queue* queue, queue_type data)
{   
    assert(queue != NULL);
    
    QNode* new_node = (QNode*) calloc(1, sizeof(QNode));

    if (!new_node)
    {
        queue_exit_code = QUEUE_MEMORY_ALLOC_ERROR + QUEUE_PUSH_CODE;
        return;
    }

    if (queue->head and queue->tail)
    {   
        queue->tail->next = new_node;
        new_node->prev = queue->tail;
        queue->tail = new_node;
    }

    else if (!queue->head)
    {
        queue->head = new_node;
        queue->tail = new_node;
    }

    queue->tail->next = NULL;
    queue->tail->data = data;

    queue->size += 1;
    queue->hash = HashSum(queue);
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

queue_type QueuePop(Queue* queue)
{    
    assert(queue != NULL);
    queue_type data = 0;


    if (queue->head)
    {   
        QNode* node_to_pop = queue->head;
        data = node_to_pop->data;
        queue->head = node_to_pop->next;
        queue->hash = HashSum(queue);
        queue->size -= 1;
        free(node_to_pop);
    }

    return data;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int QueueValidity(Queue* queue, const int func_code)
{
    if(queue->start_bird != HUMMINGBIRD)
    {
        queue_exit_code = QUEUE_WRONG_START_HUMMINGBIRD + func_code;
        return 0;
    }

    if(queue->start_bird != HUMMINGBIRD)
    {
        queue_exit_code = QUEUE_WRONG_END_HUMMINGBIRD + func_code;
        return 0;
    }

    if(queue->hash != HashSum(queue))
    {
        queue_exit_code = QUEUE_WRONG_HASH_SUM + func_code;
        return 0;
    }


    return 1;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int QueueDumpFunction(Queue* queue, const char* func_name, int line_number, const char* file_name, const char *queue_name)
{   
    int check = QueueValidity(queue, QUEUE_DUMP_CODE);

    if(check)
    {
        printf ("\n\nQueue[OK]: ");
    }

    else
    {
        printf ("\n\nQueue[ERROR][CODE: 0x%X]", queue_exit_code);
    }

    printf ("[%p] ", &queue->head);

    printf ("\"%s\" %s line %d %s'\n", queue_name, func_name, line_number, file_name);

    if(!check)
        QueuePrintExitCode();

    printf ("\n{\n");              
                                                
    printf (" size = %lX \n", queue->size);            
                                                    
    printf (" hash_sum = %llX\n", queue->hash);       
                                                    
    printf ("\t{\n"); 

    QNode* node = queue->head;
    size_t i = 0;
    while(node)
    {
        printf ("   ");      
        printf ("\t  ");

        printf  ("[%ld] = %d \n", i, node->data);
        node = node->next;
        i += 1;
    }

    printf ("\t}\n}\n"); 

    return 0;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

unsigned long long HashSum(Queue* queue)
{
    assert(queue != NULL);

    unsigned long long hash = 42 << sizeof(queue_type);

    QNode* node = queue->head;

    while (node)
    {
        hash += (uintptr_t) node->data;
        hash << sizeof(queue_type);
        node = node->next;
    }

    return hash;
}

void QueuePrintExitCode ()
{   
    int func_code = queue_exit_code % 256;
    int err_code = queue_exit_code / 256 * 256;
    
    if (err_code == QUEUE_FINE)
    {
        printf ("No errors found\n");
        return;
    }

    switch (err_code)
    {
        case QUEUE_MEMORY_ALLOC_ERROR:
            printf ("Memory allocation error in ");
            break;

        case QUEUE_WRONG_START_HUMMINGBIRD:
            printf ("Changes in start hummingbird founded in ");
            break;

        case QUEUE_WRONG_END_HUMMINGBIRD:
            printf ("Changes in end hummingbird founded in ");
            break;

        case QUEUE_WRONG_HASH_SUM:
            printf ("Mismacth of hash sum founded in ");
            break;

        default:
            printf ("Unkwonw exception with number %X in ", err_code);
            break;
    }


    switch (func_code)
    {
        case QUEUE_CTOR_CODE:
            printf ("func QueueCtor()\n");
            break;

        case QUEUE_PUSH_CODE:
            printf ("func QueuePush()\n");
            break;

        case QUEUE_POP_CODE:
            printf ("func QueuePop()\n");
            break;

        case QUEUE_DUMP_CODE:
            printf ("macro QueueDump()\n");
            break;

        default:
            printf ("unkwonw func with number %X\n", func_code);
            break;
    }

    return;
}

void QueueUnitTest ()
{   
    Queue queue1 = *QueueCtor();
    Queue queue2 = *QueueCtor();
    Queue queue3 = *QueueCtor();

    char test1[] = "PRESS F TO PAY RESPECTS";
    char test2[] = "HAHA OFIGENNO";
    char test3[] = "42 or 97 hmmmmmmmm";

    for (int i = 0; test1[i]; i++)
        QueuePush (&queue1, test1[i]);

    for (int i = 0; test2[i]; i++)
        QueuePush (&queue2, test2[i]);

    for (int i = 0; test3[i]; i++)
        QueuePush (&queue3, test3[i]);

    QueueDump (&queue1);
    QueueDump (&queue2);
    QueueDump (&queue3);

    QueuePop (&queue1);
    QueuePop (&queue2);
    QueuePop (&queue3);

    printf("\n\nAFTER POPING:\n");

    QueueDump (&queue1);
    QueueDump (&queue2);
    QueueDump (&queue3);

}