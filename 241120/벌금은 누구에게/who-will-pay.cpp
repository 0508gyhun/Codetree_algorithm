#include <iostream>
using namespace std;

int n,k,m;

int a[104];
int main() {
    
    cin >> n >> m >> k;
    int ans = -1;
    for(int i = 1 ; i <= m ; i++)
    {
        int num;
        cin >> num;

        a[num]++;

        if(a[num] >= k-1)
        {
            ans = num;
        }
    }
    cout << ans;
    
    
    // 여기에 코드를 작성해주세요.
    return 0;
}