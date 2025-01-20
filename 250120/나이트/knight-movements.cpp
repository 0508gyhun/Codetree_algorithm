#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int r1, c1, r2, c2;
int a[100][100];
int dist[100][100];
int visited[100][100];
queue<pair<int, int>> q;

int dy[8] = {-1,-2,-2,-1,1,2,2,1};
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
void dfs()
{
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        
        for(int i = 0 ; i < 8 ; i++)
        {
            int ny = y+ dy[i] ; 
            int nx = x + dx[i]; 

            if(nx<0 || ny <0 || nx>=n || ny>=n || visited[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            dist[ny][nx] = dist[y][x] +1;
            q.push({ny,nx});
        }
    }
}


int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    // Write your code here!
    r1--;
    c1--;
    r2--;
    c2--;

    visited[r1][c1] = 1;
    dist[r1][c1] = 0;
    q.push({r1,c1});
    dfs();

    if(visited[r2][c2] == 1) cout << dist[r2][c2];
    else cout << -1;

    return 0;
}
