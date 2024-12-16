#include <iostream>
using namespace std;
int n;
int a[11];
int b[11];
int c[11];
bool suc;
int main() {
    cin >>n;

    for(int i = 0 ; i < n ; i++ )
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    int cnt = 0; 

    for(int i = 1 ; i < 10 ; i++)
    {
        for(int j = 1 ; j < 10 ; j++)
        {
            for(int k = 1 ; k < 10 ; k++)
            {
                if(i == j || j == k || k == i)
					continue;
                
                suc = true;
                for(int p = 0 ; p< n ; p++)
                {
                    int cnt1 = 0 ;
                    int cnt2 = 0 ;
                    int x = a[p]/100;
                    int y = a[p]/10%10;
                    int z = a[p] % 10;

                    if(i ==x ) cnt1++;
                    if(j == y) cnt1++;
                    if(k == z) cnt1++;

                    if(x == j || x == k) cnt2++;
                    if(y== i || y == k) cnt2++;
                    if(z == i || z == j) cnt2++;

                   
                    if(cnt1 != b[p] || cnt2 != c[p])
                    {
                        suc = false;
                        break;
                    }
                }
                if(suc)
                {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    // 여기에 코드를 작성해주세요.
    return 0;
}