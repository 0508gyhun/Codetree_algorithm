#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int il,si,boon;

    cin >> il>> si>> boon;

    int sum1 = 11*1440 + 11*60 + 11;
    int sum2 = il*1440 + si*60 + boon;

    int res = sum2-sum1;
    if(res>=0) cout << res;
    else cout << -1;

    return 0;
}

