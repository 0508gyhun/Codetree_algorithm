#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> stk;
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        string dir ;
        cin >> dir;
        if(dir == "push" )
        {
            int num;
            cin >> num;
            stk.push(num);
        }
        else if (dir == "size"){
            cout << stk.size()<<endl;
        }
        else if(dir == "empty")
        {
            cout << stk.empty()<<endl;
        }
        else if( dir == "pop"){
            cout<< stk.top()<<endl;
            stk.pop();
        }
        else if( dir =="top")
        {
            cout << stk.top()<< endl;
        }
    }
    return 0;
}