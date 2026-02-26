#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];
int dp[100000004];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = INT_MIN;
    }
    dp[1] = arr[1];
    for(int i = 2 ; i <= n ; i++)
    {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }
    int ans = dp[1];
    for(int i = 2 ; i <= n ; i++)
    {
        // cout << dp[i]<<" ";
        ans = max(ans,dp[i]);
    }
    cout << ans;
    


    // Please write your code here.

    return 0;
}
