#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int profit[100];
int dp[104][10004];
int w[104];
int v[104];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        w[i] = i;
    }

    for(int i = 0 ; i < 104 ; i++)
    {
        for(int j = 0 ; j < 10004 ; j++)
        {
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = 0;

    for(int i = 1 ; i <= n ; i++) // 후보 = 동전갯수n
    {
        for(int j = 0 ; j <= n ; j++) // 만들어야 하는 수
        {
            dp[i][j] = dp[i-1][j];

            if(j-w[i]>=0)
            {
                dp[i][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            }
        }
    }
    int ans = dp[n][n] ;
    
    cout << ans;



    // Please write your code here.

    return 0;
}
