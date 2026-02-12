#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;
int w[104], v[104];
int dp[104][100004];


void initialize() {
    for(int i = 0 ; i < 104; i ++)
    {
        for(int j = 0 ; j < 104 ; j++)
        {
            dp[i][j] = INT_MIN;
        }
    }
    dp[0][0] = 0;

}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    initialize();


    for(int i = 1 ; i <= N ; i++) 
    {
        for(int j = 0 ; j <= M ; j++) {
            if( j - w[i] >= 0 ) dp[i][j] = max(dp[i-1][j] , dp[i-1][j-w[i]] + v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    int ans = 0;

    for(int j = 0; j <= M; j++)
        ans = max(ans, dp[N][j]);

    cout << ans;

    // Please write your code here.

    return 0;
}
