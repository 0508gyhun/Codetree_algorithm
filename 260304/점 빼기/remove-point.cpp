#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n, m;
int x[MAX_N], y[MAX_N];
int k[MAX_N];
set<pair<int,int>> s;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        s.insert({x[i],y[i]});
    }

    for (int i = 0; i < m; i++) {
        cin >> k[i];
        auto it = s.lower_bound({k[i],-1});
        if(it == s.end())
        {
            cout << "-1 -1"<<endl;
        }
        else
        {
            cout <<(*it).first <<" "<<(*it).second<<endl;
            s.erase(*it);
        }
       
    }

    // Please write your code here.

    return 0;
}
