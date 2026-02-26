#include <iostream>

using namespace std;

int n;
int coin[1004];
int dp[1004][5]; // 최대 3개

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }

    dp[1][1] = coin[1];
    dp[2][0] = coin[2];
    dp[2][2] = coin[1]+coin[2];

    for(int i = 3 ; i <= n ;i++)
    {
        for(int j = 0 ; j <= 3 ; j++)
        {
            //do칸
            if(dp[i-2][j] > 0 )
            {
                dp[i][j] = max(dp[i][j], dp[i-2][j] + coin[i]);
            }
            if(j-1>=0 && dp[i-1][j-1] != 0)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + coin[i]);
            }
            //han칸
        }
    } 
    int ans = 0 ;
    for(int i = 0 ; i <=3 ; i++)
    {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;

    // Please write your code here.

    return 0;
}
