#include <iostream>
#include <stack>
using namespace std;

/*
-----------------------------------------------------------------------------
Program to check if bracers sequence are "right"
-----------------------------------------------------------------------------
*/

int main() {
 
stack <char> stack;
string s;

cin >> s;

for(int i = 0; i < s.size(); i++){
    if(s[i] == '(')
        stack.push('(');

    else if(!stack.empty() && s[i] == ')' && stack.top() == '(')
        stack.pop();

    else if(s[i] == ')')
        stack.push(')');

}

cout << stack.size();

return 0;
}