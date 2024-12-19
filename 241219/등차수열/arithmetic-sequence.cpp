#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int n;
int a[104];
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    // int cnt = 0;
    int mx = INT_MIN;
    for(int i = 1 ; i <= 100 ; i++)
    {
        int cnt = 0 ;
        for(int j = 0 ; j < n-1 ; j++)
        {
            for(int p = j+1 ; p < n ; p++)
            {
                if((i - a[j]) == (a[p] - i)) {
                    cnt++;
                }
            }
        }
        mx = max(mx,cnt);
        
    }
    cout << mx;
    return 0;
}