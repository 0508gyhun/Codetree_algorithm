#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int n;
int A[10][10];
// 0-n 까지 수 중 순열인데, 뽑힌 순열이 자기 자신인덱스인 경우 제외
int visited[11];
int mn = INT_MAX;

void prt() {
    // cout<<v.front()<<endl;
    int sum = 0; 
    int st = 0;
    int dest = 0;
    for(int i : v ) {
        dest = i;
        if(A[st][dest] == 0) return ;
        sum+=A[st][dest];
        // cout << "("<<A[st][dest]<<")";
        st = dest;
        // cout <<i <<" ";
    }
    sum+=A[st][0];
    // cout << " sum = "<< sum;
    mn = min(mn,sum);
    // cout << endl;
}
void go(int idx) {
    if(idx == n-1) {
        prt();
        return;
    }
    for(int i = 1 ; i < n ; i++) {
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    go(0);
    // Please write your code here.
    cout << mn;
    return 0;
}
