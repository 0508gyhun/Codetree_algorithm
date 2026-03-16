#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n;
int a[MAX_N], b[MAX_N];
vector<tuple<int,int,int>> v;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        v.push_back({a[i],1,i});
        v.push_back({b[i],-1,i});
    }

    sort(v.begin(),v.end());

    set<int> seg;
    int st = 0;
    int end = 0;
    int ans = -1;
    for(int i = 0 ; i < 2*n ;i++)
    {
        int x,y,idx;
        tie(x,y,idx) = v[i];

        if(y == 1)
        {
            if(seg.size() == 0)
            {
                st = x;
            }
            seg.insert(idx);
        }
        else
        {
            seg.erase(idx);
            if(seg.size() == 0)
            {
                end = x;
                ans  = max(ans, abs(st-end));
            }
        }

    }

    cout << ans;

    // Please write your code here.

    return 0;
}
