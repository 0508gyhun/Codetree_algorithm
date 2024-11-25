#include <iostream>
using namespace std;
int n;
int a[104][104];
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ; 
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0 ;
    for(int y = 0 ; y < n ; y++)
    {
        for(int x = 0 ; x < n ; x ++)
        {
            int cnt = 0 ;
            for(int i = 0 ; i < 4 ; i++ )
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx <0 || nx >=n) continue;
                if(a[ny][nx] == 1) cnt++;
            }
            if(cnt>=3) ans++;
        }
    }
    cout << ans;

    return 0;
}