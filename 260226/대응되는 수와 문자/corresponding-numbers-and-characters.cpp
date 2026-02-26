#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int n, m;
string words[100004];
string queries[100004];
map <string,string> mp1;
map <string, string> mp2;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
        mp1[words[i]] = to_string(i);
        mp2[to_string(i)] = words[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
        if(mp1.find(queries[i]) != mp1.end() )
        {
            cout<<mp1[queries[i]]<<endl;
        }
        else
        {
            cout << mp2[queries[i]] << endl;
        }
    }

    // Please write your code here.

    return 0;
}
