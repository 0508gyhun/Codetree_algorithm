#include <iostream>
using namespace std;

int n;

void sol(int n)
{
    if(n == 0) return;

    sol(n-1);

    cout << "HelloWorld"<< endl;

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n ;
    sol(n);
    return 0;
}