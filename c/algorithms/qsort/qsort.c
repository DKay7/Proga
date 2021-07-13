#include <stdio.h>
#include "qsort.h"

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
            if (arr[*left] > arr[*right])
            {
                swap(&arr[*left], &arr[*right]);
            }

            (*left) += 1;
            (*right) -= 1;
        }
    }
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void qsort(int* arr, int start, int end)
{   

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
    
    int array1[] = {2148, 9058, 7742, 3153, 6324, 609, 7628, 5469, 7017, 504};

    int array2[] = {2148, 9058, 7742, 3153, 6324, 609, 7628, 5469, 7017, 504, 
                    4092, 1582, 9572, 1542, 5697, 2081, 4218, 3130, 7923, 9595, 
                    6558, 3859, 9832, 3062, 6788, 7578, 7432, 479, 8439, 9079, 
                    7173, 2667, 2770, 2655, 972, 4264, 2014, 3171, 4715, 345, 4388, 
                    3816, 8887, 3915, 3490, 2327, 123, 4596, 4307, 8737, 4007, 6798, 
                    6551, 1627, 1190, 4984, 2480, 3404, 2027, 4778, 2951, 2795, 5002, 
                    8121, 8910, 9593, 5254, 448, 6237, 5565, 1816, 392, 8143, 9310, 
                    9293, 3138, 4869, 6756, 872, 6183, 3517, 3513, 1676, 5498, 9172, 
                    5739, 6108, 7538, 7671, 5780, 8666, 540, 9771, 6837, 9341, 1590, 
                    5689, 1605, 1103, 5859};

    int array3[] = {-10, 8, 7};
    int array4[] = {0};
    int array5[] = {-9, -8, -7, -6, 0, 1, 100, 100000, 100000000, 10000000};

    printf("BEFORE SORT:\n");

    printf("\nArray-1:");
    dump_array(array1, 10);
    printf("\nArray-2:");
    dump_array(array2, 100);
    printf("\nArray-3:");    
    dump_array(array3, 3);
    printf("\nArray-4:"); 
    dump_array(array4, 1);
    printf("\nArray-5:"); 
    dump_array(array5, 10);
    
    qsort(array1, 0, 9);
    qsort(array2, 0, 100);
    qsort(array3, 0, 2);
    qsort(array4, 0, 0);
    qsort(array5, 0, 9);

    printf("\n\nAFTER SORT:\n");
    printf("\nArray-1:");
    dump_array(array1, 10);
    printf("\nArray-2:");
    dump_array(array2, 100);
    printf("\nArray-3:");    
    dump_array(array3, 3);
    printf("\nArray-4:"); 
    dump_array(array4, 1);
    printf("\nArray-5:"); 
    dump_array(array5, 10);

    printf("\n\n");

    return 0;
}