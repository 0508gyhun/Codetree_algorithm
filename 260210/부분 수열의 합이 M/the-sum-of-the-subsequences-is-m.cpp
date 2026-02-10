#include <iostream>
#include <bits/stdc++.h>

// 동전을 최소로 몇개 써서 m 을 만들 수 있는지?

using namespace std;
int INF = 10004;
int n, m;
int coin[104];
int dp[10004];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> coin[i]; 
    }

    //최소르르구해야 하므로 최대로 초기화

    for(int i = 0 ; i <= m ; i++) dp[i] = INF;
    dp[0] = 0; //아무것도 없는 것 0가지

    for(int i = 0 ; i < n ; i++) // coin
    {
        for(int j = m ; j >= 0 ; j--)
        {
            if(j-coin[i] >= 0 && dp[j-coin[i]] != INF)
            {
                dp[j] = min(dp[j] , dp[j-coin[i]] + 1);
            }
        }
    }
    if(dp[m] == INF) cout << -1;
    else cout << dp[m];

    // Please write your code here.

    return 0;
}
