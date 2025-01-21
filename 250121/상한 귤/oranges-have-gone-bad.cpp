#include <iostream>
#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int>> q;

int n, k;
int a[100][100];
int dist[100][100];
int visited[100][100];
vector<pair<int,int>> rotten;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
void dfs()
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
            if(ny<0 || nx >=n || nx <0 || ny>= n || a[ny][nx]!=1 || visited[ny][nx] ==1) continue;
            dist[ny][nx] = dist[y][x] +1;
            visited[ny][nx] = 1;
            q.push({ny,nx});
        }


    }
}
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) rotten.push_back({i,j});
            if(a[i][j] == 0) dist[i][j] = -1;
        }
    }

    for(int i = 0 ; i < rotten.size() ; i++)
    {
        int r = rotten[i].first;
        int c = rotten[i].second;
        dist[r][c] = 0;
        visited[r][c] = 1;
        q.push({r,c});
    }

    dfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visited[i][j] == 0 && a[i][j] == 1)
            {
                dist[i][j] = -2;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] <<" ";
        }
        cout << endl;
    }
    // Write your code here!

    return 0;
}
