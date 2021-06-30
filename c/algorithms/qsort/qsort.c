#include <stdio.h>

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int choose_pivot(int* arr, int start, int end)
{
    return arr[(start + end) / 2];
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void paritation(int* arr, int pivot, int* left, int* right)
{   
    while (*left <= *right)
    {
        while (arr[*left] < pivot)
        {
            (*left) += 1;
        }

        while (arr[*right] > pivot)
        {
            (*right) -= 1;
        }

        if (*left <= *right)
        {
            swap(&arr[*left], &arr[*right]);
            (*left) += 1;
            (*right) -= 1;
        }
    }
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void qsort(int* arr, int start, int end)
{   

    if (end - start == 1)
    {
        return;
    }
    
    int left = start;
    int right = end;
    int pivot = choose_pivot(arr, start, end);

    paritation(arr, pivot, &left, &right);
    
    if (left < end)
    {
        qsort(arr, left, end);
    }

    if (right > start)
    {
        qsort(arr, start, right);
    }

}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void dump_array(int* array, int size)
{   
    printf("\n");
    for (int i=0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int unit_test() {
    
    int array1[] = {9, 8, 60, 121, 20, 35, 7, 100, 0, -10};
    int array2[] = {-1, -1231, -10, -132, -13, -5, -7, -100, -110, -10};
    int array3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int array4[] = {0};
    int array5[] = {-9, -8, -7, -6, 0, 1, 100, 100000, 100000000, 10000000};

    printf("BEFORE SORT:\n");

    printf("\nArray-1:");
    dump_array(array1, 10);
    printf("\nArray-2:");
    dump_array(array2, 10);
    printf("\nArray-3:");    
    dump_array(array3, 10);
    printf("\nArray-4:"); 
    dump_array(array4, 1);
    printf("\nArray-5:"); 
    dump_array(array5, 10);
    
    qsort(array1, 0, 9);
    qsort(array2, 0, 9);
    qsort(array3, 0, 9);
    qsort(array4, 0, 0);
    qsort(array5, 0, 9);

    printf("\n\nAFTER SORT:\n");
    printf("\nArray-1:");
    dump_array(array1, 10);
    printf("\nArray-2:");
    dump_array(array2, 10);
    printf("\nArray-3:");    
    dump_array(array3, 10);
    printf("\nArray-4:"); 
    dump_array(array4, 1);
    printf("\nArray-5:"); 
    dump_array(array5, 10);

    printf("\n\n");

    return 0;
}