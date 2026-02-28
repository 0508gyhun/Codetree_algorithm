#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int n;
string words[100000];
map <string, int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        mp[words[i]]++;
    }
    for(auto i: mp)
    {
        cout << i.first <<" " <<i.second<<"\n";
    }

    // Please write your code here.

    return 0;
}
