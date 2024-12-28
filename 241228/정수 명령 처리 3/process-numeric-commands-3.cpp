#include <iostream>

using namespace std;
#include <bits/stdc++.h>
int n;
deque <int> q;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        string s;
        cin >> s;

        if(s == "push_front")
        {
            int num;
            cin >> num;
            q.push_front(num);
        }
        else if(s == "push_back")
        {
            int num;
            cin >> num;
            q.push_back(num);
        }
        else if(s == "front")
        {
            cout << q.front()<< endl;
        }
        else if(s == "back")
        {
            cout << q.back()<< endl;
        }
        else if(s == "size")
        {
            cout << q.size()<< endl;
        }
        else if( s == "pop_front")
        {
            cout << q.front() << endl;
            q.pop_front();
        }
        else if( s == "pop_back")
        {
            cout << q.back() << endl;
            q.pop_back();
        }
        else if( s == "empty")
        {
            cout << q.empty()<< endl;
        }
        
    }
    return 0;
}