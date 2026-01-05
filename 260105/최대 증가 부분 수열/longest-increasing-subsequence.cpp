#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N;
int M[1000];
int dp[1004];
void sol() 
{
    for(int i = 0 ; i < N ; i++) 
    {
        dp[i] = 1;
    }

    for(int i = 1 ; i < N ; i++) 
    {
        int mx = dp[i];
        for(int j = 0 ; j < i ; j++) 
        {
            if(M[j] < M[i])
            {
                mx = max ( mx, dp[j] + 1 );
            }    
        }
        dp[i] = mx;
        
    }
    int ans = 0;

    for(int i = 0 ; i < N ; i++) 
    {
        ans = max (ans, dp[i]);
        // cout << dp[i]<< " ";
    }
    cout<< ans;

}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    sol();

    // Please write your code here.

    return 0;
}
