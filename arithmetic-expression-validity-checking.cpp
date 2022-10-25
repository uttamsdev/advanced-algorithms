#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter your expression:\n ";
    string expression;
    cin >> expression;
    stack<int> Stack;
    int length = expression.size();
    bool result = false;

    for(int i = 0; i<length; i++){
        char character = expression[i];
        if(character=='(' || character=='{' || character=='['){
            Stack.push(character);
        }
        else if (character==')' || character=='}' || character==']'){
            if(Stack.empty()) {
                result = true;
                break;
            }
            else if((character==')'&&Stack.top()=='(') || (character=='}'&&Stack.top()=='{') || (character==']'&&Stack.top()=='[') ){
                Stack.pop();
            }
        }
    }
    if(result==true) {
        cout << "Opening bracket missing. Invalid arithmetic expression \n";
    }
    else if(!Stack.empty()) {
        cout << "Closing bracket missing. Invalid arithmetic expression \n";
    }
    else {
        cout << "Valid arithmetic expression \n";
    }
    return 0;
}
