#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n, m;
int a[20];
// n 개 중 m 개 고르기
int mx = INT_MIN;
void prt() {
    int ans = 0;
    for(int i : v) {
        // cout <<i <<" ";
        ans  = ans ^ i;
    }
    // cout << endl;
    mx = max(mx, ans);
}
void go(int idx,int cnt) {

    if(idx == n) {
        if(cnt == m) {
            //some
            prt();
        }
        return ;
    }

    
        v.push_back(a[idx]);
        go(idx+1, cnt+1);
        v.pop_back();

        go(idx+1, cnt);
    
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    go(0,0);
    cout << mx ;
    // Please write your code here.

    return 0;
}