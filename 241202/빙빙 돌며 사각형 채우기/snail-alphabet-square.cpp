#include <iostream>
using namespace std;
int n,m;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int a[104][104];

bool isRange(int y, int x)
{
    if(y>=0 && y<n && x >=0 && x<m) return true;
    return false;
}
int main() {
    // 여기에 코드를 작성해주세요.
  
    cin >> n >> m;

    int y = 0;
    int x = 0 ;
    int dir = 0; 
    a[y][x] = 1;
    for(int i = 2 ; i <= n*m ; i++)
    {
        for(int j = 0 ; j < 4 ; j ++)
        {
            int ny = y+ dy[dir];
            int nx = x+ dx[dir];
            if(isRange(ny,nx) && a[ny][nx] == 0 )
            {
                y = ny;
                x = nx;
                a[y][x] = i;
                break;
            }
            else
            {
                dir = (dir+1)%4;
            }
        }
    }


     for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int val = a[i][j];
            if(val > 26) val %= 26;
            if(val == 0) val = 26;
            
            cout << (char)(val + 'A' - 1) << " ";
        }
        cout << endl;
    }
    return 0;
}