#include <iostream>
using namespace std;


int a[1000] ; 
int n, jinsu ; 
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> jinsu;
    
    int cnt = 0 ;
    while(1)
    {
        if(n< jinsu)
        {
            a[cnt++] =n;
            break;
        }
        a[cnt++] = n%jinsu;

        n = n/jinsu;
        
    }


    for(int i =cnt-1 ; i >= 0 ; i --)
    {
        cout << a[i];
    }
    
    return 0;


}