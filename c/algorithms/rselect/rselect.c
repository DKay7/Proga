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
    
    int array1[] = {2148, 9058, 7742, 3153, 6324, 609, 7628, 5469, 7017, 504};
    
    int array2[] = {2148, 9058, 7742, 3153, 6324, 609, 7628, 5469, 7017, 504, 4092, 1582, 9572, 
                    1542, 5697, 2081, 4218, 3130, 7923, 9595, 6558, 3859, 9832, 3062, 6788, 7578, 
                    7432, 479, 8439, 9079, 7173, 2667, 2770, 2655, 972, 4264, 2014, 3171, 4715, 
                    345, 4388, 3816, 8887, 3915, 3490, 2327, 123, 4596, 4307, 8737, 4007, 6798, 
                    6551, 1627, 1190, 4984, 2480, 3404, 2027, 4778, 2951, 2795, 5002, 8121, 8910, 
                    9593, 5254, 448, 6237, 5565, 1816, 392, 8143, 9310, 9293, 3138, 4869, 6756, 
                    872, 6183, 3517, 3513, 1676, 5498, 9172, 5739, 6108, 7538, 7671, 5780, 8666, 
                    540, 9771, 6837, 9341, 1590, 5689, 1605, 1103, 5859};

    int array3[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int array4[] = {0};
    int array5[] = {-9, -8, -7, -6, 0, 1, 100, 100009, 100000000, 100000005};

    printf("INITIAL ARRAYS:\n");

    printf("\nArray-1:");
    dump_array(array1, 0, 99);

    printf("\nArray-2:");
    dump_array(array2,  0, 9);

    printf("\nArray-3:");    
    dump_array(array3,  0, 9);

    printf("\nArray-4:"); 
    dump_array(array4, 0, 0);

    printf("\nArray-5:"); 
    dump_array(array5,  0, 9);
    
    int stat1 = rselect(array1, 4, 0, 9);  // 5469 OK
    int stat2 = rselect(array2, 49, 0, 99);  // 4715 OK
    int stat3 = rselect(array3, 4, 0, 9);  // 1 OK
    int stat4 = rselect(array4, 0, 0, 0);  // 0 OK
    int stat5 = rselect(array5, 8, 0, 9);  // 100000000 OK

    
    printf("\n\nStats:\n");

    printf("\nArray-1 stat #4: \t%d", stat1);
    printf("\nArray-2 stat #49: \t%d ", stat2);
    printf("\nArray-3 stat #4: \t%d ", stat3);   
    printf("\nArray-4 stat #0: \t%d ", stat4);
    printf("\nArray-5 stat #8: \t%d ", stat5);

    printf("\n\n");

    return 0;
}