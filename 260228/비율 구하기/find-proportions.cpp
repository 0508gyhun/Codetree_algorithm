#include <iostream>
#include <string>
#include <bits/stdc++.h>


using namespace std;
map <string,int> mp;
int n;
string words[10000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        mp[words[i]]++;
    }

for(auto i : mp)
{
    // cout << fixed << setpricision(4);
    cout <<i.first <<" ";
    printf("%.4f\n",double(i.second)/n *100);
}

    // Please write your code here.

    return 0;
}
