#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100000];
set <int> s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1 ; i <= m ; i++)
    {   
        s.insert(i); // 빈자리 표시
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        set<int>::iterator it = s.upper_bound(a[i]);

        if(it != s.begin())
        {
            it--;
            ans++;
            s.erase(a[i]);
        }
        else
        {
            break;
        }
    }

    cout << ans;

    // Please write your code here.

    return 0;
}
// 1 2 3 4