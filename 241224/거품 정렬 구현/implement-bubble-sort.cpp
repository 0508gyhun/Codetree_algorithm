#include <iostream>
using namespace std;

int n ; 
int a[104];
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int flag = true;
    do{
        flag = true;
        for(int i = 0 ; i < n-1 ; i++)
        {
            if(a[i] > a[i+1])
            {
                swap(a[i],a[i+1]);
                flag = false;
            }
        }
    }while(flag == false);
    

    for(int i  =0 ; i < n ; i++) cout << a[i]<<" ";
    return 0;
}
