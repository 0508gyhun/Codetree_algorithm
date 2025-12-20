#include <iostream>

using namespace std;

int n;
int grid[500][500];
int dp[504][504];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
bool inRange(int y, int x)
{
    return (y>=0 && x>=0 && n>y && n > x);
}

int findM(int y, int x) 
{
    if(dp[y][x] != 0) return dp[y][x];
    int mx = 1;

    for(int i = 0 ; i < 4 ; i++) 
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(inRange(ny,nx))
        {
            if(grid[ny][nx] > grid[y][x])
            {
                mx = max( mx, findM(ny,nx)+ 1);
            }
        }
    }
    dp[y][x] = mx;
    return dp[y][x];
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++) {
            ans = max(ans,findM(i,j));
        }
    }
    cout << ans;
    // Please write your code here.

    return 0;
}
