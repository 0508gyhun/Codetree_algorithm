#include <iostream>
using namespace std;

int n,k;
int a[101];
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n >>k;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    int ans = -1;
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i == j)continue;
            int st,ed;
            if(a[i] == a[j])
            {
                if(abs(i-j) <= k)
                {
                    if( i>j)
                    {
                        st = j;
                        ed = i;
                    }
                    else
                    {
                        st = i;
                        ed = j;
                    }

                    for(int i = st ; i<= ed ; i++)
                    {
                        ans = max(ans,a[i]);
                    }
                }
            }
            
        }
    }
    cout << ans;
    
    return 0;
}