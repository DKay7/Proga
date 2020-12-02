#include <string>
#include <iostream>
using namespace std;


int main() {
 
int n;
cin >> n;

int* nums = new int[n-3];
string* names = new string[n];

for(int i = 0; i < n; i++)
    cin >> names[i];

for(int i = 0; i < n-3; i++)
    cin >> nums[i];



return 0;
}

void go_out(string* names, int n, int index){

    for(int i=index; i<n-1; i++)
        names[i] = names[i+1];
    
}