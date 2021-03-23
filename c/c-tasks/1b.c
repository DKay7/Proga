#include <stdio.h> 
#include <stdlib.h>

//  Структура-тип связного списка
typedef struct Node {
    int value; // Значение данного элементв
    struct Node *next; // Указатель на следующий элемент
} Node;

// Указатель на первый элемент списка
Node *head = NULL;

// Создание ноды
Node* Ctor();

// Удаление списка.
Node* DCtor(Node *);

// Пуш значения
int push(Node **, int);

// Пулл значения
int pop(Node **);

// Вывод списка на экран
void print(Node *);

// Ввод списка с клавиатуры
void input(Node **);

// Меняет последние n значений двух списков на четных позициях
void changeEven(Node *, Node *, int);

// Считает первые n нулевых символов на нечетных позициях
void countOddPos(Node **, int );

// Считает размер
int countSize(Node **);


int main() 
{
}


Node* Ctor()
{   
    //  выделяем память под новый элемент
    Node *tmp = (Node*) malloc(sizeof(Node));
    
    // если память закончилась, возвращаем null
    if (tmp == NULL)
    {
        return NULL;
    }

    // иначе возвращаем указатель на новый элемент
    return tmp;
}

Node* DCtor(Node *head)
{   
    Node* prev;

    //пока есть, что удалять
    while (head)
    {   
        // получаем текущий элемент
        prev = (head);
        //сдвигаем курсор на один элемент вперед
        head = head->next;
        //удаляем предыдущий элемент
        free(prev);
    }
    
}

int push(Node **head, int data)
{
    //выделяем память под новую ноду
    Node *tmp = (Node*) malloc(sizeof(Node));

    //если память не выделена, возвращаем null 
    if (tmp == NULL)
    {
        return NULL;
    }

    // записываем данные в новый элемент
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node **head)
{
    Node* prev = NULL;
    int value;
    
    // если список пустой, возвращаем -1
    if (head == NULL)
    {
        return -1;
    }

    //иначе возвращаем данные и сдвигаем указатель
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

    // Получаем последнее значение
    value = (*head)->value;
    return value;
}


void print(Node *head)
{   
    // пока есть, что печатать
    while (head) 
    {   
        // печатаем и передвигаем курсов
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}


void input(Node **head)
{   
    int c = 0, i=0;

    //пока есть, что вводить
    while((c = getchar()) != EOF)
    {   
        // пушим
        push(head, c);
    }
}


void countOddPos(Node **head, int num_pos)
{
    int i = 0, val = 0, count = 0;

    // от 0 до количества позиций передвигаем курсор
    for (i; i < num_pos, head != NULL; i++, head = (*head)->next)
    {   
        // получаем текущее значение
        val = getLastVal(head);

        // если значение равно 0, то увеличиваем счетчик
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

    // пока список не кончился
    while(head)
    {   
        // идем к следующей ноде и увеличиваем счетчик
        (*head) = (*head)->next;
        size += 1;
    }

    return size;
}


void changeEven(Node *head1, Node *head2, int num_pos)
{
    int i = 0, val1 = 0, val2 = 0, tmp = 0;

    // считаем размер первого списка, по логике он должен совпадать с размером второго списка
    // поэтому просто размер
    int size = countSize(&head1);

    // передвигаем указатели обеих списков на позицию num_pos
    for (i; i < size - num_pos; i++)
    {
        head1 = head1->next;
        head2 = head2->next;
    }

    // с текущей позиции и до конца списка
    for (i = num_pos; i < size; i++)
    {      
        // если позиция четная
        if (i % 2 == 0)
        {   
            // меняем значения
            val1 = head1->value;
            val2 = head2->value;

            head1->value = val2;
            head2->value = val1;
        }

        // передвигаемся к следующим нодам
        head1 = head1->next;
        head2 = head2->next;
    }
}