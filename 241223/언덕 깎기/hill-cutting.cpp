#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int a[1004];
int n;
int k =17;
int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }


    int mn = INT_MAX;
    for(int i = 0 ; i <= 100 ; i++)
    {

        int sum = 0 ;
        for(int j = 0 ; j < n ; j++)
        {
            if(i > a[j]) sum+=((i-a[j])*(i-a[j])); 
            else if(a[j] > i+k) sum+=((a[j] - i-k)*(a[j]-i-k));
        }
        mn = min(mn,sum);
    }
    cout << mn;
    return 0;
}