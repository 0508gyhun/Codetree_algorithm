#include <iostream>
using namespace std;

int a[204][204];
int n ; 
int x1,y1,x2,y2;
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ; 
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> x1>>y1>>x2>>y2;
        if(i%2 == 1)//red
        {
            for(int j = y1 ; j < y2 ;j++)
            {
                for(int p = x1 ; p < x2 ; p++)
                {
                    a[j+100][p+100] = 2;
                }
            }
        }
        else//blue
        {
            for(int j = y1 ; j < y2 ;j++)
            {
                for(int p = x1 ; p < x2 ; p++)
                {
                    a[j+100][p+100] = 3;
                }
            }
        }
    }

    int cnt = 0 ;
    for(int i = 0 ; i < 204 ; i++)
    {
        for(int j = 0 ; j < 204 ; j++)
        {
            if(a[i][j] == 3) cnt++;
        }
    }
    cout << cnt ; 
    return 0;
}