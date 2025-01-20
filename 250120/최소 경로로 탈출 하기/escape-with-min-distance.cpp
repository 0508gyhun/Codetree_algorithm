#include <iostream>
#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int>> q;

int visited[100][100];
int dist[100][100];
int n, m;
int a[100][100];
// 뱀 0 가능 1
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};


void bfs()
{
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx <0 || nx>= n || ny>=m || visited[ny][nx] == 1 || a[ny][nx] == 0) continue;

            visited[ny][nx] = 1;
            dist[ny][nx] = dist[y][x] + 1;   
            q.push({ny,nx});

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
    int ans =-1;

    dist[0][0] = 0;
    visited[0][0] = 1;
    q.push({0,0});
    bfs();

    // Write your code here!
    cout << dist[n-1][m-1];
    return 0;
}
