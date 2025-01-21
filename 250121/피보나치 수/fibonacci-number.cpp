#include <iostream>

using namespace std;

int N;
int dp[46];

int main() {
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i = 3 ; i <= 45 ; i ++)
    {
        dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[N];
    // Write your code here!

    return 0;
}
