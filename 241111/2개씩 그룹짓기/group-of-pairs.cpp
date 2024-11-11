#include <iostream>
#include<algorithm>
using namespace std;
int n;
int arr[1004];
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n ; 
    for(int i = 0 ; i < 2*n ; i++)
    {
        cin >> arr[i];
    }

    sort(arr,arr+(2*n));

    int l = 0 ;
    int r = 2*n-1;

    int mx = 0 ;
    while(l<=r)
    {
        mx = max(mx,arr[l]+ arr[r]);
        l++;
        r--;
    }
    cout << mx;
    return 0;
}

//1 2 3 5 7 8