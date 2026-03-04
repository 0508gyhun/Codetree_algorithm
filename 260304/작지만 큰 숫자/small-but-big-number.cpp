#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int sequence[100000];
int query[100000];
set<int> s; 
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
        s.insert(sequence[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> query[i];
        auto it = s.upper_bound(query[i]);
        if(it != s.end() && it != s.begin())
        {
            it--;
            cout <<*it<<endl;
            s.erase(*it);
        }
        else
        {
            cout <<-1<<endl;
        }


    }

    // Please write your code here.

    return 0;
}
