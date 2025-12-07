#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int n, k;
int grid[100][100];
queue<pair<int,int>> q;

int visited[104][104];
int dist[104][104];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n >> k; // n 격자, k 상한 귤

 // 0 = 아무것도, 1  = 귤, 2 = 상한 귤

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 2) 
            {
                q.push({i,j});
                visited[i][j] = 1;
                dist[i][j] = 0;
            }
            if(grid[i][j] == 0)
            {
                dist[i][j] = -1;
            }
        }
    }

    while(q.size()) {
        int y,x;
        tie(y,x) = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++) 
        {
            int ny = y+ dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx] == 0 && grid[ny][nx] == 1) {
                dist[ny][nx] = dist[y][x] + 1;
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 1 && dist[i][j] == 0) dist[i][j] = -2;
        }
        // cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // Please write your code here.

    return 0;
}
