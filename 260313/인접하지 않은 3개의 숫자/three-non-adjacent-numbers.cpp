#include <iostream>

using namespace std;

int n;
int arr[100000];
int l[100004];
int r[100004];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    
    l[1] = arr[1];
    for(int i = 2 ; i <= n ; i++)
    {
        l[i] = max(l[i-1], arr[i]);
    }

    // for(int i = 1 ; i <= n ; i++)
    // {
    //     cout <<l[i]<<" ";
    // }

    r[n] = arr[n];
    for(int i = n-1 ; i >= 1 ; i--)
    {
        r[i] = max(r[i+1], arr[i]);
    }   
    // cout << endl;
    int ans = -1;
    for(int i = 3 ; i+2 <= n ; i++)
    {
        ans = max(ans,l[i-2] +arr[i] +r[i+2]);
    }
    cout << ans;
    return 0;

}
