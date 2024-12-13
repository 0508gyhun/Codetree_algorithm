#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int s,n;
int a[104];

int main() {



    // 여기에 코드를 작성해주세요.

    cin >> s >> n ;
    int total = 0;

    for(int i = 0 ; i < s ;i++)
    {
        cin >> a[i];
        total+=a[i];
    }
    int mn = INT_MAX;

    for(int i = 0 ; i < s ; i++)
    {
        for(int j = i+1 ; j < s ; j++)
        {
            int dif = total - (a[i] +a[j]);
            mn = min(mn,abs(n-dif));
        }
    }
    cout << mn;

    return 0;
}