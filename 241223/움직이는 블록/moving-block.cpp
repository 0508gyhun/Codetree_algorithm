#include <iostream>
using namespace std;
int n;
int a[10004];
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n;
    int avg = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        avg+=a[i];
    }
    avg /= n;

    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] >avg)ans+=(a[i]-avg);

    }
    cout << ans;


    return 0;
}