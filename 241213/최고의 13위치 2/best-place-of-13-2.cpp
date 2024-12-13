#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int a[24][24];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n ; 

    for(int i = 0 ;i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }
    int mx = INT_MIN;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n-2 ; j++)
        {
            for(int p = 0 ; p < n ; p++)
            {
                for(int k = 0 ; k < n-2 ; k++)
                {
                    if( i == p && abs(j-k) <=2) continue;
                    int tmp = a[i][j]+a[i][j+1]+a[i][j+2];
                    int tmp2 = a[p][k] + a[p][k+1] + a[p][k+2];
                    int sum = tmp + tmp2;
                    mx= max(mx,sum);

                }
            }
        }
    }
    cout << mx;
    return 0;
}