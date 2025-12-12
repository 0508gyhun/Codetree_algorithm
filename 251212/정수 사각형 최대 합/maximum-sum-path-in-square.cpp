#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int n;
int grid[104][104];
int dp[104][104];
int ans = INT_MIN;

void prt_dp() 
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
}
void initialize() 
{
    dp[0][0] = grid[0][0];

    // 세로 좌
    for(int i = 1 ; i < n ; i++) 
    {
        dp[0][i] = grid[0][i] + dp[0][i-1];
    }

    // 가로 위
    for(int i = 1 ; i < n ; i++)
    {
        dp[i][0] = grid[i][0] + dp[i-1][0]; 
    }
    // 나머지

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j < n ; j++)
        {
            int case1 = grid[i][j] + dp[i][j-1]; // 조ㅏ
            int case2 = grid[i][j] + dp[i-1][j]; // 위
            if(case1 >= case2) dp[i][j] = case1;
            else dp[i][j] = case2;
        }
    }

    cout << dp[n-1][n-1];
    //맨 아랫줄 계산


}




int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    initialize();
    // prt_dp();
    // Please write your code here.
    // cout << ans;
    return 0;
}
