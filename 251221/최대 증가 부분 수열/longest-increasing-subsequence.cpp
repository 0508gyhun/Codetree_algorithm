#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N;
int M[1000];
int dp[1004];


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }


    for(int i = 0 ; i < N ; i++) dp[i] = INT_MIN;
    dp[0] = 1;
    
    for(int i = 1 ; i < N ; i++)
    {
        int mx = 0;
        int mxj = 0;
        for(int j = 0 ; j < i ; j++) 
        {
            if(dp[j] == INT_MIN) continue;
            else {
                if(mx < M[j]) {
                    mx = max(mx, M[j]);            
                    mxj = j;
                }
            }
        }
        if(mx < M[i]) dp[i] =  dp[mxj] + 1;
    }

    // Please write your code here.
    int res = 0;
    for(int i = 0 ; i < N ; i++)
    {   
        res = max(res,dp[i]);
        // cout << dp[i] <<" ";
    }
    // cout << endl;
    cout << res;
    
    return 0;
}
