#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];
int visited[104][104];
int dist[104][104];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
queue<pair<int,int>> q;

bool inRange(int y, int x)
{
    return (y >= 0 && y < n && x >= 0 && x < n) ;
}

void bfs() {

    while(q.size())
    {
        int y,x;
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx] == 0 && a[ny][nx] == 1 && inRange(ny,nx) == true)
            {
                dist[ny][nx] = dist[y][x] +1;
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }

    }
    
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    visited[0][0] = 1;
    q.push({0,0});
    dist[0][0] = 0;
    bfs();

    // Please write your code here.
    if(dist[n-1][m-1] == 0) cout << -1;
    else cout << dist[n-1][m-1];
    return 0;
}
