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

    for(int i = 1 ; i < n ; i++) // rk로 
    {
        dp[0][i] = a[0][i] + dp[0][i-1];
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;


    for(int i = 1 ; i < n ;i++) // 
    {
        for(int j =1 ; j < n ; j++)
        {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + a[i][j];
        }
    }
    // Write your code here!
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

 
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
   
   cout << dp[n-1][n-1];
    return 0;
}
