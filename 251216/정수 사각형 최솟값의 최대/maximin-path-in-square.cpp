#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int grid[100][100];
int dp[104][104];
vector<int> ans;

void initial() {

    dp[0][0] = grid[0][0];
    // ans.push_back(grid[0][0]);

    for(int i = 1 ; i < n ; i++) 
    {
        dp[i][0] =  min(dp[i-1][0] , grid[i][0]);
    }
    
    for(int i = 1 ; i < n ; i++) 
    {
        dp[0][i] = min(dp[0][i-1] , grid[0][i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int case1 = dp[i-1][j];
            int case2 = dp[i][j-1];
            
            dp[i][j] = min(grid[i][j],max(case1, case2));
        }
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    initial();

    cout << dp[n-1][n-1];
    // Please write your code here.


    return 0;
}
