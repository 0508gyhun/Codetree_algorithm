#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 // 1 2 5 중복 가능으로 N 만드는 법
int m;

int n = 3;
int A[3] = {1,2,5};
int dp[10000];
int main() {
    cin >> m;

    for(int i = 0 ; i < m ; i++) 
    {
        dp[i] = 0;
    }
    dp[0] = 1;

    for(int i = 1 ; i <= m ;i ++) {
        for(int j = 0 ; j < n ; j++)
        {
            if(i  - A[j] >= 0 )
            {
                dp[i] = (dp[i] + dp[i-A[j]])%10007;
            }
        }
        
    }

    cout << (dp[m] % 10007);

    // Please write your code here.

    return 0;
}
