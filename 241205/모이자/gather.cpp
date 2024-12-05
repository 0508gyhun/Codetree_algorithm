#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int n; 
int a[103];

int main() {


    // 여기에 코드를 작성해주세요.

    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    int mn = INT_MAX;
    for(int i = 1 ; i <= n ; i++)
    {
        int select = i;
        int sum = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            sum += (abs(select-j) * a[j]);
        }
        mn = min(mn,sum);
    }
    cout << mn ;
    return 0;
}