#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n ; 
int a[1005];
int main() {
    // 여기에 코드를 작성해주세요.
    
    
    cin >> n ; 

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }

    int mn = INT_MAX;
    for(int i = 1 ; i <= n ; i++)
    {
        int sum = 0 ;
        for(int j = 1 ; j <= n ; j++)
        {
            if(i == j) continue;
            else if ( i > j)
            {
                int tmp = abs(n-j) * a[j];
                sum+=tmp;
            }
            else
            {
                int tmp = abs(j-i) * a[j];
                sum+=tmp;
               // cout <<"j"<<j<<" "<< tmp<< endl;
            }
        }
        //cout <<i <<" "<< sum<< endl;
        mn = min(mn,sum);

    }
    cout << mn;
    return 0;
}