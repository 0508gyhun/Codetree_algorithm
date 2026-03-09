#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, K, B;
int missing[100001];
int arr[100004];
int psum[100004];
int main() {
    cin >> N >> K >> B;

    for (int i = 0; i < B; i++) {
        cin >> missing[i];
        arr[missing[i]] = 1;
    }
    psum[0] = 0;

    for(int i = 1 ; i <= N ;i++)
    {
        psum[i] = psum[i-1] + arr[i];
    }

    int ans = INT_MAX;
    for(int i = 1 ; i+K<= N ; i++)
    {
        ans = min(ans,psum[i+K-1] - psum[i-1]);
    }
    cout << ans;

    // Please write your code here.

    return 0;
}
