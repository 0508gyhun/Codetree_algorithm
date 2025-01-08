#include <iostream>
using namespace std;
int r,c;
int a[204][204];
int temp[204][204];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n;

void except_zero()
{

    for(int i = n-1 ; i >=0 ; i--)
    {
        int idx=n-1;
        for(int j = n-1 ; j >= 0 ; j --)
        {
            if(a[j][i] != 0)
            {
                temp[idx][i] = a[j][i];
                idx--;
            }

        }
    }
}


void bomb(int r, int c)
{
    int num = a[r][c];

    // int y = r;
    // int x = c;

    int k = a[r][c];
    a[r][c] = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        int y = r;
        int x = c;
        for(int j = 1 ; j < k ; j++)
        {
            int ny = y+ dy[i];
            int nx = x+ dx[i];
            if(ny<0 || nx <0 || ny>=n || nx >=n)continue;
           // cout << "ny nx" <<ny<<" "<<nx<< endl;
            a[ny][nx] = 0;
            y = ny;
            x = nx;
        }
        
    }

}

int main() {
    // Please write your code here.
    
    cin >> n ; 
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }

    cin >> r >> c;
    r--;
    c--;


    //수 만큼 터트리기 0으로 만들기
    bomb(r,c);


    // for(int i = 0 ; i < n ; i++)
    // {
    //     for(int j = 0 ; j < n ; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //0들 내리기
    except_zero();
    // cout<< endl;
      for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}