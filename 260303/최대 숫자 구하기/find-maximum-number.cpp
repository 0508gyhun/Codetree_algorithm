#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int queries[100000];
set <int> s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> queries[i];
    }

for(int i = 1 ; i <= m ; i++)
{
    s.insert(i);
}

for(int i =0 ; i < n ; i++)
{
    s.erase(queries[i]);
    cout << *s.rbegin()<<endl;
}


    // Please write your code here.

    return 0;
}

