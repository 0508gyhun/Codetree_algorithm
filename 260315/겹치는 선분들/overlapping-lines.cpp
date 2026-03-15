#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, K;
int M[100000];
char dir[100000];
vector<pair<int,int>> v,v1;
int main() {
    cin >> N >> K;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> M[i] >> dir[i];
        if(dir[i] == 'L')
        {
            v.push_back({sum - M[i], sum});
            sum = sum - M[i];
        }
        else if( dir[i] == 'R')
        {
            v.push_back({sum, sum+M[i]});
            sum = sum + M[i];
        }
    }

    // sort(v.begin(), v.end());

    for(int i = 0 ;i < N ; i++)
    {
        v1.push_back({v[i].first, 1});
        v1.push_back({v[i].second, -1});
    }

    sort(v1.begin(), v1.end());
    sum = 0;
    int ans = 0;
    for(int i = 0 ; i < 2* N ; i++)
    {
        int x,y;
        tie(x,y)= v1[i];

        if(sum >= K)
        {
            ans += (x - v1[i-1].first);
        }

        sum+=y;
    }
    cout << ans;

    // Please write your code here.

    return 0;
}
