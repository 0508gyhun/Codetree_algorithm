#include <iostream>
using namespace std;



int h1,m1,h2,m2;
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> h1 >> m1 >> h2 >> m2;

    int sum1 = 60*h2+m2;
    int sum2 = 60*h1+m1;

    cout << sum1-sum2;
    
    
    return 0;
}