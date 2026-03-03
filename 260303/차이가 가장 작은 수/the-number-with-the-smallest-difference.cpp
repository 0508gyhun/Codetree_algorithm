#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100000];
int ans = INT_MAX;
set <int> s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    for(int i = 0 ; i <n ; i++)
    {
        int x = arr[i];

        if(s.lower_bound(x+m) != s.end())
        {
            ans = min(ans, *s.lower_bound(m+x) - x);
        }

        auto it = s.upper_bound(x-m);
        if(it != s.begin()) {
            it--;
            ans = min(ans,x-*it);
        }
    }

        if(ans == INT_MAX) ans = -1;
        cout << ans;
    

    // Please write your code here.

    return 0;
}
