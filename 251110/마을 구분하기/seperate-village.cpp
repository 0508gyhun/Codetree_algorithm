#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int n, cnt;
int grid[25][25];
int visited[25][25];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<int> ans;
int fcnt = 0;
bool inRange(int ny, int nx) {
    if(ny >=0 && nx >=0 && ny < n && nx < n && visited[ny][nx] == 0 && grid[ny][nx] == 1) return true;
    return false;
}
void dfs(int y, int x) {

    visited[y][x] = 1;

    for(int i = 0 ; i < 4; i ++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(inRange(ny,nx)) {
            visited[ny][nx] = 1;
            cnt++;
            dfs(ny,nx);
        }
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 1 && visited[i][j] == 0)
            {
                fcnt++;
                cnt = 1;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    cout << fcnt<< endl;
    sort(ans.begin(), ans.end());
    for(int a : ans) {
        cout << a <<" "<< endl;
    }
    // Please write your code here.

    return 0;
}
