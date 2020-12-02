#include "stack.h"
#include <stdio.h>

#define deb printf("all is ok in %d\n", __LINE__);

int main()
{
    Stack* stack = StackCtor(100);
    StackPush(stack, 42);
    printf("%f", StackPop(stack));
    StackDelete(stack);
}