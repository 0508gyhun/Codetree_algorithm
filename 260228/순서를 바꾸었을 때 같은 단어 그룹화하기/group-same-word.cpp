#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
string words[1000];
map <string,int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        
        sort(words[i].begin(), words[i].end());

        mp[words[i]]++;
    }
    int ans = -1;
    for(auto i : mp)
    {
        ans = max(ans,i.second);
    }
    cout << ans;

    // Please write your code here.

    return 0;
}
