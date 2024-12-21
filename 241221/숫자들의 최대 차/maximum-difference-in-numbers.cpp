#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int n,k;
int a[1004];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    int ans = INT_MIN;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            int mx = INT_MIN;
            int mn = INT_MAX;

            for(int p = i ; p <= j ; p ++)
            {
                mx = max(mx,a[p]);
                mx = min(mn,a[p]);
            }
            if(mx-mn <= k)
            {
                ans = max(ans,j-i);
            }
        }
    }
    cout << ans;
    return 0;
}