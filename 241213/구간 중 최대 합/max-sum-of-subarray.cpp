#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[104];

int main() {
    // 여기에 코드를 작성해주세요.
    int mn = INT_MIN;
    cin >> n>>k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0 ; i <= n-k ; i++)
    {
        int sum = 0 ;
        for(int j = i ; j < i+k ; j++)
        {
            sum += arr[j];
        }
        mn = max(mn,sum);
    }
    cout << mn; 
    return 0;
}