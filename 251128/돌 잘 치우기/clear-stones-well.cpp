#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];
vector<pair<int,int>> v;
vector<int> cb;
int visited[104][104];
int dy[4] = {-1,0,1,0};
int dx[4]= {0,1,0,-1};
int ans = INT_MIN;

void set_zero() {
    for(int i : cb) {
        pair<int,int> pos = v[i];
        int y = pos.first;
        int x = pos.second;

        grid[y][x] = 0;
    }
}

void recover_zero() {
    for(int i : cb) {
        pair<int,int> pos = v[i];
        int y = pos.first;
        int x = pos.second;

        grid[y][x] = 1;
    }
}

bool inRange(int y, int x) {
    return (y >= 0 && y < n && x >= 0 && x < n );
}
void bfs() {
    for (int i = 0; i < 104; i++) {
        for (int j = 0; j < 104; j++) {
            visited[i][j] = 0;
        }
    }

    queue <pair<int,int>> q;
    for (int i = 0; i < k; i++) {
        q.push({r[i],c[i]});
        visited[r[i]][c[i]] = 1;
    }

    while(q.size()) {
        int y,x ;
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(grid[ny][nx] == 0 && visited[ny][nx] == 0 && inRange(ny,nx) == true ) {
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }
    int cnt = 0 ;
    for (int i = 0; i < 104; i++) {
        for (int j = 0; j < 104; j++) {
            if(visited[i][j] == 1) cnt++;
        }
    }
    ans = max(ans, cnt);
}


void prt() {
    for(int i : cb) {
        // cout << i << " ";
    }
    // cout << endl;
    set_zero();
    bfs();
    recover_zero();
}

void com(int idx, int cnt) {
    if(idx == v.size()) {
        if(cnt == m) {
            prt();
        }
        return ;
    }

    cb.push_back(idx);
    com(idx+1, cnt+1);
    cb.pop_back();

    com(idx+1, cnt);

}

int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1) v.push_back({i, j});
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    com(0,0);
    cout << ans;
    // Please write your code here.

    return 0;
}
