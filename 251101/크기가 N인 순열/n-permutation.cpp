#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int visited[9];
vector<int> v;

void prt() {
    for(int i : v ) {
        cout << i <<" ";
    }
    cout << endl;
}

void go (int idx) {
    if(idx == n) {
        prt();
        return;
    }

    for(int i = 1 ; i <= n ; i++) {
        if(visited[i]) continue; 

        visited[i] = true;
        v.push_back(i);
        go(idx+1);

        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> n;


    go(0);
    // Please write your code here.

    return 0;
}
