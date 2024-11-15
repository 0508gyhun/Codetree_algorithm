#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[100];
int n,k;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >>k;


    for(int i = 0 ; i < k ; i++)
    {
        int from,to;
        cin >> from >> to;
        for(int j = from ; j <= to ; j++)
        {
            a[j]++;
        }
    }
    int mx = 0 ; 
    for(int i = 0 ; i < n; i ++)
    {
        mx = max(mx,a[i]);
    }

    cout << mx;
    return 0;
}