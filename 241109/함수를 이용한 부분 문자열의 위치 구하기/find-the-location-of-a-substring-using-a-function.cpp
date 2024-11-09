#include <iostream>
using namespace std;

string targetstr;
string substr;

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> targetstr;
    cin >> substr;

    int ans = -1;

    for(int i = 0 ; i < targetstr.size()-1 ; i++)
    {
        for(int j = 0 ; j < substr.size() ; j++)
        {
            if(targetstr[i] == substr[j] && targetstr[i+1] == substr[j+1] ) ans = i;
        }
    }

    cout << ans;


    return 0;
}