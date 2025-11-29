#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k, u, d;
int grid[10][10];
int visited[10][10];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<pair<int,int>> city;
vector<int> v;
int ans = INT_MIN;

void visited_prt() {


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout<< endl;
}

int visited_cnt() {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visited[i][j] == 1) cnt++;
        }
    }
    return cnt ;
}

void visited_clear() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;       
        }
    }
}

bool inRange(int y, int x) {
    return (x >= 0 && y >= 0 && x < n && y < n );
}

bool isPossible(int y, int x, int ny, int nx ) {
    if( abs(grid[y][x] - grid[ny][nx]) >= u  && abs(grid[y][x] - grid[ny][nx]) <= d) return true;
    return false;
}

void dfs(int y, int x ) {

    for(int i = 0 ; i < 4 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(visited[ny][nx] == 0 && inRange(ny,nx) && isPossible(y,x,ny,nx)) {
            visited[ny][nx] = 1;
            dfs(ny,nx);
        }
    }
}

void prt() {

    visited_clear();
    for(int i : v) {
        // cout << i <<" "<< endl;
        int y = city[i].first;
        int x = city[i].second;
        visited[y][x] = 1;
        dfs(y,x);
    }
    
    // visited_prt();
    ans = max(ans, visited_cnt());

}

void go(int idx, int cnt) {

    if(idx == city.size())
    {
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
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            city.push_back({i,j});
        }
    }

    go(0,0);

    cout << ans;
    // Please write your code here.

    return 0;
}
