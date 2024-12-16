#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int mx = INT_MIN;
int n,k;
int BUKET = 101;
int arr[101];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++)
    {
        int cnt,pos;
        cin >> cnt >> pos;
        arr[pos] += cnt;
    }
    for(int i = 0 ; i <= 100 ; i++)
    {
        int sum = 0 ; 
        for(int j = i-k ; j<= i+k ; j++)
        {
            if(j < 0 || j > BUKET-1) continue;
            sum += arr[j];
        }
        mx = max(mx,sum);

    }
    cout << mx;


    

    return 0;
}