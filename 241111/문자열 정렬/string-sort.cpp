#include <iostream>
using namespace std;
#include<algorithm>

string s;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;
    sort(s.begin(), s.end());
    cout <<s;
    return 0;
}