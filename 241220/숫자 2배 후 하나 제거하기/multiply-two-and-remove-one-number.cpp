#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int n ;
int a[104];

int main() {
    cin >>n ; 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    int mn = INT_MAX;
    for(int i = 0 ; i < n ; i ++)
    {
        a[i] = a[i]*2;
        for(int j = 0 ; j < n ; j++)
        {
            int remain[104] = {0,};
            int cnt = 0 ;
            int sum = 0;

            for(int k = 0 ; k < n ; k ++)
            {
                if(j == k)continue;
                remain[cnt++] = a[k];
            }
            for(int k = 0 ; k < n-2 ; k ++)
            {
                 sum += abs(remain[k+1] - remain[k]);
            }

           mn = min(mn,sum);

        }
        a[i]=a[i]/2;
    }
    cout<< mn;
    // 여기에 코드를 작성해주세요.
    return 0;
}