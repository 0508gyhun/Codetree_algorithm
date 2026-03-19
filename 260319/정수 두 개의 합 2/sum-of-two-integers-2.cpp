#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100004];
vector<int> v;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    int left = 0;
    int right = n -1;
    int ans = 0;
    while(left < right)
    {
        if(v[left] + v[right] <= m)
        {
            ans+=(right - left);
            left++;
        }
        else {
            right--;
        }
    }
    
    cout << ans;

    // Please write your code here.

    return 0;
}
