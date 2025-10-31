#include <iostream>

using namespace std;
#include <bits/stdc++.h>

int N, M;
//1-N 까지 중 m=3개
vector<int> v;
void go (int idx, int cnt) {
    if(idx == N+1) {
        if(cnt == M)
        {
            for(int i : v) {
                cout << i <<" ";
            }
            cout << endl;
        }
        return;
    }
    
        v.push_back(idx);
        go(idx+1, cnt+1);
        v.pop_back();

        go(idx+1, cnt);
    
}

int main() {
    cin >> N >> M;


    go(1,0);
    // Please write your code here.

    return 0;
}
