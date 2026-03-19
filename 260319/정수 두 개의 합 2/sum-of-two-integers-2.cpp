#include <iostream>

using namespace std;

int n, m;
int arr[100004];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // int j = 1 ;
    int ans = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        int j = i;
        while(j+1 <= n && arr[i] + arr[j+1] <= m)
        {
            // cout <<i<<" "<<arr[i] <<" "<<j+1<<" "<<arr[j+1]<<endl;
            ans++;
            j++;
        }

        // j = i+1;
        
    }

    cout << ans;

    // Please write your code here.

    return 0;
}
