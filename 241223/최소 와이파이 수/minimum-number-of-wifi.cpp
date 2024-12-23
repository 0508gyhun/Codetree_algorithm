#include <iostream>
using namespace std;

int n ,m;
int a[104];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] ; 
    }
    int cnt = 0 ;
    int wifi= 0 ;
    for(int i = 0 ; i< n ; i++)
    {
        if(cnt == m)
        {
            wifi++;
            i = i*2;
            cnt = 0;
        }

        if(a[i] == 1)cnt++;
        
    }
    cout << wifi;

    return 0;


}