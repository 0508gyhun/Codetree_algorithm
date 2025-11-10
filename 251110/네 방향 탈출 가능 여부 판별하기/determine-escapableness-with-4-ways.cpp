#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];
queue<pair<int,int>> q;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[104][104];

bool inRange(int y, int x) {
    if(y>= 0 && x>=0 && y < n && x < m) return true;
    return false;
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0 ;
    q.push({0,0});
    a[0][0] = cnt++;
    int y,x;
    while(!q.empty()){
        tie(y,x) = q.front();

        q.pop();

        for(int i = 0 ; i < 4 ; i ++) {
            int ny = y +dy[i];
            int nx = x + dx[i];

            if(inRange(ny,x) && visited[ny][nx] == 0 && a[ny][nx] == 1) {
                visited[ny][nx] = cnt++;
                q.push({ny,nx});
            }
        }

    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << visited[i][j] <<" " ;
    //     }
    //     cout<< endl;
    // }
    cout << (bool)visited[n-1][m-1];
        // Please write your code here.

    return 0;
}
