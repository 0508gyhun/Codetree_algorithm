#include <iostream>
using namespace std;
int n;
int a[104];
int main() {
    // 여기에 코드를 작성해주세요.


    cin >> n;
    for(int i = 0 ; i < n ; i++)cin >> a[i];

    for(int i = 1 ; i < n ; i++)
    {
        int j = i-1;
        int key = a[i];
        while(j>=0 && a[j] > key)
        {
            a[j+1] = a[j];

            j--;
        }
        a[j+1] = key;
    }

    for(int i = 0 ; i < n ; i++)cout << a[i]<<" ";
    
    return 0;
}