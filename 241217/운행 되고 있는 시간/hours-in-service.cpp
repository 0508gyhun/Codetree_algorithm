#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int a[104][2];
int n;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n ; 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    int mx = INT_MIN;
    for(int i = 0 ;i < n ; i++)
    {
        int cnt[1004] = {0,};
        int cn = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(i == j) continue;

            for(int k = a[j][0] ; k < a[j][1] ; k++)
            {
                cnt[k]=1;
            }
        }
        for(int j = 0 ; j < 1004 ; j++)
        {
            if(cnt[j] == 1) cn++;
        }
        mx = max(mx,cn);
        

    }
    cout << mx;
    return 0;
}