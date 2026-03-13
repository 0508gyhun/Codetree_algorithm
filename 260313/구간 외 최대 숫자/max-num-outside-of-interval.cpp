#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, q;
int arr[100004];
int a[100004], b[100004];
int l[100004];
int r[100004];
int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    l[1] = arr[1];
    r[n] = arr[n];

    for(int i = 2 ; i <= n ;i++)
    {
        l[i] = max(l[i-1],arr[i]);
    }

    for(int i = n-1 ; i >= 1 ;i--)
    {
        r[i] = max(r[i+1],arr[i]);
    }
    
    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i];
        int mx = INT_MIN;

        mx = max(l[a[i]-1], r[b[i] +1]);
        cout << mx << endl; 
        

    }

    // Please write your code here.

    return 0;
}
