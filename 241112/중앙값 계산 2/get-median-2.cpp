#include <iostream>
#include <algorithm>
using namespace std;


int n ; 
int arr[100];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> arr[i];
        if(i % 2 != 0)
        {
            sort(arr,arr+i);
            cout << arr[i/2+1]<<" ";
        }
    }
    return 0;
}