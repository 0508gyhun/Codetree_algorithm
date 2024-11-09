#include <iostream>
using namespace std;

string targetstr;
string substr;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> targetstr;
    cin >> substr;

    int ans = -1;
    int cnt = 0;
    for(int i = 0 ; i < targetstr.size() ; i++)
    {
        for(int j = 0 ; j < substr.size() ; j++)
        {
            if(targetstr[i] == substr[j]) cnt++;
            if(cnt = substr.size()){
                ans = i-substr.size()+1;
            }
        }
    }
    
    cout << ans ;


    return 0;
}