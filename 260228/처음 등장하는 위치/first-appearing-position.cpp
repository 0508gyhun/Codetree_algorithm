#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100000];
map <int,int> mp;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp.insert({arr[i],i+1});
    }
    for(auto i : mp)
    {
        cout <<i.first <<" "<<i.second<<endl;
    }

    // Please write your code here.

    return 0;
}
