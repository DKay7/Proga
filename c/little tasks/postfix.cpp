#include <iostream>
#include <string>
using namespace std;


/*
-----------------------------------------------------------------------------
This program counts the postfix sting expression.
-----------------------------------------------------------------------------
*/


int to_int(string num); 	//Translates string number into integer number.


int main() {
    
    string s, num;
    int stack[100];
    int j = 0, temp = 0;

    getline(cin, s, '\n');

    for(int i = 0; i < s.size(); i++)
        stack[i] = 0;

    for(int i = 0; i < s.size(); i++){
        if((int)s[i] >= '0' && (int)s[i] <= '9'){

            while(s[i] != ' '){
                num += s[i];
                i++;
            }

            stack[j] = to_int(num);
            num = "";
            j++;
        }
        else if(s[i] == '+'){
            j--;
            stack[j-1] = stack[j-1] + stack[j];
            stack[j] = 0;
        }
        else if(s[i] == '-'){
            j--;
            stack[j-1] = stack[j-1] - stack[j];
            stack[j] = 0;
        }
        else if(s[i] == '*'){
            j--;
            stack[j-1] = stack[j-1] * stack[j];
            stack[j] = 0;
        }
    }


    cout << stack[0];

    return 0;
}

int to_int(string num){
    int ans=0;
    int power = 1;
    for(int i=num.size()-1; i >= 0; i--, power *= 10)
        ans += (int(num[i]) - '0') * power;
    
    return ans;
}