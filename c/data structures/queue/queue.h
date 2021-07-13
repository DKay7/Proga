#include <malloc.h>

#define and &&
#define or ||

typedef double queue_type;
typedef unsigned long long hummingbird_type;

extern const hummingbird_type HUMMINGBIRD;
extern int queue_exit_code;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

typedef struct QNode
{
    queue_type data;
    struct QNode* prev;
    struct QNode* next;  
} QNode;

typedef struct Queue
{
    hummingbird_type start_bird;
    QNode* head;
    QNode* tail;
    size_t size;
    unsigned long long hash;
    hummingbird_type end_bird;
} Queue;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

enum ExitCodes
{
    FINE                        = 0x000000,     //  If all is OK
    MEMORY_ALLOC_ERROR          = 0x080000,     //  Error while allocation memory in functions calloc/realloc
    WRONG_START_HUMMINGBIRD     = 0x090000,     //  Changes in start-hummingbird
    WRONG_END_HUMMINGBIRD       = 0x0A0000,     //  Changes in end-hummingbird
    WRONG_HASH_SUM              = 0x0B0000      //  Mismath with recorded hash-sum
};

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

enum FunctionNumbers
{
    QUEUE_CTOR_CODE       = 1,    //Code of QueueCtor()
    QUEUE_PUSH_CODE       = 2,    //Code of QueuePush()
    QUEUE_POP_CODE        = 3,    //Code of QueuePop()
    QUEUE_VALIDATY_CODE   = 4,    //Code of QueueValidaty()
    QUEUE_DUMP_CODE       = 5     //Code of macroQueuekDump()
};

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void QueuePush(Queue*, double);
double QueuePop(Queue*);

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxQueue
Queue *QueueCtor();
int QueueValidity(Queue*, const int);
unsigned long long HashSum(Queue*);
void QueuePrintExitCode ();
//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void UnitTest ();
int QueueDumpFunction(Queue*, const char*, int, const char*, const char*);
#define QueueDump(queue) QueueDumpFunction (queue, __PRETTY_FUNCTION__, __LINE__, __FILE__, #queue);