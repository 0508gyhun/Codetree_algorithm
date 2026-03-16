#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int a[100004], b[100004];
vector<tuple<int,int,int>> v;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        v.push_back({a[i],1,i});
        v.push_back({b[i],-1,i});
    }   
    sort(v.begin(), v.end());
    set<int> seg; //idx
    int ans = 0;
    int st = 0;
    int end = 0;
    for(int i = 0 ; i < 2*n ; i++)
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
                ans += (end-st);
            }
        }
                
    }
    cout << ans;

    // Please write your code here.

    return 0;
}
