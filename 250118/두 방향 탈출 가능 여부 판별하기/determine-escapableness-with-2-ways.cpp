#include <iostream>

using namespace std;

int n, m;
int a[100][100];
int dy[2] = {1,0};
int dx[2] = {0,1};
int cnt = 1;
int visited[100][100];

bool inRange(int y, int x )
{
    if(y<0 || y>=n || x<0 || x>=m) return false;
    return true;
}


void dfs(int y, int x)
{
    
    for(int i = 0 ; i < 2 ; i++)
    {
        int ny = y+ dy[i];
        int nx = x + dx[i] ; 

        if(!inRange(ny,nx) || a[ny][nx] == 0 || visited[ny][nx] == 1) continue;

        visited[ny][nx] = 1;
        a[ny][nx] = cnt++;
        dfs(ny,nx);
    }
    
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    //뱀 0 . 가능 1
    // Write your code here!    
    a[0][0] = cnt++;
    visited[0][0] = 1;
    dfs(0,0);

    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << a[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    if(a[n-1][m-1] >1) cout << "1";
    else cout <<"0"; 

    return 0;
}
