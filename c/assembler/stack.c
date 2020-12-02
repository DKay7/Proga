#include "stack.h"
#include<malloc.h>

void push(double element, Stack* stack)
{
    stack->buffer[stack->index] = element;
    stack->index ++;

    increase_stack(stack);
}

double get(Stack* stack)
{   
    double element = 0;

    stack->index--;
    element = stack->buffer[stack->index];
    stack->buffer[stack->index] = 0;

    decrease_stack(stack);

    return element;
}

Stack* create_stack(int size)
{
    Stack* stack = calloc(size, sizeof(double));
    return stack;
}

void delete_stack(Stack* stack)
{
    free(stack);
}

void increase_stack(Stack* stack)
{
    if(stack->index + 1 > stack->capacity)
    {
        stack->buffer = realloc(stack->buffer, 2 * stack->capacity * sizeof(Stack));
        stack->capacity = 2*stack->capacity; 
    }
}

void decrease_stack(Stack* stack)
{
    if( 2 * (stack->index - 1) < stack->capacity)
        stack->buffer = realloc(stack->buffer, 
            (2/3 + 1) * stack->capacity * sizeof(Stack));
        
        stack->capacity = stack->capacity / 3 * 2 + 1;
}