#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[104];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    int mn = INT_MAX;
    for(int i = 1 ; i <= 10000 ; i ++)
    {
        int sum = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(a[j] < i ) sum+=(i-a[j]);
            if(a[j] >i+k) sum+=(a[j]-i-k);

        }
        mn = min(mn,sum);
    }
    cout << mn;
    return 0;
}