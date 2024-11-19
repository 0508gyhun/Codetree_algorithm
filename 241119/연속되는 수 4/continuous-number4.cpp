#include <iostream>
using namespace std;


int a[1004];
int main() {
    // 여기에 코드를 작성해주세요.
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
    {
        cin>> a[i];
    }

    int cnt = 0 ;
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(i == 0 || a[i-1] < a[i])cnt++;
        else
        {
            cnt = 1;
        }

        ans = max(ans,cnt);
    }

    cout << ans;
    return 0;
}