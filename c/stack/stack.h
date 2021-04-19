#include <malloc.h>

#define and &&
#define or ||

typedef unsigned long long hummingbird_type;

extern const hummingbird_type HUMMINGBIRD;
extern int stack_exit_code;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

typedef struct Stack{
    hummingbird_type start_bird;
    double *start;
    int capacity;
    int pointer;
    unsigned long long hash; 
    hummingbird_type end_bird;
} Stack;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

enum ExitCodes
{
    FINE                        = 0x000000,     //  If all is OK
    MEMORY_ALLOC_ERROR          = 0xA10000,     //  Error while allocation memory in functions calloc/realloc
    INCORRECT_STACK_POINTER     = 0xB10000,     //  Incorrect pointer to start of stack buffer
    INCORRECT_STACK_SIZE        = 0xB20000,     //  Size below zero or size more than capacity
    INCORRCT_STACK_CAPACITY     = 0xB30000,     //  Capacity below zero
    WRONG_START_HUMMINGBIRD     = 0xE10000,     //  Changes in start-hummingbird
    WRONG_END_HUMMINGBIRD       = 0xE20000,     //  Changes in end-hummingbird
    WRONG_HASH_SUM              = 0xE30000      //  Mismath with recorded hash-sum
};

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

enum FunctionNumbers
{
    STACK_CTOR_CODE       = 1,    //Code of StackCtor()
    STACK_PUSH_CODE       = 2,    //Code of StackPush()
    STACK_POP_CODE        = 3,    //Code of StackPop()
    STACK_VALIDATY_CODE   = 4,    //Code of StackValidaty()
    STACK_INCREASE_CODE   = 5,    //Code of StackIncrease()
    STACK_DECREASE_CODE   = 6,    //Code of StackDecrease()
    STACK_DUMP_CODE       = 7     //Code of macro StackDump()
};

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void StackPush(Stack*, double);
double StackPop(Stack*);

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

Stack *StackCtor(int);
int StackValidity(Stack*, const int);
unsigned long long HashSum(Stack*);
void StackPrintExitCode ();
//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int StackIncrease(Stack*);
int StackDecrease(Stack*);

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void UnitTest ();
int StackDumpFunction(Stack*, const char*, int, const char*, const char* );
#define StackDump(stack) StackDumpFunction (stack, __PRETTY_FUNCTION__, __LINE__, __FILE__, #stack);