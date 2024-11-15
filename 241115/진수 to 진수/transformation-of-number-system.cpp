#include <iostream>
using namespace std;


int a,b;
string s;


int main() {
    // 여기에 코드를 작성해주세요.

    cin >> a>> b;
    cin >> s;
    
    int num = 0 ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        num = num*a + s[i]-'0';
    }
    //cout << num << endl;
    int a[num];
    int cnt = 0 ;
    while(1)
    {
        if(num < b){
            a[cnt++] = num;
            break;
        }
        a[cnt++] =  num%b;
        num = num/b;

    }
    for(int i = cnt-1 ; i >=0 ; i--)
    {
        cout << a[i];
    }


    return 0;
}