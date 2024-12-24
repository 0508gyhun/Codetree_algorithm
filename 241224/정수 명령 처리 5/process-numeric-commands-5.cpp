#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    vector<int> v;
    for(int i = 0 ; i < n ; i++)
    {   
        string dir;
        int tmp ;
        cin >> dir;
        if(dir == "push_back")
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        else if( dir == "get")
        {
            cin >> tmp;
            cout << v[tmp-1]<< endl;
        }
        else if( dir == "size")
        {
            cout << v.size()<< endl;
        }
        else if(dir == "pop_back")
        {
            v.pop_back();
        }

    }

    return 0;
}