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
 // 0 1 2 3.  - 3 2 1 0
    for(int i = 4 ; i <= n ; i++)
    {
        int sum = 0;
        for(int j = 0 ; j < i ; j++) 
        {
            sum += (dp[i] + dp[i-1-j]);
        }
        dp[i] = sum;
    }
    cout << dp[n];

    return 0;
}
