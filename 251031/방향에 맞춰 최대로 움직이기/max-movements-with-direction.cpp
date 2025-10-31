#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;
int dy[9] = {-8,-1,-1,0,1,1,1,0,-1};
int dx[9] = {-8,0,1,1,1,0,-1,-1,-1};

int ans = INT_MIN;

void sol(int r, int c, int idx) {

    ans = max(ans, idx);

    int h_num = num[r][c];
    int dir = move_dir[r][c];
   
    // cout << h_num <<" "<< dir <<endl;
    for(int i = 0 ; i < n ; i ++) {
        int ny = r + dy[dir]*i;
        int nx = c + dx[dir]*i;
        if(ny >= 0 && ny < n && nx >= 0 && nx < n && num[ny][nx] > h_num ) {
            sol(ny,nx,idx+1);
        }
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    r--;
    c--;
    sol(r,c,0);
    cout << ans;
    // Please write your code here.

    return 0;
}
