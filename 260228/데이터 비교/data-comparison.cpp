#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int n, m;
int arr1[100000];
int arr2[100000];

set<int> s;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        if(s.find(arr2[i]) != s.end())
        {
            cout << "1"<<" ";
        }
        else
        {
            cout << "0"<<" ";
        }
    }

    // Please write your code here.

    return 0;
}
