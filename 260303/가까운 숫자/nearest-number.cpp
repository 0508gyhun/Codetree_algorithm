#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int queries[100000];
set<int> s;


int main() {
    cin >> n;
    int ans = INT_MAX;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
    }

    for(int i = 0 ; i < n ; i++)
    {
        set<int>::iterator it = s.upper_bound(queries[i]);

        if(it != s.end())
        {
            ans = min(ans, *it - queries[i]);
        }

        it--;

        ans = min(ans,queries[i] - *it);

        s.insert(queries[i]);

        cout << ans << endl;
    }



    // Please write your code here.

    return 0;
}
