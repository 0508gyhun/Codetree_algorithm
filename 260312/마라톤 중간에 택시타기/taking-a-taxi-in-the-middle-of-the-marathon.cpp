#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int x[100004], y[100004];
int l[100004];
int r[100004];
int main() {
    cin >> n;

    x[0] = 0;
    y[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    l[1] = 0;
    for(int i = 2 ; i <= n ;i++)
    {
        l[i] = l[i-1] + abs(x[i] - x[i-1])+ abs(y[i] - y[i-1]);
    }
    r[n] = 0;
    for(int i = n-1 ; i>=1 ; i--)
    {
        r[i] = r[i+1] + abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
    }

    // for(int i = 0 ; i <= n ;i++)
    // {
    //     cout << l[i]<<" ";
    // }
    // cout << endl;
    // for(int i = 0 ; i <= n ;i++)
    // {
    //     cout << r[i]<<" ";
    // }
    int ans = INT_MAX;
    for(int i = 2 ; i < n ;i++)
    {
        ans = min(ans,l[i-1] + r[i+1] + abs(x[i-1]-x[i+1])+ abs(y[i-1] - y[i+1]));
    }
    cout << ans;

    // Please write your code here.

    return 0;
}
