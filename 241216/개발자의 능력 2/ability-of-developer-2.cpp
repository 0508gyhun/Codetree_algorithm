#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int tmp[4];
int a[6];
int main() {
    // 여기에 코드를 작성해주세요.
    for(int i = 0 ; i < 6 ; i++)
    {
        cin >> a[i];
    }

    sort(a,a+6);
    tmp[1] = a[0] +a[5];
    tmp[2] = a[1]+a[4];
    tmp[3] = a[2]+a[3];

    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i = 1 ; i <= 3 ; i++)
    {
        mx = max(mx,tmp[i]);
        mn = min(mn,tmp[i]);
    }
    cout << mx-mn;
    return 0;
}