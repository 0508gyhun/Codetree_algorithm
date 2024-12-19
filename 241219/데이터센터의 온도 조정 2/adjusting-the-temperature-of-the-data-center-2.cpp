#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,c,g,h;
int ta[1004];
int tb[1004];
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >>c >> g >>h;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin >> ta[i] >> tb[i];
    }
    int mx = INT_MIN;
    for(int i = 0 ; i <= 1000 ; i++)
    {
        int sum = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(i < ta[j]) sum += c;
            else if(i>= ta[j] && i <= tb[j]) sum+=g;
            else sum+=h;
        }

        mx = max(mx,sum);
    }
    cout << mx;
    
    return 0;
}