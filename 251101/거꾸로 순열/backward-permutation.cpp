#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool visited[9];
int n;

void prt() {
    for(int i : v) {
        cout << i <<" ";
    }
    cout << endl;
}

void go(int idx) {
    if(idx == n) {
        prt();
        return;
    }

    for(int i = n ; i >= 1 ; i--) {
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(i);

        go(idx+1);
        
        visited[i] = false;
        v.pop_back();    
    }
}


int main() {
    cin >> n;

    // Please write your code here.
    go(0);
    return 0;
}
