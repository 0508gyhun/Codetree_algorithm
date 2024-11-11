#include <iostream>
using namespace std;


int a[100];

int mx = 0;
int sol(int n)
{


    mx = max(mx,a[n]);
    if(n==0) return mx;

    return sol(n -1);
}

int main() {
    // 여기에 코드를 작성해주세요.



    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    cout << sol(n);
    return 0;
}