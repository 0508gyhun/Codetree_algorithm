#include <iostream>
using namespace std;
int n;
string s;
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n; 
    cin >>s;
    
    int cnt= 0 ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        for(int j = i+1 ; j < s.size() ; j++)
        {
            for(int k = j+1 ; k <s.size() ; k++)
            {
                if(s[i] == 'C' && s[j] == 'O' && s[k] == 'W') cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}