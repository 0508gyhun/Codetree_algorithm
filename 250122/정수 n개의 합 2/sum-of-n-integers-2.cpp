#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100000];
int mx = INT_MIN;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0 ; i < n-k ; i++)
    {
        int sum = 0;
        for(int j = i ; j < i+k ; j++)
        {
            sum+=a[j];
        }
        mx = max(mx,sum);
    }
    cout << mx;
    // Write your code here!

    return 0;
}
