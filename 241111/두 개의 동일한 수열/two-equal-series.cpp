#include <iostream>
using namespace std;
#include<algorithm>

int n ; 
int arr[104];
int brr[104];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n ; 

    for(int i = 0 ; i < n ;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i = 0 ; i < n ;i++)
    {
        cin >> brr[i];
    }
    sort(brr, brr+n);

    for(int i = 0 ; i < n ;i++)
    {
        if(arr[i] != brr[i]){
            cout << "No"; 
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}