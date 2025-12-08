#include <iostream>

using namespace std;
int dp[1004] ;
int n;

int main() {
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i = 4 ; i <= n ; i++) 
    {
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }

    cout<<dp[n];
    // Please write your code here.

    return 0;
}
