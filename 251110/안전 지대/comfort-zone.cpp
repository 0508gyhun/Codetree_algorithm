#include <iostream>
#include <bits/stdc++.h>



using namespace std;

int N, M;
int grid[50][50];
int visited[50][50];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};


int mxgrid = INT_MIN;
void visited_clear() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }
}

bool inRange(int y, int x) {
    if(y >= 0 && x >= 0 && y < N && x < M ) return true;
    return false;
}
void dfs(int y , int x, int k) {

    for(int i = 0 ; i < 4 ;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(visited[ny][nx] == 0 && inRange(ny,nx) && grid[ny][nx] > k ) {
            visited[ny][nx] = 1;
            dfs(ny,nx,k);
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            mxgrid = max(mxgrid, grid[i][j]);
        }
    }
    int mxk = 0;
    int mxc = 1;
    for(int k = 1 ; k <= mxgrid ; k++)
    {
        visited_clear();
        int cnt = 0;
        for(int i = 0 ; i < N ; i ++) {
            for(int j = 0 ; j < M ; j++) {
                if(visited[i][j] == 0 && grid[i][j] > k) {
                    visited[i][j]= 1;
                    cnt++;
                    dfs(i,j,k);
                    
                }    
            }
        }
        // cout << cnt <<" "<<k<< endl;
        if(mxc < cnt)
        {
            mxc = cnt;
            mxk = k;
            // cout << mxc <<"2"<<mxk<< endl;

        }
    }
    cout << mxc <<" "<< mxk << endl;

    // Please write your code here.

    return 0;
}
