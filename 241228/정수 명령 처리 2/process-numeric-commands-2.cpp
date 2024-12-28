#include <iostream>

using namespace std;
#include <bits/stdc++.h>
int n;
queue <int> q;
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        string s;
        cin >> s;

        if(s == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if(s == "front")
        {
            cout << q.front()<< endl;
        }
        else if(s == "size")
        {
            cout << q.size()<< endl;
        }
        else if( s == "pop")
        {
            cout << q.front() << endl;
            q.pop();
        }
        else if( s == "empty")
        {
            cout << q.empty()<< endl;
        }
        
    }
    return 0;
}