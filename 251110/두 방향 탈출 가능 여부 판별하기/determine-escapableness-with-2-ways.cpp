#include <iostream>

using namespace std;

int n, m;
int a[104][104];
int dy[2] = {1,0};
int dx[2] = {0,1};
int visited[104][104];

bool inRange(int y, int x) {
    if(y >= 0 && x >= 0 && y < n &&  x < m  && visited[y][x] == 0 && a[y][x] == 1) return true;
    return false;
}

void dfs(int y, int x) {
    
    for(int i = 0 ; i < 2 ; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(inRange(ny,nx)) {
            visited[ny][nx] = 1;
            dfs(ny,nx);
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
 // 1 가능 , 0 불가능 길
    visited[0][0] = 1;

    dfs(0,0);
    // Please write your code here.

    // for(int i = 0 ; i < n ; i++) {
    //     for(int j = 0 ; j < m ; j++) {
    //         cout << visited[i][j] <<" ";
    //     }
    //     cout << endl;
    // }

    cout << visited[n-1][m-1] ;

    return 0;
}
