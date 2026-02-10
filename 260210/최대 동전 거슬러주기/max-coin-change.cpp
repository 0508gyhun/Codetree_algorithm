#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// 중복 허용하여ㅜ동저 거슬러 주기 최대동전 수
int N, M;
int coin[104];
int dp[10004];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    for(int i = 0 ; i <= M ; i++)
    {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;

    for(int i = 0 ; i <= M ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            if(i - coin[j] >= 0 && dp[i-coin[j]] != INT_MIN)
            {
                dp[i] = max(dp[i], dp[i - coin[j]] + 1 );
            }
        }
    }

    if(dp[M] != INT_MIN) cout << dp[M];
    else cout << -1;
    // Please write your code here.

    return 0;
}
