#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int s[100004];
int e[100004];

vector<tuple<int,int,int>> v;



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
        v.push_back({s[i], 1, i});
        v.push_back({e[i],-1,i});
    }

    sort(v.begin(), v.end());
    set<int> seg;
    int ans = 0 ;
    for(int i = 0 ; i < 2 * n ; i ++)
    {
        int x,y,idx;
        tie(x,y,idx) = v[i];

        if(y == 1)
        {
            if(seg.size() == 0)
            {
                ans++;
            }
            seg.insert(idx);
        }
        else
        {
            seg.erase(idx);
        }
        
    }

    cout << ans;

    
        // Please write your code here.

    return 0;
}
