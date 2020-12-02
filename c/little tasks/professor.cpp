#include <string>
#include <iostream>
using namespace std;

unsigned long long to_int(string s);

int main() {
    
    string numbers = "", tmp;
    int n = 0, count_x, count_y;
    unsigned long long int k = 0, x, y;

    cin >> n >> k;
    for(int i=0; i<n - 1; i++){
        cin>>tmp;
        numbers += tmp + ' ';
    }

    cin>>tmp;
    numbers += tmp;

    for(int i=0; i < k; i++){
        count_x = 0;
        count_y = numbers.size();

        while(numbers[count_x] != ' ')
                count_x++;
        
        while(numbers[count_y] != ' ')
            count_y--;
        
        
        
        x = to_int(numbers.substr(0, count_x));
        y = to_int(numbers.substr(count_y+1, numbers.size()-count_y));

        if(x < y){
            numbers.erase(0, count_x+1);
            numbers = numbers + ' ' + to_string((x + y) & ((1<<30) - 1));  
        }
        if(x > y){
            numbers.erase(count_y, count_y);
            numbers.insert(0, (to_string((y - x) & ((1<<30) - 1))+' '));
        }
    }

    cout << numbers;
    return 0;
}

unsigned long long to_int(string s){
    unsigned long long ans=0;
    int power = 1;
    for(int i = s.size()-1; i >= 0; i--, power *= 10)
        ans += (int)(s[i] - '0') * power;
    
    return ans;
}