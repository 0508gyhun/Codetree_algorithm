#include <iostream>
using namespace std;
int a[2004][2004];

int main() {
    // 여기에 코드를 작성해주세요.

    
    for(int i = 0 ; i < 3 ; i++)
    {
        int x1,y1,x2,y2;
        cin >> x1>>y1>>x2>>y2;

        for(int j = x1 ; j <x2 ; j++)
        {
            for(int p = y1 ; p< y2 ; p++)
            {
                a[j+1000][p+1000] = 1;
                if(i==2 && a[j+1000][p+1000] == 1) a[j+1000][p+1000] = 0;
                
                
            }
        }
    }
    int cnt = 0 ; 
    for(int i = 0 ; i < 2004 ; i++)
    {
        for(int j = 0 ; j < 2004 ; j++)
        {
            if(a[i][j] == 1) cnt++;
        }
    }

    cout << cnt ;



    return 0;
}