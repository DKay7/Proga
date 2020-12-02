
typedef struct Stack{
    double* start;
    int capacity;
    int pointer;
} Stack;

void StackPush(Stack*, double);
double StackPop(Stack*);

Stack* StackCtor(int);
void StackDelete(Stack*);

void StackIncrease(Stack*);
void StackDecrease(Stack*);
