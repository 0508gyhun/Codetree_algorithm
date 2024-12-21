#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int n,m;
int a[104];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >>m;;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i+1];
    }

    int mx = INT_MIN;

    for(int i = 1 ; i <= n ; i++) // 시작 지점 경우의 수
    {
        int sum = 0;
        int st = i;
        for(int j = 0 ; j < m ; j++)
        {
            sum += a[st];
            st = a[st];
        }
        mx = max(mx,sum);
        
    }
    cout << mx;
    return 0;
}