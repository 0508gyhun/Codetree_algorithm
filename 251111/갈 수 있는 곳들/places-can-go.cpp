#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
int visited[104][104];
int cnt ;
queue<pair<int,int>> q;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool inRange(int y, int x) {
    if(y>=0 && x >=0 && y < n && x < n ) return true;
    return false;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++){
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
        q.push({r[i], c[i]});
    }
    int cnt = 0;
    while(!q.empty()) {
        int y,x;
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx] == 0 && inRange(ny,nx) && grid[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                q.push({ny,nx});
                cnt++;
            }
        }
    }
    cout << cnt;

    // Please write your code here.

    return 0;
}
