#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
long long x1[100004], x2[100004];
//1000 000 000
map <long long, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        mp[x1[i]]++;
        mp[x2[i]]--;

    }

    int ans = 0;
    int sum = 0;
    for(auto it : mp)
    {
        sum+=it.second;
        ans = max(ans,sum);
    }
    cout << ans;



    // Please write your code here.

    return 0;
}
