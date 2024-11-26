#include <iostream>
using namespace std;
int n,m ; 
int a[104][104];

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

bool isRange(int y, int x)
{
    if(y>=0 && y<n && x>=0 && x < m) return true;
    else return false;
}


int main() {

    cin >> n >> m ;
    int num = 1;
    int x=0;
    int y = 0;
    a[y][x] = 1;
    int dir = 0;

    for(int i = 2 ; i <= n*m ; i++)
    {
        int ny = y+dy[dir];
        int nx = x+dx[dir];
        //cout << ny <<" "<< nx << endl;
        if(!isRange(ny,nx) || a[ny][nx] != 0)
        {
            dir = (dir+1)%4;
        }
        y = y+dy[dir];
        x = x+dx[dir];
        a[y][x] = i;
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout << a[i][j]<<" ";
        }
        cout << endl;
    }

    // 여기에 코드를 작성해주세요.
    return 0;
}