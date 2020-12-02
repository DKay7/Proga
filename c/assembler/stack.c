#include "stack.h"
#include <malloc.h>
#include <stdio.h>


void StackPush(Stack* stack, double element)
{
    *(stack->start + stack->pointer) = element;
    stack->pointer += 1;

}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

double StackPop(Stack* stack)
{   
    double element = 0;

    stack->pointer -= 1;
    element = *(stack->start + stack->pointer);
    *(stack->start + stack->pointer) = 0;

    return element;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

Stack* StackCtor(int size)
{   
    Stack* stack = (Stack*) calloc(1, sizeof(Stack));
    stack->start = (double*) calloc(size, sizeof(double));
    stack->pointer = 0;
    stack->capacity = size;

    return stack;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void StackDelete(Stack* stack)
{
    free(stack);
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void StackIncrease(Stack* stack)
{
    if(stack->pointer + 1 > stack->capacity)
    {
        stack->start = realloc(stack->start, 2 * stack->capacity * sizeof(Stack));
        stack->capacity = 2*stack->capacity; 
    }
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void StackDecrease(Stack* stack)
{
    if( 2 * (stack->pointer - 1) < stack->capacity)
        stack->start = realloc(stack->start, 
            (2/3 + 1) * stack->capacity * sizeof(Stack));
        
        stack->capacity = stack->capacity / 3 * 2 + 1;
}