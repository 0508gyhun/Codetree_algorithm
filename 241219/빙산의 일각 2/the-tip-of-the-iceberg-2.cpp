#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[104];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;  
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    int mx = INT_MIN;
    for(int i = 1 ; i <= 1000 ; i++)
    {
        int ans = 0 ;

        int cnt = 0 ;
        for(int j = 0 ; j < n ;j++)
        {
            if(a[j] > i) cnt++;
            else
            {
                if(cnt>0){
                    //cout << i <<" ";
                    cnt = 0;
                    ans++;
                } 
            }
        }
        if(cnt>0)ans++;
        mx = max(mx,ans);
    }
    cout << mx;
    return 0;
}