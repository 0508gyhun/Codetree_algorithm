#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;
int coin[100];
int dp[100004];
int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

     for(int i = 0 ; i <= N  ; i++)
    {
        dp[i] = INF;
    }
    dp[0] = 0;




    for(int i = 1 ; i <= M ; i++)
    {
        for(int j = 0 ; j < N ; j++) 
        {
            // if(dp[i-coin[j]] == INT_MAX) continue;
            if(i-coin[j] >= 0) dp[i] = min(dp[i], dp[i-coin[j]] + 1);
        }
    }
    if(dp[M] == INF) cout <<-1;
    else cout << dp[M];

    // Please write your code here.

    return 0;
}
