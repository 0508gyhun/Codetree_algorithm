#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

unordered_map <int,int> um;

int n, m;
int arr[MAX_N];
int nums[MAX_N];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        um[arr[i]]++;
    }

    for (int i = 0; i < m; i++) {
        cin >> nums[i];
        cout << um[nums[i]]<<" ";
    }

    // Please write your code here.

    return 0;
}
