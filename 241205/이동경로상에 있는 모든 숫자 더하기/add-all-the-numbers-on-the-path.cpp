#include <iostream>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,m;
string s;
int a[104][104];
bool isRange(int y , int x)
{
    return y>=0 && y < n && x >=0 && x < n;
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >>m; 

    cin >> s;

    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            cin >> a[i][j];
        }
    }

    int x = n/2;
    int y = n/2;
    int dir = 0 ;
    int ans = a[y][x];

    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == 'R')
        {
            dir = (dir+1)%4;
        }
        else if( s[i] == 'L')
        {
            dir = (dir-1);
            if(dir < 0) dir = dir+4;
        }
        else if( s[i] == 'F')
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(isRange(ny,nx) && a[ny][nx] != 0)
            {
                //cout << a[ny][nx] << " ";
                y = ny;
                x = nx;
                ans += a[y][x];
                continue;
            }    
        }
    }

    cout << ans;
    return 0;
}