#include <iostream>

using namespace std;

int n;
int r, c;
int a[100][100];



void sol(int r, int c)
{
    int y = r;
    int x = c;

    int dy[4]= {-1,1,0,0};
    int dx[4] = {0,0,-1,1}; // 상하좌우 우선순위

    for(int i = 0 ; i < 4 ; i++)
    {
        int ny = y+ dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(a[ny][nx] > a[y][x])
        {
            cout << a[ny][nx] <<" ";
            sol(ny, nx);
            break;

        }
    }
    return ;


}


int main() {
    cin >> n >> r >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    r--;
    c--;
    cout << a[r][c]<<" ";
    sol(r,c);



    // Write your code here!

    return 0;
}
