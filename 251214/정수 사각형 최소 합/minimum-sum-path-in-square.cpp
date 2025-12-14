#include <iostream>

using namespace std;

int n;
int grid[104][104];
int dp[104][104];


// 1,n -> 1, 0


void initialize()
{
    dp[0][n-1] = grid[0][n-1];

    for (int i = n-2; i >= 0; i--) {
        dp[0][i] = dp[0][i+1] + grid[0][i]; 
    }// 맨 위

    for (int i = 1; i < n; i++) {
        dp[i][n-1] = dp[i-1][n-1] + grid[i][n-1]; 
    }
    //오른 쪽

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = n-2; j >= 0 ; j--)
        {
            int case1 = dp[i-1][j] + grid[i][j]; // 위
            int case2 = dp[i][j+1] + grid[i][j];                       //오른

            if(case1 >= case2) dp[i][j] = case2; 
            else dp[i][j] =  case1;
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
 // 왼쪽 , 아래

    initialize();
    // Please write your code here.

//    for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << dp[i][j] <<" ";
//         }
//         cout << endl;
//     }

    cout << dp[n-1][0];
    return 0;
}
