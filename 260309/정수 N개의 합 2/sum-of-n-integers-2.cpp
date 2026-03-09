#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100004];
int psum[100004];

int main() {
    cin >> n >> k;

    psum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum[i] = psum[i-1]+ arr[i];
    }
    int ans = INT_MIN;
    for(int i = n ; i - k >= 0 ;i--)
    {
        ans = max(ans,psum[i]-psum[i-k]);
    }
    cout << ans;

    // Please write your code here.

    return 0;
}
