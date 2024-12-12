#include <iostream>
using namespace std;
int n,m;

int dy[8] = {0,-1,-1,-1,0,1,1,1};
int dx[8] = {1,1,0,-1,-1,-1,0,1};

bool InRange(int y, int x)
{
    return y>=0 && y<n && x>=0 && x<m;
}

char arr[54][54];

int main() {
    // 여기에 코드를 작성해주세요.


    cin >> n >> m;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }


    int ans = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            if(arr[i][j] != 'L') continue;

           
            for(int k = 0 ; k < 8 ; k++)
            {
                int cury = i;
                int curx = j;
                int cnt = 0 ;   
                while(1){
                    int ny = cury + dy[k];
                    int nx = curx + dx[k];
                    if(InRange(ny,nx) == false) break;
                    if(arr[ny][nx] != 'E') break;
                    curx = nx;
                    cury = ny;
                    cnt++;
                    if(cnt == 2){
                        ans++;
                        break;
                    }
                }
                
            }

        }
    }
    cout << ans;


    return 0;
}