#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[100];
bool dp[104][100004] ; 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        m += arr[i];
    }
    dp[0][0] = true;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= m; j++)
        {
            if(j-arr[i]>= 0 && dp[i-1][j-arr[i]] )
            {
                dp[i][j] = true;
            }
            else if (dp[i-1][j]){
                dp[i][j] = true;
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 1 ; i < m ;i++)
    {
        if(dp[n][i]) ans = min(ans, abs(i-(m-i)));
    }
    cout << ans;



    // Please write your code here.

    return 0;
}
