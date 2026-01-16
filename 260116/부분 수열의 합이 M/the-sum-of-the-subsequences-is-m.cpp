#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// 동전을 더해서 숫자 m 을 만드는 갯수 (최대/최소) 같은 동전이 무제한
// 동전을 더해서 숫자 m 을 만드는 갯수(최대 최소) 같은 동전이 1개 밖에 없음

int n, m;
int A[10004];
int dp[1003e04];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }


    for(int i = 0 ; i <= m ; i++) 
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for(int i = 0; i < n ;i++) 
    {
        for(int j = m ; j >=0 ; j--)
        {
            if(j - A[i] >= 0 )
            {
                if( dp[j - A[i]] != INT_MAX)
                {
                    dp[j] = min(dp[j],dp[j-A[i]] +1 );
                }
            }
        }
    }
    int ans = dp[m];
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    // Please write your code here.

    return 0;
}
