#include <iostream>
using namespace std;

int n;

int sol(int n){
    //cout << n << " ";

    if(n == 1) return 1;
    else if( n ==2) return 1;

    return sol(n-1) + sol(n-2);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    cout << sol(n);
    return 0;
}