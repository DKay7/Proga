#include <stdio.h>
#include <iostream>

/*
-----------------------------------------------------------------------------
matrix multiplication mod s.
-----------------------------------------------------------------------------
*/

void initialize(unsigned long long int** A, 
                unsigned long long int** B, 
                unsigned long long int** C, 
                int n);

void print(unsigned long long int** C, int n);

void matmul_mod_s(unsigned long long int** A, 
                  unsigned long long int** B, 
                  unsigned long long int** C, 
                  int n, unsigned long int s);

void delete_matrixes(unsigned long long int** A, 
                     unsigned long long int** B,
                     unsigned long long int** C, 
                     int n);

int main() {
    int n = 0;
    
    unsigned long int s;

    std::cin>>n>>s;
    
    unsigned long long int **A = new unsigned long long int *[n], 
                           **B = new unsigned long long int *[n],
                           **C = new unsigned long long int *[n];
    
    initialize(A, B, C, n);
    matmul_mod_s(A, B, C, n, s);
    print(C, n);
    delete_matrixes(A, B, C, n);

    return 0;
}

void initialize(unsigned long long int** A, 
                unsigned long long int** B, 
                unsigned long long int** C, 
                int n){

    for(int i = 0; i < n; i++){
        A[i] = new unsigned long long int [n];
        for(int j = 0; j < n; j++)
            std::cin>>A[i][j];
    }

    for(int i = 0; i < n; i++){
        B[i] = new unsigned long long int [n];
        for(int j = 0; j < n; j++)
            std::cin>>B[i][j];
    }

    for(int i = 0; i < n; i++){
        C[i] = new unsigned long long int [n];
        for(int j = 0; j < n; j++)
           C[i][j] = 0;
    }
}

void print(unsigned long long int** C, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            std::cout << C[i][j]<<' ';

        std::cout<<std::endl;
    }
}

void matmul_mod_s(unsigned long long int** A, 
                  unsigned long long int** B, 
                  unsigned long long int** C, 
                  int n, unsigned long int s){

    unsigned long long int sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum = 0;
            for(int k = 0; k < n; k++)
                sum += (A[i][k] * B[k][j]);

            C[i][j] = sum % s;
            
        }
    }
}

void delete_matrixes(unsigned long long int** A, 
                     unsigned long long int** B,
                     unsigned long long int** C, 
                     int n){
    for (int i = 0; i<n; i++){
        delete[]A[i];
        delete[]B[i];
        delete[]C[i];
    }

    delete [] A;
    delete [] B;
    delete [] C;
}