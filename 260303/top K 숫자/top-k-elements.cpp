#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100000];
set <int> s;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    
    for(auto i : s){
        if(k>0)
        {
            cout <<i <<" ";
            k--;
        }
    }


    // Please write your code here.

    return 0;
}
