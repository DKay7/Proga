#include <stdio.h>

int hash(int a[], int с, int n);
int put(int a[], int c, int n);
void swap(int a[], int d, int e);

int main() {
 
    const int max_n = 200000;
    int a[max_n] = {0};





    return 0;
}

int hash(int a[], int с, int n){
    с = с % n;
    return с;
}

int put(int a[], int c, int n){
    int ind = c;

    do
    {
        ind = hash(a, ind, n);
        ind++;
    } while (a[ind] != 0);

    a[ind] = c;

    return ind; 
}

void swap(int a[], int d, int e){
    int ind_d = 
}