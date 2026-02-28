#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int x[100000], y[100000];
map<int,int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        if(mp.count(x[i]) == 0)
        {
            mp[x[i]] = y[i];
        }
        else
        {
            if(y[i] < mp[x[i]])
            {
                mp[x[i]] = y[i];
            }
        }
    }
    int ans = 0;
    for(auto i : mp)
    {   
        ans+=i.second;
        // cout << i.first << " "<< i.second<< endl;
    }
    cout << ans;
    //없으면 추가
    //있으면 비교해서 교체



    // Please write your code here.

    return 0;
}