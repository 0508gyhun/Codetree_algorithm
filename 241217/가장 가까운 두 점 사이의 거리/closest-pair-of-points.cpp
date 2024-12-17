#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int a[104][2];
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >>a[i][0] >> a[i][1];
    }

    int mn = INT_MAX;

    for(int i = 0 ; i < n ; i++)
    {   
        int ans = 0;
        for(int j = i+1 ; j < n ; j++)
        {
            ans = (a[i][0] - a[j][0])*(a[i][0] - a[j][0]) + (a[i][1] - a[j][1])*(a[i][1] - a[j][1]);
            mn = min(mn,ans);

        }
    }
    cout << mn;

    return 0;
}