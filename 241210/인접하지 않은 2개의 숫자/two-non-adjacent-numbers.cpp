#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[104];
int main() {
    // 여기에 코드를 작성해주세요.
    
    cin >> n ; 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    int ans = INT_MIN;
    int sum = 0 ;
    for(int i = 0 ; i < n-2 ; i++)
    {
        for(int j = i+2 ; j < n ; j++)
        {
            sum = a[i]+ a[j];
            ans = max(ans,sum);
        }
    }
    cout << ans;


    
    return 0;
}