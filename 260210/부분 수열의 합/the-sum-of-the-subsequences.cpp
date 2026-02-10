#include <iostream>
 // 중복 허용 x , 동전
#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[100];
int dp[10004];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0 ; i <= m ; i++)
    {
        dp[i] = INT_MIN;
    }
    dp[0] = 1;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = m ; j >=0 ; j--)
        {
            if(j - A[i] >= 0 && dp[j - A[i]] != INT_MIN)
            {
                dp[j] = max(dp[j], dp[j - A[i]]+1);
            }
        }
    }
    // for(int i = 0 ; i <= m ; i++)
    // {
    //     cout << dp[i]<<" ";
    // }

    if(dp[m] == INT_MIN) cout << "No";
    else cout << "Yes";

    // Please write your code here.

    return 0;
}
