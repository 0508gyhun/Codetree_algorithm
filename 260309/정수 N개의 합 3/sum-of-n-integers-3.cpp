#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[1004][1004];
int psum[1004][1004];
int main() {
    cin >> n >> k;

    for(int i = 0 ; i <= n ; i ++)
    {
        arr[0][i] = 0;
        arr[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + arr[i][j];
        }
    }
    int ans = INT_MIN;
    for(int i = 1 ; i + k-1 <= n ; i++)
    {
        for(int j = 1 ; j + k-1 <= n ; j++)
        {
        ans = max(ans,psum[i+k-1][j+k-1] - psum[i-1][j+k-1] - psum[i+k-1][j-1] + psum[i-1][j-1]);
        }
    }

   cout << ans;


    // Please write your code here.

    return 0;
}
