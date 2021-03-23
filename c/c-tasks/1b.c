#include <stdio.h> 
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *head = NULL;


int push(Node**, int);
int pop(Node**);
void print(Node*);
void input(Node**);

int main() 
{
}

int push(Node **head, int data)
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

int getLastVal(Node **head) {

    int value = 0;

    if (head == NULL) {
        return -1;
    }

    value = (*head)->value;
    return value;
}


void print(Node *head)
{
    while (head) 
    {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}


void input(Node **head)
{   
    int c = 0, i=0;

    while((c = getchar()) != EOF)
    {
        push(head, c);
    }
}

void countOddPos(Node **head, int num_pos)
{
    int i = 0, val = 0, count = 0;

    for (i; i < num_pos, head != NULL; i++, head = (*head)->next)
    {
        val = get_last_val(head);

        if (val == 0)
        {
            count += 1;
        }
    }

    return count;
}

int countSize(Node **head)
{   
    int size = 0;

    while(head)
    {
        (*head) = (*head)->next;
        size += 1;
    }

    return size;
}

void changeEven(Node *head1, Node *head2, int num_pos)
{
    int i = 0, val1 = 0, val2 = 0, tmp = 0;

    int size = countSize(&head1);
    for (i; i < size - num_pos; i++)
    {

    }
    
    for (i = num_pos; i >= size; i--)
    {   
        if (i % 2 == 0)
        {
            val1 = head1->value;
            val2 = head2->value;

            head1->value = val2;
            head2->value = val1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return count;
}