#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,h,t;
int a[104];
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> h >> t;

    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
    }
    int mn = INT_MAX;
    for(int i = 0 ; i <= n-t ; i++)
    {
        int cost = 0;
        for(int j = i ; j < i+t ; j++)
        {
            cost += abs(h-a[j]);
        }
        mn = min(mn,cost);
        
    }
    cout << mn;
    return 0;
}