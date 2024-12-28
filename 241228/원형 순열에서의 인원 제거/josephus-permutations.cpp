#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
queue <int> q;
int main() {
    // 여기에 코드를 작성해주세요.

    cin >>n>>k;

    for(int i = 1 ; i <= n ; i++)
    {
        q.push(i);
    }
    while(q.size())
    {
        for(int i = 0 ; i < k-1 ; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front()<< " ";
        q.pop();
        
    }
    return 0;
}