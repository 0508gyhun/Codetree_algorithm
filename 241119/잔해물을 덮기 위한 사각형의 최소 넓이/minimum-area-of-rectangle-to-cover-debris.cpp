#include <iostream>
using namespace std;


int a[2004][2004];
int main() {
    // 여기에 코드를 작성해주세요.
    int cnt1 = 0 ;
    for(int i = 0 ; i < 2 ; i++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2>> y2;

        for(int j = y1 ; j < y2 ;j++)
        {
            for(int p = x1 ; p < x2 ; p++)
            {
               if(i == 1)
               {
                    if(a[j+1000][p+1000]==1)
                    {
                        a[j+1000][p+1000] = 0 ;
                        cnt1--;
                    }
                    
               }
               else
               {
                   a[j+1000][p+1000] = 1;
                   cnt1++;
               }
            }
        }
    }
   // cout << cnt1;
    int minx = 2004;
    int miny=2004;
    int maxx=0;
    int maxy=0;
    bool exist = false;
    for(int i = 0 ; i < 2004 ; i++)
    {
        for(int j = 0 ; j < 2004 ; j++)
        {
            if(a[i][j] == 1)
            {
                exist = true;
                minx = min(minx,j);
                miny = min(miny,i);
                maxx = max(maxx,j);
                maxy = max(maxy,i);
            } 
        }
    }
    int ans=0;
    if(exist)
    {
        ans = (maxx-minx +1) *(maxy-miny+1); 
    }
    else{
        ans = 0 ;
    }

    cout << ans;
    return 0;
}