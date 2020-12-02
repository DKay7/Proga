int index = 0;

typedef struct Stack{
    double* buffer;
    int capacity;
    int index;
} Stack;

void push();
double get();
double* create_stack();
void delete_stack();