#include <iostream>
using namespace std;

int n ; 

int sol(int n, int cnt)
{
    //cout << n <<" ";
    if(n == 1) return cnt ; 
    if(n % 2 == 0)
    {
        return sol(n/2,cnt+1);
    }
    else
    {
        return sol(n/3,cnt+1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n ; 
    cout << sol(n,0);
    return 0;
}