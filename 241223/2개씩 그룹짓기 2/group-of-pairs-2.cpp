#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n; 
int a[100004];
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n; 
    for(int i = 0 ; i < 2*n ; i++)
    {
        cin >> a[i];
    }

    sort(a,a+2*n);
    int mx = INT_MIN;
    for(int i = 1 ; i < 2*n ; i++)
    {
        mx = max(mx,a[i]-a[i-1]);
    }
    cout << mx;
    
    return 0;
}