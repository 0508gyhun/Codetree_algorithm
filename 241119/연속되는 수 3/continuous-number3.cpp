#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool isplus(int n)
{
    if(n>=0) return true;
    else return false;
}
int a[2004];

int main() {
    // 여기에 코드를 작성해주세요.
    int n ; 
    cin >> n ; 

    for(int i = 0 ; i < n ; i++)
    {   
        int tmp ;
        cin >> tmp;
        a[i] = tmp ; 
    }

    int cnt = 0 ;
    vector <int> v;

    for(int i = 0 ; i < n ; i++)
    {
        if(i == 0 || isplus(a[i-1]) == isplus(a[i]))
        {
            cnt++;
        }
        else
        {
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);
    int ans = *max_element(v.begin(), v.end());
    cout << ans;
    return 0;
}