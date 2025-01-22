#include <iostream>

using namespace std;

int n;
int a[100][100];
int dp[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];

    for(int i = 1 ; i < n ; i++) // 세로 
    {
        dp[i][0] = a[i][0] + dp[i-1][0];
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    for(int i = 1 ; i < n ;i++) // 대각
    {
        dp[i][i] = dp[i-1][i-1] + a[i][i];
    }
    // Write your code here!
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int i = 2 ; i < n ; i++)
    {
        for(int j = 1 ; j < i ; j++)
        {
            dp[i][j] = max(dp[i-1][j]+a[i][j], dp[i-1][j-1] + a[i][j] );
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        ans = max(ans,dp[n-1][i]);
    }   
    cout << ans;
    return 0;
}
