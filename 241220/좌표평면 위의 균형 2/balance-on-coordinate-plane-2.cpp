#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int a[104];
int b[104];

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] >> b[i];
    }

    int ans = INT_MAX;
    for(int i = 0 ; i < 101 ; i+=2) // y
    {
        for(int j = 0 ; j < 101 ; j+=2) //x
        {
            int mx = INT_MIN;
            int cnt1 = 0;
            int cnt2 = 0 ;
            int cnt3 = 0 ;
            int cnt4 = 0;
            for(int k = 0 ; k < n ; k++)
            {
                
                if(a[k] < j && b[k] < i) cnt1++; // 왼아래
                if(a[k] < j && b[k] > i) cnt2++; // 왼위
                if(a[k] > j && b[k] < i) cnt3++;//오른 아랴
                if(a[k] > j && b[k] > i) cnt4++; // 오른 위


            }
           // cout <<i << j << cnt1 << cnt2 << cnt3 << cnt4<< endl;
            mx = max(mx, cnt1);
            mx = max(mx,cnt2);
            mx = max(mx,cnt3);
            mx = max(mx, cnt4);
            // cout << mx << endl;

            ans = min(ans,mx);

        }
    }
    cout << ans;
    return 0;
}