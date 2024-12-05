#include <iostream>
using namespace std;
//           왼 위 오 아래
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

int x ;
int y ;
int n; 
int a[104][104];

bool isRange(int y, int x)
{
    return y>=0 && y < n && x >=0 && x < n;
}
int main() {


    cin >> n ; 
    
    x = n-1;
    y = n-1;

    a[y][x] = n*n;

    int dir = 0;
    for(int i = n*n-1 ; i > 0 ; i--)
    {
        for(int k = 0 ; k < 4 ; k++)
        {
            int ny = y+ dy[dir];
            int nx = x+ dx[dir];
            if(isRange(ny,nx) && a[ny][nx] == 0)
            {
                y = ny;
                x = nx;
                a[y][x] = i;
                break;
            }
            else
            {
                dir = (dir + 1)%4;
            }
        }
    }
    
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}