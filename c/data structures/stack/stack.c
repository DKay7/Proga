#include <assert.h>
#include <stdio.h>
#include "stack.h"

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
const hummingbird_type HUMMINGBIRD = (hummingbird_type) 0xBADDED;
int stack_exit_code = 0;

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

Stack *StackCtor(int size)
{   
    assert(size > 0);
    
    Stack *stack = (Stack*) calloc(1, sizeof(Stack));
    stack_type* tmp_start = (stack_type*) calloc(size, sizeof(stack_type));

    if(stack == NULL or tmp_start == NULL)
    {
        stack_exit_code = MEMORY_ALLOC_ERROR + STACK_CTOR_CODE;
        return NULL;
    }

    stack->start_bird = HUMMINGBIRD;
    stack->start = tmp_start;
    stack->pointer = 0;
    stack->capacity = size;
    stack->hash = HashSum(stack);
    stack->end_bird = HUMMINGBIRD;

    return stack;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void StackPush(Stack *stack, stack_type element)
{   
    assert(stack != NULL);

    if(!StackIncrease(stack))  
        return;


    *(stack->start + stack->pointer) = element;
    stack->pointer += 1;
    stack->hash = HashSum(stack);

}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

stack_type StackPop(Stack *stack)
{    
    assert(stack != NULL);

    stack_type element = 0;

    if (stack->pointer >= 1)
    {
        stack->pointer -= 1;
    }

    element = *(stack->start + stack->pointer);
    *(stack->start + stack->pointer) = 0;

    StackDecrease(stack);
    stack->hash = HashSum(stack);

    return element;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int StackIncrease(Stack *stack)
{   
    assert(stack != NULL);

    stack_type* tmp_start;
    
    if(stack->pointer + 1 > stack->capacity)
    {

        tmp_start = (stack_type*) realloc(stack->start, 2 * stack->capacity * sizeof(Stack));

        if(tmp_start == NULL){
            stack_exit_code = MEMORY_ALLOC_ERROR + STACK_INCREASE_CODE;
            return 0;
        }

        stack->capacity = 2*stack->capacity;
    }

    return 1;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int StackDecrease(Stack *stack)
{   
    assert(stack != NULL);

    stack_type *tmp_start;

    if( 2 * (stack->pointer - 1) < stack->capacity)
    {
        tmp_start = (stack_type*) realloc(stack->start, 
                                            (2/3 + 1) * 
                                            stack->capacity * 
                                            sizeof(Stack));

        if(tmp_start == NULL)
        {
            stack_exit_code = STACK_DECREASE_CODE + MEMORY_ALLOC_ERROR;
            return 0;
        } 
        
        stack->start = tmp_start;
        stack->capacity = stack->capacity / 3 * 2 + 1;
    }

    return 1;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int StackValidity(Stack *stack, const int func_code)
{
    if(stack->start == NULL)
    {
        stack_exit_code = INCORRECT_STACK_POINTER + func_code;
        return 0;
    }

    if(stack->start_bird != HUMMINGBIRD)
    {
        stack_exit_code = WRONG_START_HUMMINGBIRD + func_code;
        return 0;
    }

    if(stack->start_bird != HUMMINGBIRD)
    {
        stack_exit_code = WRONG_END_HUMMINGBIRD + func_code;
        return 0;
    }

    if(stack->pointer > stack->capacity or stack->pointer < 0)
    {
        stack_exit_code = INCORRECT_STACK_POINTER + func_code;
        return 0;
    }

    if(stack->capacity < 0)
    {
        stack_exit_code = INCORRCT_STACK_CAPACITY + func_code;
        return 0;
    }

    if(stack->hash != HashSum(stack))
    {
        stack_exit_code = WRONG_HASH_SUM + func_code;
        return 0;
    }


    return 1;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int StackDumpFunction(Stack *stack, const char *func_name, int line_number, const char *file_name, const char *stack_name)
{   
    int check = StackValidity(stack, STACK_DUMP_CODE);

    if(check)
    {
        printf ("Stack[OK]: ");
    }

    else
    {
        printf ("Stack[ERROR][CODE: 0x%X]", stack_exit_code);
    }

    printf ("[%p] ", &stack->start);

    printf ("\"%s\" %s line %d %s'\n", stack_name, func_name, line_number, file_name);

    if(!check)
        StackPrintExitCode();

    printf ("\n{\n");              
                                                
    printf (" size = %lu \n", stack->pointer);           
                                                    
    printf (" capacity = %lu\n", stack->capacity);    
                                                    
    printf (" hash_sum = %llX\n", stack->hash);       
                                                    
    printf ("\t{\n"); 

    for (size_t i=0; i< stack->capacity; i++)
    {
        printf ("   ");      

        if (i < stack->pointer)                        
            printf  ("\t *");                      
        else                                        
            printf ("\t  ");

        printf  ("[%lu] = %lg \n", i, *(stack->start + i)); 
    }

    printf ("   }\n}\n"); 

    return 0;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

unsigned long long HashSum(Stack* stack)
{
    assert(stack != NULL);

    unsigned long long hash = 0;

    for (unsigned i=0; i < stack->pointer; i++)
    {
        hash += *(stack->start + i);
        hash << sizeof(stack_type);
    }

    return hash;
}

void StackPrintExitCode ()
{   
    int func_code = stack_exit_code % 256;
    int err_code = stack_exit_code - func_code;
    
    if (err_code == FINE)
    {
        printf ("No errors founded\n");
        return;
    }

    switch (err_code)
    {
        case MEMORY_ALLOC_ERROR:
            printf ("Memory allocation error in ");
            break;
    
        case INCORRECT_STACK_POINTER:
            printf ("Incorrect pointer to start of buffer founded in ");
            break;

        case INCORRECT_STACK_SIZE:
            printf ("Stack size below zero or stack overdlow exception founded in ");
            break;

        case INCORRCT_STACK_CAPACITY:
            printf ("Stack capacity below zeor  founded in ");
            break;

        case WRONG_START_HUMMINGBIRD:
            printf ("Changes in start hummingbird founded in ");
            break;

        case WRONG_END_HUMMINGBIRD:
            printf ("Changes in end hummingbird founded in ");
            break;

        case WRONG_HASH_SUM:
            printf ("Mismacth of hash sum founded in ");
            break;

        default:
            printf ("Unkwonw exception with number %X in ", err_code);
            break;
    }


    switch (func_code)
    {
        case STACK_CTOR_CODE:
            printf ("func StackCtor()\n");
            break;

        case STACK_PUSH_CODE:
            printf ("func StackPush()\n");
            break;

        case STACK_POP_CODE:
            printf ("func StackPop()\n");
            break;

        case STACK_INCREASE_CODE:
            printf ("func StackIncrease()\n");
            break;

        case STACK_DECREASE_CODE:
            printf ("func StackDecrease()\n");
            break;

        case STACK_DUMP_CODE:
            printf ("macro StackDump()\n");
            break;

        default:
            printf ("unkwonw func with number %X\n", func_code);
            break;
    }

    return;
}

void UnitTest ()
{
    Stack stack1 = *StackCtor(50);
    Stack stack2 = *StackCtor(50);
    Stack stack3 = *StackCtor(50);

    char test1[] = "PRESS F TO PAY RESPECTS";
    char test2[] = "HAHA OFIGENNO";
    char test3[] = "42 or 97 hmmmmmmmm";

    for (int i = 0; test1[i]; i++)
        StackPush (&stack1, test1[i]);

    for (int i = 0; test2[i]; i++)
        StackPush (&stack2, test2[i]);

    for (int i = 0; test3[i]; i++)
        StackPush (&stack3, test3[i]);

    StackDump (&stack1);
    StackDump (&stack2);
    StackDump (&stack3);

    StackPop (&stack1);
    StackPop (&stack2);
    StackPop (&stack3);

    printf("AFTER POPING:\n");

    StackDump (&stack1);
    StackDump (&stack2);
    StackDump (&stack3);

}