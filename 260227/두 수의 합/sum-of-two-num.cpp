#include <iostream>
//100 000 00 000
#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[100000];
unordered_map <int,int> um;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        um[arr[i]]++;
    }
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        if(um.find(k-arr[i]) != um.end())
        {
            cnt++;
        }
    }

    cout << cnt/2;

    // Please write your code here.

    return 0;
}
