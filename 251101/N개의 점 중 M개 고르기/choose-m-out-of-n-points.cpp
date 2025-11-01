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

int cal(int i , int j) {
    int st1 = v[i].first;
    int ed1 = v[i].second;

    int st2 = v[j].first;
    int ed2 = v[j].second;

    return (st2-st1)*(st2-st1) + (ed2-ed1)*(ed2-ed1);
}

void prt() {
    // for(auto i : v) {
    //     cout << i.first<<" "<<i.second<< endl;
    // }
    // cout<< endl;
    int mx = INT_MIN;

   
    for(int i = 0 ; i < m ; i ++) {
        for(int j = i+1 ; j < m ; j++) {
            //가장 먼 곳
            mx = max(mx,cal(i,j));
        }
    }
    mn = min(mn,mx);
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


    go(0,0);

    cout << mn;

    // Please write your code here.

    return 0;
}
