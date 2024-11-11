#include <iostream>
using namespace std;



void sol(int n)
{
    if(n == 0) return ;

    cout << n;
    sol(n-1);
    cout << n;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ; 
    sol(n);
    return 0;
}