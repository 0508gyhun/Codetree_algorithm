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
    dp[0][n-1] = a[0][n-1];

    //horiz
    for(int i = n-2 ; i >= 0 ;i--)
    {
        dp[0][i] = dp[0][i+1]+ a[0][i];
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout <<dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }

    for(int i = 1 ; i < n ; i++)
    {
        dp[i][n-1] = dp[i-1][n-1] + a[i][n-1];
    }
    // Write your code here!
    //  for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout <<dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    for(int i = 1 ; i<n ; i++)
    {
        for(int j = n-2 ; j >=0 ; j--)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j+1]) + a[i][j];
        }
    }
    // cout << endl;

    //  for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout <<dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n-1][0];
    return 0;
}
