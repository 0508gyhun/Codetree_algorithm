#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string str;
unordered_map <char, int> mp;
int main() {
    cin >> str;
    for(char c : str)
    {
        mp[c]++;
    }
    // Please write your code here.
    string ans = "None";
    for(auto i : str)
    {
        if(mp[i] == 1)
        {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}
