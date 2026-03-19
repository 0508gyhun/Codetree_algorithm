#include <iostream>

using namespace std;

int n, m;
int arr[100000];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int j = 1 ;
    int ans = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        while(j+1 <= n && arr[i] + arr[j+1] <= m)
        {
            ans++;
            j++;
        }
        i++;
    }

    cout << ans;

    // Please write your code here.

    return 0;
}
