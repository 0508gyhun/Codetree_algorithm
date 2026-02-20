#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;
int w[100], v[100];
int dp[10004];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    for(int i = 0 ; i <= M ; i++)
    {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    //여러개가능

    for(int i = 1  ; i <= M ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            if(i>=w[j] && dp[i] != INT_MIN) dp[i] = max(dp[i], dp[i-w[j]] + v[j]);
        }
    }

    int ans = 0 ;

    for(int i = 0 ; i <= M ; i++)
    {
        ans = max(ans,dp[i]);
    }
    cout << ans;

    // Please write your code here.

    return 0;
}
