#include <iostream>
using namespace std;
#include<algorithm>
int n;
int arr[100];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ; 
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> (arr[i]);

    }
    sort(arr,arr+n);
    for(int i ;i < n ; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;

    sort(arr,arr+n , greater<>());
    for(int i ;i <n ; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}