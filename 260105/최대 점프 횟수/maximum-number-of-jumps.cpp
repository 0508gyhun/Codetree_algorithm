#include <iostream>

using namespace std;

int n;
int arr[1000];
int dp[1004];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            
            if(arr[j] + j >= i) {
                dp[i] = max(dp[i], dp[j] +1);
            }
        }
    }
    int ans = 0 ;
    for (int i = 0; i < n; i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans;
    // Please write your code here.

    return 0;
}
