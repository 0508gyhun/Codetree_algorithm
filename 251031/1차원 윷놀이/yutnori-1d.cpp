#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int n, m, k;
int nums[12];
int mal[5];
vector<int> v;
int mx = INT_MIN;
void prt() {
    for(int i = 0 ; i < 5 ; i++) {
        mal[i] = 1;
    } // mal 초기화 
    int cnt = 0;
    for(int i : v) {
        // cout << i <<" "; // k개 중 1개를 n 번, 즉 nums = n개 
        mal[i] += nums[cnt++];
    }
    // cout << endl;
    int ans = 0 ;
    for(int i = 0 ; i < 5 ; i++)
    {
        // cout << mal[i] <<" ";
        if(mal[i] >= m) ans++;
    }
    // cout << endl; 
    mx = max(mx,ans);
}

void go (int idx) {
    if(idx == n) {
        prt();
        return ;
    }

    for(int i = 0 ; i < k ; i ++) 
    {
        // mal[i] += nums[idx];
        v.push_back(i);
        go(idx+1);
        v.pop_back();
        // mal[i] -= nums[idx];

    }
}

int main() {
    cin >> n >> m >> k;
    //n 번의 이동 기회
    //m 이라는 점수 기준
    //k 개의 말

    //k 개 중 1개를 n 번 , 덧셈으로 
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    go(0);

    // Please write your code here.
    cout << mx ;
    return 0;
}
