#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, s;
int arr[100004];

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int j = 0 ;
    int ans = INT_MAX;
    for(int i = 1 ; i <= n ; i++)
    {
        while( j + 1 <= n && sum + arr[j+1] < s)
        {
            sum+=arr[j+1];
            j++;
        }

        if(sum < s && j + 1 <= n) {
            sum += arr[j+1];
            j++;
        }
    

        

        if(sum>=s) ans = min(ans, j - i +1);

        sum -= arr[i];
    }
    if(ans == INT_MAX) cout <<-1;
    else cout << ans;

    // Please write your code here.

    return 0;
}
