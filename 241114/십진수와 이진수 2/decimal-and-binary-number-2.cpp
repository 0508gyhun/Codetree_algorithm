#include <iostream>
using namespace std;
string s;


int main() {
    // 여기에 코드를 작성해주세요.

    cin >> s;
    int num = 0 ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        num = num*2 + s[i]-'0';
    }
    num = num*17;

    int ans[num] ; 
    int cnt = 0;
    while(1)
    {
        if(num>2)
        {
            ans[cnt++] = num;
            break;
        }
        ans[cnt++] = n%2;
        n = n/2;
    }

    for(int i = cnt-1 ; i >= 0 ; i--)
    {
        cout << ans[i];
    }
    return 0;
}