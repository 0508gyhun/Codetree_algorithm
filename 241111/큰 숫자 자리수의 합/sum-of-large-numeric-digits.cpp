#include <iostream>
using namespace std;


int sol(int n)
{
    if(n<10) return n ;
    return (n%10)+ sol(n/10);
}


int main() {
    // 여기에 코드를 작성해주세요.
    int n1,n2,n3 = 0 ;
    cin >> n1 >> n2 >> n3 ;
    int total = n1* n2 * n3;

    cout << sol(total);
    return 0;
}