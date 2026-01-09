#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int n;
int x1[1000];
int dp[1004];
int x2[1000];
vector<pair<int,int>> v;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        v.push_back({x1[i], x2[i]});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for(int j = 0 ; j < i ; j++) 
        {
            int a = v[i].first;
            int b = v[j].second;

            if( a > b ){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans;
    // Please write your code here.

    return 0;
}
