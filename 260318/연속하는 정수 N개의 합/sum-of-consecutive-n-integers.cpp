#include <iostream>

using namespace std;

int n, m;
int arr[100004];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.

    int j = 0 ; 
    int ans = 0; 
    int sum = 0;
    for(int i = 1 ; i <=n ; i++)
    {
        while(j+1 <= n && sum + arr[j+1] < m)
        {
            sum+=arr[j+1];
            j++;
        }
        if(j+1 <= n && ((sum + arr[j+1]) == m)) ans++;

        sum-=arr[i];
    }
    cout << ans;
    return 0;
}
