#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[54][54];
int grid[50][50];

void sol()
{
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = INT_MIN; // 
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            for (int p = 0; p < i; p++) {
                for (int q = 0; q < j; q++) {
                    if(grid[i][j] > grid[p][q] && dp[p][q] != INT_MIN)
                    {
                        dp[i][j] = max(dp[i][j], dp[p][q]+1);
                    } 
                }
            }

        }
    }
    int ans = 0 ;
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < m; q++) {
                ans = max(ans,dp[p][q]);
       }
    }

    cout << ans ;


}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    sol();

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << grid[i][j] <<" ";
    //     }
    //     cout << endl;
    // }
    // Please write your code here.

    return 0;
}
