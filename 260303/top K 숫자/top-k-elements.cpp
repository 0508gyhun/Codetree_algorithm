#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100000];
vector<int> v;
set <int> s;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    for(int i : s)
    {
        v.push_back(i);
    }

    sort(v.begin(), v.end(),greater<int>());
    
    for(auto i : v){
        if(k>0)
        {
            cout <<i <<" ";
            k--;
        }
    }


    // Please write your code here.

    return 0;
}
