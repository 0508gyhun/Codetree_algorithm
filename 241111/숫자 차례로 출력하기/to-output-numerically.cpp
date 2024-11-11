#include <iostream>
using namespace std;


int n ; 

void sol2(int n)
{
    if(n == 0) return;
    cout << n << " ";
    sol2(n-1);
}

void sol1(int n)
{
    if( n == 0) return;
    sol1(n-1);
    cout << n <<" ";
}
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ;
    sol1(n);
    cout << endl;
    sol2(n);
    return 0;
}