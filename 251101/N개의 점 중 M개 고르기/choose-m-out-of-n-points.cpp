#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int n, m;
int x[20], y[20];
vector<pair<int,int>> nums;
vector<pair<int,int>> v;

//오름차순해갖고, 
// n개 중 M 개 고르기
// m 중 처음과 끝 거리 게산
int mn = INT_MAX;
void prt() {
    // for(auto i : v) {
    //     cout << i.first<<" "<<i.second<< endl;
    // }
    // cout<< endl;
    pair<int,int> st = v[0];
    pair<int,int> ed = v[m-1];

    int dist = ((st.first-ed.first)*(st.first-ed.first) + (st.second - ed.second)*(st.second - ed.second));

    mn = min(mn,dist);

}

void go(int idx, int cnt) {

    if(idx == n) {
        if(cnt == m) {
            prt();
        }
        return;
    }

    v.push_back(nums[idx]);
    go(idx+1, cnt+1);
    v.pop_back();

    go(idx+1, cnt);
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        nums.push_back({x[i],y[i]});
    }
    sort(nums.begin(), nums.end());

    go(0,0);

    cout << mn;

    // Please write your code here.

    return 0;
}
