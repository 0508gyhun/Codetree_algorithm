#include <iostream>
using namespace std;

string s;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> s;

    int cnt = 0 ;
    for(int i = 0 ; i < s.size()-1 ; i++)
    {
        if(s[i] == '(' && s[i+1] == '(')
        {
            for(int j = i+2 ; j < s.size()-1 ; j++)
            {
                if(s[j] == ')' && s[j+1]== ')') cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}