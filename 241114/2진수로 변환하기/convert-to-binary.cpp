#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n ,ret; 

    int cnt = 0 ;
    cin >> n ;  
    int ans[100000];
    if(n == 0)
    {
        cout <<"0";
        return 0;
    }
    while(n>=1)
    {
    //        cout << n << " ";
        
        ret = n%2;
        ans[cnt++] = ret;
        n = n/2;
        
    }
    //cout << endl;
    for(int i = cnt-1 ; i >= 0 ; i--)
    {
        cout << ans[i];
    }
    return 0;
}