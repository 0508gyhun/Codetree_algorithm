#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1004];
int N;
int s[1000], e[1000], p[1000];
vector<pair<int,int>> v;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> p[i];
        v.push_back({s[i], e[i]});
        dp[i] = p[i];
    }

    sort(v.begin(), v.end());

    for(int i = 1 ; i < N;i++) 
    {
        for(int j = 0 ; j < i ; j++) {

            pair<int,int> a = v[i];
            pair<int,int> b = v[j];

            if(b.second < a.first)
            {
                dp[i] = max(dp[i], dp[i]+ p[j]);
            }
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i < N ; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;



    // Please write your code here.

    return 0;
}
