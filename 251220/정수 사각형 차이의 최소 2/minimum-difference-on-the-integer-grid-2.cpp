#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int grid[100][100];
int dp[104][104];


void init() 
{
    dp[0][0] = grid[0][0];

    //left
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], grid[i][0]);
    }
    //top
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i-1], grid[0][i]);
    }

    
}


int sol(int lower) 
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] < lower) grid[i][j] = INT_MAX; // check
        }
    }   

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MAX; // check
        }
    }
    init();

     for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), grid[i][j]);
        }
    }   

    return dp[n-1][n-1];

}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = INT_MAX;

    for(int lower = 1 ; lower <= 100 ; lower++)
    {
        int upper = sol(lower);

        if(upper == INT_MAX) continue; //fail

        ans = min(ans, upper-lower);
    }

    cout << ans;
    // Please write your code here.

    return 0;
}
