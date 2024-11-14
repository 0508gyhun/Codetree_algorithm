#include <iostream>
using namespace std;


string s;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >>s;

    int num = 0 ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        int temp = s[i]-'0';
        num = num*2 + temp;
    }
    cout << num;
    return 0;
}