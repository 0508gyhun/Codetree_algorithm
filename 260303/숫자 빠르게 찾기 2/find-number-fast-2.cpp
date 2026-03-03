#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100000];
int queries[100000];
set<int> s;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];

        if(s.lower_bound(queries[i]) != s.end())
        {
            cout << *s.lower_bound(queries[i]) << endl;
        }
        else
        {
            cout <<"-1"<< endl;
        }
    }

    // Please write your code here.

    return 0;
}

