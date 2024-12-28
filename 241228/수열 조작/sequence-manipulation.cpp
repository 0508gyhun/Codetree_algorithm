#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int n;
deque<int> dq;
int main() {
    cin >> n;

    for(int i = 1 ; i <=n ; i++)
    {
        dq.push_back(i);
    }

    while(dq.size() > 1)
    {
        
        dq.pop_front();

        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }
    cout << dq.front();
    // 여기에 코드를 작성해주세요.
    return 0;
}