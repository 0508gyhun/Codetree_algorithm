#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100004], b[100004];
vector<tuple<int,int,int>> segment;
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        segment.push_back(make_tuple(a[i],1,i));
        segment.push_back(make_tuple(b[i],-1,i));
    }

    sort(segment.begin(), segment.end());

    set<int> seg;
    int ans = 0;
    for(int i = 0 ; i < 2*n ; i++)
    {
        int x,y,idx;
        tie(x,y,idx) = segment[i];

        if(y == 1 )
        {
            if(seg.size() == 0) ans++;
            seg.insert(idx);
        }
        else if(y == -1)
        {
            seg.erase(idx);
        }
    }

    cout << ans;

    // Please write your code here.

    return 0;
}
