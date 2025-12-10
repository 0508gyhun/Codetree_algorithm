#include <iostream>

using namespace std;

int n;
int dp[20];

int main() {
    cin >> n;

    // Please write your code here.
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for(int i = 4 ; i <= n ; i++)
    {
        dp[i] = dp[i-1]*2;
    }
    cout << dp[n];

    return 0;
}
