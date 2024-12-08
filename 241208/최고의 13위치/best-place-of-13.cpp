#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int n ;
int a[24][24];
int main() {
    
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }
    int sum = 0 ;
    int mx = INT_MIN;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n-2 ; j++)
        {
            sum = a[i][j] + a[i][j+1] + a[i][j+2];
            mx = max(mx,sum);
        }
    }
    cout << mx ;

    // 여기에 코드를 작성해주세요.
    return 0;
}