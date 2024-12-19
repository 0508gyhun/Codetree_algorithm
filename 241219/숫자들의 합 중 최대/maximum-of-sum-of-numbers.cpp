#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int x,y;
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> x >>y;

    int mx = INT_MIN;
    for(int i = x ; i<=y ; i++)
    {
        int il = i%10;
        int sip = i/10;
        int beak = i/100;
        int chun = i/1000;
        int man = i/10000;
        mx = max(mx,il+sip+beak+chun+man);
    }
    cout << mx;
    return 0;
}