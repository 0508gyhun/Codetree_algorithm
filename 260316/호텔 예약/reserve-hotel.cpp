#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int s[100004];
int e[100004];

vector<tuple<int,int,int>> v;

map<int,int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
        mp[s[i]]++;
        mp[e[i]]--;
    }

    // sort(v.begin(), v.end());
    // set<int> seg;
    int sum = 0 ;
    int ans = -1;
    int prev = -1;
    for(auto i : mp)
    {
        
        sum += i.second;
        if(prev == i.first) sum++;
        ans = max(ans,sum);
        prev = i.first;
    }

    cout << ans;

    
        // Please write your code here.

    return 0;
}
