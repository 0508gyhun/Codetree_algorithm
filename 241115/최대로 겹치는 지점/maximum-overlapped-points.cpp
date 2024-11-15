#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int a[200];


int main() {
    
    cin >> n ;

    for(int i = 0 ; i < n ; i++)
    {
        int fr,to;
        cin >> fr>> to;
        for(int j = fr ; j <=to ; j++)
        {
           
            a[j]++;
        }
    }

    int ans = *max_element(a,a+200);
    cout << ans;
    
    // 여기에 코드를 작성해주세요.
    return 0;
}