#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

void generate_a(int a0, int x, int y, int n, int* a);
void generate_c(int b0, int z, int t, int m, int n, int* b, int* c);
void compute(int* a, int* b, unsigned long long* sum, long int m);
void delete_massives(int* a, int* b, int* c);

//-----------------------------------------------------------------------------

int main() {
    long int n, m;
    int x, y, a0;
    int z, t, b0;
    unsigned long long sum = 0;

    cin >> n >> x >> y >> a0;
    cin >> m >> z >> t >> b0;

    int* a = new int[n];
    int* b = new int[2*m];
    int* c = new int[2*m];
    
    generate_a(a0, x, y, n, a);
    generate_c(b0, z, t, m, n, b, c);
    
    compute(a, c, &sum, m);

    cout << sum;
    
    delete_massives(a, b, c);

return 0;
}

//-----------------------------------------------------------------------------

void generate_a(int a0, int x, int y, int n, int* a){
    a[0] = a0;

    for(int i=1; i<n; i++)
        a[i] =  x*a[i-1] + y;

    for(int i=1; i<n; i++)
        a[i] +=  a[i-1];
}

void generate_c(int b0, int z, int t, int m, int n, int* b, int* c){
    
    long int p2_30 = pow(2, 30);
    b[0] = b0;

    for(int i = 1; i < 2*m; i++){
        b[i] = z*b[i-1] + t;
        b[i] = b[i] & ((1 << 30) - 1);
    }
    
    for(int i = 0; i < 2*m; i++)
        c[i] = b[i] % n;
}

void compute(int* a, int* c, unsigned long long* sum, long int m){
    for(int i = 0; i < 2*m - 1; i += 2){

        if(min(c[i], c[i+1]) - 1 >= 0)
            *sum += a[max(c[i], c[i+1])] - a[min(c[i], c[i+1]) - 1];
        
        else
            *sum += a[max(c[i], c[i+1])];
    }
}

void delete_massives(int* a, int* b, int* c){
    delete[] a;   
    delete[] b;
    delete[] c;
}