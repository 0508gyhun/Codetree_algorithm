#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int grid[10][10];
//n 개 중 n 개 순열
int visited[11];
vector<int> v;
int mx = INT_MIN;

int prt() {
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum+=(grid[i][v[i]]);
    }
    // cout << endl;
    return sum;
}
void go (int idx) {
    if(idx == n) {
        mx = max(mx,prt());
        return;
    }

    for(int i = 0 ; i < n ; i ++) {
        if(visited[i] == true) continue;
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
    cout << mx;


    // Please write your code here.

    return 0;
}
