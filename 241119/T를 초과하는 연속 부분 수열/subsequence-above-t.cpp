#include <iostream>
using namespace std;

int a[1004];
int n,t;
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >>t; 


    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    int cnt = 0 ;
    int ans = 0 ;

    for(int i = 0 ; i < n ; i ++)
    {
        if(a[i]>t)
        {
            if(i ==0  || a[i-1]>t ) cnt++;
            else cnt = 1;
        }
        else
        {
            cnt = 0 ;
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}