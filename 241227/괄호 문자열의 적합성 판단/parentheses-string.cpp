#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    string s;
    
    cin >> s;
    stack<int> stk;
    for(int i = 0 ; i< s.size() ; i++)
    {
        if(s[i] == '(')
        {
            stk.push(s[i]);
        }
        else{
             if(stk.empty()) {
                cout << "No";
                return 0;
            }
            stk.pop();
        }

    }


        if(stk.empty())
        {
            cout << "Yes"<< endl;
        }
        else{
            cout <<"No"<< endl;
        }
    return 0;
}