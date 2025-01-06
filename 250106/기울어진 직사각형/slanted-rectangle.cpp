#include <iostream>
using namespace std;

int n,m;
int a[24][24];
bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int sol(int y, int x, int l , int k)
{
    int sum = 0;
    int dy[4] = {-1,-1,1,1};
    int dx[4] = {1,-1,-1,1};
    int dir[4] = {l,k,l,k};
    
    for(int d = 0 ; d < 4 ; d++)
    {
        for(int q = 0 ; q< dir[d] ; q++)
        {
            x+=dx[d];
            y+=dy[d];

            if(!InRange(y,x)) return 0;

            sum+=a[y][x];
        }
    }
    return sum;
}


int main() {
    // Please write your code here.

    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            for(int l = 1 ; l < n ; l++)
            {
                for(int k = 1 ; k < n ; k++)
                {
                    ans = max(ans,sol(i,j,l,k));
                }
            }
        }
    }

    cout << ans;
    return 0;
}