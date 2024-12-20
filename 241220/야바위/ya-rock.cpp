#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[104];
int b[104];
int c[104];

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] >> b[i] >> c[i];

    }    
    int mx = INT_MIN;
    for(int i = 1 ; i <= 3 ; i++)
    {
        int state[4] = {0,0,0,0};
        state[i] = 1;
        int ans = 0 ;
        for(int j= 0 ; j < n ; j++)
        {   
            int temp = state[a[j]];
            state[a[j]] = state[b[j]];
            state[b[j]] = temp;
            if(state[c[j]] == 1) ans++;  
               

        }    
        mx = max(mx,ans);
    }
    cout << mx;
    return 0;
}