#include <iostream>
using namespace std;

int n ; 
int sol(int n)
{
    // cout << n<< endl;
    if(n < 10) return n*n;

    // cout << (n%10)*(n%10)<< endl;

    return sol(n/10) + (n%10)*(n%10);
}
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ;
    cout << sol(n);
    return 0;
}