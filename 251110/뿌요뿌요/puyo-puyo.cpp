#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int grid[104][104];
int visited[104][104];
int mx = INT_MIN;
int cnt = 0 ;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool inRange(int y, int x) {
    if(y>=0 && y < n && x >= 0 && x < n )return true;
    return false;
}
void dfs(int y, int x, int num) {

    for(int i = 0 ; i < 4 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(visited[ny][nx] == 0 && inRange(ny,nx) && grid[ny][nx] == num) {
            visited[ny][nx] = 1 ;
            cnt++;
            dfs(ny,nx,num);
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
    int bcnt = 0;
    for(int i = 0 ; i < n ; i++) 
    {
        for(int j = 0 ; j < n ; j++) {
            if(visited[i][j] == 0 )
            {
                
                cnt = 0;
                dfs(i,j,grid[i][j]);
                if(cnt >= 4 ) {
                    bcnt++;
                    mx = max(mx, cnt);
                }
                else
                {
                    mx = max(mx, cnt);
                }
            }
        }
    }
    cout <<bcnt<<" "<< mx;
    // Please write your code here.

    return 0;
}
