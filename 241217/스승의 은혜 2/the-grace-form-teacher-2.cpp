#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,b;
int a[1004];
int main() {
    // 여기에 코드를 작성해주세요.'

    cin >> n >> b;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int mx = INT_MIN;

    for(int i = 0 ; i < n ; i++)
    {
        int sum = 0;
        int cnt = 0 ;
        for(int j = 0 ; j < n ; j++)
        {
            if(i == j){
                a[i] = a[i]/2;
            }
            if(sum+a[j]<=b)
            {
                sum+=a[j];
                cnt++;
                
            } 


        }
        a[i] = a[i] *2;
        mx = max(mx,cnt);
    }

    cout << mx;
    return 0;
}