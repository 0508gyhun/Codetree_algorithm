#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int sol(string s) // 두사람의 가장 가까운 거리
{

    int mn = INT_MAX;
    int dist = INT_MAX;
    int prev = -1;
    for(int i = 0 ; i < s.size() ; i++)
    {
        
        if(prev>=0 && s[i] == '1')
        {
            dist = i-prev;
            previ = i;
        }
        if(prev < 0 && s[i] == '1')
        {
            prev = i;
        }
        mn = min(mn,dist);

    }

    
    return mn;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >>n ;
    cin >>s;

    int mx = INT_MIN;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(s[i] == '1' || s[j] == '1') continue;

            s[i] = '1';
            s[j] = '1';


            mx = max(mx,sol(s));

            s[i] = '0';
            s[j] = '0';

        }
    }
    cout << mx;
    return 0;
}