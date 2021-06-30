#include "rselect.h"

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int paritation(int* arr, int left, int right)
{   
    int smaller = left + 1;
    int larger = left + 1;
    int pivot = arr[left];


    for (larger; larger <= right; larger++)
    {   

        if (arr[larger] < pivot)
        {   
            swap(&arr[smaller], &arr[larger]);
            smaller += 1;
        }
    }

    swap(&arr[left], &arr[smaller-1]);

    return smaller - 1;
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


int rselect(int* arr, int stat_num, int start, int end)
{
    assert(stat_num <= end);

    int size = end - start + 1;
    int pivot_position = paritation(arr, start, end);



    if (pivot_position == stat_num)
    {   
        return arr[pivot_position];
    }

    else if (stat_num > pivot_position)
    {   
        return rselect(arr, stat_num, pivot_position + 1, end);
    } 

    else if (stat_num < pivot_position)
    {   
        return rselect(arr, stat_num, start, pivot_position - 1);
    }
}   

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void dump_array(int* array, int left, int right)
{   
    printf("\n");
    for (int i=left; i <= right; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

//flexxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int unit_test() {
    
    int array1[] = {9, 8, 60, 121, 20, 35, 7, 100, 0, -10};
    int array2[] = {-1, -1231, -10, -132, -13, -5, -7, -100, -110, -10};
    int array3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int array4[] = {0};
    int array5[] = {-9, -8, -7, -6, 0, 1, 100, 100009, 100000000, 100000005};

    printf("INITIAL ARRAYS:\n");

    printf("\nArray-1:");
    dump_array(array1, 0, 9);

    printf("\nArray-2:");
    dump_array(array2,  0, 9);

    printf("\nArray-3:");    
    dump_array(array3,  0, 9);

    printf("\nArray-4:"); 
    dump_array(array4, 0, 0);

    printf("\nArray-5:"); 
    dump_array(array5,  0, 9);
    
    int stat1 = rselect(array1, 7, 0, 9);  // 60 OK
    int stat2 = rselect(array2, 1, 0, 9);  // -132 OK
    int stat3 = rselect(array3, 4, 0, 9);  // 1 OK
    int stat4 = rselect(array4, 0, 0, 0);  // 0 OK
    int stat5 = rselect(array5, 8, 0, 9);  // 100000000 OK

    
    printf("\n\nStats:\n");

    printf("\nArray-1 stat #7: \t%d", stat1);
    printf("\nArray-2 stat #1: \t%d ", stat2);
    printf("\nArray-3 stat #4: \t%d ", stat3);   
    printf("\nArray-4 stat #0: \t%d ", stat4);
    printf("\nArray-5 stat #8: \t%d ", stat5);

    printf("\n\n");

    return 0;
}