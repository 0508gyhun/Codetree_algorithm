#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[200][200];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int visited[204][204];

bool flag = true;
int tom ;
vector<int> ans;

void count_a() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool inRange(int y, int x) {
    return (y >= 0 && y < N && x >= 0 && x < M);
}

void dfs(int y, int x) {
    visited[y][x] = 1;

    for(int i = 0 ; i < 4 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(visited[ny][nx] == 0 && a[ny][nx] == 0 && inRange(ny,nx) == true) {
            dfs(ny,nx);
        }
        if(visited[ny][nx] == 0 && a[ny][nx] == 1 && inRange(ny,nx) == true) {
            visited[ny][nx] = 1;
            a[ny][nx] = 0;
        }
    }
    return ;
}
void check() {
    tom++;
    int cnt = 0;
    flag = false;
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(a[i][j] == 1) {
                flag = true;
                cnt++;
            }
        }
    }
    // cout << cnt<< endl;
    
}

void fir_check() {
    int cnt = 0 ;
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(a[i][j] == 1) {
                cnt++;
            }
        }
    }
    ans.push_back(cnt);
}
int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }


    while(flag) {
        fir_check();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = 0;
            }
        }
        dfs(0,0);
        // count_a();
        check();
    }
    cout << tom << " ";
    // for(int i : ans) {
    //     cout << i <<" ";
    // }
    cout << ans[ans.size()-1] << endl;
   

    // Please write your code here.

    return 0;
}
