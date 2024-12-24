#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    list<int> l;
    for(int i = 0 ; i < n ; i++)
    {   
        string dir;
        int tmp ;
        cin >> dir;
        if(dir == "push_back")
        {
            cin >> tmp;
            l.push_back(tmp);
        }
        else if(dir == "push_front")
        {
            cin >> tmp;
            l.push_front(tmp);
        }
        else if( dir == "size")
        {
            cout << l.size()<< endl;
        }
        else if(dir == "pop_back")
        {
            cout << l.back()<< endl;
            l.pop_back();
        }
        else if(dir == "pop_front")
        {
            cout << l.front() << endl;
            l.pop_front();
        }
        else if(dir == "back")
        {
            cout << l.back() << endl;
        }
        else if(dir == "front")
        {
            cout << l.front() << endl;
        }
        else if(dir == "empty")
        {
            cout << l.empty() << endl;
        }

    }

    return 0;
}