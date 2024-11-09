#include <iostream>
using namespace std;

string targetstr;
string sbstr;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> targetstr;
    cin >> sbstr;

    int ans =-1;
    for(int i = 0 ; i < targetstr.size() ; i++)
    {
        if( targetstr.substr(i,i+sbstr.size()) == sbstr) ans = i;
    }


    cout << ans ;


    return 0;
}