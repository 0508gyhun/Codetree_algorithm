#include <iostream>
using namespace std;

int n;
int a[204][204];

int main() {
    // 여기에 코드를 작성해주세요.
    int cnt = 0 ;
    cin >> n ; 
    for(int i = 0 ; i < n; i ++)
    {
        int x1,y1,x2,y2;

        cin >> x1>>y1;
        
        x2 = x1+8;
        y2 = y1+8;   
        

        for(int j = y1 ; j <y2 ; j++)
        {
            for(int p = x1 ; p< x2 ; p++)
            {
                if(a[j][p] == 1) continue;
                a[j][p] = 1;
                cnt++;
            }
        }
    }
    
    // int cnt = 0 ;
    // for(int i = 0 ; i < 204 ; i++)
    // {
    //     for(int j = 0 ; j < 204 ; j++)
    //     {
    //         if(a[i][j] ==1) cnt++;
    //     }
    // }

    cout << cnt;
    
    return 0;
}