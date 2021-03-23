#include <stdio.h> 
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;


int push(Node**, int);
int pop(Node**);
int print(Node**);
int input(Node**);

int main() 
{
}

int push(Node** head, int data)
{
    Node *tmp = (Node*)malloc(sizeof(Node));

    if (tmp == NULL)
    {
        return -1;
    }

    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node **head)
{
    Node* prev = NULL;
    int value;
    
    if (head == NULL)
    {
        return -1;
    }

    prev = (*head);
    value = prev->value;
    (*head) = (*head) -> next;
    free(prev);

    return value;
}

int print(Node**);
int input(Node**);