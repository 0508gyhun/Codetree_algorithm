#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int r1, c1, r2, c2;
queue<pair<int,int>> q;
int visited[104][104];
int dist[104][104];

int dy[8] = {-1,-2,-2,-1,1,2,2,1};
int dx[8] = {-2,-1,1,2,2,1,-1,-2};

bool inRange(int y, int x)
{
    return (x >= 0 && x < n && y >=0 && y < n);
}
void bfs() {

    while(q.size()) {
        int y,x;
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0 ; i < 8 ; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(visited[ny][nx] == 0 && inRange(ny,nx))
            {
                dist[ny][nx] = dist[y][x] + 1;
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    // Please write your code here.
    q.push({r1,c1});
    visited[r1][c1] = 1;
    dist[r1][c1] = 0;
    bfs();
    if(visited[r2-1][c2-1] == 0) cout << -1;
    else cout << dist[r2-1][c2-1];
    return 0;
}
