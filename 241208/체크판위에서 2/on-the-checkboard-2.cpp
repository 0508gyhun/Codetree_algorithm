#include <iostream>
using namespace std;
int r,c;
char a[20][20];
int main() {
 
    cin >> r >> c;

    for(int i = 0 ; i < r  ; i ++)
    {
        for(int j = 0 ; j < c ; j ++)
        {
            cin >> a[i][j];
        }
    }
    int cnt = 0 ; 
    for(int i = 1 ; i < r ; i++)
    {
        for(int j = 1;  j < c ; j++)
        {
            for(int p = i+1 ; p < r-1 ; p++)
            {
                for(int k = j+1 ; k < c-1 ; k++)
                {
                    if(a[0][0] != a[i][j] && a[i][j] != a[p][k] && a[p][k] != a[r-1][c-1]) cnt++;
                }
            }
        }
    }
    
    cout << cnt;
    // 여기에 코드를 작성해주세요.
    return 0;
}