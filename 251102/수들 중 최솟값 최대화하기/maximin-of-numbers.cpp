#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int grid[10][10];
//순열 길이 N 개
int visited[10];
vector<int> v;
int mx = INT_MIN;

void prt() {
    int mn = INT_MAX;
    for(int i = 0 ; i < n ; i++) {
        // cout << i <<" ";
        mn = min(mn, grid[i][v[i]]);
    }
    // cout << endl;
    mx = max(mx,mn);
}

void go(int idx) {
    if(idx == n) {
        prt();
        return;
    }

    for(int i = 0 ; i < n ; i++) {
        if(visited[i]) continue;
        v.push_back(i);
        visited[i] = true;

        go(idx+1);

        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    go(0);
    cout << mx ;
    // Please write your code here.

    return 0;
}
