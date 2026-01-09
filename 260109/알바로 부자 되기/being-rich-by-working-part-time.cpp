#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1004];
int N;
int s[1000], e[1000], p[1000];
vector<tuple<int,int,int>> v;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> p[i];
        v.push_back({s[i],e[i],p[i]});
    }

    sort(v.begin(), v.end());

    for(int i = 0 ; i < N;i++) 
    {
        dp[i] = get<2>(v[i]);
        for(int j = 0 ; j < i ; j++) {

            int a = get<0>(v[i]);
            int b = get<1>(v[j]);

            if(b < a)
            {
                dp[i] = max(dp[i], dp[j]+ get<2>(v[i]));
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
