#include <iostream>

using namespace std;
long long dp[1004];
int n;

int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;

    for(int i = 3 ; i <= n ; i++) 
    {
        long long basic = dp[i-1]*2 + dp[i-2]*3;
    
        
        long long special = 0 ;
        for(int j = i-3 ; j >=0 ; j--) 
        {
            special += (dp[j] * 2);
        }

        dp[i] = (basic + special) % 1000000007;
    }
    cout << dp[n];
    // Please write your code here.

    return 0;
}
