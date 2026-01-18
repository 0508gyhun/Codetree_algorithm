#include <iostream>

using namespace std;

int n, m;
int A[100];
int dp[10004];

// n 개 동전중복 없이 사용해서 합 M
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0 ; i <= m ; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;

    for(int i = 0 ; i < n ; i++) 
    {
        for(int j = m ; j >= 0 ; j--)
        {
            if(j - A[i]>=0)
            {
                dp[j] = dp[j] + dp[j-A[i]];
            }
        }
    }
    if(dp[m] != 0 ) cout << "Yes";
    else cout << "No";

    // Please write your code here.

    return 0;
}
