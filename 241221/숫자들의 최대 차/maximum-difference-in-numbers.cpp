#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int n,k;
int a[1004];
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    int ans = INT_MIN;
    for(int i = 1 ; i <= 10000 ; i++)
    {
        int st = i;
        int end = i+k;
        int cnt = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(a[j] >= st && a[j] <= end)
            {
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}