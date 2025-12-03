#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
int grid[104][104];
int r1, c1, r2, c2;
vector <pair<int,int>> wall;
vector<int> v;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int ans = INT_MAX;

bool inRange(int y, int x) {
    return (x >= 0 && y >= 0 && x < n && y < n) ; 
}

void prt() {
    for(auto i : v) { // 벽 없애기
        int y = wall[i].first;
        int x = wall[i].second;

        grid[y][x] = 0;
    }

    queue<pair<int,int>> q;

    int visited[104][104] = {0,};
    int dist[104][104] = {0,};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
        }
    }


    q.push({r1,c1});
    visited[r1][c1] = 1;
    dist[r1][c1] = 0;

    while(q.size()) {
        int y, x;
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int ny = y+ dy[i];
            int nx = x + dx[i];

            if(inRange(ny,nx) && visited[ny][nx] == 0 && grid[ny][nx] == 0) {
                visited[ny][nx] = 1;
                dist[ny][nx] = dist[y][x] +1;
                q.push({ny,nx});
            }
        }
    }
    if(dist[r2][c2] != -1) ans = min(ans,dist[r2][c2]);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(auto i : v) { // 벽 복구
        int y = wall[i].first;
        int x = wall[i].second;

        grid[y][x] = 1;
    }

}
void go (int idx, int cnt) {

    if(cnt > k) return;

    if( idx == wall.size()) {
        if(cnt == k) {
            prt();
        }
        return;
    }

    v.push_back(idx);
    go(idx+1, cnt+1);
    v.pop_back();

    go(idx+1, cnt);
}


int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) wall.push_back({i,j});
        }
    }

    // wall의 갯수 중  K 개 고르기 , wallsize C k

  

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;
    go(0,0);
    if(ans == INT_MAX) cout<< -1;
    else cout << ans;

    // Please write your code here.

    return 0;
}
