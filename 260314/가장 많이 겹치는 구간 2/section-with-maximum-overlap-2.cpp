#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
long long x1[100004], x2[100004];
long long arr[100004];
//1000 000 000
int mx = INT_MIN;
long long ans = INT_MIN;
long sum;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        arr[x1[i]]++;
        arr[x2[i]]--;

        mx = max(mx,x2[i]);
    }

    for(int i = 1 ; i <= mx ; i++)
    {
        sum+=arr[i];
        ans = max(ans,sum);
    }
    cout << ans;



    // Please write your code here.

    return 0;
}
