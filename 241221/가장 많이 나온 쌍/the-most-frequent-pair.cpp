#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[104];
int b[104];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >>m;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a[i] >> b[i];
    }
    int mx = INT_MIN;
    for(int i = 0 ; i < m ; i++)
    {
        int cnt = 1 ;
        for(int j = i+1 ; j< m ; j++)
        {
            if((a[i] == a[j] && b[i] == b[j]) || (a[i] == b[j] && b[i] == a[j])) cnt++;
        }
        mx = max(mx,cnt);
    }
    cout << mx;
    return 0;
}