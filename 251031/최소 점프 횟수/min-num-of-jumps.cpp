#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int n;
int num[10];
int ans = INT_MAX;
void go (int idx, int cnt) {
    if(idx >= n-1) {
        ans = min(ans,cnt);
        return;
    }

    for(int i = 1 ; i <= num[idx] ; i++) {
        go(idx+i, cnt+1);
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    go(0,0);

    if(ans == INT_MAX) {
        ans = -1;
    }
    cout << ans;
    // Please write your code here.

    return 0;
}
