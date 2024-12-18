#include <iostream>
using namespace std;
int n;
int a[11][2];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            for(int k = j+1 ; k < n ; k++)
            {
                int cnt[104] = {0,};
                bool isgood = true;
                for(int p = 0 ; p < n ; p++)
                {
                    if(p == i || p == j || p == k) continue;
                    
                    for(int q = a[p][0] ; q <= a[p][1] ; q++)
                    {
                        //cout <<i<<" "<<j<<" "<<k<<endl;
                        cnt[q]++;
                        if(cnt[q] == 2)
                        {
                            isgood = false;
                        }

                    }
                    


                }
                if(isgood == true) ans++;

            }
        }
    }
    cout << ans;
    return 0;
}