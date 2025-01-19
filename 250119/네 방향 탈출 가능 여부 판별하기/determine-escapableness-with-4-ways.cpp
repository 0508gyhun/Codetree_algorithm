#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];
int visited[100][100];
queue<pair<int,int>> q;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

//뱀 0  가능 1
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 1;
    a[0][0] = cnt++;
    visited[0][0] = 1;
    q.push({0,0});
//    bfs();
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            int ny = y+ dy[i];
            int nx = x + dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] == 1 || a[ny][nx] == 0)continue;
            visited[ny][nx] = 1;
            q.push({ny,nx});
            a[ny][nx] = cnt;
        }
        cnt++;
        
    }

    //   for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << a[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    if(a[n-1][m-1] >1) cout <<"1";
    else cout << "0";
    // Write your code here!

    return 0;
}
