#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int x,y;

bool ispel(int i)
{
    string s = to_string(i);
    if(s.size() %2 == 0)
    {
       // 0 1 2 3 
        string s1 = s.substr(0,s.size()/2);
        string s2 = s.substr(s.size()/2);
        reverse(s1.begin(),s1.end());
        if(s1 == s2) return true;
        // cout << s1 << " "<< s2 <<endl;
    }
    else
    {
        string s1 = s.substr(0,s.size()/2);
        string s2 = s.substr(s.size()/2+1);
        reverse(s1.begin(),s1.end());
        if(s1 == s2) return true;   
        // cout << s1 << " "<< s2 <<endl;

    }
    return false;
}

int cnt = 0;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> x>>y;

    for(int i = x ; i <= y ; i++)
    {
        if(ispel(i)) cnt++;
    }
    cout << cnt;
    return 0;
}